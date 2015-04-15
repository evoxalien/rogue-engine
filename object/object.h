//Object header file
#ifndef OBJECT_H
#define OBJECT_H
#include "Box2D/Box2D.h"	//Includes all main Box2D headers
#include "behavior.h"
#include "attributes.h"
#include "equipment.h"		//Includes <vector> and "item.h", which includes <iostream> and <cstdint>
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
		static b2World* active_World_Pointer;				//A pointer to the Box2D World in which active Objects are located
		static b2BodyDef box2D_Body_Definition;				//A static Box2D Physics body definition member which is used in Object creation; holds a large number of values used for position, angle, type, and Physics optimization- constructor paramaters are used to define member values that are sent to the active Box2D World to generate a body
		static b2FixtureDef box2D_Fixture_Definition;		//A static Box2D Physics fixture definition, which holds shape, restitution, density, and collision layer details; a body may contain multiple fixtures
		static b2PolygonShape box2D_Polygon_Shape;			//A static Box2D Physics shape, which is used by the fixture definition to define the area which the fixture will occupy

		//Private member variables; some members may be moving to derived classes or may become protected instead of private
		Behavior behavior;							//A member which holds information regarding the state of an Object and what it should be doing, if anything
		Attributes attributes; 						//A member which holds information related to game attributes such as hit points, defense, damage, etc.
		Equipment equipment;						//A member which holds information on Items which are contributing to a variety of the Object's game attributes
		//Inventory inventory;						//A member which holds information on what Items are available to the Object to use or equip; Items here contribute to the attribute 'amount_Carried'
		//Status_Effects status_Effects;			//A member which holds information related to special effects that may be active on the Object, such as if a spell is increasing movement speed or regenerating health

	public:
		b2Body* physics;							//A pointer to the Box2D body which holds information related to Physics
		//Constructors and Destructors
		Object();									//Default constructor
		Object(const float, const float, const float, const int, const bool, const bool, const float, const float, const float, const bool, const bool, const bool, const float, const float, const float, const uint16, const uint16, const int, const float, const float);	//Constructor for Physics, may need to be updated to handle multiple fixtures
		Object(const Behavior);						//Constructor for when there is an already existing Behavior the Object should follow
		Object(const Attributes);					//Constructor for when the Attributes of an Object is known
		Object(const Behavior, const Attributes);	//Constructor for when both the Behavior and Attributes of the Object are known
		Object(const Object&);						//Copy constructor; copies the data in the existing Object's members to that of the new Object, places a pointer at the end of the Object pointer vector, and updates members to have the proper index of the pointer to their containing Object within the Object pointer vector
		Object(Object&&);							//Move constructor; moves the data detailed in the constructor into the location allocted in a right-side value already in use, rather than allocating additional space and deleting the old space
		~Object();									//Destructor

		//Public static functions
		const static void display_Information();	//For testing

		//'Getters' and 'Setters' for private static variables
		const static b2World* get_Active_World_Pointer();
		static void set_Active_World_Pointer(b2World*);

		const static b2BodyDef get_Box2D_Body_Definition();
		static void set_Box2D_Body_Definition(const b2BodyDef);

		//Overloaded functions
		Object& operator=(const Object&);			//Overloads the assignment operator, '=', to avoid changing the index contained in the appropriate members which reference the pointer to the containing Object in the Object pointer vector
		Object& operator=(Object&&);				//Overloads the assignment operator, '=', for right hand values of Object type

		//Public member functions
		const std::uint16_t get_Object_Pointer_Vector_Index();		//Rather than storing an additional index within Object itself, a member which already requires the index (behavior) is accessed for the necessary index of the Object within the static Object pointer vector
		void set_Object_Pointer_Vector_Index(const std::uint16_t);	//Updates necessary Object members to store the index within the static Object pointer vector of the Object that they are contained within

		//'Getters' and 'Setters' for private member variables
};

#endif
