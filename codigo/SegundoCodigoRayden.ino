// =====================================================================
// MINI SUMO - xMotion V3 (JSUMO)
// Hardware: 2 motores 6V, 2x QTR-1RC (borde), 3x JS40F (oponente),
//           MicroStart (opcional), LiPo 3S 11.4V
//
// MS07: biblioteca de primitivas (avanzar/retroceder/girar/detener)
//       con limite de velocidad, tiempo limite y pruebas (MODO_PRUEBAS)
// MS10: estrategia ESTANDAR vs PROPIA (condicionada por sensor)
// MS11: evasion de borde prioritaria + deteccion de atasco/empate
// =====================================================================

#include <xmotionV3.h>

// Tipo de dato de la maniobra. Debe ir ANTES de cualquier funcion, porque el
// IDE de Arduino genera prototipos automaticos al inicio del archivo.
struct Paso { int8_t l; int8_t r; uint16_t ms; };

// ---------------------------------------------------------------------
// 1. SELECCION DE MODO Y ESTRATEGIA
// ---------------------------------------------------------------------
#define MODO_COMBATE   0   // competencia
#define MODO_PRUEBAS   1   // ruedas EN EL AIRE: polaridad + pruebas de primitivas
#define MODO_CALIBRAR  2   // imprime QTR e IR por Serial (9600)

#define ESTRAT_ESTANDAR 0  // gira en sitio, embiste al ver, corrige en arco
#define ESTRAT_PROPIA   1  // apertura + giro dirigido + flanqueo si hay empate

const byte MODO      = MODO_COMBATE;
const byte ESTRATEGIA = ESTRAT_PROPIA;

#define DEBUG 1            // 1 = registra eventos por Serial (poner 0 en competencia)

#if DEBUG
  #define LOG(x) do { Serial.print(millis()); Serial.print(','); Serial.println(F(x)); } while (0)
#else
  #define LOG(x)
#endif

// ---------------------------------------------------------------------
// 2. PINES (ajusta a tu robot)
// ---------------------------------------------------------------------
const byte LED1    = 8;

// ADVERTENCIA: A0 es del MicroStart y NO puede usarse para un QTR.
// Los QTR-1RC pueden ir en cualquier pin digital/analogico libre (se leen como digitales).
const byte QTR_IZQ = 255;  // <-- AJUSTAR: pin real del QTR izquierdo (255 = sin definir)
const byte QTR_DER = A1;   // <-- VERIFICAR: pin real del QTR derecho

const byte IR_IZQ  = A5;   // JS40F izquierdo
const byte IR_CEN  = 4;    // JS40F central
const byte IR_DER  = 2;    // JS40F derecho

// MicroStart conectado en A0. Verifica el nivel con MODO_CALIBRAR:
// la columna MS debe valer MICROSTART_ACTIVO solo cuando el modulo esta ACTIVADO.
// Si el valor esta invertido, cambia a LOW (fallo seguro: si esta mal, no se mueve).
const bool USAR_MICROSTART   = true;
const byte MICROSTART_PIN    = A0;
const int  MICROSTART_ACTIVO = HIGH;   // nivel que indica "combate"

// ---------------------------------------------------------------------
// 3. SENSORES
// ---------------------------------------------------------------------
// QTR-1RC: tiempo de descarga en microsegundos. Blanco (borde) = corto,
// negro = largo. Calibra con MODO_CALIBRAR.
const unsigned int QTR_TIMEOUT_US = 1200;
const unsigned int UMBRAL_QTR_US  = 400;
const bool BORDE_ES_VALOR_BAJO    = true;   // false si tu lectura es al reves

// JS40F digital. Segun tus pruebas, en reposo con LOW daba "detecto" siempre,
// asi que detecta con HIGH. Confirma con MODO_CALIBRAR (reposo = 0, con mano = 1).
const int IR_DETECTA = HIGH;

// ---------------------------------------------------------------------
// 4. MOTORES (polaridad y potencia)
// ---------------------------------------------------------------------
// Potencia maxima real (%) de cada motor: motores 6V con bateria 11.4V.
// Ajusta cada uno por separado para que avance derecho.
// Bajado de 50 a 40 para pruebas (el robot iba demasiado rapido). Sube poco a poco.
const int POT_MAX_IZQ = 40;
const int POT_MAX_DER = 40;

