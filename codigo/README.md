# Código fuente del robot

Aquí se incorpora **solo el código de la plataforma elegida por el equipo**. No es necesario mantener cuatro proyectos en cada repositorio.

Sugerencias de estructura concreta (adaptar al hardware real):
- **M01 Mini-sumo autónomo:** `codigo/mini-sumo/` con `main.ino`, `sensors.*`, `motors.*`, `strategy.*`, documentación de pinout.
- **M03 Seguidor de línea:** `codigo/seguidor/` con proyecto Arduino/PlatformIO, módulos de sensores, control y motores.
- **M04 Tello Python:** `codigo/tello/` con `main.py`, `mission.py`, `vision.py`, `safety.py`, `requirements.txt`; validar SDK compatible.
- **M05 AMR ROS 2:** `codigo/amr_ws/src/<paquete_ros>/` para nodos Python/C++, paquetes, launch y config; nunca subir `build/`, `install/` ni `log/`.

Especificar versiones, comandos de ejecución, dependencias y procedimiento de parada segura en un README del proyecto de código.

El repositorio plantilla no contiene software listo para operar hardware. Es una estructura documental, no una validación de control de robots.
