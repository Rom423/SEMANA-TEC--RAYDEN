---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E4"
dia: 4
responsable_registro: "Mauricio Rodríguez"
estado: "Completado"
fecha: "2026-10-29"
revision_docente: 
---

# E4 · Día 4 — MI KAIZEN 2 | Refiné, comparé y defendí

**Alias:** @ROM423 · **Alcance:** MS02, MS05, MS06 · **Versiones:** V1 (Arduino Nano en protoboard / 45° ciega)[cite: 3, 5]; K1 (Soportes IR a ~25° + cuña lijada)[cite: 6, 7]; K2 (JSUMO xMotion V3 + navaja Mini Katana + soldadura limpia)[cite: 8, 9].

| Registro de Kaizen 2 | Respuesta |
|---|---|
| Retroalimentación de compañero / revisión externa | Observación de @Jamón: Los cables largos entre el driver y los motores podían atascarse con las ruedas o hacer falso contacto durante giros bruscos[cite: 8]. |
| Decisión que tomé a partir de esa observación | Aceptada e implementada: Recortar, soldar y termoensamblar los cables de alimentación de los motores N20 directamente a las borneras de la placa xMotion V3[cite: 8]. |
| Nueva hipótesis y cambio que propuse | Si integramos formalmente la placa JSUMO xMotion V3, soldamos terminales directas a los motores y montamos la navaja metálica Mini Katana, la respuesta de aceleración bajará a ~1.0 s al eliminar caídas de voltaje por falso contacto[cite: 8, 9]. |
| Modificación personal comprobable y commit/archivo | Ensamble mecánico, soldadura directa de terminales, montaje de navaja Mini Katana y ruedas JS2622[cite: 8, 9]. Commit: [Segundo Código Rayden / Hardware xMotion](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/codigo/SegundoCodigoRayden.ino)[cite: 9, 11]. |
| Método y condiciones comparables entre versiones | $n=5$ ensayos equivalentes en dohyō oficial con rival estático a 20 cm y en diagonales a $45^\circ$, midiendo el tiempo de reacción/embestida en segundos (s)[cite: 9, 10]. |
| Métrica/unidad, valores V1, K1, K2 y n | **Métrica:** Tiempo de embestida (s). **V1:** 1.82 s[cite: 5, 10] $\rightarrow$ **K1:** 1.30 s[cite: 7, 10] $\rightarrow$ **K2:** 1.06 s (100% éxito en corridas post-soldadura)[cite: 10]. |
| ¿Qué mejoró, qué empeoró y qué no sabemos? | **Mejoró:** La aceleración inicial y rigidez estructural al eliminar falsos contactos[cite: 10]. **Empeoró:** Centro de masa levemente desplazado hacia al frente por el peso de la navaja[cite: 10]. **No sabemos:** La autonomía bajo torneos continuos de más de 3 min[cite: 10]. |
| Prueba de robustez y límites seguros | Batería LiPo baja a ~11.1V (30%) y superficie del dohyō con polvo ligero[cite: 10]. Límite seguro: desconexión de LiPo y uso de funda protectora en la navaja[cite: 8, 10]. |
| Resultado de robustez y condiciones | Tras limpiar ruedas de silicona con alcohol isopropílico, el robot promedió 1.23 s (4/5 éxitos); la xMotion V3 no se reinició por caída de voltaje[cite: 10]. |
| Qué demostraré en D5 como logro propio | La rigidez del ensamble mecánico 3D, el correcto despeje y empuje de la navaja Mini Katana, y la eliminación de ángulos ciegos a $45^\circ$ en dohyō[cite: 10, 13]. |
| Qué debo corregir antes de la presentación | Cargar la batería LiPo al 100% y limpiar minuciosamente las ruedas de silicona con alcohol isopropílico antes de cada combate[cite: 11]. |

**Artefacto o función para demo:** Robot Rayden con chasis 3D, placa JSUMO xMotion V3, navaja Mini Katana integrada y soportes IR corregidos a ~25°[cite: 10]. **Evidencias:** bitácora de datos en [Ensayos](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/datos/ensayos.csv) y archivo [CAD](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/06978296ceae782cede26164a8de15d605758087/hardware/Raiden%20rumbo%20a%20japon.SLDPRT)

**Registro colectivo:** [DIA 4](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/docs/entregables/dia-04.md)
