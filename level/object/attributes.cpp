//Attributes cpp file; friend of Object class
#include "attributes.h"

//Initialization of static Attributes members
float Attributes::carrying_Capacity_Per_Strength = 0;
float Attributes::carrying_Capacity_Per_Endurance = 0;
float Attributes::vision_Range_Per_Perception = 0;
float Attributes::hearing_Range_Per_Perception = 0;
float Attributes::physical_Damage_Per_Strength = 0;
float Attributes::rate_Of_Physical_Attacks_Per_Dexterity = 0;
float Attributes::physical_Accuracy_Per_Dexterity = 0;
float Attributes::physical_Accuracy_Per_Perception = 0;
float Attributes::magical_Damage_Per_Intelligence = 0;
float Attributes::rate_Of_Magical_Attacks_Per_Dexterity = 0;
float Attributes::magical_Accuracy_Per_Dexterity = 0;
float Attributes::magical_Accuracy_Per_Perception = 0;
float Attributes::movement_Speed_Per_Dexterity = 0;
float Attributes::maximum_Stamina_Per_Endurance = 0;
float Attributes::rate_Of_Stamina_Regeneration_Per_Endurance = 0;
float Attributes::maximum_Mana_Per_Intelligence = 0;
float Attributes::rate_Of_Mana_Regeneration_Per_Intelligence = 0;
float Attributes::maximum_Health_Per_Endurance = 0;
float Attributes::rate_Of_Health_Regeneration_Per_Endurance = 0;
float Attributes::physical_Defense_Per_Endurance = 0;
float Attributes::magical_Defense_Per_Endurance = 0;
float Attributes::block_Chance_Per_Dexterity = 0;
float Attributes::block_Chance_Per_Perception = 0;
float Attributes::evasion_Per_Dexterity = 0;
float Attributes::evasion_Per_Perception = 0;

//Default Attributes constructor
Attributes::Attributes()
{
	std::cout << "Default Attributes constructor" << std::endl;

	(*this).containing_Object_Pointer_Vector_Index = 0;

	(*this).strength = 1;
	(*this).dexterity = 1;
	(*this).endurance = 1;
	(*this).intelligence = 1;
	(*this).perception = 1;

	(*this).experience = 0;
	(*this).level = 1;

	(*this).carrying_Capacity = 1;
	(*this).amount_Carried = 0;

	(*this).vision_Range = 1;
	(*this).hearing_Range = 1;

	(*this).physical_Attack_Range = 0;
	(*this).physical_Damage = 1;
	(*this).rate_Of_Physical_Attacks = 1;
	(*this).physical_Accuracy = 1;

	(*this).magical_Attack_Range = 0;
	(*this).magical_Damage = 0;
	(*this).rate_Of_Magical_Attacks = 1;
	(*this).magical_Accuracy = 1;

	(*this).movement_Speed = 1;

	(*this).maximum_Stamina = 1;
	(*this).stamina = 1;
	(*this).rate_Of_Stamina_Regeneration = 1;

	(*this).maximum_Mana = 1;
	(*this).mana = 1;
	(*this).rate_Of_Mana_Regeneration = 1;

	(*this).maximum_Health = 1;
	(*this).health = 1;
	(*this).rate_Of_Health_Regeneration = 1;

	(*this).physical_Defense = 0;
	(*this).magical_Defense = 0;
	(*this).block_Chance = 0;
	(*this).evasion = 0;
}

float Attributes::get_Carrying_Capacity_Per_Strength()
{
	return Attributes::carrying_Capacity_Per_Strength;
}

void Attributes::set_Carrying_Capacity_Per_Strength(const float carrying_Capacity_Per_Strength)
{
	Attributes::carrying_Capacity_Per_Strength = carrying_Capacity_Per_Strength;
}

float Attributes::get_Carrying_Capacity_Per_Endurance()
{
	return Attributes::carrying_Capacity_Per_Endurance;
}

void Attributes::set_Carrying_Capacity_Per_Endurance(const float carrying_Capacity_Per_Endurance)
{
	Attributes::carrying_Capacity_Per_Endurance = carrying_Capacity_Per_Endurance;
}

float Attributes::get_Vision_Range_Per_Perception()
{
	return Attributes::vision_Range_Per_Perception;
}

void Attributes::set_Vision_Range_Per_Perception(const float vision_Range_Per_Perception)
{
	Attributes::vision_Range_Per_Perception = vision_Range_Per_Perception;
}

