---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E3"
dia: 3
responsable_registro: "mimiprogramando"
estado: "Completado"
fecha: "2026-10-28"
revision_docente: 
---

# E3 · Día 3 — MI KAIZEN 1 | Aprendí a medir y mejorar

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E3.md`.

**Alias:** @mimiprogramando · **Alcance y kata relacionado:** MS07 (Primitivas de movimiento) / MS10 (Estrategia de ataque) · **V1 de partida:** commit-a3f81b2-cad-k1

| Registro de Kaizen 1 | Respuesta |
|---|---|
| Error, limitación o posibilidad de mejora que yo identifiqué | Desajuste en la lectura analógica/digital de los sensores IR debido al ángulo ciego y cambio físico de posición óptica a $45^\circ$ detectado en V1. |
| Evidencia de que el problema existe | En los ensayos 3 y 5 de la baseline V1 se registraron fallos de detección (tiempos de 2.5 s y 2.2 s) al ubicar al rival en la diagonal. |
| Hipótesis: si cambio X, espero Y porque Z | Si ajustamos los umbrales de disparo en el firmware para acoplarlos al nuevo soporte físico impreso a $\sim25^\circ$, entonces el tiempo de respuesta en diagonales disminuirá de forma estable porque el código procesará de manera síncrona la nueva cobertura óptica. |
| Qué variable decidí cambiar y cuáles mantuve iguales | **Modificada:** Umbrales de lectura analógica y digital en el código para los sensores IR reubicados. **Constantes:** Lógica principal de la FSM, placa Arduino Nano temporal y dohyō oficial. |
| Qué cambié personalmente en código, montaje o configuración | Modifiqué el archivo de código base ajustando los parámetros de lectura y validación de señales IR para sincronizarlos con la nueva geometría de los soportes mecánicos diseñados por @ROM423. |
| Registro del cambio / versión K1 | Código adaptado a la nueva geometría física en el repositorio: [Segundo Código Rayden] (https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino)    |
| Datos comparables: cuántos ensayos, condiciones y unidad | 5 corridas de prueba comparables en el dohyō oficial con rival estático y dinámico. Métrica: tiempo de reacción/detección en segundos (s). |
| Valores V1 / K1 o enlace a datos crudos | **V1:** Promedio de 1.82 s (60% éxito). **K1 (post-ajuste de firmware y mecánico):** Promedio de 1.30 s (100% éxito). Datos crudos en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| ¿Mejoró, empeoró o no pude concluir? ¿Por qué? | **Mejoró:** La sincronización del firmware con el nuevo ángulo físico de los sensores eliminó los falsos positivos y redujo el tiempo medio de reacción a 1.30 s, alcanzando el 100% de efectividad tras el ajuste de la cuña. |
| Qué entendí ahora que antes no comprendía | Comprendí que un cambio mecánico en la disposición de los sensores exige obligatoriamente una recalibración fina de los umbrales en el software para que la FSM tome decisiones ágiles y sin retrasos de lectura. |
| Apoyo recibido u ofrecido a otra persona | Recibí los soportes físicos rediseñados y la cuña ajustada por @ROM423, colaborando en su validación directa mediante la lectura en el monitor serie de Arduino. |

**Mi nueva pregunta para Kaizen 2:** ¿Podemos eliminar las caídas de voltaje de la protoboard y mejorar la aceleración inicial mediante la integración formal de la placa JSUMO xMotion V3 y la soldadura directa de los motores? 

**Enlaces:** [Código y CAD en GitHub](https://github.com/Rom423/SEMANA-TEC--RAYDEN) · Datos de ensayos: [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv)

**Registro colectivo:** [DIA 3](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/docs/entregables/dia-03.md)
