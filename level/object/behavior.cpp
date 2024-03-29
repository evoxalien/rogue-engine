//Behavior cpp file; friend of Object
#include "behavior.h"

//Default Behavior constructor
Behavior::Behavior()
{
	std::cout << "Behavior()" << std::endl;
	(*this).behavior_State = Behavior_States::Unaware;
	(*this).behavior_Pattern = Behavior_Patterns::Neutral;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

//Constructor for when the Behavior pattern is known, behavior_State will initialize to Unaware
Behavior::Behavior(Behavior_Patterns behavior_Pattern)
{
	std::cout << "Behavior(Behavior_Patterns)" << std::endl;
	(*this).behavior_State = Behavior_States::Unaware;
	(*this).behavior_Pattern = behavior_Pattern;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

//Constructor for when both the behavior state and pattern are known
Behavior::Behavior(Behavior_States behavior_State, Behavior_Patterns behavior_Pattern)
{
	std::cout << "Behavior(Behavior_States,Behavior_Patterns)" << std::endl;
	(*this).behavior_State = behavior_State;
	(*this).behavior_Pattern = behavior_Pattern;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

//Will perform the appropriate action based on the current state and set behavior pattern; currently will just call display_Information() for all combinations of states and patterns
void Behavior::act()
{
	switch((*this).behavior_State)
	{
		case Behavior_States::Unaware:
			(*this).passive();
			break;

		case Behavior_States::Alerted:
			(*this).search();
			break;

		case Behavior_States::Aware:
			(*this).wary();
			break;

		case Behavior_States::Hostile:
			(*this).attack();
			break;

		case Behavior_States::Fleeing:
			(*this).flee();
			break;

		case Behavior_States::Surrendering:
			(*this).surrender();
			break;

		default:
			break;
	}
}

void Behavior::passive()
{
	switch((*this).behavior_Pattern)
	{
		case Behavior_Patterns::Neutral:
			
//			break;

		case Behavior_Patterns::Friendly:
			
//			break;

		case Behavior_Patterns::Hostile:
			
//			break;

		case Behavior_Patterns::Store:
			(*this).display_Information();
			break;

		default:
			break;
	}
}

void Behavior::search()
{
	switch((*this).behavior_Pattern)
	{
		case Behavior_Patterns::Neutral:
			
//			break;

		case Behavior_Patterns::Friendly:
			
//			break;

		case Behavior_Patterns::Hostile:
			
//			break;

		case Behavior_Patterns::Store:
			(*this).display_Information();
			break;

		default:
			break;
	}
}

void Behavior::wary()
{
	switch((*this).behavior_Pattern)
	{
		case Behavior_Patterns::Neutral:
			
//			break;

		case Behavior_Patterns::Friendly:
			
//			break;

		case Behavior_Patterns::Hostile:
			
//			break;

		case Behavior_Patterns::Store:
			(*this).display_Information();
			break;

		default:
			break;
	}
}

void Behavior::attack()
{
	switch((*this).behavior_Pattern)
	{
		case Behavior_Patterns::Neutral:
			
//			break;

		case Behavior_Patterns::Friendly:
			
//			break;

		case Behavior_Patterns::Hostile:
			
//			break;

		case Behavior_Patterns::Store:
			(*this).display_Information();
			break;

		default:
			break;
	}
}

void Behavior::flee()
{
	switch((*this).behavior_Pattern)
	{
		case Behavior_Patterns::Neutral:
			
//			break;

		case Behavior_Patterns::Friendly:
			
//			break;

		case Behavior_Patterns::Hostile:
			
//			break;

		case Behavior_Patterns::Store:
			(*this).display_Information();
			break;

		default:
			break;
	}
}

void Behavior::surrender()
{
	switch((*this).behavior_Pattern)
	{
		case Behavior_Patterns::Neutral:
			
//			break;

		case Behavior_Patterns::Friendly:
			
//			break;

		case Behavior_Patterns::Hostile:
			
//			break;

		case Behavior_Patterns::Store:
			(*this).display_Information();
			break;

		default:
			break;
	}
}

//Used for testing
void Behavior::display_Information() const
{
	std::cout << "behavior_State = " << static_cast<int>((*this).behavior_State) << std::endl;
	std::cout << "behavior_Pattern = " << static_cast<int>((*this).behavior_Pattern) << std::endl;
	std::cout << "containing_Object_Pointer_Vector_Index = " << (*this).containing_Object_Pointer_Vector_Index << std::endl;
	std::cout << "Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index] = " << Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index] << std::endl;
//	std::cout << "Size of behavior_State = " << sizeof((*this).behavior_State) << std::endl;
//	std::cout << "Size of behavior_Pattern = " << sizeof((*this).behavior_Pattern) << std::endl;
//	std::cout << "Size of containing_Object_Pointer_Vector_Index = " << sizeof((*this).containing_Object_Pointer_Vector_Index) << std::endl;
//	std::cout << "Size of Object::object_Pointer_Vector[(*(*this).containing_Object_Pointer_Vector_Index)] = " << sizeof(*(Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index])) << std::endl;
//	std::cout << "Size of Object = " << sizeof(Object) << std::endl;
//	std::cout << "Size of Behavior = " << sizeof(Behavior) << std::endl;
//	std::cout << "Size of int = " << sizeof(int) << std::endl;
//	std::cout << "Size of this = " << sizeof(this) << std::endl;
//	std::cout << "Size of (*this) = " << sizeof((*this)) << std::endl;
	std::cout << std::endl;
}

void Behavior::update()
{
}

//'Getters' and 'Setters' for private member variables
Behavior_States Behavior::get_Behavior_State() const
{
	return (*this).behavior_State;
}

void Behavior::set_Behavior_State(const Behavior_States behavior_State)
{
	(*this).behavior_State = behavior_State;
}

Behavior_Patterns Behavior::get_Behavior_Pattern() const
{
	return (*this).behavior_Pattern;
}

void Behavior::set_Behavior_Pattern(const Behavior_Patterns behavior_Pattern)
{
	(*this).behavior_Pattern = behavior_Pattern;
}

std::uint16_t Behavior::get_Containing_Object_Pointer_Vector_Index() const
{
	return (*this).containing_Object_Pointer_Vector_Index;
}

void Behavior::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}
