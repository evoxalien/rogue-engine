//Object -> Player header file
#ifndef PLAYER_H
#define PLAYER_H
#include "object.h"

class Player : public Object
{
	private:
		//Private member variables
		std::uint16_t player_Pointer_Vector_Index;			//The pointer's position in the static vector of player pointers; will be stored in input later
		//Input input 										//The member which will hold information on the player's controls

	public:
		//Static class variables; currently public, may be made private in the future
		static std::vector<Player*> player_Pointer_Vector;							//A vector with pointers to all Players currently in memory

		//Constructors and Destructors
		Player();			//Default constructor
		~Player();			//Destructor

		//Static functions
		const static void display_Information();			//For testing

		//Member functions
		//'Getters' and 'Setters' for private member variables
		void set_Player_Pointer_Vector_Index(const std::uint16_t);
		const std::uint16_t get_Player_Pointer_Vector_Index();
};
#endif