float Attributes::get_Hearing_Range_Per_Perception()
{
	return Attributes::hearing_Range_Per_Perception;
}

void Attributes::set_Hearing_Range_Per_Perception(const float hearing_Range_Per_Perception)
{
	Attributes::hearing_Range_Per_Perception = hearing_Range_Per_Perception;
}

float Attributes::get_Physical_Damage_Per_Strength()
{
	return Attributes::physical_Damage_Per_Strength;
}

void Attributes::set_Physical_Damage_Per_Strength(const float physical_Damage_Per_Strength)
{
	Attributes::physical_Damage_Per_Strength = physical_Damage_Per_Strength;
}

float Attributes::get_Rate_Of_Physical_Attacks_Per_Dexterity()
{
	return Attributes::rate_Of_Physical_Attacks_Per_Dexterity;
}

void Attributes::set_Rate_Of_Physical_Attacks_Per_Dexterity(const float rate_Of_Physical_Attacks_Per_Dexterity)
{
	Attributes::rate_Of_Physical_Attacks_Per_Dexterity = rate_Of_Physical_Attacks_Per_Dexterity;
}

float Attributes::get_Physical_Accuracy_Per_Dexterity()
{
	return Attributes::physical_Accuracy_Per_Dexterity;
}

void Attributes::set_Physical_Accuracy_Per_Dexterity(const float physical_Accuracy_Per_Dexterity)
{
	Attributes::physical_Accuracy_Per_Dexterity = physical_Accuracy_Per_Dexterity;
}

float Attributes::get_Physical_Accuracy_Per_Perception()
{
	return Attributes::physical_Accuracy_Per_Perception;
}

void Attributes::set_Physical_Accuracy_Per_Perception(const float physical_Accuracy_Per_Perception)
{
	Attributes::physical_Accuracy_Per_Perception = physical_Accuracy_Per_Perception;
}

float Attributes::get_Magical_Damage_Per_Intelligence()
{
	return Attributes::magical_Damage_Per_Intelligence;
}

void Attributes::set_Magical_Damage_Per_Intelligence(const float magical_Damage_Per_Intelligence)
{
	Attributes::magical_Damage_Per_Intelligence = magical_Damage_Per_Intelligence;
}

float Attributes::get_Rate_Of_Magical_Attacks_Per_Dexterity()
{
	return Attributes::rate_Of_Magical_Attacks_Per_Dexterity;
}

void Attributes::set_Rate_Of_Magical_Attacks_Per_Dexterity(const float rate_Of_Magical_Attacks_Per_Dexterity)
{
	Attributes::rate_Of_Magical_Attacks_Per_Dexterity = rate_Of_Magical_Attacks_Per_Dexterity;
}

float Attributes::get_Magical_Accuracy_Per_Dexterity()
{
	return Attributes::magical_Accuracy_Per_Dexterity;
}

void Attributes::set_Magical_Accuracy_Per_Dexterity(const float magical_Accuracy_Per_Dexterity)
{
	Attributes::magical_Accuracy_Per_Dexterity = magical_Accuracy_Per_Dexterity;
}

float Attributes::get_Magical_Accuracy_Per_Perception()
{
	return Attributes::magical_Accuracy_Per_Perception;
}

void Attributes::set_Magical_Accuracy_Per_Perception(const float magical_Accuracy_Per_Perception)
{
	Attributes::magical_Accuracy_Per_Perception = magical_Accuracy_Per_Perception;
}

float Attributes::get_Movement_Speed_Per_Dexterity()
{
	return Attributes::movement_Speed_Per_Dexterity;
}

void Attributes::set_Movement_Speed_Per_Dexterity(const float movement_Speed_Per_Dexterity)
{
	Attributes::movement_Speed_Per_Dexterity = movement_Speed_Per_Dexterity;
}

float Attributes::get_Maximum_Stamina_Per_Endurance()
{
	return Attributes::maximum_Stamina_Per_Endurance;
}

void Attributes::set_Maximum_Stamina_Per_Endurance(const float maximum_Stamina_Per_Endurance)
{
	Attributes::maximum_Stamina_Per_Endurance = maximum_Stamina_Per_Endurance;
}

float Attributes::get_Rate_Of_Stamina_Regeneration_Per_Endurance()
{
	return Attributes::rate_Of_Stamina_Regeneration_Per_Endurance;
}

