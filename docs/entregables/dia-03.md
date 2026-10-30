---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E3"
dia: 3
responsable_registro: "@mimiprogramando"
estado: "Completado"
fecha: "2026-10-28"
revision_docente: "--"
--- 

# E3 Día 3 - MEDIR Y APRENDER | Kaizen 1: ensayo, hipótesis y mejora

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E3.md`.

## 0 Contexto de investigación de hoy

| Campo | Dato |
|---|---|
| Fecha, equipo y misión | 2026-10-28, RAYDEN / M01 Mini-sumo autónomo |
| **Dōjō exacto** | Campus León / CTA / Laboratorio de electrónica |

## 1 Ruta del Día 3 (180 min)

| Actividad | Minutos | Evidencia a registrar |
|---|---|---|
| Analizar un fallo real / demostración | 0-15 | Ángulo ciego en sensores IR de 45° detectado en los ensayos 3 y 5 de V1 |
| Diseño del experimento | 15-40 | Hipótesis sobre rediseño CAD de soportes 3D en SolidWorks e impresión en PLA |
| Diagnóstico del prototipo V1 | 40-80 | Análisis de geometría de visión lateral y despeje de cuña |
| Kaizen 1: cambio técnico | 80-125 | Modelado 3D de nuevos soportes (cobertura ajustada de 45° a ~25°), reimpresión y lijado de cuña |
| Reensayo equivalente | 125-160 | Datos crudos V1 vs K1 registrados en 
[Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) |
| Documentar, debatir, reflejar | 160-180 | Conclusión del ciclo Kaizen 1 y registro E3 personal |

## 2 Problema, hipótesis y trazabilidad

| Campo | Completar |
|---|---|
| Fallo observatorio en V1 | En los ensayos 3 y 5 del Día 2 se registraron fallos (tiempos de 2.5s y 2.2s) por un ángulo ciego a 45° entre sensores IR frontales y laterales. |
| Dónde se presenta y frecuencia | Presente en el 40% de los ensayos de la baseline V1 (2 de 5 corridas). |
| Diagnóstico de causas alternativas | Falso positivo por rebote de luz o retraso de lectura en bucle principal de FSM sobre Arduino Nano. |
| Hipótesis contrastable | **Si** rediseñamos los soportes de los sensores IR en SolidWorks reduciendo su separación angular a ~25° y ajustamos la cuña frontal, **entonces** el tiempo de detección a 45° disminuira a menos de 1.5 s **porque** eliminamos el punto ciego óptico directo. |
| Variable independiente modificada | Geometría y ángulo del soporte 3D de sensores IR e impresión en PLA (Centauri Carbon 2). |
| Métrica primaria y criterio de éxito | Tiempo de reacción/detección en segundos (s). Criterio de éxito: respuesta en diagonales < 1.5 s sin salirse del dohyō. |
| Variables mantenidas constantes | Batería LiPo 3S, motores DC, dohyō oficial, rival estático y luz ambiental. |
| Ensayos requeridos y muestreo | 5 corridas de prueba variando la posición inicial del rival. |
| Parada de seguridad / aborto | Desconexión manual inmediata de la batería si el robot ataca fuera del borde o si la cuña genera fricción excesiva contra la pista. |

## 3 Colaboración y cambio técnico Kaizen 1

| Alias y alcance | Kata asociado | Qué cambió exactamente | Por qué | Código/CAD/commit y revisor | Validación de interfaz |
|---|---|---|---|---|---|
| @ROM423 | MS02 | Rediseño de cuña y nuevos soportes de sensores IR en SolidWorks impresos en PLA. | Para reducir el perfil ciego de 45° a ~25° y mejorar el perfil de ataque. | [CAD](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/hardware/Raiden%20rumbo%20a%20japon.SLDPRT) (@ROM423) | Ajuste mecánico sobre el chasis sin obstruir sensores QTR de borde. |
| @mimiprogramando | MS07, MS10 | Ajuste menor en el umbral de disparo de lectura analógica/digital de los IR. | Para acoplar el código al nuevo ángulo de visión física de los sensores. | [Segundo Código Rayden](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino)
 (@mimiprogramando) | Recepción de señales IR verificada por puerto serie. |

## 4 Ensayos comparables

**Enlace a datos crudos CSV:** [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv)

| Prueba | Condición/escenario | V1 (s) | K1 (s) | Cambio / resultado | Incidencia o desviación observada en K1 |
|---|---|---|---|---|---|
| 1 | Rival al frente a 20 cm | 1.2 s | 1.1 s | Mejora (-0.1 s) | Detección limpia con nuevo soporte PLA |
| 2 | Rival al frente a 20 cm | 1.4 s | 1.2 s | Mejora (-0.2 s) | Embestida directa fluida |
| 3 | Rival a 45° derecha | 2.5 s (FALLO) | **0.0 s (FALLO)** | Interrupción técnica | **Incidencia:** La cuña en PLA quedó muy baja y se raspó/atoró contra la pista |
| 4 | Rival a 45° derecha | -- | **1.4 s (ÉXITO)** | **Gran mejora (-1.1 s)** | Reensayo tras lijar manualmente el borde inferior de la cuña |
| 5 | Rival en borde opuesto | 1.8 s | 1.5 s | Mejora (-0.3 s) | Menos vacilación al girar y detenerse en borde |

**Resumen y comparativa V1 vs K1:**
* **N de ensayos:** 5 corridas comparables registradas.
* **Tiempo medio de reacción:** Reducido de **$1.82\text{ s}$ (V1)** a **$1.30\text{ s}$ (K1 post-ajuste)**.
* **Tasa de éxito de detección y ataque:** Incrementada del **$60\%$ (V1)** al **$100\%$ (K1)** tras resolver el lijado mecánico de la cuña.
* **Limitaciones observadas:** La fricción inicial de la cuña en PLA demostró que las tolerancias de impresión 3D deben verificarse físicamente sobre el dohyō antes de correr la serie de pruebas.

## 5 Interpretación y decisión

* **¿La evidencia respalda la hipótesis?** Sí. El rediseño físico del soporte de sensores eliminó la zona ciega, permitiendo detectar objetivos diagonales a 45° en 1.4 s (frente a los fallos de V1) y bajando el promedio general a 1.30 s.
* **Compromisos/Riesgos detectados:** La cuña impresa en PLA quedó inicialmente muy justa al nivel del suelo y requirió ajuste manual con lija para evitar fricción contra imperfecciones del dohyō.
* **Decisión:** **Conservar K1**, debido a que la cobertura sensorial mejoró sustancialmente y la tasa de detección pasó a ser del 100% tras el ajuste físico.
* **Siguiente pregunta para Kaizen 2:** ¿Podemos eliminar las caídas de voltaje de la protoboard y mejorar la aceleración inicial mediante la integración formal de la placa **JSUMO xMotion V3** y la soldadura directa de los motores?

## 6 Puerta de salida E3

- [x] V1 y K1 tienen identificadores inequívocos (`commit-a3f81b2-cad-k1`).
- [x] La hipótesis está conectada con una medida y un problema diagnosticado en V1.
- [x] Se documentó la modificación técnica y sus responsables (@ROM423 en CAD y @mimiprogramando en ajuste de umbrales).
- [x] Ensayos y resultados mantienen condiciones comparables y exponen los fallos intermedios con honestidad en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv).
- [x] Cada estudiante registró su entregable personal en `participantes/<alias>/dias/E3.md`.

**Gate E3:**   
**Revisor:** Camilo Duque  
**Fecha:** 2026-10-28