// Si una rueda gira al reves, pon true. Cambiar SOLO aqui.
// Tus pruebas: todo iba en reversa -> ambos motores invertidos.
const bool INVERTIR_IZQ = true;
const bool INVERTIR_DER = true;

const unsigned int T_MAX_MOV = 1500;  // tope absoluto de cualquier movimiento (ms)
const unsigned int T_CMD     = 100;   // vigencia de un comando continuo (ms): si el
                                      // lazo se congela, los motores se detienen

// ---------------------------------------------------------------------
// 5. PARAMETROS DE ESTRATEGIA (en % y ms)
// ---------------------------------------------------------------------
const int V_ATAQUE   = 100;
const int V_BUSQUEDA = 60;
const int V_GIRO     = 80;

const unsigned int ESPERA_INICIAL = 5000;  // regla: 5 s tras iniciar (sin MicroStart)

// Evasion de borde
const unsigned int T_RETRO = 200;
const unsigned int T_GIRO  = 250;

// Estrategia propia
const unsigned int T_APERTURA   = 200;   // avance inicial hacia el centro
const unsigned int T_EMPUJE_MAX = 2500;  // empate de empuje -> flanqueo

// true  = si el IR frontal ve al rival, embiste aun sobre el borde (arriesgado)
// false = el borde SIEMPRE tiene prioridad (recomendado)
const bool PRIORIDAD_FRENTE = false;

// ---------------------------------------------------------------------
// 6. PRIMITIVAS DE MOVIMIENTO (MS07)
// ---------------------------------------------------------------------
unsigned long tFinMov = 0;
bool movActivo = false;

int velSegura(int v) {                 // limita a -100..100 %
  if (v > 100)  return 100;
  if (v < -100) return -100;
  return v;
}

void motoresRaw(int l, int r) {        // UNICO punto que toca el hardware
  l = velSegura(l);
  r = velSegura(r);
  if (INVERTIR_IZQ) l = -l;
  if (INVERTIR_DER) r = -r;
  xmotion.MotorControl((int)((long)l * POT_MAX_IZQ / 100),
                       (int)((long)r * POT_MAX_DER / 100));
}

void detener() {
  xmotion.StopMotors(1);
  movActivo = false;
}

void mover(int l, int r, unsigned int ms) {  // con tiempo limite
  if (ms > T_MAX_MOV) ms = T_MAX_MOV;
  motoresRaw(l, r);
  tFinMov = millis() + ms;
  movActivo = true;
}

void avanzar(int vel, unsigned int ms)     { mover(vel, vel, ms); }
void retroceder(int vel, unsigned int ms)  { mover(-vel, -vel, ms); }
// dir = +1 derecha (izq adelante, der atras), -1 izquierda
void girar(int dir, int vel, unsigned int ms) { mover(dir * vel, -dir * vel, ms); }

// ---- Secuencias de pasos (maniobras reproducibles) ----

#define SEQ_NINGUNA  0
#define SEQ_EVASION  1   // prioridad maxima, no interrumpible por oponente
#define SEQ_ATAQUE   2   // flanqueo, no interrumpible por oponente
#define SEQ_APERTURA 3   // interrumpible por oponente
#define SEQ_BUSQUEDA 4   // interrumpible por oponente

const Paso* seq = NULL;
uint8_t seqN = 0, seqIdx = 0, seqTipo = SEQ_NINGUNA;

// Devuelve true mientras el movimiento actual sigue vigente
bool actualizarMovimiento() {
  if (movActivo && (long)(millis() - tFinMov) >= 0) {
    movActivo = false;
    if (seqTipo == SEQ_NINGUNA) detener();   // watchdog: tiempo agotado -> parar
  }
  return movActivo;
}

void ejecutarPaso() {
  mover(seq[seqIdx].l, seq[seqIdx].r, seq[seqIdx].ms);
}

void iniciarSecuencia(const Paso* s, uint8_t n, uint8_t tipo) {
  seq = s; seqN = n; seqIdx = 0; seqTipo = tipo;
  ejecutarPaso();
}

// true mientras la secuencia sigue corriendo
bool actualizarSecuencia() {
  if (seqTipo == SEQ_NINGUNA) return false;
  if (!actualizarMovimiento()) {
    seqIdx++;
    if (seqIdx >= seqN) {
      seqTipo = SEQ_NINGUNA;
      detener();
      return false;
    }
    ejecutarPaso();
  }
  return true;
}