void Attributes::set_Rate_Of_Stamina_Regeneration_Per_Endurance(const float rate_Of_Stamina_Regeneration_Per_Endurance)
{
	Attributes::rate_Of_Stamina_Regeneration_Per_Endurance = rate_Of_Stamina_Regeneration_Per_Endurance;
}

float Attributes::get_Maximum_Mana_Per_Intelligence()
{
	return Attributes::maximum_Mana_Per_Intelligence;
}

void Attributes::set_Maximum_Mana_Per_Intelligence(const float maximum_Mana_Per_Intelligence)
{
	Attributes::maximum_Mana_Per_Intelligence = maximum_Mana_Per_Intelligence;
}

float Attributes::get_Rate_Of_Mana_Regeneration_Per_Intelligence()
{
	return Attributes::rate_Of_Mana_Regeneration_Per_Intelligence;
}

void Attributes::set_Rate_Of_Mana_Regeneration_Per_Intelligence(const float rate_Of_Mana_Regeneration_Per_Intelligence)
{
	Attributes::rate_Of_Mana_Regeneration_Per_Intelligence = rate_Of_Mana_Regeneration_Per_Intelligence;
}

float Attributes::get_Maximum_Health_Per_Endurance()
{
	return Attributes::maximum_Health_Per_Endurance;
}

void Attributes::set_Maximum_Health_Per_Endurance(const float maximum_Health_Per_Endurance)
{
	Attributes::maximum_Health_Per_Endurance = maximum_Health_Per_Endurance;
}

float Attributes::get_Rate_Of_Health_Regeneration_Per_Endurance()
{
	return Attributes::rate_Of_Health_Regeneration_Per_Endurance;
}

void Attributes::set_Rate_Of_Health_Regeneration_Per_Endurance(const float rate_Of_Health_Regeneration_Per_Endurance)
{
	Attributes::rate_Of_Health_Regeneration_Per_Endurance = rate_Of_Health_Regeneration_Per_Endurance;
}

float Attributes::get_Physical_Defense_Per_Endurance()
{
	return Attributes::physical_Defense_Per_Endurance;
}

void Attributes::set_Physical_Defense_Per_Endurance(const float physical_Defense_Per_Endurance)
{
	Attributes::physical_Defense_Per_Endurance = physical_Defense_Per_Endurance;
}

float Attributes::get_Magical_Defense_Per_Endurance()
{
	return Attributes::magical_Defense_Per_Endurance;
}

void Attributes::set_Magical_Defense_Per_Endurance(const float magical_Defense_Per_Endurance)
{
	Attributes::magical_Defense_Per_Endurance = magical_Defense_Per_Endurance;
}

float Attributes::get_Block_Chance_Per_Dexterity()
{
	return Attributes::block_Chance_Per_Dexterity;
}

void Attributes::set_Block_Chance_Per_Dexterity(const float block_Chance_Per_Dexterity)
{
	Attributes::block_Chance_Per_Dexterity = block_Chance_Per_Dexterity;
}

float Attributes::get_Block_Chance_Per_Perception()
{
	return Attributes::block_Chance_Per_Perception;
}

void Attributes::set_Block_Chance_Per_Perception(const float block_Chance_Per_Perception)
{
	Attributes::block_Chance_Per_Perception = block_Chance_Per_Perception;
}

float Attributes::get_Evasion_Per_Dexterity()
{
	return Attributes::evasion_Per_Dexterity;
}

void Attributes::set_Evasion_Per_Dexterity(const float evasion_Per_Dexterity)
{
	Attributes::evasion_Per_Dexterity = evasion_Per_Dexterity;
}

float Attributes::get_Evasion_Per_Perception()
{
	return Attributes::evasion_Per_Perception;
}

void Attributes::set_Evasion_Per_Perception(const float evasion_Per_Perception)
{
	Attributes::evasion_Per_Perception = evasion_Per_Perception;
}

