//Equipment cpp file; friend of Object class
#include "equipment.h"

//Default Equipment constructor
Equipment::Equipment()
{
	std::cout << "Default Equipment constructor" << std::endl;

	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		(*this).equipped_Item_Pointer_Array[i] = nullptr;
	}

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

void Equipment::display_Information()
{
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		std::cout << "Item " << i << " pointer: " << (*this).equipped_Item_Pointer_Array[i] << std::endl;
	}
}

float Equipment::get_Total_Strength_Modifier()
{
	float total_Strength_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		total_Strength_Modifier = total_Strength_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).strength_Modifier;
	}
	return total_Strength_Modifier;
}

float Equipment::get_Total_Dexterity_Modifier()
{
	
}

float Equipment::get_Total_Endurance_Modifier()
{
	
}

float Equipment::get_Total_Intelligence_Modifier()
{
	
}

float Equipment::get_Total_Perception_Modifier()
{
	
}

float Equipment::get_Total_Carrying_Capacity_Modifier()
{
	
}

float Equipment::get_Total_Vision_Range_Modifier()
{
	
}

float Equipment::get_Total_Hearing_Range_Modifier()
{
	
}

float Equipment::get_Total_Physical_Attack_Range_Modifier()
{
	
}

float Equipment::get_Total_Physical_Damage_Modifier()
{
	
}

float Equipment::get_Total_Rate_Of_Physical_Attacks_Modifier()
{
	
}

float Equipment::get_Total_Physical_Accuracy_Modifier()
{
	
}

float Equipment::get_Total_Magical_Attack_Range_Modifier()
{
	
}

float Equipment::get_Total_Magical_Damage_Modifier()
{
	
}

float Equipment::get_Total_Rate_Of_Magical_Attacks_Modifier()
{
	
}

float Equipment::get_Total_Magical_Accuracy_Modifier()
{
	
}

float Equipment::get_Total_Movement_Speed_Modifier()
{
	
}

float Equipment::get_Total_Maximum_Stamina_Modifier()
{
	
}

float Equipment::get_Total_Rate_Of_Stamina_Regeneration_Modifier()
{
	
}

float Equipment::get_Total_Maximum_Mana_Modifier()
{
	
}

float Equipment::get_Total_Rate_Of_Mana_Regeneration_Modifier()
{
	
}

float Equipment::get_Total_Maximum_Health_Modifier()
{
	
}

float Equipment::get_Total_Rate_Of_Health_Regeneration_Modifier()
{
	
}

float Equipment::get_Total_Physical_Defense_Modifier()
{
	
}

float Equipment::get_Total_Magical_Defense_Modifier()
{
	
}

float Equipment::get_Total_Block_Chance_Modifier()
{
	
}

float Equipment::get_Total_Evasion_Modifier()
{
	
}

//'Getters' and 'Setters' for private member variables
const std::uint16_t Equipment::get_Containing_Object_Pointer_Vector_Index()
{
	return (*this).containing_Object_Pointer_Vector_Index;
}

void Equipment::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}
