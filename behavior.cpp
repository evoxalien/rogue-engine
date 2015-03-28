//Behavior cpp file
#include "behavior.h"

using namespace std;

//Default Behavior Constructor
Behavior::Behavior()
{
	(*this).behavior_State = Behavior_States::Unaware;
	(*this).behavior_Pattern = Behavior_Patterns::Take_No_Action;
}

//Will perform the appropriate action based on the current state and set behavior pattern
void Behavior::act()
{
}

//'Getters' and 'Setters' for private member variables
void Behavior::set_Behavior_State(Behavior_States behavior_State)
{
	(*this).behavior_State = behavior_State;
}

const Behavior_States Behavior::get_Behavior_State()
{
	return (*this).behavior_State;
}

void Behavior::set_Behavior_Pattern(Behavior_Patterns behavior_Pattern)
{
	(*this).behavior_Pattern = behavior_Pattern;
}
const Behavior_Patterns Behavior::get_Behavior_Pattern()
{
	return (*this).behavior_Pattern;
}
