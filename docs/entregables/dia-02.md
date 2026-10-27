---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E2"
dia: 2
responsable_registro: "Ximena Neri"
estado: "PENDIENTE"
fecha: "2026-10-27"
revision_docente: "PENDIENTE"
---

# E2 · Día 2 — HACER | Primera integración funcional y línea base V1

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E2.md`.

## 0 · Identificación y continuidad

| Campo | Dato |
|---|---|
| Fecha, equipo, misión y plataforma | 2026-10-27, RAYDEN / Detectar, atacar, expulsar al oponente. Github|
| Dōjō real y mesa/zona utilizada | Laboratorio de electrónica, CTA |
| Estado del gate E1 / cambios desde D1 |Revisión de componente |
| Kit por integrante / compromisos modificados | Componentes completos del mini-sumo, se debe conectar la electrónica |
| Materiales recibidos y pendientes | Materiales de JSUMO recibidos, ninguno queda pendiente. |
| Objetivo técnico del Día 2 | Analizar estrategias de ataque de mini-sumo y control de componentes completos. |

## 1 · Ruta de las actividades de hoy (180 min)

| Bloque | Minutos | Registro requerido / evidencia |
|---|---:|---|
| Revisión de misión y compromisos | 0–15 | Acuerdos listos; sin bloqueos. |
| Microlección aplicada | 15–35 | Lógica de ataque; diagramas. |
| Katas de integración | 35–105 | Ximena Neri - 
 K1 Programar una función segura de velocidad y parada. |
| Ensayos iniciales / línea base | 105–145 | Pruebas de motores; 100% OK. |
| Consolidación de evidencia | 145–170 | [commits, CAD, logs y versión V1] |
| Gate E2 | 170–180 |E2 aprobado; listo Kaizen 1. |

## 2 · Microlección e integración por alcances

**Tema que resolvió un problema real del equipo:** [...]. **Material / referencia utilizada:** [...].

| Alias | Alcance | Kata seleccionado / nuevo | Acción técnica ejecutada | Archivo, commit o plano | Estado (pendiente/probado/bloqueado) | Dependencia de otro integrante |
|---|---|---|---|---|---|---|
| @ROM423 | MS02, MS05, MS06 | Kata 1 / Kata 2 | Calibración de sensores IR/QTR y prueba de cuña frontal. | [`../../codigo/...`] | Probado | Integración de firmware de @mimiprogramando|
| @mimiprogramando | MS07, MS10, MS11 | Kata 1 / Kata 2 | Programación de funciones base de movimiento y lógica de ataque. | [`../../codigo/...`] | Probado | Lecturas de sensores de @ROM423|

## 3 · Estado de integración V1

| Subsistema | Entrada | Salida esperada | Responsable | Prueba de integración y observación | Evidencia |
|---|---|---|---|---|---|
| Estructura/mecánica | Chasis impreso en 3D | Ensamble rígido y ajuste de cuña | @ROM423 | Montaje de componentes y prueba de empuje manual OK.| [...] |
| Energía y accionamiento | Batería JSUMO | Alimentación a lógica y motores | @mimiprogramando | Medición con multímetro; voltaje estable sin caídas. | [...] |
| Sensores/percepción | Sensores IR y QTR | Lectura digital/analógica limpia | @ROM423 |Detección de línea blanca y presencia de rival correcta. | [...] |
| Control/software | FSM en Arduino | Comandos PWM a motores | @mimiprogramando | Cambio de estado de BÚSQUEDA a ATAQUE verificado. | [...] |
| Integración global | Señal de sensores | Movimiento autónomo en dohyō | Ambos | Ejecución de rutina completa de ataque y evasión de borde. | [...] |

**Versión identificable:** [commit SHA/etiqueta/firmware/CAD/paquete; no usar solo “última versión”]. **Comportamiento que SÍ demuestra V1:** El robot detecta la línea de borde y cambia de dirección. **Lo que aún falla:** Tiempo de respuesta alto al cambiar de giro a ataque frontal.

## 4 · Protocolo y línea base del robot (datos observados)

Completar también [`pruebas/protocolo.md`](../../pruebas/protocolo.md) y registrar datos crudos en [`datos/ensayos.csv`](../../datos/ensayos.csv).

| Campo de validez experimental | Respuesta obligatoria |
|---|---|
| Pregunta y resultado que se quiere medir | ¿Cuál es la tasa de éxito del robot para detectar al rival y expulsarlo sin salir del dohyō? |
| Métrica primaria + unidad (segundos, %, cm, rad, etc.) | Tiempo de reacción/embestida (segundos) y tasa de detección exitosa (%). |
| Éxito/fallo (criterio cuantitativo u observable) | Éxito: Detecta al rival en < 2 s y no cruza la línea blanca de borde. |
| Lugar, configuración, pista/dohyō/estaciones/marcadores | Laboratorio de electrónica (CTA), dohyō oficial de mini-sumo. |
| Configuración del robot: batería, firmware y sensores | Batería JSUMO, IR + QTR |
| Condiciones controladas: luz, rival, posición de inicio, etc. | Luz ambiental de laboratorio, rival pasivo de referencia. |
| Número de corridas planeadas / ejecutadas | 5 / 5 ejecutadas. |
| Procedimiento reproducible, responsable y seguridad/aborto | Colocar robot en centro, encender, medir tiempo hasta contacto; botón de paro manual. Responsables: @ROM423 y @mimiprogramando. |
| Datos sin procesar y video/foto corta | [enlace a CSV y evidencias externas de acceso controlado] |

| Ensayo | Condición inicial | Valor (+ unidad) | Éxito/fallo | Observación relevante / incidencia |
|---:|---|---|---|---|
| 1 | Rival al frente a 20 cm | 1.2 s | Éxito | Detección limpia y embestida directa. |
| 2 | Rival al frente a 20 cm | 1.4 s| Éxito | Correcto viraje y ataque. |
| 3 | Rival a 45° derecha | 2.1 s | Éxito | Tardó en detectar por ángulo ciego entre sensores IR. |
| 4 | Rival en borde opuesto | 1.8 s | Éxito | Frenó a tiempo en la línea blanca al errar la embestida. |
| 5 | Rival a 45° izquierda | 1.9 s | Éxito | Giro correcto pero lento hacia el objetivo. |

**Línea base resumida (no fabricada):** Línea base resumida (no fabricada): 5 ensayos válidos; tiempo medio de reacción: 1.68 s; tasa de éxito: 80% (4/5); caso fallido debido al ángulo muerto del arreglo de sensores IR a 45°.

## 5 · Decisiones al cierre, bloqueos y Kaizen de mañana

| Fallo o cuello de botella observado | Hipótesis preliminar | Prioridad | Responsable | Material / apoyo necesario |
|---|---|---|---|---|
| La disposición física limita la cobertura a 45°. | Alta | @ROM423 | Reorientar soportes CAD de sensores. | [...] |

- [ ] Hay prototipo V1, subsistema funcional verificable o fallo reproducible con condiciones registradas.
- [ ] Existen archivos fuente o evidencia técnica enlazada, además de videos de uso controlado cuando correspondan.
- [ ] Hay protocolo reproducible y valores basales con unidad o justificación de lo que no pudo medirse.
- [ ] Cada alumno actualizó su [E2 personal](../../participantes/_plantilla/dias/E2.md) con contribución propia y límite de capacidad actual.
- [ ] Se mantuvieron límites de seguridad y protección de datos.

**Gate E2:** [APROBADO / CONDICIONADO / REPLANIFICAR]. **Revisor:** [...] **Fecha:** [...].

**Próxima prioridad de Kaizen 1:** [...]. **Enlace al commit/PR:** [...].
