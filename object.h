//object.h

//Warning: Be sure to set the pointers of both vectors to NULL if they are deleted but don't delete the element,
//and check if the pointer is null before dereferencing it. It's slightly inefficient (+1 size of a pointer wasted per useless object),
//but for now never remove elements from the array as it will throw some logic off.

//To do: Actually useful commenting and documentation. Include a vector of object pointers for currently active objects where collisions will be checked
//Look in to potentially dividing the screen into a two-dimensional array of booleans representing portions of the active area,
//probably something like a size of the screensize/16 or something

#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
#include "physics.h"

using namespace std;

class Object
{
	private:
		static int number_Of_X_Physics_Segments;	//The number of partitions along the x-axis for the Physics collision system
		static int number_Of_Y_Physics_Segments;	//The number of partitions along the y-axis for the Physics collision system
		static int screen_X_Length;					//May be updated to be a vector of structures containing both the X and Y lengths of the corresponding levels, or left as it is and passed when the level is called
		static int screen_Y_Length;

		int object_Pointer_Vector_Index;

	public:
		Object();
		Object(Physics);
		~Object();

		static std::vector<Object*> object_Pointer_Vector;							//A vector with pointers to all objects created
		static std::vector<Physics*> physics_Pointer_Vector;						//Contains a pointer to all active Object's physics members
		static std::vector<std::vector<std::vector<Physics*>>> physics_Segments;	//A two-dimensional vector which holds pointers to the physics member of Objects near eachother
		static std::vector<Physics*> out_Of_Bounds_Physics_Vector;					//A vector of Physics pointers which are not inside the bounds of the physics segments

		Physics physics;									//Contains position, velocity, acceleration, mass, etc, along with useful functions for dealing with collisions
		//ArtificialIntelligence artificial_Intelligence;	//This will be the class for AI when I get around to it
		//Stats stats; 										//Unknown name at the moment, this will contain game attributes such as hit points, defense, damage, etc.

		static void check_For_Collisions();

		const static void display_Information();		//For testing

		static void set_Number_Of_X_Physics_Segments(int);
		const static int get_Number_Of_X_Physics_Segments();

		static void set_Number_Of_Y_Physics_Segments(int);
		const static int get_Number_Of_Y_Physics_Segments();

		static void set_Screen_X_Length(int);

		static void set_Screen_Y_Length(int);

		const int get_Object_Pointer_Vector_Index();	//For setting the pointer to NULL in the vector of object pointers
		//void resolve_Collisions();
};
#endif
