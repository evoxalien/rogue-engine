//Equipment cpp file; friend of Object class
#include "equipment.h"

//Default Equipment constructor
Equipment::Equipment()
{
	std::cout << "Default Equipment constructor" << std::endl;

	(*this).number_Of_Items_Equipped = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		(*this).equipped_Item_Pointer_Array[i] = nullptr;
		//(*this).equipped_Item_Pointer_Array[i] = new Item();		//new only used for testing; avoid if possible
		//(*(*this).equipped_Item_Pointer_Array[i]).set_Containing_Object_Pointer_Vector_Index((*this).get_Containing_Object_Pointer_Vector_Index());
		//(*(*this).equipped_Item_Pointer_Array[i]).set_Item_State(Item_States::Equipped);
	}

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

//Equipment::Equipment(Item& item)
//{
//	std::cout << "Equipment(Item)" << std::endl;

//	(*this).number_Of_Items_Equipped = 1;
//	(*this).equipped_Item_Pointer_Array[0] = &item;
//}

void Equipment::display_Information() const
{
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		std::cout << "Item " << i << " pointer: " << (*this).equipped_Item_Pointer_Array[i] << std::endl;
	}
}

void Equipment::update()
{
}

//Returns true if the item was successfully equipped or false if the item couldn't be equipped for whatever reason
bool Equipment::equip_Item(Item& item, std::uint8_t index_To_Equip_Item)
{
	if(index_To_Equip_Item < Equipment::total_Number_Of_Equipment_Slots)
	{
		if((*this).equipped_Item_Pointer_Array[index_To_Equip_Item] == nullptr)
		{
			if(item.get_Item_State() != Item_States::Equipped)
			{
				(*this).equipped_Item_Pointer_Array[index_To_Equip_Item] = &item;
				item.set_Item_State(Item_States::Equipped);
				return true;
			}
			else
			{
				return false;	//Item was already equipped by an Object
			}
		}
		else
		{
			return false; //Slot already had an item equipped
		}
	}
	else
	{
		return false;	//Slot to equip to exceeded possible slots
	}
}

float Equipment::get_Total_Strength_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Strength_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Dexterity_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Dexterity_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Endurance_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Endurance_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Intelligence_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Intelligence_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Perception_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Perception_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Carrying_Capacity_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Carrying_Capacity_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Vision_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Vision_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Hearing_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Hearing_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Physical_Attack_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Physical_Attack_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Physical_Damage_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Physical_Damage_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Rate_Of_Physical_Attacks_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Rate_Of_Physical_Attacks_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Physical_Accuracy_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Physical_Accuracy_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Magical_Attack_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Magical_Attack_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Magical_Damage_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Magical_Damage_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Rate_Of_Magical_Attacks_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Rate_Of_Magical_Attacks_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Magical_Accuracy_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Magical_Accuracy_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Movement_Speed_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Movement_Speed_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Maximum_Stamina_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Maximum_Stamina_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Rate_Of_Stamina_Regeneration_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Rate_Of_Stamina_Regeneration_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Maximum_Mana_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Maximum_Mana_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Rate_Of_Mana_Regeneration_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Rate_Of_Mana_Regeneration_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Maximum_Health_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Maximum_Health_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Rate_Of_Health_Regeneration_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Rate_Of_Health_Regeneration_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Physical_Defense_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Physical_Defense_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Magical_Defense_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Magical_Defense_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Block_Chance_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Block_Chance_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Equipment::get_Total_Evasion_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < Equipment::total_Number_Of_Equipment_Slots; i++)
	{
		if((*this).equipped_Item_Pointer_Array[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).equipped_Item_Pointer_Array[i]).get_Evasion_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

//'Getters' and 'Setters' for private member variables
std::uint16_t Equipment::get_Containing_Object_Pointer_Vector_Index() const
{
	return (*this).containing_Object_Pointer_Vector_Index;
}

void Equipment::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}
