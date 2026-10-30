---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E5"
dia: 5
responsable_registro: "equipo"
estado: "Completado"
fecha: "2026-10-30"
revision_docente: "PENDIENTE"
---

# E5 Día 5 — DEMOSTRAR | Desafío, defensa técnica y cierre Kaizen

## 0 Identificación del evento y sus límites

| Campo | Valor |
|---|---|
| Fecha / equipo / misión y plataforma | 2026-10-30 / RAYDEN / M01 Mini-sumo autónomo |
| Dōjō o espacio exacto, bloque horario y supervisor | Campus León / CTA / Laboratorio de electrónica, 09:10 - 12:10 hrs, Camilo Duque |
| Modalidad real | Desafío interno de demostración y evaluación técnica presencial |
| ¿Participación en Robolympics posterior? | Planeada por confirmar tras evaluación interna |
| Versión final congelada y enlace al código/CAD | Versión final **K2**, 2026-10-29, @mimiprogramando y @ROM423 |
| Objetivo demostrable y criterio de éxito | Búsqueda rápida, detección de oponente sin puntos ciegos, ataque con máxima aceleración/tracción y freno preventivo en borde blanco. |
| Acceso autorizado a espectadores/evidencias | Acceso abierto a la comunidad universitaria y supervisión docente en el CTA |

## 1 Ruta de la experiencia final (180 min)

| Actividad | Minutos | Evidencia requerida |
|---|---:|---|
| Seguridad y chequeo previo | 0–20 | Inspección de batería LiPo 3S al 100%, limpieza de ruedas con alcohol isopropílico y prueba de paro con MicroStart |
| Ensayo de demostración | 20–45 | 1 corrida de calibración sobre dohyō oficial: 100% éxito en detección y viraje |
| Desafío/competencia/exhibición interna | 45–135 | 5 corridas oficiales documentadas en video y registradas en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| Reflexión sobre frontera e intercambio | 135–165 | Intercambio técnico con equipos pares sobre la relación de velocidad de motores DC y tracción de silicona |
| Ritual de cierre y siguiente paso | 165–180 | Evaluación del ciclo Kaizen, firmas de cierre y devolución de herramentales al CTA |

## 2 Checklist de seguridad antes de operar

- [x] Infraestructura, supervisor y operación autorizados.
- [x] Batería/cables/driver/sensores y fijaciones revisados.
- [x] Paro y contingencia practicados; nadie dentro de la zona de riesgo.
- [x] Configuración y versión final identificables (`commit-c7d291e-hardware-xmotion`).
- [x] Ruta de evacuación o emergencia, accesibilidad y permisos de captura de imagen comprobados.

**Observación o NO-GO de seguridad:** Sistema completamente seguro. Protector de goma retirado de la navaja Mini Katana únicamente al colocar el robot en el dohyō.  
**Autoriza:**  Camilo Duque

## 3 Registro de demostración de la misión

**Investigación y ajuste técnico previo a la demo:** Tras investigar la arquitectura de minisumos ganadores en competencias, se refinaron las rampas de aceleración PWM en el código [Código Final Rayden](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/CodigoFinalRayden.ino) para aprovechar al máximo las RPM de los motores Core DC de JSUMO en conjunto con la tracción de las ruedas JS2622 de silicona. Esto eliminó la vacilación al embestir.