// ---- Maniobras definidas (positivo = adelante) ----
// Borde IZQ -> retrocede y gira a la DERECHA (alejandose del borde)
const Paso EV_IZQ[]   = { {-100, -100, T_RETRO},        { 100, -100, T_GIRO} };
const Paso EV_DER[]   = { {-100, -100, T_RETRO},        {-100,  100, T_GIRO} };
// Borde frontal (ambos QTR): retroceso mas largo y giro de ~180 grados
const Paso EV_FRENTE[] = { {-100, -100, T_RETRO + 100}, { 100, -100, T_GIRO * 2} };

// Flanqueo (estrategia propia): retro, giro hacia un lado, arco de regreso
const Paso FLANCO_IZQ[] = { {-100, -100, 150}, {-100, 100, 200}, {100,  50, 350} };
const Paso FLANCO_DER[] = { {-100, -100, 150}, { 100,-100, 200}, { 50, 100, 350} };

// Apertura: avance recto al centro
const Paso APERTURA[] = { {100, 100, T_APERTURA} };

// Busqueda propia: giro + avance corto (barrido, no solo girar en sitio)
const Paso BUSQ_DER[] = { { V_GIRO, -V_GIRO, 350}, {60, 60, 200} };
const Paso BUSQ_IZQ[] = { {-V_GIRO,  V_GIRO, 350}, {60, 60, 200} };

// ---------------------------------------------------------------------
// 7. LECTURA DE SENSORES
// ---------------------------------------------------------------------
unsigned int leerQTR(byte pin) {
  // Proteccion: jamas manejar como salida el pin del MicroStart o un pin sin definir
  if (pin == 255 || pin == MICROSTART_PIN) return QTR_TIMEOUT_US;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  pinMode(pin, INPUT);
  unsigned long t0 = micros();
  while (digitalRead(pin) == HIGH) {
    if (micros() - t0 >= QTR_TIMEOUT_US) return QTR_TIMEOUT_US;
  }
  return (unsigned int)(micros() - t0);
}

bool esBorde(unsigned int v) {
  return BORDE_ES_VALOR_BAJO ? (v < UMBRAL_QTR_US) : (v > UMBRAL_QTR_US);
}
bool bordeIzq() { return esBorde(leerQTR(QTR_IZQ)); }
bool bordeDer() { return esBorde(leerQTR(QTR_DER)); }

bool irIzq() { return digitalRead(IR_IZQ) == IR_DETECTA; }
bool irCen() { return digitalRead(IR_CEN) == IR_DETECTA; }
bool irDer() { return digitalRead(IR_DER) == IR_DETECTA; }

// ---------------------------------------------------------------------
// 8. ESTADO DE COMBATE Y REGISTRO A/B
// ---------------------------------------------------------------------
int ultimaDireccion = 1;           // -1 izq, +1 der (donde se vio al rival)
bool enContacto = false;
unsigned long tContacto = 0;
bool aperturaHecha = false;

unsigned int nAtaques = 0, nEvasiones = 0, nAtascos = 0;

// ---------------------------------------------------------------------
// 9. MODOS AUXILIARES
// ---------------------------------------------------------------------
void parpadear(int veces, int ms) {
  for (int i = 0; i < veces; i++) {
    digitalWrite(LED1, HIGH); delay(ms);
    digitalWrite(LED1, LOW);  delay(ms);
  }
}

void modoCalibrar() {
  Serial.println(F("QTR_IZQ(us)\tQTR_DER(us)\tIR_I\tIR_C\tIR_D\tMS"));
  while (true) {
    Serial.print(leerQTR(QTR_IZQ)); Serial.print('\t');
    Serial.print(leerQTR(QTR_DER)); Serial.print('\t');
    Serial.print(irIzq());          Serial.print('\t');
    Serial.print(irCen());          Serial.print('\t');
    Serial.print(irDer());          Serial.print('\t');
    Serial.println(digitalRead(MICROSTART_PIN));
    delay(200);
  }
}

bool probar(const __FlashStringHelper* nombre, bool ok) {
  Serial.print(nombre);
  Serial.println(ok ? F(" ... OK") : F(" ... FALLA"));
  return ok;
}

unsigned long medirMovimiento(int l, int r, unsigned int ms) {
  unsigned long t0 = millis();
  mover(l, r, ms);
  while (actualizarMovimiento()) {}
  return millis() - t0;
}

