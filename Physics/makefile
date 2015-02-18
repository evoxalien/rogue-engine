physics_Test: physics_Test.o physics.o object.o
	g++ physics_Test.o physics.o object.o -o a

physics_Test.o: physics_Test.cpp physics.h object.h
	g++ -c physics_Test.cpp -o physics_Test.o

physics.o: physics.cpp physics.h
	g++ -c physics.cpp -o physics.o

object.o: object.cpp object.h
	g++ -c object.cpp -o object.o