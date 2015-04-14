//Item cpp file
#include "item.h"

//Default Item constructor
Item::Item()
{
	std::cout << "Default Item constructor" << std::endl;

	(*this).item_State = Item_States::On_Ground;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

void Item::display_Information()
{
	std::cout << "item_State : " << static_cast<uint8_t>((*this).item_State) << std::endl;
}

//'Getters' and 'Setters' for private member variables

void Item::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}

const std::uint16_t Item::get_Containing_Object_Pointer_Vector_Index()
{
	return (*this).containing_Object_Pointer_Vector_Index;
}
