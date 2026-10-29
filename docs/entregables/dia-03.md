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
| Dónde se presenta y cuántas veces | Se presentó en el 20% de las pruebas (1 de 5 corridas con oponentes a 45°). |
| Diagnóstico: causas alternativas que se consideraron | [...] |
| Hipótesis contrastable: **si cambio X, espero que Y ocurra porque Z** | [...] |
| Variable independiente que se modifica | [...] |
| Métrica de resultado con unidad y criterio de mejora | [...] |
| Variables que se mantendrán iguales | [...] |
| Ensayos requeridos y forma de muestreo | [5 o n justificado] |
| Riesgo de sesgo/confusión y cómo se mitigará | [...] |
| Parada de seguridad / condición de aborto | [...] |

## 3 · Colaboración y cambio técnico Kaizen 1

| Alias y alcance | Kata asociado (código o propio) | Qué cambió exactamente | Por qué | Código/CAD/commit y responsable de revisión | Validación de interfaz |
|---|---|---|---|---|---|
| [...] | [...] | [...] | [...] | [...] | [...] |

**Identificador de versión K1:** [...]. **Otras modificaciones involuntarias o perturbaciones:** [...].

## 4 · Ensayos comparables

**Enlace a datos crudos CSV:** [`../../datos/ensayos.csv`](../../datos/ensayos.csv) · **Protocolo:** [`../../pruebas/protocolo.md`](../../pruebas/protocolo.md).

| Prueba emparejada o bloque | Condición/escenario idéntico | V1, valor + unidad | K1, valor + unidad | Cambio / resultado | Incidencia o desviación |
|---:|---|---|---|---|---|
| 1 | [...] | [...] | [...] | [...] | [...] |
| 2 | [...] | [...] | [...] | [...] | [...] |
| 3 | [...] | [...] | [...] | [...] | [...] |
| 4 | [...] | [...] | [...] | [...] | [...] |
| 5 | [...] | [...] | [...] | [...] | [...] |

**N válido V1 / K1:** [... / ...]. **Resumen, variabilidad y tasa de éxito:** [...]. **Incertidumbres/limitaciones:** [...].

## 5 · Interpretación y decisión

- **¿La evidencia respalda, contradice o no permite decidir la hipótesis?** [...]
- **Si no hubo mejora, qué aprendimos:** [...]
- **¿Qué riesgo o compromiso generó el cambio?** [...]
- **Decisión:** [conservar K1 / revertir / revisar / recolectar más datos], con razón: [...]
- **Siguiente pregunta para Kaizen 2:** [...]

## 6 · Puerta de salida E3

- [ ] V1 y K1 tienen identificadores o referencias inequívocas.
- [ ] La hipótesis está conectada con una medida y un problema diagnosticado.
- [ ] Se documentó una modificación técnica y su responsable.
- [ ] Ensayos y resultados mantienen condiciones comparables o exponen diferencias explícitamente.
- [ ] La conclusión es honesta, incluso si el resultado es negativo.
- [ ] Cada estudiante registró su [E3 personal](../../participantes/_plantilla/dias/E3.md).

**Gate E3:** [APROBADO / CONDICIONADO]. **Revisor:** [...]. **Enlace a PR/commit:** [...].