//Displays the values held inside of the individual members along with the 'get_Effective_Attribute()' values; used for debugging
void Attributes::display_Information() const
{
	std::cout << "Vector Index: " << (*this).containing_Object_Pointer_Vector_Index << std::endl;

	std::cout << "strength: " << (*this).strength << std::endl;
	std::cout << "effective strength: " << (*this).get_Effective_Strength() << std::endl;
	std::cout << "dexterity: " << (*this).dexterity << std::endl;
	std::cout << "effective dexterity: " << (*this).get_Effective_Dexterity() << std::endl;
	std::cout << "endurance: " << (*this).endurance << std::endl;
	std::cout << "effective endurance: " << (*this).get_Effective_Endurance() << std::endl;
	std::cout << "intelligence: " << (*this).intelligence << std::endl;
	std::cout << "effective intelligence: " << (*this).get_Effective_Intelligence() << std::endl;
	std::cout << "perception: " << (*this).perception << std::endl;
	std::cout << "effective perception: " << (*this).get_Effective_Perception() << std::endl;
	std::cout << std::endl;

	std::cout << "experience: " << (*this).experience << std::endl;
	std::cout << "level: " << (*this).level << std::endl;
	std::cout << std::endl;

	std::cout << "carrying_Capacity: " << (*this).carrying_Capacity << std::endl;
	std::cout << "effective carrying_Capacity: " << (*this).get_Effective_Carrying_Capacity() << std::endl;
	std::cout << "amount_Carried: " << (*this).amount_Carried << std::endl;
	std::cout << std::endl;

	std::cout << "vision_Range: " << (*this).vision_Range << std::endl;
	std::cout << "effective vision_Range: " << (*this).get_Effective_Vision_Range() << std::endl;
	std::cout << "hearing_Range: " << (*this).hearing_Range << std::endl;
	std::cout << "effective hearing_Range: " << (*this).get_Effective_Hearing_Range() << std::endl;
	std::cout << std::endl;

	std::cout << "physical_Attack_Range: " << (*this).physical_Attack_Range << std::endl;
	std::cout << "effective physical_Attack_Range: " << (*this).get_Effective_Physical_Attack_Range() << std::endl;
	std::cout << "physical_Damage: " << (*this).physical_Damage << std::endl;
	std::cout << "effective physical_Damage: " << (*this).get_Effective_Physical_Damage() << std::endl;
	std::cout << "rate_Of_Physical_Attacks: " << (*this).rate_Of_Physical_Attacks << std::endl;
	std::cout << "effective rate_Of_Physical_Attacks: " << (*this).get_Effective_Rate_Of_Physical_Attacks() << std::endl;
	std::cout << "physical_Accuracy: " << (*this).physical_Accuracy << std::endl;
	std::cout << "effective physical_Accuracy: " << (*this).get_Effective_Physical_Accuracy() << std::endl;
	std::cout << std::endl;

	std::cout << "magical_Attack_Range: " << (*this).magical_Attack_Range << std::endl;
	std::cout << "effective magical_Attack_Range: " << (*this).get_Effective_Magical_Attack_Range() << std::endl;
	std::cout << "magical_Damage: " << (*this).magical_Damage << std::endl;
	std::cout << "effective magical_Damage: " << (*this).get_Effective_Magical_Damage() << std::endl;
	std::cout << "rate_Of_Magical_Attacks: " << (*this).rate_Of_Magical_Attacks << std::endl;
	std::cout << "effective rate_Of_Magical_Attacks: " << (*this).get_Effective_Rate_Of_Magical_Attacks() << std::endl;
	std::cout << "magical_Accuracy: " << (*this).magical_Accuracy << std::endl;
	std::cout << "effective magical_Accuracy: " << (*this).get_Effective_Magical_Accuracy() << std::endl;
	std::cout << std::endl;

	std::cout << "movement_Speed: " << (*this).movement_Speed << std::endl;
	std::cout << "effective movement_Speed: " << (*this).get_Effective_Movement_Speed() << std::endl;
	std::cout << std::endl;

	std::cout << "maximum_Stamina: " << (*this).maximum_Stamina << std::endl;
	std::cout << "effective maximum_Stamina: " << (*this).get_Effective_Maximum_Stamina() << std::endl;
	std::cout << "stamina: " << (*this).stamina << std::endl;
	std::cout << "rate_Of_Stamina_Regeneration: " << (*this).rate_Of_Stamina_Regeneration << std::endl;
	std::cout << "effective rate_Of_Stamina_Regeneration: " << (*this).get_Effective_Rate_Of_Stamina_Regeneration() << std::endl;
	std::cout << std::endl;

	std::cout << "maximum_Mana: " << (*this).maximum_Mana << std::endl;
	std::cout << "effective maximum_Mana: " << (*this).get_Effective_Maximum_Mana() << std::endl;
	std::cout << "mana: " << (*this).mana << std::endl;
	std::cout << "rate_Of_Mana_Regeneration: " << (*this).rate_Of_Mana_Regeneration << std::endl;
	std::cout << "effective rate_Of_Mana_Regeneration: " << (*this).get_Effective_Rate_Of_Mana_Regeneration() << std::endl;
	std::cout << std::endl;

	std::cout << "maximum_Health: " << (*this).maximum_Health << std::endl;
	std::cout << "effective maximum_Health: " << (*this).get_Effective_Maximum_Health() << std::endl;
	std::cout << "health: " << (*this).health << std::endl;
	std::cout << "rate_Of_Health_Regeneration: " << (*this).rate_Of_Health_Regeneration << std::endl;
	std::cout << "effective rate_Of_Health_Regeneration: " << (*this).get_Effective_Rate_Of_Health_Regeneration() << std::endl;
	std::cout << std::endl;

	std::cout << "physical_Defense: " << (*this).physical_Defense << std::endl;
	std::cout << "effective physical_Defense: " << (*this).get_Effective_Physical_Defense() << std::endl;
	std::cout << "magical_Defense: " << (*this).magical_Defense << std::endl;
	std::cout << "effective magical_Defense: " << (*this).get_Effective_Magical_Defense() << std::endl;
	std::cout << "block_Chance: " << (*this).block_Chance << std::endl;
	std::cout << "effective block_Chance: " << (*this).get_Effective_Block_Chance() << std::endl;
	std::cout << "evasion: " << (*this).evasion << std::endl;
	std::cout << "effective evasion: " << (*this).get_Effective_Evasion() << std::endl;

	std::cout << std::endl;
}

