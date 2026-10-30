---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E2"
dia: 2
responsable_registro: "Mauricio Rodríguez"
estado: "Completado"
fecha: "2026-10-27"
revision_docente:
---

# E2 · Día 2 — MI V1 | Qué integré y cómo lo comprobé

**Alias:** @ROM423 · **Alcance(s):** MS02, MS05, MS06 · **Kata(s) trabajados:** K1, K2 · **Equipo/dojo:** RAYDEN / Campus León / CTA / Laboratorio de electrónica.

| Registro personal | Mi respuesta |
|---|---|
| Microlección o concepto que utilicé realmente | Lógica de FSM (Máquina de Estados Finitos) para Búsqueda, Ataque y Evasión, e implementación de temporizadores no bloqueantes con `millis()`. |
| Qué desarrollé yo (función, pieza, esquema, dato o algoritmo) | Montaje y ajuste mecánico de la cuña base, calibración física de umbrales analógicos IR/QTR y ensamble del chasis impreso en PLA. |
| A qué componente del equipo se conectó | Al firmware del sistema ejecutado sobre la plataforma Arduino Nano temporal desarrollada por @mimiprogramando. |
| Código/CAD/componente y ruta relativa |[Primer_Código](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/codigo/PrimerCodigo_Rayden.ino) y [CAD](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/hardware/Raiden%20rumbo%20a%20japon.SLDPRT) |
| Commit/PR o evidencia de mi autoría | Integración de archivos CAD del chasis y calibración de sensores registradas en la rama principal del repositorio del equipo. |
| Condición de ensayo o prueba que ejecuté | 5 corridas de prueba en dohyō oficial con rival estático a 20 cm y en ángulos laterales ($45^\circ$), alimentado con batería LiPo 3S 11.4V. |
| Resultado observable, métrica y unidad | Tiempo medio de reacción/embestida: **1.82 s**. Tasa de éxito real V1: **60% (3/5 corridas)**. |
| ¿Qué parte funcionó / cuál no? | **Funcionó:** Detección de borde (frenado en línea blanca) y ataques directos frontales. **No funcionó:** Presencia de un ángulo ciego a $45^\circ$ que provocó fallos en los ensayos 3 y 5. |
| Qué ayuda recibí, sin perder responsabilidad propia | Colaboración de @mimiprogramando para la integración de la lectura de sensores dentro de la FSM del firmware. |
| Qué dependencia o material quedó pendiente | Rediseño de soportes en SolidWorks para corregir el ángulo de los sensores IR y preparación para la migración a la placa JSUMO xMotion V3 en K2. |

**V1 verificable de mi alcance:** [codigo/PrimerCodigo_Rayden.ino](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/codigo/PrimerCodigo_Rayden.ino). **Qué parte del kit ya está cumplida:** Detección de borde con QTR-1RC (MS05) y lectura base de sensores de oponente (MS06). **Qué necesito medir/mejorar en D3:** Rediseñar e imprimir soportes 3D para reducir la separación angular de los sensores de $45^\circ$ a $\sim25^\circ$ para eliminar la zona ciega (MS02).
