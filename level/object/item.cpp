//Item cpp file
#include "item.h"

//Default Item constructor
Item::Item()
{
	std::cout << "Default Item constructor" << std::endl;

	(*this).item_State = Item_States::On_Ground;

	(*this).strength_Modifier = 10;
	(*this).dexterity_Modifier = 0;
	(*this).endurance_Modifier = 0;
	(*this).intelligence_Modifier = 0;
	(*this).perception_Modifier = 0;

	(*this).level = 1;

	(*this).durability = 1;

	(*this).carrying_Capacity_Modifier = 0;
	(*this).weight = 0;

	(*this).vision_Range_Modifier = 0;
	(*this).hearing_Range_Modifier = 0;

	(*this).physical_Attack_Range_Modifier = 0;
	(*this).physical_Damage_Modifier = 0;
	(*this).rate_Of_Physical_Attacks_Modifier = 0;
	(*this).physical_Accuracy_Modifier = 0;

	(*this).magical_Attack_Range_Modifier = 0;
	(*this).magical_Damage_Modifier = 0;
	(*this).rate_Of_Magical_Attacks_Modifier = 0;
	(*this).magical_Accuracy_Modifier = 0;

	(*this).movement_Speed_Modifier = 0;

	(*this).maximum_Stamina_Modifier = 0;
	(*this).rate_Of_Stamina_Regeneration_Modifier = 0;
	(*this).stamina_Consumed_On_Use = 0;

	(*this).maximum_Mana_Modifier = 0;
	(*this).rate_Of_Mana_Regeneration_Modifier = 0;
	(*this).mana_Consumed_On_Use = 0;

	(*this).maximum_Health_Modifier = 0;
	(*this).rate_Of_Health_Regeneration_Modifier = 0;
	(*this).health_Consumed_On_Use = 0;

	(*this).physical_Defense_Modifier = 0;
	(*this).magical_Defense_Modifier = 0;
	(*this).block_Chance_Modifier = 0;
	(*this).evasion_Modifier = 0;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

void Item::display_Information() const
{
	std::cout << "item_State : " << static_cast<uint8_t>((*this).item_State) << std::endl;
}

//'Getters' and 'Setters' for private member variables
Item_States Item::get_Item_State() const
{
	return (*this).item_State;
}

void Item::set_Item_State(const Item_States item_State)
{
	(*this).item_State = item_State;
}

float Item::get_Strength_Modifier() const
{
	return (*this).strength_Modifier;
}

void Item::set_Strength_Modifier(const float strength_Modifier)
{
	(*this).strength_Modifier = strength_Modifier;
}

float Item::get_Dexterity_Modifier() const
{
	return (*this).dexterity_Modifier;
}

void Item::set_Dexterity_Modifier(const float dexterity_Modifier)
{
	(*this).dexterity_Modifier = dexterity_Modifier;
}

float Item::get_Endurance_Modifier() const
{
	return (*this).endurance_Modifier;
}

void Item::set_Endurance_Modifier(const float endurance_Modifier)
{
	(*this).endurance_Modifier = endurance_Modifier;
}

float Item::get_Intelligence_Modifier() const
{
	return (*this).intelligence_Modifier;
}

void Item::set_Intelligence_Modifier(const float intelligence_Modifier)
{
	(*this).intelligence_Modifier = intelligence_Modifier;
}

float Item::get_Perception_Modifier() const
{
	return (*this).perception_Modifier;
}

void Item::set_Perception_Modifier(const float perception_Modifier)
{
	(*this).perception_Modifier = perception_Modifier;
}

float Item::get_Level() const
{
	return (*this).level;
}

void Item::set_Level(const float level)
{
	(*this).level = level;
}

float Item::get_Durability() const
{
	return (*this).durability;
}

void Item::set_Durability(const float durability)
{
	(*this).durability = durability;
}

float Item::get_Carrying_Capacity_Modifier() const
{
	return (*this).carrying_Capacity_Modifier;
}

void Item::set_Carrying_Capacity_Modifier(const float carrying_Capacity_Modifier)
{
	(*this).carrying_Capacity_Modifier = carrying_Capacity_Modifier;
}

float Item::get_Weight() const
{
	return (*this).weight;
}

void Item::set_Weight(const float weight)
{
	(*this).weight = weight;
}

float Item::get_Vision_Range_Modifier() const
{
	return (*this).vision_Range_Modifier;
}

void Item::set_Vision_Range_Modifier(const float vision_Range_Modifier)
{
	(*this).vision_Range_Modifier = vision_Range_Modifier;
}

float Item::get_Hearing_Range_Modifier() const
{
	return (*this).hearing_Range_Modifier;
}

void Item::set_Hearing_Range_Modifier(const float hearing_Range_Modifier)
{
	(*this).hearing_Range_Modifier = hearing_Range_Modifier;
}

float Item::get_Physical_Attack_Range_Modifier() const
{
	return (*this).physical_Attack_Range_Modifier;
}

void Item::set_Physical_Attack_Range_Modifier(const float physical_Attack_Range_Modifier)
{
	(*this).physical_Attack_Range_Modifier = physical_Attack_Range_Modifier;
}

float Item::get_Physical_Damage_Modifier() const
{
	return (*this).physical_Damage_Modifier;
}

void Item::set_Physical_Damage_Modifier(const float physical_Damage_Modifier)
{
	(*this).physical_Damage_Modifier = physical_Damage_Modifier;
}

float Item::get_Rate_Of_Physical_Attacks_Modifier() const
{
	return (*this).rate_Of_Physical_Attacks_Modifier;
}

void Item::set_Rate_Of_Physical_Attacks_Modifier(const float rate_Of_Physical_Attacks_Modifier)
{
	(*this).rate_Of_Physical_Attacks_Modifier = rate_Of_Physical_Attacks_Modifier;
}

float Item::get_Physical_Accuracy_Modifier() const
{
	return (*this).physical_Accuracy_Modifier;
}

void Item::set_Physical_Accuracy_Modifier(const float physical_Accuracy_Modifier)
{
	(*this).physical_Accuracy_Modifier = physical_Accuracy_Modifier;
}

float Item::get_Magical_Attack_Range_Modifier() const
{
	return (*this).magical_Attack_Range_Modifier;
}

void Item::set_Magical_Attack_Range_Modifier(const float magical_Attack_Range_Modifier)
{
	(*this).magical_Attack_Range_Modifier = magical_Attack_Range_Modifier;
}

float Item::get_Magical_Damage_Modifier() const
{
	return (*this).magical_Damage_Modifier;
}

void Item::set_Magical_Damage_Modifier(const float magical_Damage_Modifier)
{
	(*this).magical_Damage_Modifier = magical_Damage_Modifier;
}

float Item::get_Rate_Of_Magical_Attacks_Modifier() const
{
	return (*this).rate_Of_Magical_Attacks_Modifier;
}

void Item::set_Rate_Of_Magical_Attacks_Modifier(const float rate_Of_Magical_Attacks_Modifier)
{
	(*this).rate_Of_Magical_Attacks_Modifier = rate_Of_Magical_Attacks_Modifier;
}

float Item::get_Magical_Accuracy_Modifier() const
{
	return (*this).magical_Accuracy_Modifier;
}

void Item::set_Magical_Accuracy_Modifier(const float magical_Accuracy_Modifier)
{
	(*this).magical_Accuracy_Modifier = magical_Accuracy_Modifier;
}

float Item::get_Movement_Speed_Modifier() const
{
	return (*this).movement_Speed_Modifier;
}

void Item::set_Movement_Speed_Modifier(const float movement_Speed_Modifier)
{
	(*this).movement_Speed_Modifier = movement_Speed_Modifier;
}

float Item::get_Maximum_Stamina_Modifier() const
{
	return (*this).maximum_Stamina_Modifier;
}

void Item::set_Maximum_Stamina_Modifier(const float maximum_Stamina_Modifier)
{
	(*this).maximum_Stamina_Modifier = maximum_Stamina_Modifier;
}

float Item::get_Rate_Of_Stamina_Regeneration_Modifier() const
{
	return (*this).rate_Of_Stamina_Regeneration_Modifier;
}

void Item::set_Rate_Of_Stamina_Regeneration_Modifier(const float rate_Of_Stamina_Regeneration_Modifier)
{
	(*this).rate_Of_Stamina_Regeneration_Modifier = rate_Of_Stamina_Regeneration_Modifier;
}

float Item::get_Stamina_Consumed_On_Use() const
{
	return (*this).stamina_Consumed_On_Use;
}

void Item::set_Stamina_Consumed_On_Use(const float stamina_Consumed_On_Use)
{
	(*this).stamina_Consumed_On_Use = stamina_Consumed_On_Use;
}

float Item::get_Maximum_Mana_Modifier() const
{
	return (*this).maximum_Mana_Modifier;
}

void Item::set_Maximum_Mana_Modifier(const float maximum_Mana_Modifier)
{
	(*this).maximum_Mana_Modifier = maximum_Mana_Modifier;
}

float Item::get_Rate_Of_Mana_Regeneration_Modifier() const
{
	return (*this).rate_Of_Mana_Regeneration_Modifier;
}

void Item::set_Rate_Of_Mana_Regeneration_Modifier(const float rate_Of_Mana_Regeneration_Modifier)
{
	(*this).rate_Of_Mana_Regeneration_Modifier = rate_Of_Mana_Regeneration_Modifier;
}

float Item::get_Mana_Consumed_On_Use() const
{
	return (*this).mana_Consumed_On_Use;
}

void Item::set_Mana_Consumed_On_Use(const float mana_Consumed_On_Use)
{
	(*this).mana_Consumed_On_Use = mana_Consumed_On_Use;
}

float Item::get_Maximum_Health_Modifier() const
{
	return (*this).maximum_Health_Modifier;
}

void Item::set_Maximum_Health_Modifier(const float maximum_Health_Modifier)
{
	(*this).maximum_Health_Modifier = maximum_Health_Modifier;
}

float Item::get_Rate_Of_Health_Regeneration_Modifier() const
{
	return (*this).rate_Of_Health_Regeneration_Modifier;
}

void Item::set_Rate_Of_Health_Regeneration_Modifier(const float rate_Of_Health_Regeneration_Modifier)
{
	(*this).rate_Of_Health_Regeneration_Modifier = rate_Of_Health_Regeneration_Modifier;
}

float Item::get_Health_Consumed_On_Use() const
{
	return (*this).health_Consumed_On_Use;
}

void Item::set_Health_Consumed_On_Use(const float health_Consumed_On_Use)
{
	(*this).health_Consumed_On_Use = health_Consumed_On_Use;
}

float Item::get_Physical_Defense_Modifier() const
{
	return (*this).physical_Defense_Modifier;
}

void Item::set_Physical_Defense_Modifier(const float physical_Defense_Modifier)
{
	(*this).physical_Defense_Modifier = physical_Defense_Modifier;
}

float Item::get_Magical_Defense_Modifier() const
{
	return (*this).magical_Defense_Modifier;
}

void Item::set_Magical_Defense_Modifier(const float magical_Defense_Modifier)
{
	(*this).magical_Defense_Modifier = magical_Defense_Modifier;
}

float Item::get_Block_Chance_Modifier() const
{
	return (*this).block_Chance_Modifier;
}

void Item::set_Block_Chance_Modifier(const float block_Chance_Modifier)
{
	(*this).block_Chance_Modifier = block_Chance_Modifier;
}

float Item::get_Evasion_Modifier() const
{
	return (*this).evasion_Modifier;
}

void Item::set_Evasion_Modifier(const float evasion_Modifier)
{
	(*this).evasion_Modifier = evasion_Modifier;
}

std::uint16_t Item::get_Containing_Object_Pointer_Vector_Index() const
{
	return (*this).containing_Object_Pointer_Vector_Index;
}

void Item::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}
