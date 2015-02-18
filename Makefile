#OBJS specifies which files to compile as part of the project
OBJS = gameroot.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS_WIN = -Imingw_dev_lib\include\SDL2
INCLUDE_PATHS_MAC = -I/Library/Frameworks/SDL.framework/Headers

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS_WIN = -Lmingw_dev_lib\lib
LIBRARY_PATHS_MAC = SDLmain.m 

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
#COMPILER_FLAGS_WIN = -w -Wl,-subsystem,windows
#COMPILER_FLAGS_MAC = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS_WIN = -lmingw32 -lSDL2main -lSDL2
LINKER_FLAGS_MAC = -framework SDL -framework Cocoa

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = gameroot

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS_WIN) $(LIBRARY_PATHS_WIN) $(COMPILER_FLAGS_WIN) $(LINKER_FLAGS_WIN) -o $(OBJ_NAME)

mac : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)