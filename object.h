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
		std::uint16_t object_Pointer_Vector_Index;			//The pointer's position in the static vector of object pointers, in the range of 0 to 65,535

	public:
		//Static class variables; currently public, may be made private in the future
		static std::vector<Object*> object_Pointer_Vector;							//A vector with pointers to all Objects currently in memory; the size should never exceed a length of 65,535 or pointers may be unintentionally overwritten and cause errors

		//Constructors and Destructors
		Object();			//Default Constructor
		Object(Behavior);	//Constructor for when there is an already existing Behavior the Object should follow
		~Object();			//Destructor

		//Public member variables; may be made private in the future
		Behavior behavior;									//A member which holds information regarding the state of an Object and what it should be doing, if anything
		//Stats stats; 										//Unknown name at the moment, this will contain game attributes such as hit points, defense, damage, etc.

		//Static functions
		const static void display_Information();			//For testing

		//'Getters' and 'Setters' for private member variables
		void set_Object_Pointer_Vector_Index(int);
		const int get_Object_Pointer_Vector_Index();
};
#endif
