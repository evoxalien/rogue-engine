//Object header file
#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
#include <cstdint>
#include "behavior.h"
#include "attributes.h"

class Object
{
	private:
		//Private member variables; some members may be moving to derived classes or may become protected
		Behavior behavior;							//A member which holds information regarding the state of an Object and what it should be doing, if anything
		Attributes attributes; 						//A member which holds information related to game attributes such as hit points, defense, damage, etc.
		//Equipment equipment;
		//Inventory inventory;


	public:
		//Static class variables; currently public, may be made private in the future
		static std::vector<Object*> object_Pointer_Vector;	//A vector with pointers to all Objects currently in memory; the size should never exceed a length of 65,535 or pointers may be unintentionally overwritten and cause errors

		//Constructors and Destructors
		Object();									//Default constructor
		Object(const Behavior);						//Constructor for when there is an already existing Behavior the Object should follow
		Object(const Attributes);					//Constructor for when the Attributes of an Object is known
		Object(const Behavior, const Attributes);	//Constructor for when both the Behavior and Attributes of the Object are known
		Object(const Object&);						//Copy constructor; copies the data in the existing Object's members to that of the new Object, places a pointer at the end of the Object pointer vector, and updates members to have the proper index of the pointer to their containing Object within the Object pointer vector
		Object(Object&&);							//Move constructor; moves the data detailed in the constructor into the location allocted in a right-side value already in use, rather than allocating additional space and deleting the old space
		~Object();									//Destructor

		//Static functions
		const static void display_Information();	//For testing

		//Overloaded functions
		Object& operator=(const Object&);			//Overloads the assignment operator, '=', to avoid changing the index contained in the appropriate members which reference the pointer to the containing Object in the Object pointer vector
		Object& operator=(Object&&);			//Overloads the assignment operator, '=', for right hand values of Object type

		//Member functions
		void set_Object_Pointer_Vector_Index(const std::uint16_t);	//Updates necessary Object members to store the index within the static Object pointer vector of the Object that they are contained within
		const std::uint16_t get_Object_Pointer_Vector_Index();		//Rather than storing an additional index within Object itself, a member which already requires the index (behavior) is accessed for the necessary index of the Object within the static Object pointer vector
};
#endif