//Updates stats according to regeneration rates and events such as the Object being damaged, having a spell cast on the Object, or the Object killing a monster; needs to have access to time_Step
void Attributes::update()
{
	(*this).stamina = std::min((((*this).get_Effective_Rate_Of_Stamina_Regeneration() * static_cast<float>(1.0 / 60)) + (*this).stamina), (*this).get_Effective_Maximum_Stamina());
	(*this).health =  std::min((((*this).get_Effective_Rate_Of_Health_Regeneration() * static_cast<float>(1.0 / 60)) + (*this).health), (*this).get_Effective_Maximum_Health());
	(*this).mana =  std::min((((*this).get_Effective_Rate_Of_Mana_Regeneration() * static_cast<float>(1.0 / 60)) + (*this).mana), (*this).get_Effective_Maximum_Mana()); 
}

float Attributes::get_Effective_Strength() const
{
	return ((*this).strength + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Strength_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Strength_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Strength_Multiplier();
}

float Attributes::get_Effective_Dexterity() const
{
	return ((*this).dexterity + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Dexterity_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Dexterity_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Dexterity_Multiplier();
}

float Attributes::get_Effective_Endurance() const
{
	return ((*this).endurance + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Endurance_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Endurance_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Endurance_Multiplier();
}

float Attributes::get_Effective_Intelligence() const
{
	return ((*this).intelligence + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Intelligence_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Intelligence_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Intelligence_Multiplier();
}

float Attributes::get_Effective_Perception() const
{
	return ((*this).perception + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Perception_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Perception_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Perception_Multiplier();
}

float Attributes::get_Effective_Carrying_Capacity() const
{
	return ((*this).carrying_Capacity + ((*this).get_Effective_Strength() * Attributes::carrying_Capacity_Per_Strength) + ((*this).get_Effective_Endurance() * Attributes::carrying_Capacity_Per_Endurance) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Carrying_Capacity_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Carrying_Capacity_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Carrying_Capacity_Multiplier();
}

float Attributes::get_Effective_Vision_Range() const
{
	return ((*this).vision_Range + ((*this).get_Effective_Perception() * Attributes::vision_Range_Per_Perception) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Vision_Range_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Vision_Range_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Vision_Range_Multiplier();
}

float Attributes::get_Effective_Hearing_Range() const
{
	return ((*this).hearing_Range + ((*this).get_Effective_Perception() * Attributes::hearing_Range_Per_Perception) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Hearing_Range_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Hearing_Range_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Hearing_Range_Multiplier();
}

float Attributes::get_Effective_Physical_Attack_Range() const
{
	return ((*this).physical_Attack_Range + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Physical_Attack_Range_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Attack_Range_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Attack_Range_Multiplier();
}

float Attributes::get_Effective_Physical_Damage() const
{
	return ((*this).physical_Damage + ((*this).get_Effective_Strength() * Attributes::physical_Damage_Per_Strength) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Physical_Damage_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Damage_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Damage_Multiplier();
}

float Attributes::get_Effective_Rate_Of_Physical_Attacks() const
{
	return ((*this).rate_Of_Physical_Attacks + ((*this).get_Effective_Dexterity() * Attributes::rate_Of_Physical_Attacks_Per_Dexterity) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Rate_Of_Physical_Attacks_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Physical_Attacks_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Physical_Attacks_Multiplier();
}

float Attributes::get_Effective_Physical_Accuracy() const
{
	return ((*this).physical_Accuracy + ((*this).get_Effective_Dexterity() * Attributes::physical_Accuracy_Per_Dexterity) + ((*this).get_Effective_Perception() * Attributes::physical_Accuracy_Per_Perception) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Physical_Accuracy_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Accuracy_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Accuracy_Multiplier();
}

float Attributes::get_Effective_Magical_Attack_Range() const
{
	return ((*this).magical_Attack_Range + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Magical_Attack_Range_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Attack_Range_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Attack_Range_Multiplier();
}

float Attributes::get_Effective_Magical_Damage() const
{
	return ((*this).magical_Damage + ((*this).get_Effective_Intelligence() * Attributes::magical_Damage_Per_Intelligence) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Magical_Damage_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Damage_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Damage_Multiplier();
}

float Attributes::get_Effective_Rate_Of_Magical_Attacks() const
{
	return ((*this).rate_Of_Magical_Attacks + ((*this).get_Effective_Dexterity() * Attributes::rate_Of_Magical_Attacks_Per_Dexterity) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Rate_Of_Magical_Attacks_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Magical_Attacks_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Magical_Attacks_Multiplier();
}

float Attributes::get_Effective_Magical_Accuracy() const
{
	return ((*this).magical_Accuracy + ((*this).get_Effective_Dexterity() * Attributes::magical_Accuracy_Per_Dexterity) + ((*this).get_Effective_Perception() * Attributes::magical_Accuracy_Per_Perception) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Magical_Accuracy_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Accuracy_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Accuracy_Multiplier();
}

//carrying_Capacity and amount_Carried don't factor into movement speed at the moment
float Attributes::get_Effective_Movement_Speed() const
{
	return ((*this).movement_Speed + ((*this).get_Effective_Dexterity() * Attributes::movement_Speed_Per_Dexterity) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Movement_Speed_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Movement_Speed_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Movement_Speed_Multiplier();
}

float Attributes::get_Effective_Maximum_Stamina() const
{
	return ((*this).maximum_Stamina + ((*this).get_Effective_Endurance() * Attributes::maximum_Stamina_Per_Endurance) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Maximum_Stamina_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Maximum_Stamina_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Maximum_Stamina_Multiplier();
}

float Attributes::get_Effective_Rate_Of_Stamina_Regeneration() const
{
	return ((*this).rate_Of_Stamina_Regeneration + ((*this).get_Effective_Endurance() * Attributes::rate_Of_Stamina_Regeneration_Per_Endurance) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Rate_Of_Stamina_Regeneration_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Stamina_Regeneration_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Stamina_Regeneration_Multiplier();
}

float Attributes::get_Effective_Maximum_Mana() const
{
	return ((*this).maximum_Mana + ((*this).get_Effective_Intelligence() * Attributes::maximum_Mana_Per_Intelligence) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Maximum_Mana_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Maximum_Mana_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Maximum_Mana_Multiplier();
}

float Attributes::get_Effective_Rate_Of_Mana_Regeneration() const
{
	return ((*this).rate_Of_Mana_Regeneration + ((*this).get_Effective_Intelligence() * Attributes::rate_Of_Mana_Regeneration_Per_Intelligence) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Rate_Of_Mana_Regeneration_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Mana_Regeneration_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Mana_Regeneration_Multiplier();
}

float Attributes::get_Effective_Maximum_Health() const
{
	return ((*this).maximum_Health + ((*this).get_Effective_Endurance() * Attributes::maximum_Health_Per_Endurance) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Maximum_Health_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Maximum_Health_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Maximum_Health_Multiplier();
}

float Attributes::get_Effective_Rate_Of_Health_Regeneration() const
{
	return ((*this).rate_Of_Health_Regeneration + ((*this).get_Effective_Endurance() * Attributes::rate_Of_Health_Regeneration_Per_Endurance) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Rate_Of_Health_Regeneration_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Health_Regeneration_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Rate_Of_Health_Regeneration_Multiplier();
}

float Attributes::get_Effective_Physical_Defense() const
{
	return ((*this).physical_Defense + ((*this).get_Effective_Endurance() * Attributes::physical_Defense_Per_Endurance) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Physical_Defense_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Defense_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Physical_Defense_Multiplier();
}

float Attributes::get_Effective_Magical_Defense() const
{
	return ((*this).magical_Defense + ((*this).get_Effective_Endurance() * Attributes::magical_Defense_Per_Endurance) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Magical_Defense_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Defense_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Magical_Defense_Multiplier();
}

float Attributes::get_Effective_Block_Chance() const
{
	return ((*this).block_Chance + ((*this).get_Effective_Dexterity() * Attributes::block_Chance_Per_Dexterity) + ((*this).get_Effective_Perception() * Attributes::block_Chance_Per_Perception) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Block_Chance_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Block_Chance_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Block_Chance_Multiplier();
}

float Attributes::get_Effective_Evasion() const
{
	return ((*this).evasion + ((*this).get_Effective_Dexterity() * Attributes::evasion_Per_Dexterity) + ((*this).get_Effective_Perception() * Attributes::evasion_Per_Perception) + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).equipment.get_Total_Evasion_Modifier() + (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Evasion_Modifier()) * (*Object::object_Pointer_Vector[(*this).containing_Object_Pointer_Vector_Index]).status_Effects.get_Total_Evasion_Multiplier();
}

//'Getters' and 'Setters' for private member variables
std::uint16_t Attributes::get_Containing_Object_Pointer_Vector_Index() const
{
	return (*this).containing_Object_Pointer_Vector_Index;
}

void Attributes::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}

float Attributes::get_Strength() const
{
	return (*this).strength;
}

void Attributes::set_Strength(const float strength)
{
	(*this).strength = strength;
}

float Attributes::get_Dexterity() const
{
	return (*this).dexterity;
}

void Attributes::set_Dexterity(const float dexterity)
{
	(*this).dexterity = dexterity;
}

float Attributes::get_Endurance() const
{
	return (*this).endurance;
}

void Attributes::set_Endurance(const float endurance)
{
	(*this).endurance = endurance;
}

float Attributes::get_Intelligence() const
{
	return (*this).intelligence;
}

void Attributes::set_Intelligence(const float intelligence)
{
	(*this).intelligence = intelligence;
}

float Attributes::get_Perception() const
{
	return (*this).perception;
}

void Attributes::set_Perception(const float perception)
{
	(*this).perception = perception;
}

float Attributes::get_Experience() const
{
	return (*this).experience;
}

void Attributes::set_Experience(const float experience)
{
	(*this).experience = experience;
}

float Attributes::get_Level() const
{
	return (*this).level;
}

void Attributes::set_Level(const float level)
{
	(*this).level = level;
}

float Attributes::get_Carrying_Capacity() const
{
	return (*this).carrying_Capacity;
}

void Attributes::set_Carrying_Capacity(const float carrying_Capacity)
{
	(*this).carrying_Capacity = carrying_Capacity;
}

float Attributes::get_Amount_Carried() const
{
	return (*this).amount_Carried;
}

void Attributes::set_Amount_Carried(const float amount_Carried)
{
	(*this).amount_Carried = amount_Carried;
}

float Attributes::get_Vision_Range() const
{
	return (*this).vision_Range;
}

void Attributes::set_Vision_Range(const float vision_Range)
{
	(*this).vision_Range = vision_Range;
}

float Attributes::get_Hearing_Range() const
{
	return (*this).hearing_Range;
}

void Attributes::set_Hearing_Range(const float hearing_Range)
{
	(*this).hearing_Range = hearing_Range;
}

float Attributes::get_Physical_Attack_Range() const
{
	return (*this).physical_Attack_Range;
}

void Attributes::set_Physical_Attack_Range(const float physical_Attack_Range)
{
	(*this).physical_Attack_Range = physical_Attack_Range;
}

float Attributes::get_Physical_Damage() const
{
	return (*this).physical_Damage;
}

void Attributes::set_Physical_Damage(const float physical_Damage)
{
	(*this).physical_Damage = physical_Damage;
}

float Attributes::get_Rate_Of_Physical_Attacks() const
{
	return (*this).rate_Of_Physical_Attacks;
}

void Attributes::set_Rate_Of_Physical_Attacks(const float rate_Of_Physical_Attacks)
{
	(*this).rate_Of_Physical_Attacks = rate_Of_Physical_Attacks;
}

float Attributes::get_Physical_Accuracy() const
{
	return (*this).physical_Accuracy;
}

void Attributes::set_Physical_Accuracy(const float physical_Accuracy)
{
	(*this).physical_Accuracy = physical_Accuracy;
}

float Attributes::get_Magical_Attack_Range() const
{
	return (*this).magical_Attack_Range;
}

void Attributes::set_Magical_Attack_Range(const float magical_Attack_Range)
{
	(*this).magical_Attack_Range = magical_Attack_Range;
}

float Attributes::get_Magical_Damage() const
{
	return (*this).magical_Damage;
}

void Attributes::set_Magical_Damage(const float magical_Damage)
{
	(*this).magical_Damage = magical_Damage;
}

float Attributes::get_Rate_Of_Magical_Attacks() const
{
	return (*this).rate_Of_Magical_Attacks;
}

void Attributes::set_Rate_Of_Magical_Attacks(const float rate_Of_Magical_Attacks)
{
	(*this).rate_Of_Magical_Attacks = rate_Of_Magical_Attacks;
}

float Attributes::get_Magical_Accuracy() const
{
	return (*this).magical_Accuracy;
}

void Attributes::set_Magical_Accuracy(const float magical_Accuracy)
{
	(*this).magical_Accuracy = magical_Accuracy;
}

float Attributes::get_Movement_Speed() const
{
	return (*this).movement_Speed;
}

void Attributes::set_Movement_Speed(const float movement_Speed)
{
	(*this).movement_Speed = movement_Speed;
}

float Attributes::get_Maximum_Stamina() const
{
	return (*this).maximum_Stamina;
}

void Attributes::set_Maximum_Stamina(const float maximum_Stamina)
{
	(*this).maximum_Stamina = maximum_Stamina;
}

float Attributes::get_Stamina() const
{
	return (*this).stamina;
}

void Attributes::set_Stamina(const float stamina)
{
	(*this).stamina = stamina;
}

float Attributes::get_Rate_Of_Stamina_Regeneration() const
{
	return (*this).rate_Of_Stamina_Regeneration;
}

void Attributes::set_Rate_Of_Stamina_Regeneration(const float rate_Of_Stamina_Regeneration)
{
	(*this).rate_Of_Stamina_Regeneration = rate_Of_Stamina_Regeneration;
}

float Attributes::get_Maximum_Mana() const
{
	return (*this).maximum_Mana;
}

void Attributes::set_Maximum_Mana(const float maximum_Mana)
{
	(*this).maximum_Mana = maximum_Mana;
}

float Attributes::get_Mana() const
{
	return (*this).mana;
}

void Attributes::set_Mana(const float mana)
{
	(*this).mana = mana;
}

float Attributes::get_Rate_Of_Mana_Regeneration() const
{
	return (*this).rate_Of_Mana_Regeneration;
}

void Attributes::set_Rate_Of_Mana_Regeneration(const float rate_Of_Mana_Regeneration)
{
	(*this).rate_Of_Mana_Regeneration = rate_Of_Mana_Regeneration;
}

float Attributes::get_Maximum_Health() const
{
	return (*this).maximum_Health;
}

void Attributes::set_Maximum_Health(const float maximum_Health)
{
	(*this).maximum_Health = maximum_Health;
}

float Attributes::get_Health() const
{
	return (*this).health;
}

void Attributes::set_Health(const float health)
{
	(*this).health = health;
}

float Attributes::get_Rate_Of_Health_Regeneration() const
{
	return (*this).rate_Of_Health_Regeneration;
}

void Attributes::set_Rate_Of_Health_Regeneration(const float rate_Of_Health_Regeneration)
{
	(*this).rate_Of_Health_Regeneration = rate_Of_Health_Regeneration;
}

float Attributes::get_Physical_Defense() const
{
	return (*this).physical_Defense;
}

void Attributes::set_Physical_Defense(const float physical_Defense)
{
	(*this).physical_Defense = physical_Defense;
}

float Attributes::get_Magical_Defense() const
{
	return (*this).magical_Defense;
}

void Attributes::set_Magical_Defense(const float magical_Defense)
{
	(*this).magical_Defense = magical_Defense;
}

float Attributes::get_Block_Chance() const
{
	return (*this).block_Chance;
}

void Attributes::set_Block_Chance(const float block_Chance)
{
	(*this).block_Chance = block_Chance;
}

float Attributes::get_Evasion() const
{
	return (*this).evasion;
}

void Attributes::set_Evasion(const float evasion)
{
	(*this).evasion = evasion;
}
