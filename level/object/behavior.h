//Behavior header file; friend of Object
#ifndef BEHAVIOR_H
#define BEHAVIOR_H

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
	friend class Object;

	private:
		//Private member variables
		Behavior_States behavior_State;							//An Object's current state in reference to the Player; for example, whether they are oblivious to the player being near or are hostile towards them
		Behavior_Patterns behavior_Pattern;						//An Object's generic style of action; for example, an enemy or neutral NPC
		std::uint16_t containing_Object_Pointer_Vector_Index;	//The index of the Object in which the Behavior member resides inside of the static Object Pointer Vector in the Object class

	public:
		//Constructors
		Behavior();										//Default Constructor, behavior_State will initialize to Unaware and behavior_Pattern to Neutral
		Behavior(Behavior_Patterns);					//Constructor for when the Behavior pattern is known, behavior_State will initialize to Unaware
		Behavior(Behavior_States, Behavior_Patterns);	//Constructor for when both the behavior state and pattern are known

		//Public member functions
		void act();			//Calls the appropriate action function from the behavior state
		void passive();		//The Object will perform actions as if it is unaware of the Player
		void search();		//The Object is alerted that the Player is near, but does not know where they are, and will perform a search for them appropriate to their behavior pattern; for example, a guard may search nearby hiding locations or a shopkeeper may seek out guards to alert
		void wary();		//The Object is aware of the Player's location and will act appropriate to their behavior pattern; a guard may greet you or attempt to apprehend you depending on circumstances, and a shopkeeper may offer wares for sale or try to defend his property
		void attack();		//The Object will pursue and attempt to harm the Player
		void flee();		//The Object will attempt to ensure its own survival by escaping from the Player's vicinity
		void surrender();	//The Object is cornered and cannot flee or win, so will attempt to gain the mercy of the Player

		void display_Information() const;						//For testing
		void update();

		//'Getters' and 'Setters' for private member variables
		Behavior_States get_Behavior_State() const;
		void set_Behavior_State(const Behavior_States);

		Behavior_Patterns get_Behavior_Pattern() const;
		void set_Behavior_Pattern(const Behavior_Patterns);

		std::uint16_t get_Containing_Object_Pointer_Vector_Index() const;
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);
};

#endif
