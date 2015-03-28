//Behavior header file
#ifndef BEHAVIOR_H
#define BEHAVIOR_H

using namespace std;

enum class Behavior_States {Unaware, Aware, Alerted, Hostile, Fleeing, Surrendering};
enum class Behavior_Patterns {Take_No_Action, Move_Forward, Walk_Back_And_Forth};

class Behavior
{
	private:
		//Private member variables
		Behavior_States behavior_State;
		Behavior_Patterns behavior_Pattern;

	public:
		//Constructor
		Behavior();			//Default Constructor

		void act();

		//'Getters' and 'Setters' for private member variables
		void set_Behavior_State(Behavior_States);
		const Behavior_States get_Behavior_State();

		void set_Behavior_Pattern(Behavior_Patterns);
		const Behavior_Patterns get_Behavior_Pattern();
};
#endif
