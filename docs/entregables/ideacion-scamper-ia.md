# Ideación SCAMPER + IA — Equipo RAYDEN

**Misión:** M01 Mini-sumo autónomo | **Alcance:** MS06 / MS02 | **Fecha:** 2026-10-26

## 1. Idea Base
"Nuestro mini-sumo utiliza 3 sensores IR montados con una separación angular fija de 45°, generando zonas ciegas laterales que provocan fallos de embestida (tiempo de reacción 1.82 s y 40% de fallos en la baseline V1)."

## 2. Aplicación de SCAMPER
* **Adaptar (A):** Rediseñar en SolidWorks los soportes 3D para reorientar la visión de los IR de 45° a ~25°.
* **Sustituir (S):** Reemplazar IR fijos por un sensor ultrasónico montado sobre un micro-servo dinámico.
* **Combinar (C):** Ajustar la FSM para ejecutar giros de pivote asimétricos al detectar objetivos laterales.

## 3. Consulta y Aportes de la IA (Google Gemini)
* **Prompt enviado:** "Somos el equipo RAYDEN de Kaizen Dōjō 2026 en M01 Mini-sumo. Aplica SCAMPER a nuestra idea de 3 IR fijos a 45°..."
* **Aportes y filtro:**
  1. *Aceptado:* Brackets 3D a ~25° en PLA.
  2. *Ajustado:* Espejos reflectores sustituidos por rediseño directo en CAD.
  3. *Descartado:* Visión por cámara OpenCV por peso (>500g) y restricción de 15 horas.

## 4. Propuesta Final Elegida
Implementar el rediseño CAD de soportes a ~25° (Alt 1) acoplado con ajuste de umbrales en el firmware. Se comprobará en D3 mediante 5 ensayos cuantitativos.

## 5. Conexión con Entregables
* **Enlace desde E1:** [`docs/entregables/dia-01.md`](../docs/entregables/dia-01.md)
* **Evolución en D2/D3:** Esta hipótesis dio origen al cambio de soporte K1 en el Día 3.
