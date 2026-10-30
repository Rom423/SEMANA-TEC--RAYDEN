---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E3"
dia: 3
responsable_registro: "Mauricio Rodríguez"
estado: "Completado"
fecha: "2026-10-28"
revision_docente: 
---

# E3 · Día 3 — MI KAIZEN 1 | Aprendí a medir y mejorar

**Alias:** @ROM423 · **Alcance y kata relacionado:** MS02 (Diseñar y comparar cuñas o pala frontal) / MS06 · **V1 de partida:** commit-a3f81b2-cad-k1

| Registro de Kaizen 1 | Respuesta |
|---|---|
| Error, limitación o posibilidad de mejora que yo identifiqué | Existencia de una zona ciega de cobertura óptica a $45^\circ$ por la geometría original de fijación de los sensores IR en el chasis V1. |
| Evidencia de que el problema existe | En los ensayos 3 y 5 de la baseline V1 se registraron fallos (tiempos de 2.5 s y 2.2 s) al no detectar al rival en $45^\circ$, provocando que el robot saliera del dohyō. |
| Hipótesis: si cambio X, espero Y porque Z | Si rediseñamos los soportes de los sensores IR en SolidWorks reduciendo su separación angular a $\sim25^\circ$ y ajustamos la cuña frontal, entonces el tiempo de detección a $45^\circ$ disminuirá a menos de 1.5 s porque eliminamos el punto ciego óptico directo. |
| Qué variable decidí cambiar y cuáles mantuve iguales | **Modificada:** Geometría y ángulo del soporte 3D de sensores IR e impresión en PLA (Centauri Carbon 2). **Constantes:** Batería LiPo 3S, motores DC, dohyō oficial y rival estático. |
| Qué cambié personalmente en código, montaje o configuración | Diseñé en SolidWorks los nuevos soportes 3D para reorientar los sensores a $\sim25^\circ$, reimprimí en PLA y realicé el lijado manual del borde inferior de la cuña frontal para evitar fricción contra el dohyō. |
| Registro del cambio / versión K1 | Modelo CAD de soportes y cuña integrados en el repositorio: [CAD](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/hardware/Raiden%20rumbo%20a%20japon.SLDPRT) |
| Datos comparables: cuántos ensayos, condiciones y unidad | 5 corridas de prueba comparables en el dohyō oficial con rival estático en distintas posiciones. Métrica: tiempo de reacción/detección en segundos (s). |
| Valores V1 / K1 o enlace a datos crudos | **V1:** Promedio de 1.82 s (60% éxito). **K1 (post-ajuste de lijado):** Promedio de 1.30 s (100% éxito tras lijado). Datos crudos en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| ¿Mejoró, empeoró o no pude concluir? ¿Por qué? | **Mejoró:** La cobertura sensorial eliminó la zona ciega a $45^\circ$ (restringiendo la respuesta diagonal a 1.4 s) y elevó la tasa de éxito al 100% tras corregir la fricción de la cuña con lija. |
| Qué entendí ahora que antes no comprendía | Entendí la importancia de verificar físicamente las tolerancias mecánicas de impresión 3D sobre el dohyō real, ya que un roce mínimo de la cuña contra la pista interrumpe el desempeño del robot aunque el CAD sea correcto. |
| Apoyo recibido u ofrecido a otra persona | Colaboré con @mimiprogramando para reajustar los umbrales de lectura en el código en función de la nueva posición física de los sensores. |

**Mi nueva pregunta para Kaizen 2:** ¿Podemos eliminar las caídas de voltaje de la protoboard y mejorar la aceleración inicial mediante la integración formal de la placa JSUMO xMotion V3 y la soldadura directa de los motores?

**Enlaces:** [Código y CAD en GitHub](https://github.com/Rom423/SEMANA-TEC--RAYDEN) · Datos de ensayos: [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv)

**Registro colectivo:** [DIA 3](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/docs/entregables/dia-03.md) 
