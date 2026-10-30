# Código fuente del robot
// =====================================================
// MINI SUMO - XMOTION V3
// 2 motores, 2 QTR (borde del dojo), 3 sensores IR (oponente)
// =====================================================

#include <xmotionV3.h>

// ---------------- PINES (AJUSTAR A TU ROBOT) ----------------
const byte Led1 = 8;

const byte QTR_IZQ = A0;   // QTR izquierdo (analógico)
const byte QTR_DER = A1;   // QTR derecho (analógico)

const byte IR_IZQ = A5;     // IR izquierdo
const byte IR_CEN = 4;     // IR central
const byte IR_DER = 2;     // IR derecho

// ---------------- AJUSTES DE SENSORES ----------------
// QTR: abre el monitor serial para ver los valores sobre negro y sobre el borde blanco.
// Normalmente el blanco da un valor BAJO en QTR analógico. Si el tuyo es al revés,
// cambia BORDE_ES_VALOR_BAJO a false.
const int  UMBRAL_QTR = 500;
const bool BORDE_ES_VALOR_BAJO = true;

// IR digitales: la mayoría de módulos dan LOW cuando detectan.
// Si el tuyo da HIGH, cambia a HIGH.
const int IR_DETECTA = HIGH;   // antes: LOW

// ---------------- CALIBRACION DE MOTORES ----------------
// Usa la proporción que te funcionó para ir derecho.
// Estos valores son la potencia máxima (100%) de cada motor.
const int CALIB_L = 50;
const int CALIB_R = 50;

// ---------------- TIEMPOS (ms) ----------------
const int ESPERA_INICIAL = 5000;
const int T_RETROCESO    = 200;
const int T_GIRO_BORDE   = 250;

// Última dirección donde se vio al oponente: -1 izquierda, 1 derecha
int ultimaDireccion = 1;

// ---------------- ESTRATEGIA ----------------
// true  = si el IR central ve al oponente, embiste SIEMPRE (incluso sobre el borde)
// false = el borde del dojo tiene prioridad (más seguro)
const bool PRIORIDAD_FRENTE = true;

// Velocidades de búsqueda (en %), ambas hacia adelante
const int BUSCAR_RAPIDA = 70;
const int BUSCAR_LENTA  = 30;

// ---------------- FUNCIONES ----------------
void driveCalibrated(int percentLeft, int percentRight) {
  int speedL = map(percentLeft, -100, 100, -CALIB_L, CALIB_L);
  int speedR = map(percentRight, -100, 100, -CALIB_R, CALIB_R);
  xmotion.MotorControl(speedL, speedR);
}

bool bordeIzq() {
  int v = analogRead(QTR_IZQ);
  return BORDE_ES_VALOR_BAJO ? (v < UMBRAL_QTR) : (v > UMBRAL_QTR);
}

bool bordeDer() {
  int v = analogRead(QTR_DER);
  return BORDE_ES_VALOR_BAJO ? (v < UMBRAL_QTR) : (v > UMBRAL_QTR);
}

bool irIzq() { return digitalRead(IR_IZQ) == IR_DETECTA; }
bool irCen() { return digitalRead(IR_CEN) == IR_DETECTA; }
bool irDer() { return digitalRead(IR_DER) == IR_DETECTA; }

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(IR_IZQ, INPUT);
  pinMode(IR_CEN, INPUT);
  pinMode(IR_DER, INPUT);

  xmotion.StopMotors(1);

  // Espera de 5 segundos (LED parpadeando, 10 ciclos de 500 ms)
  for (int i = 0; i < ESPERA_INICIAL / 500; i++) {
    digitalWrite(Led1, HIGH);
    delay(250);
    digitalWrite(Led1, LOW);
    delay(250);
  }

  digitalWrite(Led1, HIGH); // LED encendido = combate
}

void loop() {
  bool oI = irIzq();
  bool oC = irCen();
  bool oD = irDer();

  // ---------- PRIORIDAD 1: OPONENTE DE FRENTE ----------
  if (PRIORIDAD_FRENTE && oC) {
    driveCalibrated(100, 100);
    return;
  }

  bool bI = bordeIzq();
  bool bD = bordeDer();

  // ---------- PRIORIDAD 2: NO CAERSE DEL DOJO ----------
  if (bI && bD) {
    driveCalibrated(-100, -100);
    delay(T_RETROCESO);
    driveCalibrated(100, -100);
    delay(T_GIRO_BORDE * 2);
    return;
  }
  if (bI) {
    driveCalibrated(-100, -100);
    delay(T_RETROCESO);
    driveCalibrated(100, -100);
    delay(T_GIRO_BORDE);
    return;
  }
  if (bD) {
    driveCalibrated(-100, -100);
    delay(T_RETROCESO);
    driveCalibrated(-100, 100);
    delay(T_GIRO_BORDE);
    return;
  }

  // ---------- PRIORIDAD 3: OPONENTE (si el borde tenía prioridad) ----------
  if (oC) {
    driveCalibrated(100, 100);
  } else if (oI) {
    ultimaDireccion = -1;
    driveCalibrated(30, 100);      // corrige a la izquierda sin ir hacia atrás
  } else if (oD) {
    ultimaDireccion = 1;
    driveCalibrated(100, 30);      // corrige a la derecha sin ir hacia atrás
  } else {
    // ---------- PRIORIDAD 4: BUSCAR (avanzando en arco) ----------
    if (ultimaDireccion == 1) driveCalibrated(BUSCAR_RAPIDA, BUSCAR_LENTA);
    else                      driveCalibrated(BUSCAR_LENTA, BUSCAR_RAPIDA);
  }
}
