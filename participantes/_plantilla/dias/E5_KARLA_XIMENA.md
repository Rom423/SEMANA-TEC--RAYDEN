---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E5"
dia: 5
responsable_registro: "mimiprogramando"
estado: "Completado"
fecha: "2026-10-30"
revision_docente: "APROBADO"
---

# E5 · Día 5 — MI CONQUISTA | Demostración y reflexión

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E5.md`.

**Alias:** @mimiprogramando · **Territorio/carta/frontera:** Territorio D DOMINAR / Frontera F2 DECIDIR / Cartas D1 AUTONOMOUS SYSTEM, D2 ROBUST ROBOT[cite: 1, 14] · **Alcances y katas completados:** MS07 (Primitivas de movimiento), MS10 (Estrategia de ataque), MS11 (Calibración de firmware); Katas K1, K2 y K3[cite: 4, 13, 14].

| Mi defensa personal | Respuesta |
|---|---|
| Antes de la semana NO podía… | Comprender a fondo la programación de un mini-sumo autónomo ni coordinar la lectura de sensores con la gestión de motores para estrategias de ataque efectivas sin bloqueos en el código[cite: 14]. |
| Ahora SÍ puedo… (con evidencia) | Estructurar máquinas de estado finitas (FSM) no bloqueantes mediante `millis()`, calibrar sensores de contraste y programar ataques autónomos estables adaptados a hardware avanzado como la xMotion V3[cite: 4, 11, 14]. |
| Qué hice realmente en el proyecto y dónde está mi aporte | Desarrollé la arquitectura del firmware en Arduino, programé la lógica de la FSM para búsqueda y evasión de borde, calibré la lectura analógica de los sensores IR/QTR y adapté el control PWM para la placa xMotion V3[cite: 4, 11, 14]. |
| Acción concreta que mostré en vivo / grabación | Demostré ante la clase y el profesor la ejecución de la FSM no bloqueante, el frenado preventivo en la línea blanca del dohyō y el diagrama de estados en el pizarrón[cite: 11, 14]. |
| Resultado observable o métrica con unidad | **5/5 corridas exitosas (100% de efectividad)** en la demostración oficial con un tiempo medio de reacción/embestida de **0.994 s**[cite: 13]. |
| Comparación entre V1 y última versión atribuible a mi trabajo | **V1:** 1.82 s (60% éxito en protoboard con retrasos)[cite: 5] $\rightarrow$ **K1:** 1.30 s (umbrales ajustados al nuevo ángulo físico)[cite: 7, 8] $\rightarrow$ **K2 / Final:** **0.994 s** (100% éxito con xMotion V3 y firmware optimizado)[cite: 13]. |
| Mi kata más significativo y por qué | K1 de MS07 (pruebas unitarias de movimiento y FSM): permitió pasar de tiempos de 1.82s a menos de 1 segundo al depurar la lógica de transición entre estados[cite: 4, 13, 14]. |
| Una decisión autónoma que tomé | Modificar los temporizadores de la FSM utilizando `millis()` en lugar de retardos bloqueantes, asegurando que el robot detectara el borde del dohyō de manera instantánea incluso en plena aceleración de ataque[cite: 4, 11]. |
| Una falla y cómo reaccioné o qué aprendí | En los primeros ensayos con la xMotion V3 hubo falsos contactos en una bornera por impacto; reaccioné soldando de forma directa y aprendí que la robustez eléctrica es tan crítica como la lógica del código[cite: 10, 11]. |
| Apoyo que di o recibí de mis compañeros | Trabajé en equipo con @ROM423 integrando su diseño CAD de soportes con los umbrales del software; recibí feedback de @Jamón para optimizar el peinado de cables hacia el driver[cite: 8, 14]. |
| Un conocimiento que puedo transferir a otra situación | El diseño de máquinas de estado finitas modulares y la gestión de eventos concurrentes sin bloqueo de procesador para sistemas embebidos en tiempo real[cite: 4, 14]. |
| Qué mejoraría si tuviera un día más | Implementar trayectorias de ataque en curva (*curved dash*) utilizando el control PWM diferencial de los motores en la placa xMotion V3[cite: 15]. |
| Comentario recibido de par o profesor | **Profesor (Camilo Duque):** Destacó que el código está altamente estructurado y presenta excelentes tiempos de respuesta[cite: 14]. **Par (@Jamón):** Resaltó la velocidad de reacción tras la migración a la placa xMotion V3[cite: 14]. |

**Enlaces a 2–3 evidencias contundentes:**
1. [Repositorio público de GitHub - RAYDEN](https://github.com/Rom423/SEMANA-TEC--RAYDEN)[cite: 14]
2. [Código Final Rayden y asignación de hardware xMotion](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino)[cite: 9, 13]
3. Registros de pruebas y datos crudos en `datos/ensayos.csv`[cite: 10, 13]

**Autovaloración por aprendizaje:** Conquisté frontera: logré dominar la programación de una FSM robusta en entornos de alta exigencia temporal y hardware integrado sin fallos en la demostración final[cite: 13, 14].

**Mi frase de cierre:** “Antes no podía estructurar un sistema autónomo competitivo sin bloqueos ni errores de lectura. Ahora puedo diseñar máquinas de estado finitas eficientes y calibrar firmware de control en tiempo real, y lo demuestro con 100% de efectividad en el dohyō y código trazable en GitHub”[cite: 13, 14].

**Registro colectivo:** [`../../../docs/entregables/dia-05.md`](../../../docs/entregables/dia-05.md)
```[cite: 13, 14, 15]
