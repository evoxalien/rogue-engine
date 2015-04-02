//Object header file
#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
#include <cstdint>
#include "behavior.h"

class Object
{
	private:
		//Private member variables

	public:
		//Static class variables; currently public, may be made private in the future
		static std::vector<Object*> object_Pointer_Vector;							//A vector with pointers to all Objects currently in memory; the size should never exceed a length of 65,535 or pointers may be unintentionally overwritten and cause errors

		//Constructors and Destructors
		Object();			//Default Constructor
		Object(Behavior);	//Constructor for when there is an already existing Behavior the Object should follow
		~Object();			//Destructor

		//Public member variables; may be made private in the future
		Behavior behavior;									//A member which holds information regarding the state of an Object and what it should be doing, if anything
		//Statistics statistics; 							//Unknown name at the moment, this will contain game attributes such as hit points, defense, damage, etc.

		//Static functions
		const static void display_Information();			//For testing

		//Member functions
		void set_Object_Pointer_Vector_Index(std::uint16_t);	//Updates necessary Object members to store the index within the static Object pointer vector of the Object that they are contained within
		const std::uint16_t get_Object_Pointer_Vector_Index();	//Rather than storing an additional index within Object itself, a member which already requires the index (behavior) is accessed for the necessary index of the Object within the static Object pointer vector
};
#endif
