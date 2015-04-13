//Equipment header file; friend of Object class
#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <iostream>
#include <vector>
#include <cstdint>
#include "item.h"

class Equipment
{
	private:
		const static std::uint8_t total_Number_Of_Equipment_Slots = 18;
		Item* equipped_Item_Pointer_Array[Equipment::total_Number_Of_Equipment_Slots];

		std::uint16_t containing_Object_Pointer_Vector_Index;

	public:
		//Constructors and Destructors
		Equipment();									//Default constructor

		//Member functions
		void display_Information();

		float get_Total_Strength_Modifier();
		float get_Total_Dexterity_Modifier();
		float get_Total_Endurance_Modifier();
		float get_Total_Intelligence_Modifier();
		float get_Total_Perception_Modifier();
		float get_Total_Carrying_Capacity_Modifier();
		float get_Total_Vision_Range_Modifier();
		float get_Total_Hearing_Range_Modifier();
		float get_Total_Physical_Attack_Range_Modifier();
		float get_Total_Physical_Damage_Modifier();
		float get_Total_Rate_Of_Physical_Attacks_Modifier();
		float get_Total_Physical_Accuracy_Modifier();
		float get_Total_Magical_Attack_Range_Modifier();
		float get_Total_Magical_Damage_Modifier();
		float get_Total_Rate_Of_Magical_Attacks_Modifier();
		float get_Total_Magical_Accuracy_Modifier();
		float get_Total_Movement_Speed_Modifier();
		float get_Total_Maximum_Stamina_Modifier();
		float get_Total_Rate_Of_Stamina_Regeneration_Modifier();
		float get_Total_Maximum_Mana_Modifier();
		float get_Total_Rate_Of_Mana_Regeneration_Modifier();
		float get_Total_Maximum_Health_Modifier();
		float get_Total_Rate_Of_Health_Regeneration_Modifier();
		float get_Total_Physical_Defense_Modifier();
		float get_Total_Magical_Defense_Modifier();
		float get_Total_Block_Chance_Modifier();
		float get_Total_Evasion_Modifier();

		//'Getters' and 'Setters' for private member variables
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);
		const std::uint16_t get_Containing_Object_Pointer_Vector_Index();
};

#endif