| Intento | Versión/condiciones | Métrica y unidad | Resultado/éxito-fallo | Incidente o razón de fallo | Evidencia |
|---:|---|---|---|---|---|
| 1 | K2 / Batería 100% (12.6V) / Rival al frente (20 cm) | Tiempo de reacción: **0.85 s** | **ÉXITO** | Salida limpia, detección inmediata y embestida directa sin vacilación. | [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| 2 | K2 / Batería 100% / Rival a 45° derecha | Tiempo de reacción: **1.05 s** | **ÉXITO** | Giro ágil, barrido óptico completo y ataque al objetivo. | [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv)|
| 3 | K2 / Batería 98% / Rival a 45° izquierda | Tiempo de reacción: **1.02 s** | **ÉXITO** | Detección limpia gracias a la reorientación a ~25° de los sensores IR. | [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| 4 | K2 / Batería 95% / Rival en borde opuesto | Tiempo de reacción: **1.10 s** | **ÉXITO** | Ataque a máxima velocidad; frenado instantáneo en la línea blanca al errar blanco. | [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| 5 | K2 / Batería 95% / Rival dinámico en movimiento | Tiempo de reacción: **0.95 s** | **ÉXITO** | Rastreo efectivo de trayectoria y expulsión exitosa del rival. | [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |

**Procedimiento y datos crudos:** Registrados en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv).

**Resumen de resultados:** $n=5$ corridas ejecutadas, **5 éxitos / 0 fallos (100% de efectividad)**. Tiempo medio de reacción/embestida en la demostración: **$0.994\text{ s}$**.  
**Limitación:** El agarre perfecto depende críticamente de la limpieza de las ruedas de silicona antes de cada combate para evitar acumulación de estática y polvo.

## 4 Defensa individual de fronteras (cada estudiante completa su E5 personal)

| Alias | Alcance(s) original(es) | Qué aportó realmente / enlace a evidencia | Antes no podía... | Ahora puedo... | Demostración de capacidad ante otro | Feedback de par o profesor |
|---|---|---|---|---|---|---|
| @ROM423 | MS02, MS05, MS06 | Diseñó en SolidWorks y pulió los soportes 3D para eliminar puntos ciegos e integró la cuña Mini Katana. [CAD](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/hardware/Raiden%20rumbo%20a%20japon.SLDPRT) | Diseñar mecanismos optimizados para evitar ajustes de última hora en competencias. | Diseñar, imprimir y ajustar la geometría física y de ataque de un robot conforme a reglamento. | Demostró el ajuste mecánico en dohyō reduciendo la zona ciega de 45° a 25°. | Excelente trabajo en tolerancias de impresión 3D y estabilidad del chasis. |
| @mimiprogramando | MS07, MS10, MS11 | Desarrolló la FSM en Arduino, calibró la lectura de sensores QTR/IR y adaptó el código para xMotion V3. [Código Final Rayden](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/CodigoFinalRayden.ino)| Entender la programación de un mini-sumo ni mover motores/QTR para estrategias de ataque. | Estructurar máquinas de estado finitas, calibrar sensores de contraste y programar ataques autónomos. | Explicó la FSM no bloqueante con `millis()` y demostró el frenado en borde blanco ante la clase. | Código altamente estructurado y con tiempos de respuesta excelentes. |

**Portafolios individuales:**  
* `participantes/ROM423/dias/E5.md`  
* `participantes/mimiprogramando/dias/E5.md`

## 5 Evaluación de la experiencia y cierre Design Thinking

| Pregunta para validar la experiencia | Respuesta basada en evidencia (no solo opinión) |
|---|---|
| ¿Qué elecciones del catálogo C2 tuvieron sentido? | La combinación de MS02 (Cuñas/Pala) con MS10 (Estrategia de ataque) permitió alinear el rendimiento físico con el firmware de potencia. |
| ¿Qué katas fueron útiles, redundantes o faltaron? | Los katas de prueba A/B de estrategia (K3 de MS10) y pruebas unitarias de movimiento (K1 de MS07) fueron fundamentales para pasar de 1.82s a 0.99s. |
| ¿Los materiales y el dōjō habilitaron el trabajo sin exclusiones? | Sí, el uso del dohyō oficial y las herramientas del CTA permitieron iteraciones rápidas sin cuellos de botella. |
| ¿Hubo evidencia de dos ciclos de mejora técnica? | Sí: **V1** (Baseline en protoboard/45° ciega, 1.82s) $\rightarrow$ **K1** (Soporte CAD corregido + cuña lijada, 1.30s) $\rightarrow$ **K2** (xMotion V3 + soldadura + firmware optimizado, 0.99s). |
| ¿Qué se debería rediseñar para la próxima iteración? | Implementar un sistema de limpieza activa o cubiertas antipolvo para las ruedas de silicona y agregar sensores IR de mayor alcance. |
| ¿La experiencia protegió confianza, autonomía, pertenencia y seguridad? | Totalmente. Se cumplieron todos los protocolos de seguridad de corte/soldadura y el trabajo en pareja enriqueció la resolución de problemas. |

**Feedback externo:** El equipo par (observador @Jamón) destacó la velocidad de reacción tras la migración a la placa xMotion V3 y el excelente acabado de empuje de la navaja metálica.

## 6 Cierre, transferencia y archivo

- **Estado técnico final:** **TOTALMENTE FUNCIONAL**. Oponente detectado y atacado con alta efectividad; evasión de borde 100% confiable.
- **Logros colectivos y límites reales:** Se redujo el tiempo de embestida en un **45%** desde V1 hasta K2. Límite: la tracción decae sensiblemente con polvo en la pista.
- **Qué reutilizaría una generación futura:** El firmware [Código Final Rayden](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/CodigoFinalRayden.ino) con lógica de FSM no bloqueante y el modelo CAD de soportes IR de alta cobertura [CAD](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/hardware/Raiden%20rumbo%20a%20japon.SLDPRT).
- **Qué falta antes de competencia externa (Robolympics):** Montar ruedas de silicona de mayor durómetro y agregar un segundo par de sensores de borde traseros.
- **Inventario devuelto/resguardado:** Todos los componentes JSUMO (`MAT-001` a `MAT-010`) resguardados en la caja del equipo Rayden; cautín y dohyō devueltos al CTA en manos de Camilo Duque.
- **Archivo de evidencias:** Código y archivos CAD subidos al repositorio público de GitHub: `https://github.com/Rom423/SEMANA-TEC--RAYDEN`.
- **Próximo experimento o kata que se exploraría:** Implementación de trayectorias de ataque en curva (curved dash) aprovechando el control PWM diferencial de la xMotion V3.

### Gate E5

- [x] Demostración registrada honestamente en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) con 100% de éxito en la prueba final.
- [x] V1, K1, K2 y la versión final tienen trazabilidad completa en commits y documentación.
- [x] Cada estudiante completó su entregable E5 personal y defendió exitosamente sus fronteras.
- [x] Se registraron las reflexiones de cierre de Design Thinking.
- [x] Inventario entregado y resguardado en el Laboratorio de Electrónica sin incidentes.

**Revisión final docente:**     
**Fecha:** 2026-10-30  
**Firma/alias:** Camilo Duque (`@camiloduque`)
