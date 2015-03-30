//Behavior header file
#ifndef BEHAVIOR_H
#define BEHAVIOR_H
#include <cstdint>

class Object;								//Forward reference of Object class to allow an Object pointer to be stored in Behavior instances, giving Behavior access to Physics and Statistics used to determine actions

enum class Behavior_States : std::uint8_t	//Various states that an Object can be in
{
	Unaware,								//The Object is unaware of the Player
	Alerted,								//The Object is alerted that the Player is near, but does not know where they are
	Aware,									//The Object is aware of the Player's location
	Hostile,								//The Object is aggressive towards the Player
	Fleeing,								//The Object is attempting to escape from the Player
	Surrendering							//The Object is attempting to plead with the Player for its safety
};

enum class Behavior_Patterns : std::uint8_t	//Various patterns an Object can follow
{
	Neutral,								//The Object will neither help or harm the Player unless attacked
	Friendly,								//The Object will assist the Player if the Player is in combat nearby
	Hostile,								//The Object will attempt to attack the Player if the Player is nearby
	Store									//The Object will act as a shopkeeper and offer items for sale
};

class Behavior
{
	private:
		//Private member variables
		Behavior_States behavior_State;		//An Object's current state in reference to the Player; for example, whether they are oblivious to the player being near or are hostile towards them
		Behavior_Patterns behavior_Pattern;	//An Object's generic style of action; for example, an enemy or neutral NPC
		Object* containing_Object_Pointer;	//A pointer to the Object in which the member of Behavior resides

	public:
		//Constructor
		Behavior();										//Default Constructor, behavior_State will initialize to Unaware and behavior_Pattern to Neutral
		Behavior(Behavior_Patterns);					//Constructor for when the Behavior pattern is known, behavior_State will initialize to Unaware
		Behavior(Behavior_States, Behavior_Patterns);	//Constructor for when both the behavior state and pattern are known

		void act();			//Calls the appropriate action function from the behavior state
		void passive();		//The Object will perform actions as if it is unaware of the Player
		void search();		//The Object is alerted that the Player is near, but does not know where they are, and will perform a search for them appropriate to their behavior pattern; for example, a guard may search nearby hiding locations or a shopkeeper may seek out guards to alert
		void wary();		//The Object is aware of the Player's location and will act appropriate to their behavior pattern; a guard may greet you or attempt to apprehend you depending on circumstances, and a shopkeeper may offer wares for sale or try to defend his property
		void attack();		//The Object will pursue and attempt to harm the Player
		void flee();		//The Object will attempt to ensure its own survival by escaping from the Player's vicinity
		void surrender();	//The Object is cornered and cannot flee or win, so will attempt to gain the mercy of the Player

		void display_Information();						//For testing

		//'Getters' and 'Setters' for private member variables
		void set_Behavior_State(Behavior_States);
		const Behavior_States get_Behavior_State();

		void set_Behavior_Pattern(Behavior_Patterns);
		const Behavior_Patterns get_Behavior_Pattern();

		void set_Containing_Object_Pointer(Object*);
		const Object* get_Containing_Object_Pointer();
};

#include "object.h"		//Object and its components need to have headers fully defined for Behavior function definitions

#endif
