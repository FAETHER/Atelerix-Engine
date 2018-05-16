# Atelerix Game Engine
Free and Open-source game engine that is currently in the works.


# Current Dependencies

This project currently uses the following deps:

* SFML 2.4
* GLM (OpenGL Mathematics)
* GLEW (OpenGL Extension Wrangler)

# Dependencies for Windows

The dependencies used if you are compiling on Windows
is contained here on the repository.
All you need is minGw package.
https://sourceforge.net/projects/mingw/?source=directory


# Dependencies for Unix-based systems

Install the dependencies before compiling for now.
Use your preferred package manager and install the
deps like so(I will be using apt in the examples):

* `sudo apt install libsfml-dev`
* `sudo apt install libglm-dev`
* `sudo apt install libglew-dev`

You should now be able to compile the project using g++, since
our Makefile are currently not ready for use. If you are unsure
about the packages in your package manager, try searching for them
using their commands. `apt-cache search <query>` or if you are on
an arch based distro `pacman -Ss <query>`. More dependencies may
come in the future so stay updated.



