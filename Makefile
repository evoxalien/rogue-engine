#OBJS specifies which files to compile as part of the project

OBJS = main.cpp object.cpp player.cpp log.cpp behavior.cpp attributes.cpp equipment.cpp item.cpp mingw_dev_lib/include/Box2D/Rope/b2Rope.cpp mingw_dev_lib/include/Box2D/Common/b2StackAllocator.cpp mingw_dev_lib/include/Box2D/Common/b2BlockAllocator.cpp mingw_dev_lib/include/Box2D/Common/b2Settings.cpp mingw_dev_lib/include/Box2D/Common/b2Draw.cpp mingw_dev_lib/include/Box2D/Common/b2Math.cpp mingw_dev_lib/include/Box2D/Common/b2Timer.cpp mingw_dev_lib/include/Box2D/Collision/Shapes/b2ChainShape.cpp mingw_dev_lib/include/Box2D/Collision/Shapes/b2EdgeShape.cpp mingw_dev_lib/include/Box2D/Collision/Shapes/b2PolygonShape.cpp mingw_dev_lib/include/Box2D/Collision/Shapes/b2CircleShape.cpp mingw_dev_lib/include/Box2D/Collision/b2BroadPhase.cpp mingw_dev_lib/include/Box2D/Collision/b2CollideCircle.cpp mingw_dev_lib/include/Box2D/Collision/b2CollideEdge.cpp mingw_dev_lib/include/Box2D/Collision/b2CollidePolygon.cpp mingw_dev_lib/include/Box2D/Collision/b2Collision.cpp mingw_dev_lib/include/Box2D/Collision/b2Distance.cpp mingw_dev_lib/include/Box2D/Collision/b2DynamicTree.cpp mingw_dev_lib/include/Box2D/Collision/b2TimeOfImpact.cpp mingw_dev_lib/include/Box2D/Dynamics/b2Body.cpp mingw_dev_lib/include/Box2D/Dynamics/b2ContactManager.cpp mingw_dev_lib/include/Box2D/Dynamics/b2Fixture.cpp mingw_dev_lib/include/Box2D/Dynamics/b2Island.cpp mingw_dev_lib/include/Box2D/Dynamics/b2World.cpp mingw_dev_lib/include/Box2D/Dynamics/b2WorldCallbacks.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2CircleContact.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2Contact.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2ContactSolver.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp mingw_dev_lib/include/Box2D/Dynamics/Contacts/b2PolygonContact.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2DistanceJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2FrictionJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2GearJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2Joint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2MotorJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2MouseJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2PulleyJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2RopeJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2WeldJoint.cpp mingw_dev_lib/include/Box2D/Dynamics/Joints/b2WheelJoint.cpp


#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Imingw_dev_lib\include\SDL2 -Imingw_dev_lib\include\Box2D -Imingw_dev_lib\include

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
LINKER_FLAGS_M = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -D LINUX

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME_W = bin/windows/Rogue_Engine
OBJ_NAME_L = bin/linux/Rogue_Engine
OBJ_NAME_M = bin/mac/Rogue_Engine

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS_W) -o $(OBJ_NAME_W)

linux : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS_L) -o $(OBJ_NAME_L)

mac : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(MACSTUFF) $(LINKER_FLAGS_L) -D MAC  -o $(OBJ_NAME_M)
