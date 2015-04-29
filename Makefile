#OBJS specifies which files to compile as part of the project


OBJSW = main.cpp SoundManager.cpp log.cpp vector2d.cpp Camera.cpp level/level.cpp level/object/objectcpps.cpp mingw_dev_lib/include/Box2D/Box2Dcpps.cpp
OBJSM = main.cpp SoundManager.cpp log.cpp vector2d.cpp Camera.cpp level/level.cpp level/object/objectcpps.cpp


#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Imingw_dev_lib\include\SDL2 -Imingw_dev_lib\include

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -Lmingw_dev_lib\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
#COMPILER_FLAGS = -w -Wl,-subsystem,windows
COMPILER_FLAGS = -std=c++11

#Mac Library Path
MACSTUFF =  -I/usr/local/include/ -L/usr/local/lib



#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS_W = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -D WINDOWS
LINKER_FLAGS_L = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -D LINUX
LINKER_FLAGS_M = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lBox2D -D MAC

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME_W = bin/windows/Rogue_Engine
OBJ_NAME_L = bin/linux/Rogue_Engine
OBJ_NAME_M = bin/mac/Rogue_Engine

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJSW) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS_W) -o $(OBJ_NAME_W)

linux : $(OBJS)
	$(CC) $(OBJSW) $(COMPILER_FLAGS) $(LINKER_FLAGS_L) -o $(OBJ_NAME_L)

mac : $(OBJS)
	$(CC) $(OBJSM) $(COMPILER_FLAGS) $(MACSTUFF) $(LINKER_FLAGS_M)  -o $(OBJ_NAME_M)
