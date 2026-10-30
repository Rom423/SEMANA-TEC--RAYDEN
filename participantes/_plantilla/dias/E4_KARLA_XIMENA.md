---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E4"
dia: 4
responsable_registro: "mimiprogramando"
estado: "Completado"
fecha: "2026-10-29"
revision_docente: 
---

# E4 · Día 4 — MI KAIZEN 2 | Refiné, comparé y defendí

**Alias:** @mimiprogramando · **Alcance:** MS07, MS10, MS11 · **Versiones:** V1 (Arduino Nano en protoboard / 45° ciega)[cite: 3, 5]; K1 (Soportes IR a ~25° + cuña lijada); K2 (JSUMO xMotion V3 + firmware optimizado PWM + soldadura limpia).

| Registro de Kaizen 2 | Respuesta |
|---|---|
| Retroalimentación de compañero / revisión externa | Observación de @Jamón: Los cables largos entre el driver y los motores podían atascarse con las ruedas o hacer falso contacto en giros bruscos. |
| Decisión que tomé a partir de esa observación | Aceptada e implementada: Reorganizar la asignación de pines y puertos en el firmware para acoplarlos al peinado de cables, recortado y soldadura directa de los motores a las borneras de la placa xMotion V3. |
| Nueva hipótesis y cambio que propuse | Si adaptamos el firmware para la placa integrada JSUMO xMotion V3 y redefinimos los pines PWM/dirección para controlar directamente los motores DC sin protoboard, la respuesta de aceleración bajará a ~1.0 s al eliminar caídas de voltaje por resistencia de contacto.. |
| Modificación personal comprobable y commit/archivo | Mapeo de pines PWM y dirección en el firmware, adaptación del control FSM para xMotion V3 y ajuste de tiempos de respuesta no bloqueantes. Commit: [Segundo Código Rayden / Hardware xMotion](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino). |
| Método y condiciones comparables entre versiones | $n=5$ ensayos equivalentes en dohyō oficial con rival estático a 20 cm y en diagonales a $45^\circ$, midiendo el tiempo de reacción/embestida en segundos (s). |
| Métrica/unidad, valores V1, K1, K2 y n | **Métrica:** Tiempo de embestida (s). **V1:** 1.82 s $\rightarrow$ **K1:** 1.30 s $\rightarrow$ **K2:** 1.06 s (100% éxito en corridas post-soldadura de bornera).|
| ¿Qué mejoró, qué empeoró y qué no sabemos? | **Mejoró:** Respuesta inmediata de los motores y estabilidad en la aceleración por la gestión limpia de potencia de la xMotion V3. **Empeoró:** Sensibilidad en la tracción si el piso acumula polvo debido a la mayor fuerza de arranque. **No sabemos:** La autonomía total del sistema en competencias prolongadas de más de 3 min. |
| Prueba de robustez y límites seguros | Batería LiPo a medio consumo (~11.1V / 30%) y dohyō con polvo ligero. Límite seguro: desconexión de batería antes de manipular soldaduras o componentes. |
| Resultado de robustez y condiciones | La xMotion V3 mantuvo estable la lógica FSM sin reiniciarse por caídas de voltaje; tras limpiar ruedas con alcohol se promediaron 1.23 s (4/5 éxitos). |
| Qué demostraré en D5 como logro propio | La FSM no bloqueante programada con `millis()`, la calibración precisa de sensores de borde QTR para frenado preventivo y el control PWM optimizado para la placa xMotion V3. |
| Qué debo corregir antes de la presentación | Mantener la batería LiPo cargada al 100% y asegurar la limpieza con alcohol isopropílico de las ruedas de silicona antes de la demostración. |

**Artefacto o función para demo:** Firmware [Segundo Código Rayden](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino) cargado en la placa JSUMO xMotion V3 ejecutando la FSM de búsqueda, ataque y evasión de borde en tiempo real[cite: 3, 9, 11]. **Evidencias:** código fuente [Segundo Código Rayden](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino) y registros crudos en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv)

**Registro colectivo:** [DIA 4](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/docs/entregables/dia-04.md)
