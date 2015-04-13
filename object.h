//Object header file
#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
#include <cstdint>
#include "Box2D.h"
#include "behavior.h"
#include "attributes.h"
#include "equipment.h"
//#include "inventory.h"
//#include "status_effects.h"

class Object
{
	friend class Behavior;			//Allows Behavior access to Object's private and protected member variables and functions; communicates to attributes and status_Effects members
	friend class Attributes;		//Allows Attributes access to Object's private and protected member variables and functions; communicates to equipment, inventory, and status_Effects members
//	friend class Equipment;			//Allows Equipment access to Object's private and protected member variables and functions; communicates to ...
//	friend class Inventory;			//Allows Inventory access to Object's private and protected member variables and functions; communicates to ...
//	friend class Status_Effects;	//Allows Status_Effects access to Object's private and protected member variables and functions; communicates to ...

	private:
		//Private static class variables
		static std::vector<Object*> object_Pointer_Vector;	//A vector with pointers to all Objects currently in memory; the size should never exceed a length of 65,535 or pointers may be unintentionally overwritten and cause errors

		//Private member variables; some members may be moving to derived classes or may become protected instead of private
		b2Body* physics;
		Behavior behavior;							//A member which holds information regarding the state of an Object and what it should be doing, if anything
		Attributes attributes; 						//A member which holds information related to game attributes such as hit points, defense, damage, etc.
		Equipment equipment;						//A member which holds information on Items which are contributing to a variety of the Object's game attributes
		//Inventory inventory;						//A member which holds information on what Items are available to the Object to use or equip; Items here contribute to the attribute 'amount_Carried'
		//Status_Effects status_Effects;			//A member which holds information related to special effects that may be active on the Object, such as if a spell is increasing movement speed or regenerating health

	public:
		//Constructors and Destructors
		Object();									//Default constructor
		Object(const float, const float, const float, const float, const float, const float, const bool, b2World*);
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
		Object& operator=(Object&&);				//Overloads the assignment operator, '=', for right hand values of Object type

		//Member functions
		void set_Object_Pointer_Vector_Index(const std::uint16_t);	//Updates necessary Object members to store the index within the static Object pointer vector of the Object that they are contained within
		const std::uint16_t get_Object_Pointer_Vector_Index();		//Rather than storing an additional index within Object itself, a member which already requires the index (behavior) is accessed for the necessary index of the Object within the static Object pointer vector
};

#endif
