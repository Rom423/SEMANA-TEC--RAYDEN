---
kaizen_dojo: "2026"
formato: "Entregable diario G2"
evidencia: "E1"
dia: 1
responsable_registro: "mimiprogramando"
participante: "Ximena Neri"
estado: "Completado"
fecha: "2026-10-26"
revision_docente: 
---

# E1 · Día 1 — MI FRONTERA | Diagnóstico y pacto personal

**Alias de GitHub:** @mimiprogramando · **Equipo:** [RAYDEN](https://github.com/Rom423/SEMANA-TEC--RAYDEN) · **Misión:** M01 Mini-sumo autónomo · **Dōjō asignado:** Campus León / CTA / Laboratorio de electrónica.

## A. Kit de configuración exportado de Mission Forge (OBLIGATORIO)

- **Archivo original:** [Compromisos_Karla_Neri](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/participantes/compromiso-kaizen-karla-ximena-jaime-neri.md)
- **Fecha/hora en que lo generé:** 2026-10-26 09:12
- **ID/versión del catálogo:** C2/1.1

- [x] Descargué el `.md` desde el configurador y lo copié al repositorio sin transcribir ni omitir el frontmatter.
- [x] Mi selección de misión coincide con la del equipo (M01).
- [x] Si propuse alcance o kata nuevo, expliqué su pertinencia y solicité aprobación.

- **Cambios negociados después de exportar el kit:** Ninguno.
- **Responsable que aprobó:** Camilo Duque (@camiloduque)

---

## B. Mi diagnóstico y frontera

| Pregunta | Mi respuesta real |
| :--- | :--- |
| **Lo que ya sé hacer sin ayuda** | Estructurar máquinas de estado finitas (FSM), programar lógica en Arduino y realizar lecturas de sensores analógicos y digitales. |
| **Lo que todavía no puedo demostrar** | Un dominio completo de la integración de arquitecturas de hardware avanzadas como la placa JSUMO xMotion V3 sin depender de protoboards temporales. |
| **Qué desafío me emociona y por qué** | Programar la lógica de búsqueda, ataque y evasión de borde (FSM) optimizada con temporizadores no bloqueantes (`millis()`) para garantizar tiempos de reacción mínimos. |
| **Mi territorio, carta y frontera F1–F4 elegidos** | **Territorio:** D DOMINAR · **Frontera:** F2 DECIDIR · **Cartas:** D1 AUTONOMOUS SYSTEM, D2 ROBUST ROBOT. |
| **Mi alcance principal y complementarios (máximo 3)** | **Principal:** MS07 (Implementar primitivas de movimiento autónomo en FSM). <br> **Complementarios:** MS10 (Diseñar y ajustar estrategia de ataque), MS11 (Calibrar y depurar firmware del sistema). |
| **Qué quiero construir/programar/mejorar personalmente** | Desarrollar el código base en Arduino Nano para el control de motores y la gestión simultánea de los sensores IR y QTR sin bloqueos de tiempo. |
| **Evidencia verificable de que lo logré** | Archivos de código fuente (`.ino`) en el repositorio y bitácora de pruebas de respuesta de sensores en el monitor serie. |
| **Qué apoyo o recurso necesito (sin revelar datos sensibles)** | Arduino Nano, drivers de motores, sensores JS40F/QTR-1RC y dohyō oficial de pruebas en el Laboratorio de Electrónica. |

---

## C. Kata 0 de exploración

- **Pregunta técnica:** ¿El firmware en Arduino lee correctamente las señales analógicas y digitales de los sensores IR y QTR de manera estable?
- **Prueba que realicé y materiales usados:** Carga de un script preliminar de lectura por puerto serie utilizando la placa Arduino Nano, sensores JS40F y QTR-1RC sobre el dohyō.
- **Qué funcionó / qué falló:** Las lecturas respondieron adecuadamente a los cambios de distancia y contraste, permitiendo mapear los umbrales iniciales necesarios para la FSM.
- **Evidencia:** [Primer_Código](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/codigo/PrimerCodigo_Rayden.ino)

---

## D. Mi compromiso y límites

- **Katas priorizados:** 
  * MS07: Programar primitivas de movimiento y validar cambios de estado en la FSM.
  * MS10: Mapear umbrales de disparo para la rutina de ataque autónomo.
  * MS11: Validar la estabilidad de lectura de los sensores de borde y oponente.
- **Duración técnica prevista:** 9–12 h (8–10 h de trabajo técnico presencial).
- **Dependencia con otra persona:** Integración del diseño mecánico, chasis y soportes 3D realizados por @ROM423.

> **Mi pacto Kaizen:** “Al terminar la semana podré estructurar máquinas de estado finitas, calibrar sensores de contraste y programar ataques autónomos eficientes para el robot Rayden, demostrado mediante repositorio de código estructurado y pruebas exitosas en el dohyō.”

- **Validación de profesor:
- **Enlace a registro colectivo E1:** [DIA 1](https://github.com/Rom423/SEMANA-TEC--RAYDEN/blob/main/docs/entregables/dia-01.md)
