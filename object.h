//object.h

#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
#include "physics.h"

using namespace std;

class Object
{
	private:
		//Private static class variables
		static int number_Of_X_Physics_Segments;	//The number of partitions along the x-axis for the Physics collision system
		static int number_Of_Y_Physics_Segments;	//The number of partitions along the y-axis for the Physics collision system
		static int screen_X_Length;					//May be updated to be a vector of structures containing both the X and Y lengths of the corresponding levels, or left as it is and passed when the level is called
		static int screen_Y_Length;

		//Private member variables
		int object_Pointer_Vector_Index;			//The pointer's position in the static vector of object pointers

	public:
		//Static class variables; currently public, may be made private in the future
		static std::vector<Object*> object_Pointer_Vector;							//A vector with pointers to all objects created
		static std::vector<Physics*> physics_Pointer_Vector;						//Contains a pointer to all active Object's physics members
		static std::vector<std::vector<std::vector<Physics*>>> physics_Segments;	//A two-dimensional vector which holds pointers to the physics member of Objects near eachother

		//Constructors and Destructors
		Object();			//Default Constructor
		Object(Physics);	//Constructor
		~Object();			//Destructor

		//Public member variables; may be made private in the future
		Physics physics;									//Contains position, velocity, acceleration, mass, etc, along with useful functions for dealing with collisions
		//ArtificialIntelligence artificial_Intelligence;	//This will be the class for AI when I get around to it
		//Stats stats; 										//Unknown name at the moment, this will contain game attributes such as hit points, defense, damage, etc.

		//Static functions
		static void check_For_Collisions();					//Checks through the active collidable objects and calls Physics::resolve_Collisions if there is a collision

		const static void display_Information();			//For testing

		static void set_Number_Of_X_Physics_Segments(int);
		const static int get_Number_Of_X_Physics_Segments();

		static void set_Number_Of_Y_Physics_Segments(int);
		const static int get_Number_Of_Y_Physics_Segments();

		static void set_Screen_X_Length(int);
		const static int get_Screen_X_Length();

		static void set_Screen_Y_Length(int);
		const static int get_Screen_Y_Length();

		//'Getters' and 'Setters' for private member variables
		void set_Object_Pointer_Vector_Index(int);
		const int get_Object_Pointer_Vector_Index();

		//void resolve_Collisions();
};
#endif
