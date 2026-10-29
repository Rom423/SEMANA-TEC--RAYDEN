---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E1"
dia: 1
responsable_registro: "Mauricio Rodríguez"
estado: "Completado"
fecha: "2026-10-26"
revision_docente: "PENDIENTE"
---

# E1 · Día 1 — ATREVERSE | Contrato de misión, inventario y dōjō

> **Regla:** sustituir los corchetes, registrar lo realmente observado y enlazar a evidencias del repositorio. **No inventar datos ni marcar pruebas no realizadas.** Los archivos del equipo resumen el trabajo compartido; las reflexiones y evidencias personales van en `participantes/<alias>/dias/E1.md`.

## 0 · Identificación, equipo y logística del dōjō

| Campo obligatorio | Dato |
|---|---|
| Fecha y horario de esta sesión | 2026-10-26 9:10 - 11:50 |
| Nombre / alias del equipo | RAYDEN |
| Misión / plataforma | M01 mini-sumo autónomo |
| Objetivo verificable del robot (una frase) | Mejora de estrategia de ataque y búsqueda para obtener un robot competitivo |
| **Dōjō asignado — campus, edificio y sala/taller exactos** | Campus León / CTA / Laboratorio de electrónica |
| Instructor o supervisor presente en la sesión | Camilo Duque |

> ⛔ **No se permite avanzar a pruebas físicas sin dōjō concreto y autorización del responsable.** No inventar salón, número de laboratorio ni recursos que no hayan sido confirmados.

## 1 · Integrantes, responsabilidades, accesibilidad y decisiones (0–15 min)

| Alias GitHub | Rol inicial | Carta y frontera (D/S/E; F1–F4) | Alcances ID (1–3) | Kit personal (archivo) | Necesidad de apoyo o accesibilidad acordada |
|---|---|---|---|---|---|
| @ROM423 | Documentación | S · SUPERAR / F3 · OPTIMIZAR | MS02, MS05, MS06 | [`participantes/compromiso-kaizen-mauricio-rodriguez-martinez.md`](participantes/compromiso-kaizen-mauricio-rodriguez-martinez.md) | Ninguna |
| @mimiprogramando | Integración | D · DOMINAR / F2 · DECIDIR | MS07, MS10, MS11 | [`participantes/compromiso-kaizen-karla-ximena-jaime-neri.md`](participantes/compromiso-kaizen-karla-ximena-jaime-neri.md) | Ninguna |

**Acuerdo de colaboración:** Las decisiones técnicas sobre CAD y mecánica son asumidas por @ROM423, mientras que la programación de la FSM, calibración de sensores y control de versión del código corresponden a @mimiprogramando. Ante desacuerdos sobre el diseño o la estrategia, se realizan pruebas rápidas de laboratorio (A/B) para respaldar la decisión con datos medibles en el dohyō. Ambos integrantes se apoyan activamente en las tareas de soldadura, ensamble y cableado, realizando pausas breves cada 60 minutos para revisar el cumplimiento del plan diario.

**Acuerdo de colaboración:** [Cómo se toman decisiones, cómo se resuelven conflictos, apoyos senpai–kōhai, pausas y distribución equitativa de participación.]

## 2 · Demostración de la plataforma y seguridad (15–35 min)

| Elemento | Observación directa | Evidencia / vínculo |
|---|---|---|
| Plataforma base inspeccionada (estado, modelo, ID inventario) | Minisumo en operación | [enlace / foto no sensible] |
| Funciones existentes y límites comprobados | CAD completo, electrónica funcional, función de búsqueda y ataque en proceso de mejora. | [enlace] |
| Restricciones de competición o exhibición verificadas | Completado | [fuente / por verificar] |
| Riesgos vistos y medidas activas | Generar protector para la cuchilla | [docs/seguridad.md] |

**Normas específicas según misión:**
- **M01:** protecciones de alimentación; desarmar motores antes de tocar ruedas; dohyō delimitado, rival de referencia y bordes seguros.
- **M03:** pista despejada, altura/posición de sensores controlada, baterías y ruedas comprobadas.
- **M04:** espacio interior autorizado, observador humano, altura y desplazamientos limitados, baterías y aterrizaje inmediato; *verificar modelo real de Tello*.
- **M05:** ROS 2 y TF/navegación listos; límites de velocidad, sensor de obstáculos, paro seguro y zona de tránsito marcada.

## 3 · Integración de Mission Forge C2 y pacto de alcances (65–100 min)

Cada participante debe colocar el archivo **Markdown original generado por la web** en:

`participantes/<alias>/compromiso.md`

Se conserva íntegro (incluido el frontmatter y la lista de katas). Los nuevos alcances/katas diseñados por el participante quedan claramente marcados como *propuesta propia* y requieren aprobación técnica.

