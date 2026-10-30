---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E5"
dia: 5
responsable_registro: "Mauricio Rodríguez"
estado: "Completado"
fecha: "2026-10-30"
revision_docente: "PENDIENTE"
---

# E5 · Día 5 — MI CONQUISTA | Demostración y reflexión

**Alias:** @ROM423 · **Territorio/carta/frontera:** Territorio S SUPERAR / Frontera F3 OPTIMIZAR / Cartas D1 AUTONOMOUS SYSTEM, D2 ROBUST ROBOT, S2 PERFORMANCE LAB[cite: 1, 15] · **Alcances y katas completados:** MS02 (Cuñas/Pala), MS05 (Sensores de borde), MS06 (Sensores de oponente); Katas K1, K2 y K3[cite: 2, 14, 15].

| Mi defensa personal | Respuesta |
|---|---|
| Antes de la semana NO podía… | Contar con un diseño mecánico optimizado tanto en chasis como en tolerancia de componentes para llegar a competir sin hacer modificaciones de última hora en el dohyō[cite: 13, 15]. |
| Ahora SÍ puedo… (con evidencia) | Diseñar, imprimir en 3D y ajustar la geometría física y de ataque de un robot mini-sumo conforme a reglamento, garantizando detección óptima sin puntos ciegos[cite: 13, 14]. |
| Qué hice realmente en el proyecto y dónde está mi aporte | Diseñé en SolidWorks y pulí los soportes 3D para reorientar los sensores IR, eliminando el punto ciego lateral, e integré la cuña/navaja Mini Katana[cite: 7, 8, 13]. |
| Acción concreta que mostré en vivo / grabación | Demostré el ajuste mecánico en el dohyō oficial, reduciendo la zona ciega de $45^\circ$ a $\sim25^\circ$ e impactando al rival con máxima aceleración y tracción[cite: 7, 12, 14]. |
| Resultado observable o métrica con unidad | $5/5$ corridas exitosas en la demostración oficial (100% efectividad) con un tiempo medio de reacción/embestida de **0.994 s**[cite: 13]. |
| Comparación entre V1 y última versión atribuible a mi trabajo | **V1:** 1.82 s (60% éxito por zona ciega a $45^\circ$)[cite: 5] $\rightarrow$ **K1:** 1.30 s (soportes IR corregidos y cuña lijada)[cite: 7] $\rightarrow$ **K2 / Final:** **0.994 s** (100% éxito)[cite: 13]. |
| Mi kata más significativo y por qué | K1 de MS02 (medición y ajuste de cuña): demostró que pequeñas tolerancias de impresión 3D influyen drásticamente en el desempeño físico sobre la pista[cite: 7, 8, 14]. |
| Una decisión autónoma que tomé | Decidir el lijado manual preciso del borde inferior de la cuña de PLA tras detectar que rozaba la pista en las primeras pruebas de K1[cite: 7, 8]. |
| Una falla y cómo reaccioné o qué aprendí | En K1 la cuña quedó muy baja y se raspó contra la pista (fallo a $45^\circ$)[cite: 7]. Reaccioné lijando el borde y aprendí a verificar tolerancias físicas antes de ensayar series completas[cite: 7, 8]. |
| Apoyo que di o recibí de mis compañeros | Recibí retroalimentación de @Jamón sobre el cableado de motores[cite: 8] y trabajé en pareja con @mimiprogramando dividiendo ensamble/soldadura y firmware[cite: 8]. |
| Un conocimiento que puedo transferir a otra situación | El método de diseño iterativo CAD-impresión-ensayo físico considerando tolerancias de ajuste para mecanismos que interactúan directamente con el entorno[cite: 8, 13, 14]. |
| Qué mejoraría si tuviera un día más | Diseñar e implementar un sistema de cubiertas o limpieza activa para evitar la acumulación de polvo en las ruedas de silicona y mantener tracción máxima[cite: 10, 13, 14]. |
| Comentario recibido de par o profesor | **Profesor (Camilo Duque):** "Excelente trabajo en tolerancias de impresión 3D y estabilidad del chasis"[cite: 14]. **Par (@Jamón):** Destacó la velocidad y el excelente acabado de empuje de la navaja[cite: 14]. |

**Enlaces a 2–3 evidencias contundentes:**
1. [Repositorio público de GitHub - RAYDEN](https://github.com/Rom423/SEMANA-TEC--RAYDEN)[cite: 14]
2. [Código Final Rayden y asignación de hardware xMotion](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino)[cite: 9, 13]
3. Modelos CAD de soporte e integración mecánica: `cad/chasis_v1.sldprt` y `cad/soportes_ir_k1.sldprt`[cite: 3, 7]

**Registro colectivo:** [`../../../docs/entregables/dia-05.md`](../../../docs/entregables/dia-05.md)
