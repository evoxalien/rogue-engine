//Status_Effect cpp file
#include "statusEffect.h"

Status_Effect::Status_Effect()
{
	std::cout << "Default Status_Effect constructor" << std::endl;

	(*this).status_Effect_State = Status_Effect_States::Inactive;

	(*this).strength_Modifier = 0;
	(*this).strength_Multiplier_Modifier = 0;
	(*this).dexterity_Modifier = 0;
	(*this).dexterity_Multiplier_Modifier = 0;
	(*this).endurance_Modifier = 0;
	(*this).endurance_Multiplier_Modifier = 0;
	(*this).intelligence_Modifier = 0;
	(*this).intelligence_Multiplier_Modifier = 0;
	(*this).perception_Modifier = 0;
	(*this).perception_Multiplier_Modifier = 0;

	(*this).carrying_Capacity_Modifier = 0;
	(*this).carrying_Capacity_Multiplier_Modifier = 0;

	(*this).vision_Range_Modifier = 0;
	(*this).vision_Range_Multiplier_Modifier = 0;
	(*this).hearing_Range_Modifier = 0;
	(*this).hearing_Range_Multiplier_Modifier = 0;

	(*this).physical_Attack_Range_Modifier = 0;
	(*this).physical_Attack_Range_Multiplier_Modifier = 0;
	(*this).physical_Damage_Modifier = 0;
	(*this).physical_Damage_Multiplier_Modifier = 0;
	(*this).rate_Of_Physical_Attacks_Modifier = 0;
	(*this).rate_Of_Physical_Attacks_Multiplier_Modifier = 0;
	(*this).physical_Accuracy_Modifier = 0;
	(*this).physical_Accuracy_Multiplier_Modifier = 0;

	(*this).magical_Attack_Range_Modifier = 0;
	(*this).magical_Attack_Range_Multiplier_Modifier = 0;
	(*this).magical_Damage_Modifier = 0;
	(*this).magical_Damage_Multiplier_Modifier = 0;
	(*this).rate_Of_Magical_Attacks_Modifier = 0;
	(*this).rate_Of_Magical_Attacks_Multiplier_Modifier = 0;
	(*this).magical_Accuracy_Modifier = 0;
	(*this).magical_Accuracy_Multiplier_Modifier = 0;

	(*this).movement_Speed_Modifier = 0;
	(*this).movement_Speed_Multiplier_Modifier = 0;

	(*this).maximum_Stamina_Modifier = 0;
	(*this).maximum_Stamina_Multiplier_Modifier = 0;
	(*this).rate_Of_Stamina_Regeneration_Modifier = 0;
	(*this).rate_Of_Stamina_Regeneration_Multiplier_Modifier = 0;

	(*this).maximum_Mana_Modifier = 0;
	(*this).maximum_Mana_Multiplier_Modifier = 0;
	(*this).rate_Of_Mana_Regeneration_Modifier = 0;
	(*this).rate_Of_Mana_Regeneration_Multiplier_Modifier = 0;

	(*this).maximum_Health_Modifier = 0;
	(*this).maximum_Health_Multiplier_Modifier = 0;
	(*this).rate_Of_Health_Regeneration_Modifier = 0;
	(*this).rate_Of_Health_Regeneration_Multiplier_Modifier = 0;

	(*this).physical_Defense_Modifier = 0;
	(*this).physical_Defense_Multiplier_Modifier = 0;
	(*this).magical_Defense_Modifier = 0;
	(*this).magical_Defense_Multiplier_Modifier = 0;
	(*this).block_Chance_Modifier = 0;
	(*this).block_Chance_Multiplier_Modifier = 0;
	(*this).evasion_Modifier = 0;
	(*this).evasion_Multiplier_Modifier = 0;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

void Status_Effect::display_Information() const
{
}

void Status_Effect::update()
{
}

Status_Effect_States Status_Effect::get_Status_Effect_State() const
{
	return (*this).status_Effect_State;
}

void Status_Effect::set_Status_Effect_State(const Status_Effect_States status_Effect_State)
{
	(*this).status_Effect_State = status_Effect_State;
}

float Status_Effect::get_Strength_Modifier() const
{
	return (*this).strength_Modifier;
}

void Status_Effect::set_Strength_Modifier(const float strength_Modifier)
{
	(*this).strength_Modifier = strength_Modifier;
}

float Status_Effect::get_Strength_Multiplier_Modifier() const
{
	return (*this).strength_Multiplier_Modifier;
}

void Status_Effect::set_Strength_Multiplier_Modifier(const float strength_Multiplier_Modifier)
{
	(*this).strength_Multiplier_Modifier = strength_Multiplier_Modifier;
}

float Status_Effect::get_Dexterity_Modifier() const
{
	return (*this).dexterity_Modifier;
}

void Status_Effect::set_Dexterity_Modifier(const float dexterity_Modifier)
{
	(*this).dexterity_Modifier = dexterity_Modifier;
}

float Status_Effect::get_Dexterity_Multiplier_Modifier() const
{
	return (*this).dexterity_Multiplier_Modifier;
}

void Status_Effect::set_Dexterity_Multiplier_Modifier(const float dexterity_Multiplier_Modifier)
{
	(*this).dexterity_Multiplier_Modifier = dexterity_Multiplier_Modifier;
}

float Status_Effect::get_Endurance_Modifier() const
{
	return (*this).endurance_Modifier;
}

void Status_Effect::set_Endurance_Modifier(const float endurance_Modifier)
{
	(*this).endurance_Modifier = endurance_Modifier;
}

float Status_Effect::get_Endurance_Multiplier_Modifier() const
{
	return (*this).endurance_Multiplier_Modifier;
}

void Status_Effect::set_Endurance_Multiplier_Modifier(const float endurance_Multiplier_Modifier)
{
	(*this).endurance_Multiplier_Modifier = endurance_Multiplier_Modifier;
}

float Status_Effect::get_Intelligence_Modifier() const
{
	return (*this).intelligence_Modifier;
}

void Status_Effect::set_Intelligence_Modifier(const float intelligence_Modifier)
{
	(*this).intelligence_Modifier = intelligence_Modifier;
}

float Status_Effect::get_Intelligence_Multiplier_Modifier() const
{
	return (*this).intelligence_Multiplier_Modifier;
}

void Status_Effect::set_Intelligence_Multiplier_Modifier(const float intelligence_Multiplier_Modifier)
{
	(*this).intelligence_Multiplier_Modifier = intelligence_Multiplier_Modifier;
}

float Status_Effect::get_Perception_Modifier() const
{
	return (*this).perception_Modifier;
}

void Status_Effect::set_Perception_Modifier(const float perception_Modifier)
{
	(*this).perception_Modifier = perception_Modifier;
}

float Status_Effect::get_Perception_Multiplier_Modifier() const
{
	return (*this).perception_Multiplier_Modifier;
}

void Status_Effect::set_Perception_Multiplier_Modifier(const float perception_Multiplier_Modifier)
{
	(*this).perception_Multiplier_Modifier = perception_Multiplier_Modifier;
}

float Status_Effect::get_Carrying_Capacity_Modifier() const
{
	return (*this).carrying_Capacity_Modifier;
}

void Status_Effect::set_Carrying_Capacity_Modifier(const float carrying_Capacity_Modifier)
{
	(*this).carrying_Capacity_Modifier = carrying_Capacity_Modifier;
}

float Status_Effect::get_Carrying_Capacity_Multiplier_Modifier() const
{
	return (*this).carrying_Capacity_Multiplier_Modifier;
}

void Status_Effect::set_Carrying_Capacity_Multiplier_Modifier(const float carrying_Capacity_Multiplier_Modifier)
{
	(*this).carrying_Capacity_Multiplier_Modifier = carrying_Capacity_Multiplier_Modifier;
}

float Status_Effect::get_Vision_Range_Modifier() const
{
	return (*this).vision_Range_Modifier;
}

void Status_Effect::set_Vision_Range_Modifier(const float vision_Range_Modifier)
{
	(*this).vision_Range_Modifier = vision_Range_Modifier;
}

float Status_Effect::get_Vision_Range_Multiplier_Modifier() const
{
	return (*this).vision_Range_Multiplier_Modifier;
}

void Status_Effect::set_Vision_Range_Multiplier_Modifier(const float vision_Range_Multiplier_Modifier)
{
	(*this).vision_Range_Multiplier_Modifier = vision_Range_Multiplier_Modifier;
}

float Status_Effect::get_Hearing_Range_Modifier() const
{
	return (*this).hearing_Range_Modifier;
}

void Status_Effect::set_Hearing_Range_Modifier(const float hearing_Range_Modifier)
{
	(*this).hearing_Range_Modifier = hearing_Range_Modifier;
}

float Status_Effect::get_Hearing_Range_Multiplier_Modifier() const
{
	return (*this).hearing_Range_Multiplier_Modifier;
}

void Status_Effect::set_Hearing_Range_Multiplier_Modifier(const float hearing_Range_Multiplier_Modifier)
{
	(*this).hearing_Range_Multiplier_Modifier = hearing_Range_Multiplier_Modifier;
}

float Status_Effect::get_Physical_Attack_Range_Modifier() const
{
	return (*this).physical_Attack_Range_Modifier;
}

void Status_Effect::set_Physical_Attack_Range_Modifier(const float physical_Attack_Range_Modifier)
{
	(*this).physical_Attack_Range_Modifier = physical_Attack_Range_Modifier;
}

float Status_Effect::get_Physical_Attack_Range_Multiplier_Modifier() const
{
	return (*this).physical_Attack_Range_Multiplier_Modifier;
}

void Status_Effect::set_Physical_Attack_Range_Multiplier_Modifier(const float physical_Attack_Range_Multiplier_Modifier)
{
	(*this).physical_Attack_Range_Multiplier_Modifier = physical_Attack_Range_Multiplier_Modifier;
}

float Status_Effect::get_Physical_Damage_Modifier() const
{
	return (*this).physical_Damage_Modifier;
}

void Status_Effect::set_Physical_Damage_Modifier(const float physical_Damage_Modifier)
{
	(*this).physical_Damage_Modifier = physical_Damage_Modifier;
}

float Status_Effect::get_Physical_Damage_Multiplier_Modifier() const
{
	return (*this).physical_Damage_Multiplier_Modifier;
}

void Status_Effect::set_Physical_Damage_Multiplier_Modifier(const float physical_Damage_Multiplier_Modifier)
{
	(*this).physical_Damage_Multiplier_Modifier = physical_Damage_Multiplier_Modifier;
}

float Status_Effect::get_Rate_Of_Physical_Attacks_Modifier() const
{
	return (*this).rate_Of_Physical_Attacks_Modifier;
}

void Status_Effect::set_Rate_Of_Physical_Attacks_Modifier(const float rate_Of_Physical_Attacks_Modifier)
{
	(*this).rate_Of_Physical_Attacks_Modifier = rate_Of_Physical_Attacks_Modifier;
}

float Status_Effect::get_Rate_Of_Physical_Attacks_Multiplier_Modifier() const
{
	return (*this).rate_Of_Physical_Attacks_Multiplier_Modifier;
}

void Status_Effect::set_Rate_Of_Physical_Attacks_Multiplier_Modifier(const float rate_Of_Physical_Attacks_Multiplier_Modifier)
{
	(*this).rate_Of_Physical_Attacks_Multiplier_Modifier = rate_Of_Physical_Attacks_Multiplier_Modifier;
}

float Status_Effect::get_Physical_Accuracy_Modifier() const
{
	return (*this).physical_Accuracy_Modifier;
}

void Status_Effect::set_Physical_Accuracy_Modifier(const float physical_Accuracy_Modifier)
{
	(*this).physical_Accuracy_Modifier = physical_Accuracy_Modifier;
}

float Status_Effect::get_Physical_Accuracy_Multiplier_Modifier() const
{
	return (*this).physical_Accuracy_Multiplier_Modifier;
}

void Status_Effect::set_Physical_Accuracy_Multiplier_Modifier(const float physical_Accuracy_Multiplier_Modifier)
{
	(*this).physical_Accuracy_Multiplier_Modifier = physical_Accuracy_Multiplier_Modifier;
}

float Status_Effect::get_Magical_Attack_Range_Modifier() const
{
	return (*this).magical_Attack_Range_Modifier;
}

void Status_Effect::set_Magical_Attack_Range_Modifier(const float magical_Attack_Range_Modifier)
{
	(*this).magical_Attack_Range_Modifier = magical_Attack_Range_Modifier;
}

float Status_Effect::get_Magical_Attack_Range_Multiplier_Modifier() const
{
	return (*this).magical_Attack_Range_Multiplier_Modifier;
}

void Status_Effect::set_Magical_Attack_Range_Multiplier_Modifier(const float magical_Attack_Range_Multiplier_Modifier)
{
	(*this).magical_Attack_Range_Multiplier_Modifier = magical_Attack_Range_Multiplier_Modifier;
}

float Status_Effect::get_Magical_Damage_Modifier() const
{
	return (*this).magical_Damage_Modifier;
}

void Status_Effect::set_Magical_Damage_Modifier(const float magical_Damage_Modifier)
{
	(*this).magical_Damage_Modifier = magical_Damage_Modifier;
}

float Status_Effect::get_Magical_Damage_Multiplier_Modifier() const
{
	return (*this).magical_Damage_Multiplier_Modifier;
}

void Status_Effect::set_Magical_Damage_Multiplier_Modifier(const float magical_Damage_Multiplier_Modifier)
{
	(*this).magical_Damage_Multiplier_Modifier = magical_Damage_Multiplier_Modifier;
}

float Status_Effect::get_Rate_Of_Magical_Attacks_Modifier() const
{
	return (*this).rate_Of_Magical_Attacks_Modifier;
}

void Status_Effect::set_Rate_Of_Magical_Attacks_Modifier(const float rate_Of_Magical_Attacks_Modifier)
{
	(*this).rate_Of_Magical_Attacks_Modifier = rate_Of_Magical_Attacks_Modifier;
}

float Status_Effect::get_Rate_Of_Magical_Attacks_Multiplier_Modifier() const
{
	return (*this).rate_Of_Magical_Attacks_Multiplier_Modifier;
}

void Status_Effect::set_Rate_Of_Magical_Attacks_Multiplier_Modifier(const float rate_Of_Magical_Attacks_Multiplier_Modifier)
{
	(*this).rate_Of_Magical_Attacks_Multiplier_Modifier = rate_Of_Magical_Attacks_Multiplier_Modifier;
}

float Status_Effect::get_Magical_Accuracy_Modifier() const
{
	return (*this).magical_Accuracy_Modifier;
}

void Status_Effect::set_Magical_Accuracy_Modifier(const float magical_Accuracy_Modifier)
{
	(*this).magical_Accuracy_Modifier = magical_Accuracy_Modifier;
}

float Status_Effect::get_Magical_Accuracy_Multiplier_Modifier() const
{
	return (*this).magical_Accuracy_Multiplier_Modifier;
}

void Status_Effect::set_Magical_Accuracy_Multiplier_Modifier(const float magical_Accuracy_Multiplier_Modifier)
{
	(*this).magical_Accuracy_Multiplier_Modifier = magical_Accuracy_Multiplier_Modifier;
}

float Status_Effect::get_Movement_Speed_Modifier() const
{
	return (*this).movement_Speed_Modifier;
}

void Status_Effect::set_Movement_Speed_Modifier(const float movement_Speed_Modifier)
{
	(*this).movement_Speed_Modifier = movement_Speed_Modifier;
}

float Status_Effect::get_Movement_Speed_Multiplier_Modifier() const
{
	return (*this).movement_Speed_Multiplier_Modifier;
}

void Status_Effect::set_Movement_Speed_Multiplier_Modifier(const float movement_Speed_Multiplier_Modifier)
{
	(*this).movement_Speed_Multiplier_Modifier = movement_Speed_Multiplier_Modifier;
}

float Status_Effect::get_Maximum_Stamina_Modifier() const
{
	return (*this).maximum_Stamina_Modifier;
}

void Status_Effect::set_Maximum_Stamina_Modifier(const float maximum_Stamina_Modifier)
{
	(*this).maximum_Stamina_Modifier = maximum_Stamina_Modifier;
}

float Status_Effect::get_Maximum_Stamina_Multiplier_Modifier() const
{
	return (*this).maximum_Stamina_Multiplier_Modifier;
}

void Status_Effect::set_Maximum_Stamina_Multiplier_Modifier(const float maximum_Stamina_Multiplier_Modifier)
{
	(*this).maximum_Stamina_Multiplier_Modifier = maximum_Stamina_Multiplier_Modifier;
}

float Status_Effect::get_Rate_Of_Stamina_Regeneration_Modifier() const
{
	return (*this).rate_Of_Stamina_Regeneration_Modifier;
}

void Status_Effect::set_Rate_Of_Stamina_Regeneration_Modifier(const float rate_Of_Stamina_Regeneration_Modifier)
{
	(*this).rate_Of_Stamina_Regeneration_Modifier = rate_Of_Stamina_Regeneration_Modifier;
}

float Status_Effect::get_Rate_Of_Stamina_Regeneration_Multiplier_Modifier() const
{
	return (*this).rate_Of_Stamina_Regeneration_Multiplier_Modifier;
}

void Status_Effect::set_Rate_Of_Stamina_Regeneration_Multiplier_Modifier(const float rate_Of_Stamina_Regeneration_Multiplier_Modifier)
{
	(*this).rate_Of_Stamina_Regeneration_Multiplier_Modifier = rate_Of_Stamina_Regeneration_Multiplier_Modifier;
}

float Status_Effect::get_Maximum_Mana_Modifier() const
{
	return (*this).maximum_Mana_Modifier;
}

void Status_Effect::set_Maximum_Mana_Modifier(const float maximum_Mana_Modifier)
{
	(*this).maximum_Mana_Modifier = maximum_Mana_Modifier;
}

float Status_Effect::get_Maximum_Mana_Multiplier_Modifier() const
{
	return (*this).maximum_Mana_Multiplier_Modifier;
}

void Status_Effect::set_Maximum_Mana_Multiplier_Modifier(const float maximum_Mana_Multiplier_Modifier)
{
	(*this).maximum_Mana_Multiplier_Modifier = maximum_Mana_Multiplier_Modifier;
}

float Status_Effect::get_Rate_Of_Mana_Regeneration_Modifier() const
{
	return (*this).rate_Of_Mana_Regeneration_Modifier;
}

void Status_Effect::set_Rate_Of_Mana_Regeneration_Modifier(const float rate_Of_Mana_Regeneration_Modifier)
{
	(*this).rate_Of_Mana_Regeneration_Modifier = rate_Of_Mana_Regeneration_Modifier;
}

float Status_Effect::get_Rate_Of_Mana_Regeneration_Multiplier_Modifier() const
{
	return (*this).rate_Of_Mana_Regeneration_Multiplier_Modifier;
}

void Status_Effect::set_Rate_Of_Mana_Regeneration_Multiplier_Modifier(const float rate_Of_Mana_Regeneration_Multiplier_Modifier)
{
	(*this).rate_Of_Mana_Regeneration_Multiplier_Modifier = rate_Of_Mana_Regeneration_Multiplier_Modifier;
}

float Status_Effect::get_Maximum_Health_Modifier() const
{
	return (*this).maximum_Health_Modifier;
}

void Status_Effect::set_Maximum_Health_Modifier(const float maximum_Health_Modifier)
{
	(*this).maximum_Health_Modifier = maximum_Health_Modifier;
}

float Status_Effect::get_Maximum_Health_Multiplier_Modifier() const
{
	return (*this).maximum_Health_Multiplier_Modifier;
}

void Status_Effect::set_Maximum_Health_Multiplier_Modifier(const float maximum_Health_Multiplier_Modifier)
{
	(*this).maximum_Health_Multiplier_Modifier = maximum_Health_Multiplier_Modifier;
}

float Status_Effect::get_Rate_Of_Health_Regeneration_Modifier() const
{
	return (*this).rate_Of_Health_Regeneration_Modifier;
}

void Status_Effect::set_Rate_Of_Health_Regeneration_Modifier(const float rate_Of_Health_Regeneration_Modifier)
{
	(*this).rate_Of_Health_Regeneration_Modifier = rate_Of_Health_Regeneration_Modifier;
}

float Status_Effect::get_Rate_Of_Health_Regeneration_Multiplier_Modifier() const
{
	return (*this).rate_Of_Health_Regeneration_Multiplier_Modifier;
}

void Status_Effect::set_Rate_Of_Health_Regeneration_Multiplier_Modifier(const float rate_Of_Health_Regeneration_Multiplier_Modifier)
{
	(*this).rate_Of_Health_Regeneration_Multiplier_Modifier = rate_Of_Health_Regeneration_Multiplier_Modifier;
}

float Status_Effect::get_Physical_Defense_Modifier() const
{
	return (*this).physical_Defense_Modifier;
}

void Status_Effect::set_Physical_Defense_Modifier(const float physical_Defense_Modifier)
{
	(*this).physical_Defense_Modifier = physical_Defense_Modifier;
}

float Status_Effect::get_Physical_Defense_Multiplier_Modifier() const
{
	return (*this).physical_Defense_Multiplier_Modifier;
}

void Status_Effect::set_Physical_Defense_Multiplier_Modifier(const float physical_Defense_Multiplier_Modifier)
{
	(*this).physical_Defense_Multiplier_Modifier = physical_Defense_Multiplier_Modifier;
}

float Status_Effect::get_Magical_Defense_Modifier() const
{
	return (*this).magical_Defense_Modifier;
}

void Status_Effect::set_Magical_Defense_Modifier(const float magical_Defense_Modifier)
{
	(*this).magical_Defense_Modifier = magical_Defense_Modifier;
}

float Status_Effect::get_Magical_Defense_Multiplier_Modifier() const
{
	return (*this).magical_Defense_Multiplier_Modifier;
}

void Status_Effect::set_Magical_Defense_Multiplier_Modifier(const float magical_Defense_Multiplier_Modifier)
{
	(*this).magical_Defense_Multiplier_Modifier = magical_Defense_Multiplier_Modifier;
}

float Status_Effect::get_Block_Chance_Modifier() const
{
	return (*this).block_Chance_Modifier;
}

void Status_Effect::set_Block_Chance_Modifier(const float block_Chance_Modifier)
{
	(*this).block_Chance_Modifier = block_Chance_Modifier;
}

float Status_Effect::get_Block_Chance_Multiplier_Modifier() const
{
	return (*this).block_Chance_Multiplier_Modifier;
}

void Status_Effect::set_Block_Chance_Multiplier_Modifier(const float block_Chance_Multiplier_Modifier)
{
	(*this).block_Chance_Multiplier_Modifier = block_Chance_Multiplier_Modifier;
}

float Status_Effect::get_Evasion_Modifier() const
{
	return (*this).evasion_Modifier;
}

void Status_Effect::set_Evasion_Modifier(const float evasion_Modifier)
{
	(*this).evasion_Modifier = evasion_Modifier;
}

float Status_Effect::get_Evasion_Multiplier_Modifier() const
{
	return (*this).evasion_Multiplier_Modifier;
}

void Status_Effect::set_Evasion_Multiplier_Modifier(const float evasion_Multiplier_Modifier)
{
	(*this).evasion_Multiplier_Modifier = evasion_Multiplier_Modifier;
}

std::uint16_t Status_Effect::get_Containing_Object_Pointer_Vector_Index() const
{
	return (*this).containing_Object_Pointer_Vector_Index;
}

void Status_Effect::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}

std::uint8_t Status_Effect::get_Active_Status_Effects_Index() const
{
	return (*this).active_Status_Effects_Index;
}

void Status_Effect::set_Active_Status_Effects_Index(const std::uint8_t active_Status_Effects_Index)
{
	(*this).active_Status_Effects_Index = active_Status_Effects_Index;
}
