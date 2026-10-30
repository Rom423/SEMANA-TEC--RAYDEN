---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E4"
dia: 4
responsable_registro: "@mimiprogramando"
estado: "Completado"
fecha: "2026-10-29"
revision_docente: "APROBADO"
---

# E4 Día 4 - ITERAR | Kaizen 2, robustez y preparación de demostración

## 0 Contexto

| Campo | Dato |
|---|---|
| Fecha y dōjō | 2026-10-29, Campus León / CTA / Laboratorio de electrónica |
| Equipo y misión | RAYDEN / M01 Mini-sumo autónomo |
| Versiones trazables | V1, K1, K2 |

## 1 Ruta de actividades del Día 4 (180 min)

| Actividad | Minutos | Registro requerido / evidencia |
|---|---|---|
| Revisión por pares y retroalimentación | 0-20 | Retroalimentación del equipo par sobre cableado y fijación de navaja |
| Diseño/ejecución Kaizen 2 | 20-70 | Integración de placa JSUMO xMotion V3, soldadura limpia de terminales y montaje de navaja metálica |
| Comparación V1-K1-K2 | 70-115 | Pruebas de movimiento, respuesta de aceleración y tiempos de reacción (registrados en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| Ensayo de robustez | 115-145 | Prueba con batería a medio consumo (11.1V / 30%) y tracción en superficie con polvo |
| Preparación de demo | 145-165 | Guion de presentación para el Día 5, asignación de roles y plan de contingencia |
| Gate de preparación | 165-180 | Verificación del checklist y aprobación docente para demostración final |

## 2 Revisión por pares

| Persona o equipo observador | Evidencia revisada | Observación útil / pregunta | Respuesta técnica y decisión | Cambio aceptado o descartado |
|---|---|---|---|---|
| @Jamón | Ensamble de cuña y disposición de cableado | Los cables largos entre el driver y los motores pueden atascarse con las ruedas o hacer falso contacto en giros bruscos. | Se decidió recortar, soldar y termoensamblar los cables de alimentación de los motores N20 directamente a las borneras de la xMotion V3. | Aceptado e implementado en el ensamble de hoy. |

**Acuerdo de colaboración:** Se dividieron las tareas en la mesa de trabajo: soldadura y peinado del cableado por parte de ambos integrantes; asignación de pines y firmware de la xMotion V3 por @mimiprogramando; montaje mecánico de navaja, ruedas JSUMO y chasis por @ROM423.

## 3 Segundo ciclo Kaizen (K2)

| Campo experimental | Completar |
|---|---|
| Limitación detectada en K1 | Los conectores sueltos en protoboard generaban caídas temporales de voltaje y riesgo de desconexión bajo carga máxima. |
| Hipótesis K2 y fundamento | **Si** integramos formalmente la placa **JSUMO xMotion V3**, soldamos terminales directas a los motores y recortamos cableado, **entonces** la respuesta de aceleración se reducirá a ~1.0 s **porque** eliminamos caídas de voltaje y resistencia por falso contacto. |
| Variable modificada | Integración de tarjeta JSUMO xMotion V3, soldadura directa de motores, peinado de arnés y montaje final de navaja metálica Mini Katana. |
| Requisitos de seguridad | Desconectar batería LiPo antes de manipular cautín; colocar cubierta protectora de goma en la navaja al realizar ajustes. |
| Personas responsables | @ROM423 (Ensamble mecánico, soldadura y navaja) / @mimiprogramando (Mapeo de pines xMotion V3 y firmware adaptado). |
| Cambio exacto de código/CAD | Asignación de pines PWM/Dirección en el firmware [Segundo Código Rayden] (https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino) y ajuste de soporte CAD. |
| Enlace a commit | [Segundo Código Rayden] (https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino) |
| Métrica primaria y éxito | Tiempo de arranque/embestida (s) y cero caídas de sistema en 5 ensayos consecutivos. |

## 4 Comparación de evolución (V1 vs K1 vs K2)

**Registros fuente:** [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv)

### Tabla de ensayos equivalentes observados

| Ensayo / Condición | V1 (s) | K1 (s) | K2 (s) | Incidencias u observaciones relevantes en K2 |
|---|---|---|---|---|
| 1. Rival al frente a 20 cm | 1.2 s | 1.1 s | 0.9 s | Respuesta de arranque inmediata tras integrar xMotion V3 |
| 2. Rival al frente a 20 cm | 1.4 s | 1.2 s | 1.0 s | Giro ágil sin vibración ni ruido en conectores de motor |
| 3. Rival a 45° derecha | 2.5 s (F) | 1.4 s | 1.2 s | Excelente respuesta angular con sensores IR fijos |
| 4. Rival a 45° izquierda | 2.2 s (F) | -- | **0.0 s (F)** | **Incidencia:** Falso contacto en bornera de motor izquierdo tras impacto inicial |
| 5. Rival a 45° izquierda | -- | -- | **1.1 s (É)** | Prueba repetida con éxito tras reajustar y resoldar el terminal del motor |
| 6. Rival en borde opuesto | 1.8 s | 1.5 s | 1.1 s | Detención precisa en línea blanca e impacto firme con navaja |

**Síntesis cuantitativa (para $n=5$ ensayos exitosos comparables):**
* **Tiempo medio de reacción/embestida:** **$1.82\text{ s}$ en V1** $\rightarrow$ **$1.30\text{ s}$ en K1** $\rightarrow$ **$1.06\text{ s}$ en K2**.
* **Tasa de éxito de la rutina K2:** **$100\%$** (5/5 en corridas post-soldadura de bornera).

**¿Qué mejora, qué empeora y qué no podemos concluir?**
* **Mejora:** La aceleración inicial y la rigidez estructural mejoraron drásticamente al usar la xMotion V3 y eliminar cables sueltos; la navaja metálica proporciona mejor palanca de empuje.
* **Empeora:** El centro de masa se desplazó levemente hacia el frente por el peso de la navaja Katana, exigiendo asegurar máxima tracción en las ruedas traseras.
* **No podemos concluir:** La autonomía total de la batería bajo torneos continuos de más de 3 minutos ininterrumpidos.

## 5 Ensayo de robustez o variación de condiciones

| Cambio controlado de entorno | Riesgo y límite seguro | Predicción | Resultado observativo / unidad / éxitos | ¿Se mantiene el objetivo? | Evidencia |
|---|---|---|---|---|---|
| Batería baja a ~11.1V (LiPo al 30%) y polvo ligero en ruedas de silicona. | Pérdida de tracción o reinicio de la placa por caída de voltaje. | El robot tardará un poco más en empujar pero mantendrá la lógica FSM y evasión de borde. | **Ensayo 7 (CSV):** Perdió tracción ($1.8\text{ s}$, Fallo). <br>**Ensayos 8-10 (CSV):** Tras limpiar ruedas con alcohol isopropílico, promedió $1.23\text{ s}$ (4/5 éxitos totales). | Sí, la xMotion V3 mantuvo estable la lógica sin reiniciarse. | [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |

**Límites de inferencia:** Se demostró que la tarjeta xMotion V3 tolera fluctuaciones de voltaje sin reiniciarse. Sin embargo, el polvo reduce drásticamente el agarre de las ruedas de silicona JSUMO, haciendo obligatorio el mantenimiento con alcohol isopropílico entre combates.

## 6 Ensayo general de demostración (Preparación Día 5)

| Segmento | Qué se demostrará (20-60 s) | Integrante responsable | Versión / Código usado | Material requerido | Plan B ante fallo |
|---|---|---|---|---|---|
| Inicio / contexto | Explicación del chasis 3D, integración de la xMotion V3 y soportes corregidos. | @ROM423 | K2 | Robot Rayden en mano, protector de navaja. | Usar ficha técnica impresa si falla la proyección. |
| Prueba principal | Salida autónoma en dohyō, giro de búsqueda, detección de oponente y embestida. | @mimiprogramando | [Segundo Código Rayden] (https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino) | Dohyō oficial, oponente de prueba. | Reinicio rápido con el módulo MicroStart. |
| Evidencia de mejora | Mostrar comparativa cuantitativa (V1 vs K1 vs K2) y freno en línea blanca por QTR. | Ambos | Gráfica de datos / [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) | Bitácora y registros CSV. | Mostrar archivo de datos local en laptop. |
| Defensa de fronteras | Explicación de eliminación de ángulos ciegos a 45° y control de potencia FSM. | @mimiprogramando | Código en Arduino IDE | Repositorio GitHub abierto. | Explicar diagrama de estados en pizarrón. |

## 7 Gate E4

- [x] Existe un ciclo K2 explícito, con hipótesis, modificación física y datos registrados en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv).
- [x] Se conservan V1, K1 y K2 en el repositorio para plena reproducibilidad.
- [x] Se efectuó la prueba de robustez documentada (batería a 11.1V y superficie con polvo).
- [x] El equipo cuenta con guion, responsabilidades y plan de contingencia listo para el Día 5.
- [x] Cada participante actualizó su registro individual en `participantes/<alias>/dias/E4.md`.

**Estado de preparación:**     
**Pendientes y responsables:** Cargar batería LiPo al 100% y limpiar ruedas de silicona antes del evento (@ROM423 y @mimiprogramando).  
**Revisor:** Camilo Duque  
**Fecha:** 2026-10-29
