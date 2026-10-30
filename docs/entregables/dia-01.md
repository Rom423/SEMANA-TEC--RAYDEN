kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E1"
dia: 1
responsable_registro: "Mauricio Rodríguez"
estado: "Completado"
fecha: "2026-10-26"
revision_docente: "APROBADO"

# E1 Día 1 - ATREVERSE | Contrato de misión, inventario y dōjō

## 0 Identificación, equipo y logística del dōjō

| Campo obligatorio | Dato |
|---|---|
| Fecha y horario de esta sesión | 2026-10-26 09:10 - 11:50 |
| Nombre / alias del equipo | RAYDEN |
| Misión / plataforma | M01 Mini-sumo autónomo |
| Objetivo verificable del robot (una frase) | Mejora de estrategia de ataque y búsqueda para obtener un robot altamente competitivo. |
| **Dōjō asignado - campus, edificio y sala/taller exactos** | Campus León / CTA / Laboratorio de electrónica |
| Instructor o supervisor presente en la sesión | Camilo Duque |

## 1 Integrantes, responsabilidades, accesibilidad y decisiones (0-15 min)

| Alias GitHub | Rol inicial | Carta y frontera (D/S/E; F1-F4) | Alcances ID (1-3) | Necesidad de apoyo o accesibilidad acordada |
|---|---|---|---|---|
| @ROM423 | Documentación y Mecánica | S SUPERAR / F3 OPTIMIZAR | MS02, MS05, MS06 | Ninguna |
| @mimiprogramando | Integración y Firmware | D DOMINAR / F2 DECIDIR | MS07, MS10, MS11 | Ninguna |

**Acuerdo de colaboración:** Las decisiones técnicas sobre CAD y estructura mecánica son asumidas por @ROM423, mientras que la programación de la FSM, calibración de sensores y control de versión corresponden a @mimiprogramando. Ante desacuerdos sobre el diseño o la estrategia, se realizan pruebas rápidas de laboratorio (A/B) para respaldar la decisión con datos medibles en el dohyō. Ambos integrantes se apoyan activamente en soldadura y cableado, realizando pausas breves cada 60 minutos.

## 2 Demostración de la plataforma y seguridad (15-35 min)