**Catálogo de referencia:** [Google Sheets C2](https://docs.google.com/spreadsheets/d/1FKxFzoyu9KJb3RlOwB609vliS5hAtmwWFu2G2zG3Ky4/edit) · **Configurador Mission Forge:** [`herramientas/mission-forge-c2.html`](../../herramientas/mission-forge-c2.html) (descárgalo y ábrelo en el navegador; funciona sin Internet).

| Alias | Kit enlazado | Alcance principal | Complementos | Katas elegidos o nuevos | Horas mín.–máx. | Evidencia final esperada | Negociación aprobada |
|---|---|---|---|---|---|---|---|
| @ROM423 | participantes/compromiso-kaizen-mauricio-rodriguez-martinez.md | MSO02 | MS05, MS06 | K1, K3 | [9–12 h] | Video de pruebas, donde el robot es funcional | Sí |
| @mimprogramando | participantes/compromiso-kaizen-karla-ximena-jaime-neri.md | MSO07 | MS10, MS11 | K1, K2, K3 | [9–12 h] | Video de registro de pruebas de mejora y documentación del código | Sí |

**Resultado de negoROMciación grupal:** [Puntos de integración; interfaces entre códigos/firmware/sensores/estructura; prioridad si no hay tiempo.]

## 5 · Inventario exhaustivo y especificación de materiales (obligatorio)

### 5.1 Inventario maestro del equipo

Completar **cada recurso requerido**: estructura, electrónica, actuadores, sensores, herramientas, consumibles, instrumentos, software, datos, red, espacios de ensayo y elementos de seguridad. Añadir filas sin límite.

| ID | Categoría | Material o recurso (especificación exacta: modelo, medida, versión o característica) | Cantidad requerida + unidad | Cantidad confirmada | Fuente/proveedor o dueño | Ubicación física o ruta digital | Responsable | Estado (disponible/reservado/falta) | Alternativa compatible | Día requerido |
|---|---|---|---|---|---|---|---|---|---|---|
| MAT-001 | ROBOT Mini sumo | Robot Rayden| 1 unidad | 1 unidad | Equipo Rayden | En nuestra propiedad | @Rom423 | Disponible | ROBOT MAMI | Día 1 |
| MAT-002 | Mecánica | Diseño CAD / Impresión 3D | 1 unidad | 1 unidad | Equipo Rayden | En nuestra propiedad | @Rom423 | Disponible | Reimpresión | Día 1 |
| MAT-003 | Electrónica| PCB JSUMO | 1 unidad | 1 unidad | Equipo Rayden | En nuestra propiedad | @mimiprogramando | Disponible | PCB JSUMO DE ROBOT MAMI | Día 1 |
| MAT-002 | Sensor | Sensor IR | 5 unidades | 5 unidades | Equipo Rayden | En nuestra propiedad | @mimiprogramando | Disponible | Sensores de repuesto | Día 1 |
| MAT-002 | Sensor | Sensor QTR | 2 unidades | 2 unidades | Equipo Rayden | En nuestra propiedad | @mimiprogramando | Disponible | Sensores de repuesto | Día 1 |
| MAT-004 | Programación | Arduino | 1 unidad | 1 unidad | Equipo Rayden | En nuestra propiedad | @Rom423 | Disponible | Programación | Día 1 |

También disponible el archivo [`datos/inventario_materiales.csv`](../../datos/inventario_materiales.csv) para registrar muchos materiales sin agrandar esta tabla.

### 5.2 Lista de cotejo específica por plataforma (elegir solo la misión asignada)

| Misión | Revisar y especificar (marca/modelo/cantidad reales) |
|---|---|
| M01 · Mini-sumo autónomo | Chasis y material para cuñas, ruedas/motores/soportes, driver, controlador y firmware, batería/cargador/fusible, sensores de borde y rival, cableado/conectores, dohyō/rival de referencia, CAD/impresora 3D/herramientas, instrumentos de medición y protocolo de paro. |

**Enlaces a fichas técnicas / instrucciones de conexión, fabricación y seguridad:** [URLs o rutas dentro del repositorio.]

### 5.3 Riesgos de recursos y abastecimiento

| Bloqueante | A qué alcance afecta | Solución prevista / fecha y responsable | Impacto si no se resuelve |
|---|---|---|---|
| Todo validado | NA| NA | NA |

**Materiales completos para ejecutar el Día 2:** [Sí / Parcial / No]. **Confirmado por:** [docente y responsable equipo] a [fecha/hora].

## 6 · Kata 0 — exploración técnica de arranque (100–160 min)

| Integrante/alcance | Pregunta técnica | Mini-prueba o prototipo de exploración | Resultado o error observado | Evidencia enlazada | Acción necesaria antes de D2 |
|---|---|---|---|---|---|
| @mimiprogramando | Verificar el funcionamiento de la programación | Preparar el programa | Compilar para verificar el programa |

**Integración entre subequipos:** [Qué interfaz se dejó validada: alimentación, dimensiones, tópicos, salida sensorial, etc.]

## 7 · Cierre: contrato técnico y puerta de salida E1 (160–180 min)

- [ SI ] El objetivo colectivo tiene condición de éxito verificable.
- [ SI ] Cada estudiante depositó **su kit Markdown original** en `participantes/<alias>/compromiso.md`.
- [ SI ] Cada estudiante completó [E1 personal](../../participantes/_plantilla/dias/E1.md) y definió frontera, evidencia y alcance negociado.
- [ SI ] El inventario está **completo** y cada recurso indica cantidad, especificación, disponibilidad y responsable.
- [ SI ] Se asignó **dōjō específico** con edificio, salón/taller, horarios, supervisión y autorización.
- [ SI ] Se inspeccionaron riesgos, paro y condiciones de seguridad de la plataforma.
- [ SI ] Se identificaron dependencias y bloqueos del Día 2; están bajo control o se ajustó la misión.
- [ SI ] El profesor aprobó el alcance y la seguridad, o registró observaciones y una alternativa viable.


**Criterio mínimo E1:** existe un contrato de misión y frontera individual, hay evidencia del punto de partida, un inventario verificable y un espacio de trabajo autorizado. La ausencia de algún material crítico NO debe esconderse.