unsigned long medirSecuencia(const Paso* s, uint8_t n) {
  unsigned long t0 = millis();
  iniciarSecuencia(s, n, SEQ_EVASION);
  while (actualizarSecuencia()) {}
  return millis() - t0;
}

void modoPruebas() {
  Serial.println(F("== PRUEBAS (ruedas en el aire) =="));
  parpadear(10, 250);                       // 5 s para soltar el robot

  // --- Pruebas puras ---
  probar(F("velSegura(150)==100"),  velSegura(150) == 100);
  probar(F("velSegura(-150)==-100"), velSegura(-150) == -100);
  probar(F("velSegura(40)==40"),    velSegura(40) == 40);

  // --- Polaridad (verificar a simple vista) ---
  Serial.println(F("Solo IZQ adelante 1 s: la rueda IZQUIERDA debe girar hacia ADELANTE"));
  medirMovimiento(60, 0, 1000); delay(800);
  Serial.println(F("Solo DER adelante 1 s: la rueda DERECHA debe girar hacia ADELANTE"));
  medirMovimiento(0, 60, 1000); delay(800);
  Serial.println(F("Si alguna giro al reves -> INVERTIR_IZQ / INVERTIR_DER"));

  // --- Tiempos de cada primitiva (tolerancia 20 ms) ---
  unsigned long dt;
  dt = medirMovimiento(60, 60, 300);   probar(F("avanzar 300ms"),    dt >= 285 && dt <= 320); delay(500);
  dt = medirMovimiento(-60, -60, 300); probar(F("retroceder 300ms"), dt >= 285 && dt <= 320); delay(500);
  dt = medirMovimiento(60, -60, 300);  probar(F("girar 300ms"),      dt >= 285 && dt <= 320); delay(500);

  // --- Tope de seguridad: se pide 9999 ms, debe cortar en T_MAX_MOV ---
  dt = medirMovimiento(60, 60, 9999);
  probar(F("tiempo limite T_MAX_MOV"), dt >= T_MAX_MOV - 15 && dt <= T_MAX_MOV + 20);
  detener(); delay(500);

  // --- Consistencia: misma maniobra 3 veces ---
  unsigned long t[3];
  for (int i = 0; i < 3; i++) { t[i] = medirSecuencia(EV_IZQ, 2); delay(400); }
  unsigned long esperado = T_RETRO + T_GIRO;
  bool consistente = true;
  for (int i = 0; i < 3; i++) if (t[i] + 20 < esperado || t[i] > esperado + 20) consistente = false;
  probar(F("secuencia EV_IZQ x3 consistente"), consistente);

  detener();
  Serial.println(F("== FIN DE PRUEBAS =="));
  while (true) { parpadear(1, 100); }
}

void esperarArranque() {
  if (USAR_MICROSTART) {
    while (digitalRead(MICROSTART_PIN) != MICROSTART_ACTIVO) {
      digitalWrite(LED1, HIGH); delay(50);
      digitalWrite(LED1, LOW);  delay(50);
    }
  } else {
    parpadear(ESPERA_INICIAL / 500, 250);
  }
  digitalWrite(LED1, HIGH);   // LED encendido = combate
}

// ---------------------------------------------------------------------
// 10. SETUP / LOOP
// ---------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(IR_IZQ, INPUT);
  pinMode(IR_CEN, INPUT);
  pinMode(IR_DER, INPUT);
  if (USAR_MICROSTART) pinMode(MICROSTART_PIN, INPUT);

  detener();

  // Seguridad: si los pines de los QTR estan sin definir o chocan con el MicroStart,
  // el robot NO arranca (LED parpadeando rapido) hasta corregirlo.
  if (MODO != MODO_CALIBRAR &&
      (QTR_IZQ == 255 || QTR_DER == 255 ||
       QTR_IZQ == MICROSTART_PIN || QTR_DER == MICROSTART_PIN ||
       QTR_IZQ == QTR_DER)) {
    Serial.println(F("ERROR: pines QTR sin definir o en conflicto con el MicroStart (A0)"));
    while (true) { parpadear(1, 100); }
  }

  if (MODO == MODO_CALIBRAR) modoCalibrar();
  if (MODO == MODO_PRUEBAS)  modoPruebas();

  esperarArranque();
  LOG("INICIO");
}

