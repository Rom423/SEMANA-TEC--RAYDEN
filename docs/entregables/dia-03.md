---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E3"
dia: 3
responsable_registro: "@mimiprogramando"
estado: "PENDIENTE"
fecha: "2026-10-28"
revision_docente: "PENDIENTE"
---

# E3 · Día 3 — MEDIR Y APRENDER | Kaizen 1: ensayo, hipótesis y mejora

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E3.md`.

## 0 · Contexto de investigación de hoy

**Fecha/equipo/misión:** 2026-10-28 · **Dōjō exacto:** Cubículo de Ingeniería en CCI · **Versión de partida:** [commit/etiqueta V1] · **Protocolo E2:** [enlace].

## 1 · Ruta del Día 3 (180 min)

| Actividad | Minutos | Evidencia a registrar |
|---|---:|---|
| Analizar un fallo real / demostración | 0–15 | Ángulo ciego en sensores IR de 45° y geometría de cuña baja ineficiente|
| Diseño del experimento | 15–40 |Hipótesis sobre rediseño CAD en SolidWorks e impresión en PLA (Carbon Centauri 2). |
| Diagnóstico del prototipo V1 | 40–80 | Pruebas de ensamble y análisis de cobertura de detección lateral.|
| Kaizen 1: cambio técnico | 80–125 | Modelado 3D de nuevos soportes y cuña optimizada; impresión 3D en PLA. |
| Reensayo equivalente | 125–160 | Datos crudos V1 vs K1 (tiempo de reacción y tasa de éxito de detección). |
| Documentar, debatir, reflejar | 160–180 | Conclusión del ciclo Kaizen 1 y registro E3 personal. |

## 2 · Problema, hipótesis y trazabilidad

| Campo | Completar |
|---|---|
| Fallo / oportunidad de mejora observada (con evidencia) | En el ensayo 3 del Día 2 se registró un retraso (2.1 s) debido a un ángulo ciego entre los sensores IR frontales y laterales, además de una altura mejorable en la cuña frontal. |
| Dónde se presenta y cuántas veces | Se presentó en el 20% de las pruebas del Día 2 (1 de 5 corridas con oponentes posicionados a 45°). |
| Diagnóstico: causas alternativas que se consideraron | Falso positivo por rebote de luz ambiental o retraso/lectura lenta en el bucle principal de la FSM en Arduino. |
| Hipótesis contrastable: **si cambio X, espero que Y ocurra porque Z** | Si rediseñamos los soportes de los sensores IR en SolidWorks reduciendo su ángulo de separación y ajustamos la cuña frontal a una menor luz sobre el suelo, el tiempo de detección a 45° disminuirá a menos de 1.5 s porque eliminamos el punto ciego óptico y mejoramos la posición física del sensor. |
| Variable independiente que se modifica | Geometría del soporte 3D de sensores IR (ángulo ajustado) y cuña frontal reimpresa en PLA. |
| Métrica de resultado con unidad y criterio de mejora | Tiempo de reacción/detección en segundos (s). Criterio de éxito: promedio de respuesta < 1.5 s en ataques diagonales. |
| Variables que se mantendrán iguales | Batería JSUMO, motores, código de la FSM, dohyō de ensayo y luz ambiental del laboratorio. |
| Ensayos requeridos y forma de muestreo | 5 corridas de prueba en el dohyō variando la posición inicial del rival estático. |
| Riesgo de sesgo/confusión y cómo se mitigará | Desgaste de la batería en las últimas corridas. Se mitigará midiendo el voltaje antes y después de la serie de pruebas. |
| Parada de seguridad / condición de aborto | Desconexión manual inmediata de la batería si el robot ataca fuera del borde o si la cuña genera fricción excesiva contra el suelo. |

## 3 · Colaboración y cambio técnico Kaizen 1

| Alias y alcance | Kata asociado (código o propio) | Qué cambió exactamente | Por qué | Código/CAD/commit y responsable de revisión | Validación de interfaz |
|---|---|---|---|---|---|
| @ROM423 | MS02 | Rediseño completo de la cuña y soporte de sensores en SolidWorks, impresos en PLA en la Centauri Carbon 2. | Para reducir el perfil ciego de 45° a ~25° y mejorar el contacto de la cuña contra la superficie. | [`../../cad/rayden_v2_soporte.sldprt`] (@ROM423) | Ajuste mecánico directo sobre el chasis sin obstruir sensores QTR. |
| @mimiprogramando | MS07, MS10 | Ajuste menor en el umbral de disparo de lectura analógica para alinearlo a la nueva posición de los IR. | Para acoplar el código al nuevo ángulo de visión física de los sensores. | [`../../codigo/rayden_main.ino`] (@mimiprogramando) | Recepción de señales IR verificada en monitor serie. |

**Identificador de versión K1:** [...]. **Otras modificaciones involuntarias o perturbaciones:** [...].

## 4 · Ensayos comparables

**Enlace a datos crudos CSV:** [`../../datos/ensayos.csv`](../../datos/ensayos.csv) · **Protocolo:** [`../../pruebas/protocolo.md`](../../pruebas/protocolo.md).

| Prueba emparejada o bloque | Condición/escenario idéntico | V1, valor + unidad | K1, valor + unidad | Cambio / resultado | Incidencia o desviación |
|---:|---|---|---|---|---|
| 1 | Rival al frente a 20 cm | 1.2 s | 1.1 s | Ligera mejora (-0.1 s) | Detección limpia. |
| 2 | Rival al frente a 20 cm | 1.4 s | 1.2 s | Mejora (-0.2 s) | Embestida directa fluida. |
| 3 | Rival a 45° derecha | 2.1 s | 1.4 s | **Gran mejora (-0.7 s)** | El nuevo ángulo del soporte eliminó la zona ciega. |
| 4 | Rival en borde opuesto | 1.8 s | 1.5 s | Mejora (-0.3 s) | Menos vacilación al girar. |
| 5 | Rival a 45° izquierda | 1.9 s | 1.3 s | **Gran mejora (-0.6 s)** | Reacción y giro mucho más rápido. |

**N válido V1 / K1:** 5 / 5.  
**Resumen, variabilidad y tasa de éxito:** Tiempo medio de reacción reducido de **1.68 s (V1)** a **1.30 s (K1)**. Tasa de éxito de detección y ataque: **100% (5/5)**.  
**Incertidumbres/limitaciones:** El peso de las piezas impresas en PLA es ligeramente menor al estimado en el modelo CAD virtual, lo que requiere vigilar la tracción al empujar.

## 5 · Interpretación y decisión

- **¿La evidencia respalda, contradice o no permite decidir la hipótesis?** La evidencia respalda la hipótesis. El rediseño físico del soporte redujo el tiempo de reacción en diagonales de 2.1 s a 1.4 s promedio.
- **Si no hubo mejora, qué aprendimos:** N/A (se observó mejora sustancial en la detección física).
- **¿Qué riesgo o compromiso generó el cambio?** La pieza impresa en PLA quedó muy justa al borde del piso y requirió un lijado rápido para evitar que se atorara con imperfecciones del dohyō.
- **Decisión:** **Conservar K1**, con la razón de que la cobertura sensorial mejoró considerablemente y la tasa de detección pasó a ser del 100%.
- **Siguiente pregunta para Kaizen 2:** ¿Podemos optimizar los tiempos de la máquina de estados en el código para pasar de búsqueda a aceleración máxima sin depender de ningún `delay()`?

## 6 · Puerta de salida E3

- [x] V1 y K1 tienen identificadores o referencias inequívocas (`commit-a3f81b2-cad-k1`).
- [x] La hipótesis está conectada con una medida y un problema diagnosticado.
- [x] Se documentó una modificación técnica y su responsable (@ROM423 en CAD y @mimiprogramando en ajuste de umbrales).
- [x] Ensayos y resultados mantienen condiciones comparables o exponen diferencias explícitamente.
- [x] La conclusión es honesta, incluso si el resultado es negativo.
- [x] Cada estudiante registró su [E3 personal](../../participantes/alias/dias/E3.md).


**Gate E3:** [APROBADO / CONDICIONADO]. **Revisor:** [...]. **Enlace a PR/commit:** [...].
