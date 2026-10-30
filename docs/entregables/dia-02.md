kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E2"
dia: 2
responsable_registro: "Ximena Neri"
estado: "Completado"
fecha: "2026-10-27"
revision_docente: "APROBADO"

# E2 Día 2 - HACER | Primera integración funcional y línea base V1

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E2.md`.

## 0 Identificación y continuidad

| Campo | Dato |
|---|---|
| Fecha, equipo, misión y plataforma | 2026-10-27, RAYDEN / M01 Mini-sumo autónomo |
| Dōjō real y mesa/zona utilizada | Campus León / CTA / Laboratorio de electrónica |
| Estado del gate E1 / cambios desde D1 | APROBADO; sin cambios en los compromisos iniciales |
| Kit por integrante / compromisos modificados | Integración funcional V1 mediante plataforma Arduino Nano temporal; componentes JSUMO validados |
| Materiales recibidos y pendientes | Recepción completa de componentes JSUMO; ninguno pendiente |
| Objetivo técnico del Día 2 | Lograr integración V1 funcional, calibrar sensores IR/QTR y medir línea base de ataque/evasión |

## 1 Ruta de las actividades de hoy (180 min)

| Bloque | Minutos | Registro requerido / evidencia |
|---|---|---|
| Revisión de misión y compromisos | 0-15 | Acuerdos listos; asignación de pruebas A/B |
| Microlección aplicada | 15-35 | Lógica de FSM (Búsqueda, Ataque, Evasión de Borde) y diagramas |
| Katas de integración | 35-105 | @mimiprogramando: Primitivas de movimiento (MS07); @ROM423: Calibración IR/QTR y cuña (MS02, MS05, MS06) |
| Ensayos iniciales / línea base | 105-145 | Pruebas de tracción y 5 ensayos en dohyō oficial |
| Consolidación de evidencia | 145-170 | Registro de datos crudos en [datos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/277f1ba101c710beecec6df6cc05f8c7eab22321/datos/ensayos.csv) |
| Gate E2 | 170-180 | Documentación de fallos para ciclo Kaizen 1; E2 Aprobado |

## 2 Microlección e integración por alcances

**Tema que resolvió un problema real del equipo:** Implementación de temporizadores no bloqueantes con `millis()` para la transición fluida entre giros de búsqueda y aceleración de ataque en la FSM.

| Alias | Alcance | Kata seleccionado | Acción técnica ejecutada | Archivo, commit o plano | Estado | Dependencia |
|---|---|---|---|---|---|---|
| @ROM423 | MS02, MS05, MS06 | K1, K2 | Calibración de umbrales analógicos IR/QTR y montaje de cuña base | [codigo/PrimerCodigo_Rayden.ino](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/e149206f0970ecd95b8f658a21806b809238644a/codigo/PrimerCodigo_Rayden.ino) | Probado | Integración de firmware por @mimiprogramando |
| @mimiprogramando | MS07, MS10, MS11 | K1, K2 | Programación de biblioteca de movimientos y lógica FSM en Arduino Nano |  [codigo/PrimerCodigo_Rayden.ino](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/e149206f0970ecd95b8f658a21806b809238644a/codigo/PrimerCodigo_Rayden.ino) | Probado | Lectura de sensores de @ROM423 |

## 3 Estado de integración V1

| Subsistema | Entrada | Salida esperada | Responsable | Prueba de integración y observación | Evidencia |
|---|---|---|---|---|---|
- | Estructura/mecánica | Chasis impreso 3D | Ensamble rígido y ajuste de cuña | @ROM423 | Montaje completo y prueba de empuje manual limpia | [cad/chasis_v1.sldprt](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/72a3c4c8354637cf3a6339036df4e79acfc28471/hardware/Raiden%20rumbo%20a%20japon.SLDPRT) |
| Energía y accionamiento | Batería LiPo 3S 11.4V | Alimentación regulada a lógica y motores DC | @mimiprogramando | Medición con multímetro; voltaje estable sin caídas de tensión | `[docs/inventario.md]` |
| Sensores/percepción | Sensores JS40F y QTR-1RC | Lecturas digitales/analógicas estables | @ROM423 | Detección de contraste de línea blanca y distancia de rival comprobada | `[codigo/test_sensores.ino]` |
| Control/software | FSM sobre Arduino Nano | Comandos PWM a motores DC | @mimiprogramando | Cambio de estado correcto de BÚSQUEDA a ATAQUE | `[codigo/PrimerCodigo_Rayden.ino]` |
| Integración global | Señal sensorial completa | Movimiento autónomo en dohyō | Ambos | Ejecución de rutinas de ataque y freno en borde | `[pruebas/protocolo.md]` |

**Versión identificable:** `commit-v1- baseline-arduinonano`  
**Comportamiento que SÍ demuestra V1:** El robot detecta la línea de borde y cambia de dirección; ejecuta ataques frontales efectivos a corta distancia.  
**Lo que aún falla:** Presencia de un ángulo ciego a 45° que genera retraso o pérdida de detección del oponente, provocando salirse del dohyō o giros muy lentos.

## 4 Protocolo y línea base del robot (datos observados)

| Campo de validez experimental | Respuesta obligatoria |
|---|---|
| Pregunta y resultado que se quiere medir | ¿Cuál es la tasa de éxito y el tiempo de reacción del robot V1 para detectar al rival y atacarlo sin salir del dohyō? |
| Métrica primaria + unidad | Tiempo de reacción/embestida (segundos) y Tasa de éxito (%) |
| Éxito/fallo (criterio cuantitativo) | Éxito: Detecta al rival y realiza contacto directo sin cruzar la línea blanca de borde. |
| Lugar y configuración | Campus León / CTA / Lab. Electrónica, dohyō oficial de mini-sumo |
| Configuración del robot | Batería LiPo 3S, Arduino Nano + driver, 3x IR JS40F, 2x QTR-1RC |
| Condiciones controladas | Luz ambiental constante de laboratorio, rival estático de referencia |
| Número de corridas ejecutadas | 5 / 5 ejecutadas |
| Procedimiento y seguridad | Posicionar robot en centro, activar vía código, medir tiempo hasta impacto; botón de paro manual. Responsables: @ROM423 y @mimiprogramando. |

### Registros crudos observados (`datos/ensayos.csv`)

| Ensayo | Condición inicial | Valor (s) | Resultado | Observación relevante / incidencia |
|---|---|---|---|---|
| 1 | Rival al frente a 20 cm | 1.2 s | Éxito | Detección limpia y embestida directa |
| 2 | Rival al frente a 20 cm | 1.4 s | Éxito | Correcto viraje y ataque |
| 3 | Rival a 45° derecha | 2.5 s | **FALLO** | **Ángulo ciego:** el robot no vio al rival y terminó saliéndose del dohyō |
| 4 | Rival en borde opuesto | 1.8 s | Éxito | Frenó a tiempo en la línea blanca al errar la embestida |
| 5 | Rival a 45° izquierda | 2.2 s | **FALLO** | **Giro muy lento:** el rival salió de su zona antes de ser embestido |

**Línea base resumida:**
* **Corridas válidas:** 5/5
* **Tiempo medio de reacción:** $1.82\text{ s}$
* **Tasa de éxito real V1:** **$60\%$ ($3/5$)**
* **Causa principal de fallo:** Existencia de una zona ciega de cobertura óptica a $45^\circ$ por la geometría original de fijación de los sensores IR.

## 5 Decisiones al cierre, bloqueos y Kaizen de mañana

| Fallo o cuello de botella observado | Hipótesis preliminar | Prioridad | Responsable | Material / apoyo necesario |
|---|---|---|---|---|
| Cobertura ciega a 45° en sensores IR frontales/laterales | La disposición física en el chasis V1 limita la cobertura óptica | Alta | @ROM423 | Rediseñar soporte 3D en SolidWorks para ajustar ángulos |
| Respuesta de aceleración limitada | Presencia de delays residuales y cableado en protoboard | Media | @mimiprogramando | Optimización FSM y preparación para migrar a xMotion V3 en K2 |

- [x] Hay prototipo V1 y fallo reproducible con condiciones registradas en `datos/ensayos.csv`.
- [x] Existen archivos fuente enlazados en el repositorio.
- [x] Hay protocolo reproducible y valores basales cuantitativos.
- [x] Cada alumno actualizó su registro individual en `participantes/<alias>/dias/E2.md`.
- [x] Se mantuvieron los límites de seguridad en las pruebas.

**Gate E2:** APROBADO  
**Revisor:** Camilo Duque  
**Fecha:** 2026-10-27  
**Próxima prioridad de Kaizen 1:** Rediseñar en SolidWorks los soportes 3D de los sensores IR para cerrar el ángulo ciego y reimprimir la cuña frontal.
