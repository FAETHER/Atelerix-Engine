
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif

# UNIX BASED COMPILE ------------------------------------------------------------------------

ifeq ($(detected_OS),Linux)

# C++ compiler
CPPC = g++

# C++ compiler flags
# -c flag is for object files.
CFLAGS = -c

# make reference
MAKE = make

# sfml libs for linux
LNXSFLIBS = -lsfml-graphics -lsfml-window -lsfml-system

allunix:
	$(MAKE) -C ./src
	


cleanunix:
	rm -rf *.exe *.o *.out

endif



# WINDOWS COMPILE --------------------------------------------------------------------------

ifeq ($(detected_OS),Windows)

OBJS = src/*.cpp
HEADS = include/*.h
CC = g++
OBJ_NAME = Atelerix

# . means to look in current directory. AND NOT DIRECTORY ABOVE!!
# -L for libs ()static binaries
# -I for include files!!!

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
#COMPILER_FLAGS = -m64 -O3 -w -Wl,-subsystem,windows

# all:
	# g++ main.cpp -o main.exe -DSFML_STATIC -I D:\1\Atelerix-Engine\SFML-2.4.2\include -L D:\1\Atelerix-Engine\SFML-2.4.2\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg

# NOTE!!!! Libraries have to be in this LOAD ORDER! -Kyryl	
# BOTH FLAGS -DSFML_STATIC -static-libstdc++ HAVE TO BE PRESENT; FIRST FOR STATIC LINK, SECOND FIXES INCORRECT ENTRY POINT BECAUSE OF (libgcc_s_seh-1.dll, libgomp-1.dll, _libstdc++-6.dll_l, libwinpthread-1.dll) BUGS!!!
#remember to set -framework OpenGL maybe? ...

#----- 64 bit compile flag
#env CFLAGS=-m64 CXXFLAGS=-m64 LDFLAGS=-m64 make

LIBS = -L ./SFML-2.4.2/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg -L ./glew-2.1.0/lib/Release/Win32 -lGLEW32s
INCS = -I ./SFML-2.4.2/include -I ./glew-2.1.0/include -I ./glm/include



all:
	$(CC) $(OBJS) -o $(OBJ_NAME) $(HEADS) -DSFML_STATIC -static-libstdc++ $(INCS) $(LIBS)

clean:
	rm -rf *.o *~

endif	
	
	
	
	
