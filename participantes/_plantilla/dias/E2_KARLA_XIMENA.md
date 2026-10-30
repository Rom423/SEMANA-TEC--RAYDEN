---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E2"
dia: 2
responsable_registro: "mimiprogramando"
estado: "Completado"
fecha: "2026-10-27"
revision_docente: 
---

# E2 · Día 2 — MI V1 | Qué integré y cómo lo comprobé

**Alias:** @mimiprogramando · **Alcance(s):** MS07, MS10, MS11 · **Kata(s) trabajados:** K1, K2 · **Equipo/dojo:** RAYDEN / Campus León / CTA / Laboratorio de electrónica.

| Registro personal | Mi respuesta |
|---|---|
| Microlección o concepto que utilicé realmente | Lógica de FSM (Máquina de Estados Finitos) para las rutinas de Búsqueda, Ataque y Evasión de Borde, combinada con temporizadores no bloqueantes mediante `millis()`. |
| Qué desarrollé yo (función, pieza, esquema, dato o algoritmo) | Programación de la biblioteca de movimientos y la estructura principal de la FSM sobre la plataforma temporal Arduino Nano, gestionando las señales de los sensores IR y QTR. |
| A qué componente del equipo se conectó | Al chasis impreso en 3D, la cuña base y la calibración analógica de sensores realizada por @ROM423. |
| Código/CAD/componente y ruta relativa | `codigo/PrimerCodigo_Rayden.ino` |
| Commit/PR o evidencia de mi autoría | Estructuración y carga del código base de control de motores y lectura de sensores en la rama principal del repositorio del equipo. |
| Condición de ensayo o prueba que ejecuté | 5 corridas de prueba en el dohyō oficial evaluando tiempos de reacción y embestida ante un rival estático a 20 cm y en ángulos diagonales ($45^\circ$), usando batería LiPo 3S 11.4V. |
| Resultado observable, métrica y unidad | Tiempo medio de reacción/embestida: **1.82 s**. Tasa de éxito real V1: **60% (3/5 corridas)**. |
| ¿Qué parte funcionó / cuál no? | **Funcionó:** Transición fluida entre estados de búsqueda y ataque, así como la respuesta de frenado al detectar la línea blanca de borde. **No funcionó:** Hubo retrasos y pérdidas de detección en los ensayos 3 y 5 debido al ángulo ciego a $45^\circ$ de los sensores físicos. |
| Qué ayuda recibí, sin perder responsabilidad propia | Recepción de señales físicas y ajustes de umbrales analógicos por parte de @ROM423 para alimentar correctamente las entradas de la FSM. |
| Qué dependencia o material quedó pendiente | Sincronización del código con el rediseño mecánico de soportes IR en SolidWorks y la futura migración hacia la placa JSUMO xMotion V3 en el ciclo K1/K2. |

**V1 verificable de mi alcance:** [codigo/PrimerCodigo_Rayden.ino](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/codigo/PrimerCodigo_Rayden.ino). **Qué parte del kit ya está cumplida:** Primitivas de movimiento autónomo en FSM (MS07) y calibración básica del firmware de control (MS11). **Qué necesito medir/mejorar en D3:** Ajustar ligeramente los umbrales de disparo de lectura analógica/digital de los sensores IR para acoplar el código al nuevo ángulo de visión física que rediseñará el equipo (MS10).

**Registro colectivo:** [DIA 2](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/docs/entregables/dia-02.md)