void loop() {
  // Paro de seguridad si el MicroStart se apaga
  if (USAR_MICROSTART && digitalRead(MICROSTART_PIN) != MICROSTART_ACTIVO) {
    seqTipo = SEQ_NINGUNA;
    detener();
    return;
  }

  actualizarMovimiento();

  bool oI = irIzq(), oC = irCen(), oD = irDer();
  bool frente = oC || (oI && oD);

  // ---------- PRIORIDAD 1: BORDE (MS11) ----------
  // Durante el retroceso de una evasion no se re-evalua (los QTR miran
  // hacia adelante). Si durante el giro vuelve a tocar borde, se reinicia.
  bool retrocediendo = (seqTipo == SEQ_EVASION && seqIdx == 0);
  bool ignorarBorde  = PRIORIDAD_FRENTE && frente;

  if (!retrocediendo && !ignorarBorde) {
    bool bI = bordeIzq();
    bool bD = bordeDer();
    if (bI || bD) {
      nEvasiones++;
      enContacto = false;
      if (bI && bD)  { LOG("BORDE_FRENTE"); iniciarSecuencia(EV_FRENTE, 2, SEQ_EVASION); }
      else if (bI)   { LOG("BORDE_IZQ");    iniciarSecuencia(EV_IZQ,    2, SEQ_EVASION); }
      else           { LOG("BORDE_DER");    iniciarSecuencia(EV_DER,    2, SEQ_EVASION); }
      return;
    }
  }

  // ---------- Secuencias en curso ----------
  if (seqTipo == SEQ_EVASION || seqTipo == SEQ_ATAQUE) {
    actualizarSecuencia();
    return;
  }
  if (seqTipo == SEQ_APERTURA || seqTipo == SEQ_BUSQUEDA) {
    if (frente) {
      seqTipo = SEQ_NINGUNA;          // oponente adquirido: cancelar y atacar
    } else {
      actualizarSecuencia();
      return;
    }
  }

  // ---------- PRIORIDAD 2: ATAQUE (MS10) ----------
  if (frente) {
    aperturaHecha = true;
    if (!enContacto) {
      enContacto = true;
      tContacto = millis();
      nAtaques++;
      LOG("ATAQUE");
    }
    // Propia: si hay empate de empuje, flanquear (MS11: recuperacion de atasco)
    if (ESTRATEGIA == ESTRAT_PROPIA && millis() - tContacto > T_EMPUJE_MAX) {
      nAtascos++;
      enContacto = false;
      LOG("ATASCO_FLANQUEO");
      if (ultimaDireccion > 0) iniciarSecuencia(FLANCO_DER, 3, SEQ_ATAQUE);
      else                     iniciarSecuencia(FLANCO_IZQ, 3, SEQ_ATAQUE);
      ultimaDireccion = -ultimaDireccion;   // alternar lado en el siguiente atasco
      return;
    }
    avanzar(V_ATAQUE, T_CMD);
    return;
  }
  enContacto = false;

  // ---------- Rival visto de lado ----------
  if (oI) {
    aperturaHecha = true;
    ultimaDireccion = -1;
    if (ESTRATEGIA == ESTRAT_PROPIA) girar(-1, V_GIRO, T_CMD);   // pivota hasta centrar
    else                             mover(30, 100, T_CMD);      // corrige en arco
    return;
  }
  if (oD) {
    aperturaHecha = true;
    ultimaDireccion = 1;
    if (ESTRATEGIA == ESTRAT_PROPIA) girar(1, V_GIRO, T_CMD);
    else                             mover(100, 30, T_CMD);
    return;
  }

  // ---------- PRIORIDAD 3: BUSQUEDA ----------
  if (ESTRATEGIA == ESTRAT_PROPIA) {
    if (!aperturaHecha) {
      aperturaHecha = true;
      LOG("APERTURA");
      iniciarSecuencia(APERTURA, 1, SEQ_APERTURA);
    } else {
      if (ultimaDireccion > 0) iniciarSecuencia(BUSQ_DER, 2, SEQ_BUSQUEDA);
      else                     iniciarSecuencia(BUSQ_IZQ, 2, SEQ_BUSQUEDA);
    }
  } else {
    girar(ultimaDireccion, V_BUSQUEDA, T_CMD);   // estandar: giro en sitio
  }
}
