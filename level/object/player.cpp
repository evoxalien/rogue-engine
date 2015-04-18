//Object -> Player cpp file
#include "player.h"

//Initialization of static Player members
std::vector<Player*> Player::player_Pointer_Vector;

//Default Player constructor; adds a pointer to the Player to the Player pointer vector
Player::Player()
{
	(*this).set_Player_Pointer_Vector_Index(static_cast<std::uint16_t>(Player::player_Pointer_Vector.size()));
	Player::player_Pointer_Vector.push_back(this);
}

//Player::Player(Input input)
//{
//	(*this).input = input;
//	(*this).set_Player_Pointer_Vector_Index(static_cast<std::uint16_t>(Player::player_Pointer_Vector.size()));
//	Player::player_Pointer_Vector.push_back(this);
//}

//Player Deconstructor; when a Player is deleted or goes out of scope, the Player pointer vector will swap the last element with the one deleted and remove the previous last element before deleting the Player from memory
Player::~Player()
{
	Player::player_Pointer_Vector[(*this).get_Player_Pointer_Vector_Index()] = Player::player_Pointer_Vector[Player::player_Pointer_Vector.size() - 1];		//Changes pointer stored in the deconstructing Player's index to be a pointer to the last Player in the vector
	(*Player::player_Pointer_Vector[(*this).get_Player_Pointer_Vector_Index()]).set_Player_Pointer_Vector_Index((*this).get_Player_Pointer_Vector_Index());	//Changes the index of the Player which previously had its pointer at the end to its new position in the vector 
	Player::player_Pointer_Vector.pop_back();																												//Removes the last element of the Player pointer vector since it's effectively been moved to a new index
}

//Used for testing; displays useful information in the console log related to the Player class
const void Player::display_Information()
{
	std::cout << "size of vector = " << Player::player_Pointer_Vector.size() << std::endl;
	std::cout << "capacity of vector = " << Player::player_Pointer_Vector.capacity() << std::endl;
	std::cout << "max capacity of vector = " << Player::player_Pointer_Vector.max_size() << std::endl << std::endl;
	for(int i = 0; i < Player::player_Pointer_Vector.size(); i++)
	{
		std::cout << std::endl << "Player index = " << (*Player::player_Pointer_Vector[i]).get_Player_Pointer_Vector_Index() << std::endl;
	}
	std::cout << std::endl;
}

//'Getters' and 'Setters' for private member variables
void Player::set_Player_Pointer_Vector_Index(const std::uint16_t player_Pointer_Vector_Index)
{
	(*this).player_Pointer_Vector_Index = player_Pointer_Vector_Index;
	//(*this).input.set_Containing_Player_Pointer_Vector_Index(player_Pointer_Vector_Index);
}

const std::uint16_t Player::get_Player_Pointer_Vector_Index()
{
	return (*this).player_Pointer_Vector_Index;
	//return (*this).input.get_Containing_Player_Pointer_Vector_Index();
}