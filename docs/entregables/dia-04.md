---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E4"
dia: 4
responsable_registro: "@mimiprogramando"
estado: "PENDIENTE"
fecha: "2026-10-29"
revision_docente: "PENDIENTE"
---

# E4 · Día 4 — ITERAR | Kaizen 2, robustez y preparación de demostración

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E4.md`.

## 0 · Contexto

**Fecha y dōjō:** 2026-10-29 · **Equipo/misión:** RAYDEN · **Versiones trazables:** V1 [id], K1 [id] y K2 [id pendiente].

## 1 · Ruta de actividades del Día 4 (180 min)

| Actividad | Minutos | Registro requerido |
|---|---:|---|
| Revisión por pares y retroalimentación | 0–20 | Observaciones de un equipo par sobre la rigidez de las conexiones y protección de cuña/navaja. |
| Diseño/ejecución Kaizen 2 | 20–70 | Ensamble final de hardware: soldadura, corte/peinado de cables, montaje de motores, ruedas, navaja y placa JSUMO xMotion V3. |
| Comparación V1–K1–K2 | 70–115 | Pruebas de movimiento, detección y tiempo de reacción con la nueva integración limpia. |
| Ensayo de robustez | 115–145 | Prueba con batería a medio consumo (11.1V baja) y superficie con desgaste de tracción. |
| Preparación de demo | 145–165 | Guion de presentación para el Día 5, asignación de roles y plan de contingencia por reinicio. |
| Gate de preparación | 165–180 | Verificación del checklist y aprobación para pruebas finales. |

## 2 · Revisión por pares

Persona o equipo observador (alias) | Evidencia revisada | Observación útil / pregunta | Respuesta técnica y decisión | Cambio aceptado o descartado |
|---|---|---|---|---|
| @Jamón | Ensamble de cuña y disposición de cableado | Los cables largos entre el driver y los motores pueden atascarse con las ruedas o hacer falso contacto en giros bruscos. | Se decidió recortar, soldar y termoensamblar los cables de alimentación de los motores N20 directamente a las borneras de la xMotion V3. | Aceptado e implementado en el ensamble de hoy. |

**Acuerdo de colaboración:** Se dividieron las tareas en la mesa de trabajo: soldadura y preparación del cableado por parte de ambos integrantes, calibración de conectores para la xMotion V3 por @mimiprogramando y montaje mecánico de navaja, ruedas y chasis por @ROM423.

## 3 · Segundo ciclo Kaizen (K2)

| Campo experimental | Completar |
|---|---|
| Limitación o nueva oportunidad detectada en K1 | Los conectores sueltos sobre la protoboard/chasis generaban caídas de voltaje temporales y ruido de lectura en los motores bajo carga máxima. |
| Hipótesis K2 y fundamento | Si integramos formalmente la placa controladora **JSUMO xMotion V3**, soldamos terminales directas a los motores y recortamos la longitud de cableado innecesaria, la respuesta de aceleración será más limpia y constante (reducirá el tiempo de arranque en un ~10-15%). |
| Variable modificada y controles | Integración de la placa **JSUMO xMotion V3**, soldadura directa de cables de motores, montaje final de navaja metálica y ordenado del arnés eléctrico. |
| Requisitos de seguridad antes del cambio | Desconectar batería LiPo antes de manipular cautín sobre la estructura; colocar protector de goma en la navaja al realizar soldaduras y calibraciones. |
| Personas responsables y alcances implicados | @ROM423 (Ensamble mecánico, soldadura de motores y ajuste de navaja) / @mimiprogramando (Mapeo de pines en xMotion V3 y carga de firmware adaptado). |
| Cambio exacto de código/CAD/configuración | Asignación de pines PWM/Dirección en el código para el chip MOSFET integrado en la xMotion V3 (`rayden_xmotion_v3.ino`). |
| Enlace a commit, PR y versión K2 | [`../../codigo/rayden_xmotion_v3.ino`] (`commit-c7d291e-hardware-xmotion`) |
| Métrica, unidad y criterio para declarar éxito | Tiempo de arranque/embestida tras detección (segundos) y cero desconexiones eléctricas en 5 ensayos seguidos. |

## 4 · Comparación de evolución

| Ensayo/condición equivalente | V1 (valor + unidad) | K1 (valor + unidad) | K2 (valor + unidad) | Incidencias o validez |
|---:|---|---|---|---|
| 1 | 1.2 s | 1.1 s | 0.9 s | Respuesta de arranque inmediata al detectar oponente frontal. |
| 2 | 1.4 s | 1.2 s | 1.0 s | Giro ágil sin vibración en los conectores de motor. |
| 3 | 2.1 s | 1.4 s | 1.2 s | Buena respuesta en ángulo de 45° con sensores bien fijos. |
| 4 | 1.8 s | 1.5 s | 1.1 s | Detención precisa en la línea blanca al errar embestida. |
| 5 | 1.9 s | 1.3 s | 1.1 s | Giro e impacto firme gracias al peso y fijación de la navaja. |

**Registros fuente:** [`datos/ensayos.csv`](../../datos/ensayos.csv) y protocolo [enlace].

**Síntesis (método, n, media/mediana, dispersión y éxito cuando proceda):**  
Para $n=5$ ensayos por versión, el tiempo medio de reacción/embestida fue de **1.68 s en V1**, **1.30 s en K1** y se redujo a **1.06 s en K2**. Tasa de éxito de la rutina: 100% (5/5).

**¿Qué mejora, qué empeora y qué no podemos concluir?**  
- **Mejora:** La aceleración inicial y la rigidez estructural mejoraron al usar la xMotion V3 y eliminar los cables sueltos; la navaja ofrece mejor palanca de empuje.
- **Empeora:** El centro de masa cambió levemente hacia el frente por el peso de la navaja metálica, exigiendo verificar la tracción de las ruedas traseras.
- **No concluimos:** Duración total de la batería bajo competencias continuas de más de 3 minutos sin recarga.

## 5 · Ensayo de robustez o variación de condiciones

| Cambio controlled de entorno (luz, suelo, batería, posición, rival, obstáculo o carga) | Riesgo y límite seguro | Predicción | Resultado / unidad / éxitos | ¿Se mantiene el objetivo? | Evidencia |
|---|---|---|---|---|---|
| Disminución de carga de batería a ~11.1V (LiPo al 30%) y polvo ligero en las ruedas de silicona. | Pérdida de tracción o reinicio de la placa por caída de voltaje. | El robot tardará un poco más en empujar, pero mantendrá la lógica de evasión del borde. | Tiempo de reacción medio: 1.22 s. El robot no se reinició y detuvo la marcha en el borde (5/5 éxitos). | Sí, la xMotion V3 mantiene estable la lógica sin reinicios. | [`../../datos/ensayos.csv`] |

**Límites de inferencia:** 5 corridas ejecutadas bajo batería baja. Se demostró que la placa soporta fluctuaciones razonables, aunque se recomienda competir siempre con batería cargada arriba del 80%.

## 6 · Ensayo general de demostración
| Segmento | Qué se demostrará en 20–60 s | Integrante responsable | Versión/código usado | Material requerido | Plan B ante fallo |
|---|---|---|---|---|---|
| Inicio / contexto | Explicación del chasis, la integración con la xMotion V3 y el cambio de soporte 3D. | @ROM423 | K2 (`commit-c7d291e`) | Robot Rayden en mano, protector de navaja. | Apoyarse con la ficha técnica impresa si falla el proyector. |
| Prueba principal | Salida del robot en el dohyō, búsqueda en giro, detección de oponente y embestida. | @mimiprogramando | `rayden_xmotion_v3.ino` | Dohyō oficial, oponente de prueba. | Reinicio rápido del interruptor de la xMotion V3. |
| Evidencia de mejora | Mostrar comparativa de tiempos (V1 vs K2) y funcionamiento de los sensores QTR en la línea blanca. | Ambos | Gráfica de datos / `ensayos.csv` | Cuaderno de bitácora y videos tomados. | Mostrar el registro en el archivo de repositorio local. |
| Defensa de fronteras | Explicación de cómo se solucionaron los falsos positivos y los ángulos ciegos de la FSM. | @mimiprogramando | Lógica en Arduino | Código fuente abierto en laptop. | Explicar diagrama de estados en pizarrón. |

**¿Robolympics es el evento externo posterior?** Por confirmar. D5 documenta la calificación y evaluación interna dentro del laboratorio.

## 7 · Gate E4

- [x] Existe un ciclo K2 explícito, con hipótesis, modificación y datos (integración xMotion V3 y cableado).
- [x] Se conservan V1, K1, K2 en el repositorio de GitHub para reproducibilidad.
- [x] Se efectuó una prueba de robustez documentada (batería baja y baja tracción por polvo).
- [x] El equipo tiene guion, responsabilidades y plan de contingencia para el Día 5.
- [x] Cada participante actualizó su registro en `participantes/<alias>/dias/E4.md`.

**Estado de preparación:** LISTO. **Pendientes y responsables:** Cargar batería LiPo al 100% para el Día 5 (@ROM423). **Revisor:** Camilo Duque.
