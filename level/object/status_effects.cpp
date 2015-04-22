//Status_Effects cpp file; friend of Object class
#include "status_effects.h"

//Default Status_Effects constructor
Status_Effects::Status_Effects()
{
	std::cout << "Default Status_Effects constructor" << std::endl;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

void Status_Effects::display_Information() const
{
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		std::cout << "Status_Effect " << i << " pointer: " << (*this).active_Status_Effect_Pointer_Vector[i] << std::endl;
	}
}

void Status_Effects::update()
{
}

void Status_Effects::apply_Status_Effect(Status_Effect& status_Effect)
{
	if(status_Effect.get_Status_Effect_State() == Status_Effect_States::Inactive)
	{
		status_Effect.set_Active_Status_Effects_Index((*this).active_Status_Effect_Pointer_Vector.size());
		status_Effect.set_Status_Effect_State(Status_Effect_States::Active);
		(*this).active_Status_Effect_Pointer_Vector.push_back(&status_Effect);
	}
	else
	{
		std::cerr << "A single Status_Effect cannot currently be applied to two separate objects." << std::endl;
	}
}

void Status_Effects::remove_Status_Effect(std::uint8_t index_Of_Status_Effect)
{
	if((*this).active_Status_Effect_Pointer_Vector[index_Of_Status_Effect] != nullptr)
	{
		(*(*this).active_Status_Effect_Pointer_Vector[index_Of_Status_Effect]).set_Active_Status_Effects_Index(0);
		(*(*this).active_Status_Effect_Pointer_Vector[index_Of_Status_Effect]).set_Status_Effect_State(Status_Effect_States::Inactive);
		(*this).active_Status_Effect_Pointer_Vector[index_Of_Status_Effect] = nullptr;
	}
}

float Status_Effects::get_Total_Strength_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Strength_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Strength_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Strength_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Dexterity_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Dexterity_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Dexterity_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Dexterity_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Endurance_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Endurance_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Endurance_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Endurance_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Intelligence_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Intelligence_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Intelligence_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Intelligence_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Perception_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Perception_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Perception_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Perception_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Carrying_Capacity_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Carrying_Capacity_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Carrying_Capacity_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Carrying_Capacity_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Vision_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Vision_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Vision_Range_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Vision_Range_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Hearing_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Hearing_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Hearing_Range_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Hearing_Range_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Physical_Attack_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Attack_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Physical_Attack_Range_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Attack_Range_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Physical_Damage_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Damage_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Physical_Damage_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Damage_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Rate_Of_Physical_Attacks_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Physical_Attacks_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Rate_Of_Physical_Attacks_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Physical_Attacks_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Physical_Accuracy_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Accuracy_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Physical_Accuracy_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Accuracy_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Magical_Attack_Range_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Attack_Range_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Magical_Attack_Range_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Attack_Range_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Magical_Damage_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Damage_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Magical_Damage_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Damage_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Rate_Of_Magical_Attacks_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Magical_Attacks_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Rate_Of_Magical_Attacks_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Magical_Attacks_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Magical_Accuracy_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Accuracy_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Magical_Accuracy_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Accuracy_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Movement_Speed_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Movement_Speed_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Movement_Speed_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Movement_Speed_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Maximum_Stamina_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Maximum_Stamina_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Maximum_Stamina_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Maximum_Stamina_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Rate_Of_Stamina_Regeneration_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Stamina_Regeneration_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Rate_Of_Stamina_Regeneration_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Stamina_Regeneration_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Maximum_Mana_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Maximum_Mana_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Maximum_Mana_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Maximum_Mana_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Rate_Of_Mana_Regeneration_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Mana_Regeneration_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Rate_Of_Mana_Regeneration_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Mana_Regeneration_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Maximum_Health_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Maximum_Health_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Maximum_Health_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Maximum_Health_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Rate_Of_Health_Regeneration_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Health_Regeneration_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Rate_Of_Health_Regeneration_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Rate_Of_Health_Regeneration_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Physical_Defense_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Defense_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Physical_Defense_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Physical_Defense_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Magical_Defense_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Defense_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Magical_Defense_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Magical_Defense_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Block_Chance_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Block_Chance_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Block_Chance_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Block_Chance_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

float Status_Effects::get_Total_Evasion_Modifier() const
{
	float total_Attribute_Modifier = 0;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Modifier = total_Attribute_Modifier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Evasion_Modifier();
		}
	}
	return total_Attribute_Modifier;
}

float Status_Effects::get_Total_Evasion_Multiplier() const
{
	float total_Attribute_Multiplier = 1;
	for(std::uint8_t i = 0; i < (*this).active_Status_Effect_Pointer_Vector.size(); i++)
	{
		if((*this).active_Status_Effect_Pointer_Vector[i] != nullptr)
		{
			total_Attribute_Multiplier = total_Attribute_Multiplier + (*(*this).active_Status_Effect_Pointer_Vector[i]).get_Evasion_Multiplier_Modifier();
		}
	}
	return total_Attribute_Multiplier;
}

//'Getters' and 'Setters' for private member variables
std::uint16_t Status_Effects::get_Containing_Object_Pointer_Vector_Index() const
{
	return (*this).containing_Object_Pointer_Vector_Index;
}

void Status_Effects::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}
