# Cómo contribuir en Kaizen Dōjō

1. Actualiza `participantes/<alias>/dias/E1.md` … `E5.md` al cierre de cada sesión; `portafolio.md` funciona como índice de tus evidencias.
2. Vincula tus avances con el alcance correspondiente de `alcances/<ID>-<tema>/README.md`.
3. Conserva versiones del código funcional y registra en `datos/ensayos.csv` qué cambió y cómo se probó.
4. Para cambios de código: crea una rama `feat/MS01-chasis`, `fix/SL06-control` o `docs/E3-alias` y envía un Pull Request con contexto; revisa con al menos un compañero cuando sea posible.
5. Para correcciones pequeñas de Markdown, el equipo puede editar mediante GitHub web sin instalar software, si su flujo de colaboración lo permite.
6. Antes de integrar, comprueba que no se suban secretos, archivos binarios pesados o datos personales.

## Convención sugerida de mensajes de commit
- `docs(E1): acordar frontera de estudiante-01`
- `feat(MS05): integrar detector de borde`
- `test(SL07): registrar ensayos de control PD`
- `fix(AR04): corregir manejo de meta fallida`

## Acuerdos del Dōjō
- Respeto al error y retroalimentación constructiva.
- Se registra quién contribuye, sin convertir un commit en una calificación.
- Nunca sobrescribir ensayos anteriores: documentar versiones y condiciones.