| Elemento | Observación directa | Evidencia / vínculo |
|---|---|---|
| Plataforma base inspeccionada (estado, modelo, ID inventario) | Minisumo Rayden en fase de integración funcional | [docs/inventario.md](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/0fbd57b585966195a52b2dc4828b429047eb1107/datos/inventario_materiales.csv) |
| Funciones existentes y límites comprobados | Chasis impreso, electrónica preliminar basada en Arduino Nano, sensores IR y QTR funcionales. | [codigo/test_sensores.ino](https://drive.google.com/drive/folders/14Y3g8qSaT5biWsKJrnndZYpBty7S89Eg?usp=sharing) |
| Restricciones de competición o exhibición verificadas | Dimensiones (10x10 cm) y peso (máx. 500 g) verificados | [docs/reglamento_minisumo.pdf](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/1b9895cfbf8a2e58687364c232a2c91b44a6ce5b/herramientas/Reglamento.pdf) |
| Riesgos vistos y medidas activas | Cuchilla afilada (navaja) y motores de alta tracción; requiere cubierta protectora | [docs/seguridad.md](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/f0afe7f0010fecbf4091b81b7b256fa9efa34853/docs/seguridad.md) |

**Normas específicas según misión (M01):**
* Protecciones de alimentación (fusible y switch principal).
* Desarmar motores o desconectar LiPo antes de manipular ruedas o estructuras.
* Dohyō delimitado, rival de referencia estático y botón de paro manual verificado.

## 3 Integración de Mission Forge C2 y pacto de alcances (65-100 min)

| Alias | Kit enlazado | Alcance principal | Complementos | Katas elegidos | Horas mín.-máx. | Evidencia final esperada | Negociación aprobada |
|---|---|---|---|---|---|---|---|
| @ROM423 | [compromiso kaizen mauricio](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/15c14192ac98ddd2902c7f769ad5755911ccc98d/participantes/compromiso-kaizen-mauricio-rodriguez-martinez.md) | MS02 | MS05, MS06 | K1, K2 | 9-12 h | Video de pruebas y CAD final validado | Sí |
| @mimiprogramando | [compromiso kaizen ximena](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/2b05528171ec14a208a0ec19f9a77702006b38e6/participantes/compromiso-kaizen-karla-ximena-jaime-neri.md) | MS07 | MS10, MS11 | K1, K2, K3 | 9-12 h | Video de pruebas de ataque y repositorio de código | Sí |

**Resultado de negociación grupal:**

## 5 Inventario exhaustivo y especificación de materiales (obligatorio)

### 5.1 Inventario maestro del equipo

| ID | Categoría | Material o recurso (especificación exacta) | Cantidad req. | Cantidad conf. | Fuente/proveedor | Ubicación física | Responsable | Estado | Alternativa compatible | Día req. |
|---|---|---|---|---|---|---|---|---|---|---|
| MAT-001 | Plataforma | Chasis impreso 3D en PLA Rayden | 1 ud | 1 | Equipo Rayden | Lab Electrónica CTA | @ROM423 | CONFIRMADO | Reimpresión Centauri Carbon 2 | D1 |
| MAT-002 | Actuadores | Motores Core DC 6V 400/750 RPM JSUMO | 2 ud | 2 | Equipo Rayden | Lab Electrónica CTA | @ROM423 | CONFIRMADO | Motores N20 estándar | D1 |
| MAT-003 | Estructura | Mini Katana Blade 10cm JSUMO | 1 ud | 1 | Equipo Rayden | Lab Electrónica CTA | @ROM423 | CONFIRMADO | Placa de latón/acero | D2 |
| MAT-004 | Mecánica | Ruedas JS2622 aluminio/silicona JSUMO | 1 par | 1 | Equipo Rayden | Lab Electrónica CTA | @ROM423 | CONFIRMADO | Ruedas de goma N20 | D1 |
| MAT-005 | Seguridad | MicroStart Módulo de arranque JSUMO | 1 ud | 1 | Equipo Rayden | Lab Electrónica CTA | @mimiprogramando | CONFIRMADO | Switch manual directo | D1 |
| MAT-006 | Sensores | JS40F Sensor IR digital (Rango 40 cm) | 3 ud | 3 | Equipo Rayden | Lab Electrónica CTA | @mimiprogramando | CONFIRMADO | Sensores Sharp GP2Y0A21 | D1 |
| MAT-007 | Sensores | QTR-1RC Sensor IR de borde | 1 par | 1 | Equipo Rayden | Lab Electrónica CTA | @mimiprogramando | CONFIRMADO | Sensor QTR-1A | D1 |
| MAT-008 | Electrónica | JSUMO xMotion V3 Controlador Integrado | 1 ud | 1 | Equipo Rayden | Lab Electrónica CTA | @mimiprogramando | RESERVADO | Arduino Nano + Driver TB6612FNG | D2/D4 |
| MAT-009 | Energía | Batería LiPo 3S 11.4V 300mAh HV XT30 | 1 ud | 1 | Equipo Rayden | Lab Electrónica CTA | @ROM423 | CONFIRMADO | Batería LiPo 2S 7.4V | D1 |
| MAT-010 | Actuadores | MG90S Micro Servo Motor | 1 ud | 1 | Equipo Rayden | Lab Electrónica CTA | @ROM423 | CONFIRMADO | Servo SG90 estándar | D2 |
| MAT-011 | Herramientas | Cautín y estación de soldadura con estaño | 1 ud | 1 | Lab CTA | Lab Electrónica CTA | @ROM423 | CONFIRMADO | Cautín tipo lápiz | D4 |
| MAT-012 | Infraestructura| Dohyō oficial de mini-sumo de pruebas | 1 ud | 1 | Lab CTA | Lab Electrónica CTA | Camilo Duque | CONFIRMADO | Lona delimitada con cinta blanca | D2 |

### 5.2 Riesgos de recursos y abastecimiento

| Bloqueante | A qué alcance afecta | Solución prevista / fecha y responsable | Impacto si no se resuelve |
|---|---|---|---|
| Retraso en integración de xMotion V3 | MS07, MS10 | Utilizar tarjeta Arduino Nano + driver externo temporal durante D2/D3 | Ninguno; ruta de respaldo validada |

**Materiales completos para ejecutar el Día 2:** Sí.  
**Confirmado por:** Ximena Neri a las 11:45 hrs (2026-10-26).

## 6 Kata 0 exploración técnica de arranque (100-160 min)

| Integrante/alcance | Pregunta técnica | Mini-prueba o prototipo de exploración | Resultado o error observado | Evidencia enlazada | Acción necesaria antes de D2 |
|---|---|---|---|---|---|
| @ROM423 | ¿El chasis 3D soporta la carga del módulo de motores y cuña? | Ensamble manual y prueba de empuje básico | Ajuste mecánico firme | [cad/chasis_v1.sldprt](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/57d780fc676ac320a3cda1ca0d785d211eee3a58/hardware/Raiden%20rumbo%20a%20japon.SLDPRT) | Imprimir soportes de repuesto |
| @mimiprogramando | ¿El firmware lee correctamente los sensores IR sobre Arduino? | Lectura analógica/digital por puerto serie | Lecturas estables a 20 cm | [codigo/test_ir.ino](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/e296b2336d4382ef7655c44c3e12fb9f6f1530bf/codigo/PrimerCodigo_Rayden.ino) | Mapear pines definitivos para la FSM |

## 7 Cierre: contrato técnico y puerta de salida E1 (160-180 min)

- [x] El objetivo colectivo tiene condición de éxito verificable.
- [x] Cada estudiante depositó su kit Markdown original en `participantes/<alias>/compromiso.md`.
- [x] Cada estudiante completó su E1 personal y definió frontera, evidencia y alcances.
- [x] El inventario está completo, normalizado y con responsables asignados.
- [x] Se asignó dōjō específico (Campus León / CTA / Lab. Electrónica).
- [x] Se inspeccionaron riesgos, paro de emergencia y seguridad.
- [x] El profesor aprobó el alcance y las condiciones de seguridad.

**Gate E1:** APROBADO  
**Revisor:** Camilo Duque  
**Fecha:** 2026-10-26
