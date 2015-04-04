//Attributes cpp file
#include "attributes.h"

//Default Attributes constructor
Attributes::Attributes()
{
	std::cout << "Default Attributes constructor" << std::endl;
	for(std::uint8_t i = 0; i < static_cast<std::uint8_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES); i++)
	{
		(*this).attributes[i] = 1;
	}
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Experience)] = 0;
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Amount_Carried)] = 0;
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Physical_Attack_Range)] = 0;
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Magical_Attack_Range)] = 0;
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Physical_Defense)] = 0;
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Magical_Defense)] = 0;
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Block_Chance)] = 0;
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Evasion)] = 0;

	(*this).containing_Object_Pointer_Vector_Index = 0;
}

Attributes::Attributes(float attributes[static_cast<std::uint8_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES)])
{
	std::cout << "Attributes constructor with float array passed" << std::endl;
	for(std::uint8_t i = 0; i < static_cast<std::uint8_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES); i++)
	{
		(*this).attributes[i] = attributes[i];
	}
}

void Attributes::display_Information()
{
	for(std::uint8_t i = 0; i < static_cast<std::uint8_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES); i++)
	{
		std::cout << "Attribute " << i << ": " << attributes[i] << std::endl;
	}
}

//'Getters' and 'Setters' for private member variables
void Attributes::set_Attributes(const float attributes[static_cast<std::uint8_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES)])
{
	for(std::uint8_t i = 0; i < static_cast<std::uint8_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES); i++)
	{
		(*this).attributes[i] = attributes[i];
	}
}

const float* Attributes::get_Attributes()
{
	return (*this).attributes;
}

void Attributes::set_Experience(const float experience)
{
	(*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Experience)] = experience;
}

const float Attributes::get_Experience()
{
	return (*this).attributes[static_cast<std::uint8_t>(Object_Attributes::Experience)];
}

void Attributes::set_Containing_Object_Pointer_Vector_Index(const std::uint16_t containing_Object_Pointer_Vector_Index)
{
	(*this).containing_Object_Pointer_Vector_Index = containing_Object_Pointer_Vector_Index;
}

const std::uint16_t Attributes::get_Containing_Object_Pointer_Vector_Index()
{
	return (*this).containing_Object_Pointer_Vector_Index;
}
