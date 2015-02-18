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
		static int number_Of_Objects;		//Probably unnecessary as the vector.size() gets the same value, leaving it for now
		int object_Pointer_Vector_Index;

	public:
		Object();
		Object(Physics);

		static vector<Object*> object_Pointer_Vector;		//A vector with pointers to all objects created

		Physics physics;									//Contains position, velocity, acceleration, mass, etc, along with useful functions for dealing with collisions
		//ArtificialIntelligence artificial_Intelligence;	//This will be the class for AI when I get around to it
		//Stats stats; 										//Unknown name at the moment, this will contain game attributes such as hit points, defense, damage, etc.

		static void display_Information();		//For testing
		int get_Object_Pointer_Vector_Index();	//For setting the pointer to NULL in the vector of object pointers

		//void resolve_Collisions();
};
#endif
