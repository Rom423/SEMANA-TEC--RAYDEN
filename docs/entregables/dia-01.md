---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E1"
dia: 1
responsable_registro: "equipo"
estado: "PENDIENTE"
fecha: "AAAA-MM-DD"
revision_docente: "PENDIENTE"
---

# E1 · Día 1 — ATREVERSE | Contrato de misión, inventario y dōjō

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E1.md`.

## 0 · Identificación, equipo y logística del dōjō

| Campo obligatorio | Dato |
|---|---|
| Fecha y horario de esta sesión | [AAAA-MM-DD; HH:MM–HH:MM, 180 min] |
| Nombre / alias del equipo | [kd26-mXX-equipoYY] |
| Misión / plataforma | [M01 mini-sumo autónomo / M03 seguidor / M04 Tello Python / M05 AMR ROS 2] |
| Objetivo verificable del robot (una frase) | [Acción + condiciones + éxito] |
| **Dōjō asignado — campus, edificio y sala/taller exactos** | **[Campus ___ / Edificio ___ / Sala o taller ___ / Nº de laboratorio ___]** |
| Puesto o zona dentro del dōjō | [Mesa, banco, espacio de vuelo, pista, dohyō o estación] |
| Horario / reserva confirmada | [Fechas y bloque horario; quien la autorizó] |
| Responsable del espacio y contacto institucional | [Nombre/cargo y canal institucional, sin publicar teléfonos privados] |
| Acceso, aforo y ajustes de accesibilidad | [Restricciones de ingreso, capacidad, adecuaciones necesarias] |
| Salidas, botiquín, extintor y punto de reunión | [Ubicación real validada al llegar] |
| Zonas segregadas por riesgo | [Vuelo / herramientas / tránsito AMR / ensayo de pista] |
| Ubicación de materiales y resguardo nocturno | [Gabinete/estante/inventario; responsable] |
| Plan de sustitución si falla el espacio | [Dōjō alternativo con autorización; no improvisar espacio de vuelo] |
| Instructor o supervisor presente en la sesión | [@alias / nombre institucional] |

> ⛔ **No se permite avanzar a pruebas físicas sin dōjō concreto y autorización del responsable.** No inventar salón, número de laboratorio ni recursos que no hayan sido confirmados.

## 1 · Integrantes, responsabilidades, accesibilidad y decisiones (0–15 min)

| Alias GitHub | Rol inicial | Carta y frontera (D/S/E; F1–F4) | Alcances ID (1–3) | Kit personal (archivo) | Necesidad de apoyo o accesibilidad acordada |
|---|---|---|---|---|---|
| [@alias-1] | [Integración / documentación / seguridad / pruebas ...] | [D · F1 · D1] | [MS01, MS02] | [`../../participantes/alias/compromiso.md`](../../participantes/_plantilla/compromiso.md) | [Acordar con la persona sin registrar datos sensibles] |
| [@alias-2] | [...] | [...] | [...] | [enlace] | [...] |

**Acuerdo de colaboración:** [Cómo se toman decisiones, cómo se resuelven conflictos, apoyos senpai–kōhai, pausas y distribución equitativa de participación.]

## 2 · Demostración de la plataforma y seguridad (15–35 min)

| Elemento | Observación directa | Evidencia / vínculo |
|---|---|---|
| Plataforma base inspeccionada (estado, modelo, ID inventario) | [ ] | [enlace / foto no sensible] |
| Funciones existentes y límites comprobados | [ ] | [enlace] |
| Paro de emergencia / desconexión segura ensayados | [ ] | [enlace / tutor responsable] |
| Restricciones de competición o exhibición verificadas | [ ] | [fuente / por verificar] |
| Riesgos vistos y medidas activas | [ ] | [docs/seguridad.md] |

**Normas específicas según misión:**
- **M01:** protecciones de alimentación; desarmar motores antes de tocar ruedas; dohyō delimitado, rival de referencia y bordes seguros.
- **M03:** pista despejada, altura/posición de sensores controlada, baterías y ruedas comprobadas.
- **M04:** espacio interior autorizado, observador humano, altura y desplazamientos limitados, baterías y aterrizaje inmediato; *verificar modelo real de Tello*.
- **M05:** ROS 2 y TF/navegación listos; límites de velocidad, sensor de obstáculos, paro seguro y zona de tránsito marcada.

## 3 · Diagnóstico práctico colectivo (35–65 min)

**Condición inicial V0 de la plataforma:** [Robot completo / kit / subensambles / simulador; qué funciona y qué falta]

| Prueba diagnóstica | Condición y procedimiento | Resultado observado / unidad | Problema / causa probable | Evidencia |
|---|---|---|---|---|
| [1: movimiento o comunicación] | [...] | [...] | [...] | [enlace] |
| [2: lectura de sensor] | [...] | [...] | [...] | [enlace] |
| [3: comportamiento de la misión] | [...] | [...] | [...] | [enlace] |

**Capacidades ya disponibles y dependencias:** [qué módulos se pueden reutilizar, y qué necesita cada alcance de otro integrante.]

## 4 · Integración de Mission Forge C2 y pacto de alcances (65–100 min)

Cada participante debe colocar el archivo **Markdown original generado por la web** en:

`participantes/<alias>/compromiso.md`

Se conserva íntegro (incluido el frontmatter y la lista de katas). Los nuevos alcances/katas diseñados por el participante quedan claramente marcados como *propuesta propia* y requieren aprobación técnica.

**Catálogo de referencia:** [Google Sheets C2](https://docs.google.com/spreadsheets/d/1FKxFzoyu9KJb3RlOwB609vliS5hAtmwWFu2G2zG3Ky4/edit) · **Configurador Mission Forge:** [`herramientas/mission-forge-c2.html`](../../herramientas/mission-forge-c2.html) (descárgalo y ábrelo en el navegador; funciona sin Internet).

| Alias | Kit enlazado | Alcance principal | Complementos | Katas elegidos o nuevos | Horas mín.–máx. | Evidencia final esperada | Negociación aprobada |
|---|---|---|---|---|---|---|---|
| [@alias] | [compromiso.md] | [MS01] | [MS02 / ninguno] | [K1, K3 / propio] | [6–8 h] | [CAD ensamblado + prueba] | [Sí / Pendiente; revisor] |

**Resultado de negociación grupal:** [Puntos de integración; interfaces entre códigos/firmware/sensores/estructura; prioridad si no hay tiempo.]

## 5 · Inventario exhaustivo y especificación de materiales (obligatorio)

### 5.1 Inventario maestro del equipo

Completar **cada recurso requerido**: estructura, electrónica, actuadores, sensores, herramientas, consumibles, instrumentos, software, datos, red, espacios de ensayo y elementos de seguridad. Añadir filas sin límite.

| ID | Categoría | Material o recurso (especificación exacta: modelo, medida, versión o característica) | Cantidad requerida + unidad | Cantidad confirmada | Fuente/proveedor o dueño | Ubicación física o ruta digital | Responsable | Estado (disponible/reservado/falta) | Alternativa compatible | Día requerido |
|---|---|---|---|---|---|---|---|---|---|---|
| MAT-001 | [Robot/plataforma] | [Modelo preciso y compatibilidad] | [1 ud.] | [?] | [laboratorio/equipo] | [armario] | [@alias] | [por confirmar] | [alternativa] | [D1] |
| MAT-002 | [Mecánica/electrónica/sensor] | [...] | [...] | [...] | [...] | [...] | [...] | [...] | [...] | [...] |
| MAT-003 | [Herramienta/seguridad/medición] | [...] | [...] | [...] | [...] | [...] | [...] | [...] | [...] | [...] |
| MAT-004 | [Software/datos/conectividad] | [SO + versión, ROS/Python/OpenCV o controlador, puerto/red] | [...] | [...] | [...] | [...] | [...] | [...] | [...] | [...] |
| MAT-005 | [Zona de pruebas] | [Pista/dohyō/marcadores/mapa; dimensiones y configuración] | [...] | [...] | [...] | [...] | [...] | [...] | [...] | [...] |

También disponible el archivo [`datos/inventario_materiales.csv`](../../datos/inventario_materiales.csv) para registrar muchos materiales sin agrandar esta tabla.

### 5.2 Lista de cotejo específica por plataforma (elegir solo la misión asignada)

| Misión | Revisar y especificar (marca/modelo/cantidad reales) |
|---|---|
| M01 · Mini-sumo autónomo | Chasis y material para cuñas, ruedas/motores/soportes, driver, controlador y firmware, batería/cargador/fusible, sensores de borde y rival, cableado/conectores, dohyō/rival de referencia, CAD/impresora 3D/herramientas, instrumentos de medición y protocolo de paro. |
| M03 · Seguidor de línea | Chasis/ruedas/motores, driver, controlador, barra de sensores reflectivos/soportes, batería/cargador, placa y cableado, pista con curvas y superficie definida, software de programación, cinta/regla/cronómetro/instrumentos y paro seguro. |
| M04 · Tello Python | **Modelo Tello verificado** y baterías suficientes, cargador, computadora y adaptador Wi-Fi, versión Python y SDK compatible, OpenCV si aplica, marcadores visuales impresos, área interior de vuelo demarcada, supervisor/observador, barreras y protocolo de aterrizaje/abortos. |
| M05 · AMR ROS 2 | Base AMR y baterías/cargador, computador y distribución ROS 2/paquetes, workspace y repositorio base, sensores (p. ej. lidar/odometría), mapa y TF/localización, RViz/Nav2 si aplica, red de comunicación, estaciones/marcadores, área de navegación acordonada, instrumento de medida y paro seguro. |

**Enlaces a fichas técnicas / instrucciones de conexión, fabricación y seguridad:** [URLs o rutas dentro del repositorio.]

### 5.3 Riesgos de recursos y abastecimiento

| Bloqueante | A qué alcance afecta | Solución prevista / fecha y responsable | Impacto si no se resuelve |
|---|---|---|---|
| [material o software aún no validado] | [...] | [...] | [reducir alcance / simulación / replanificar] |

**Materiales completos para ejecutar el Día 2:** [Sí / Parcial / No]. **Confirmado por:** [docente y responsable equipo] a [fecha/hora].

## 6 · Kata 0 — exploración técnica de arranque (100–160 min)

| Integrante/alcance | Pregunta técnica | Mini-prueba o prototipo de exploración | Resultado o error observado | Evidencia enlazada | Acción necesaria antes de D2 |
|---|---|---|---|---|---|
| [@alias / ID] | [qué quiero verificar] | [qué hice] | [qué ocurrió] | [commit/foto/log] | [acción] |

**Integración entre subequipos:** [Qué interfaz se dejó validada: alimentación, dimensiones, tópicos, salida sensorial, etc.]

## 7 · Cierre: contrato técnico y puerta de salida E1 (160–180 min)

- [ ] El objetivo colectivo tiene condición de éxito verificable.
- [ ] Cada estudiante depositó **su kit Markdown original** en `participantes/<alias>/compromiso.md`.
- [ ] Cada estudiante completó [E1 personal](../../participantes/_plantilla/dias/E1.md) y definió frontera, evidencia y alcance negociado.
- [ ] El inventario está **completo** y cada recurso indica cantidad, especificación, disponibilidad y responsable.
- [ ] Se asignó **dōjō específico** con edificio, salón/taller, horarios, supervisión y autorización.
- [ ] Se inspeccionaron riesgos, paro y condiciones de seguridad de la plataforma.
- [ ] Se identificaron dependencias y bloqueos del Día 2; están bajo control o se ajustó la misión.
- [ ] El profesor aprobó el alcance y la seguridad, o registró observaciones y una alternativa viable.

**Estado del gate:** [APROBADO / APROBADO CON CONDICIONES / REPLANIFICAR].

**Condiciones, responsables, fecha y próxima decisión:** [ ... ]

**Revisor docente:** [ ... ] · **Enlace a commit/PR:** [ ... ]

**Criterio mínimo E1:** existe un contrato de misión y frontera individual, hay evidencia del punto de partida, un inventario verificable y un espacio de trabajo autorizado. La ausencia de algún material crítico NO debe esconderse.
