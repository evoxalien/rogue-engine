//Object -> Player header file
#ifndef PLAYER_H
#define PLAYER_H
#include "object.h"

using namespace std;

class Player : public Object
{
	private:
		//Private member variables
		int player_Pointer_Vector_Index;			//The pointer's position in the static vector of player pointers

	public:
		//Static class variables; currently public, may be made private in the future
		static std::vector<Player*> player_Pointer_Vector;							//A vector with pointers to all Players currently in memory

		//Constructors and Destructors
		Player();			//Default constructor
		~Player();			//Destructor

		//Public member variables; may be made private in the future
		//Input input 										//The member which will hold information on the player's controls

		//Static functions
		const static void display_Information();			//For testing

		//'Getters' and 'Setters' for private member variables
		void set_Player_Pointer_Vector_Index(int);
		const int get_Player_Pointer_Vector_Index();
};
#endif
