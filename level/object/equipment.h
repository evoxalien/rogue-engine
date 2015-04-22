//Equipment header file; friend of Object class
#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <vector>
#include "item.h"

class Equipment
{
	private:
		const static std::uint8_t total_Number_Of_Equipment_Slots = 6;
		std::uint8_t number_Of_Items_Equipped;
		Item* equipped_Item_Pointer_Array[Equipment::total_Number_Of_Equipment_Slots];

		std::uint16_t containing_Object_Pointer_Vector_Index;

	public:
		//Constructors and Destructors
		Equipment();									//Default constructor
	//	Equipment(Item&);

		//Member functions
		void display_Information() const;
		void update();

		bool equip_Item(Item&, std::uint8_t);

		float get_Total_Strength_Modifier() const;
		float get_Total_Dexterity_Modifier() const;
		float get_Total_Endurance_Modifier() const;
		float get_Total_Intelligence_Modifier() const;
		float get_Total_Perception_Modifier() const;
		float get_Total_Carrying_Capacity_Modifier() const;
		float get_Total_Vision_Range_Modifier() const;
		float get_Total_Hearing_Range_Modifier() const;
		float get_Total_Physical_Attack_Range_Modifier() const;
		float get_Total_Physical_Damage_Modifier() const;
		float get_Total_Rate_Of_Physical_Attacks_Modifier() const;
		float get_Total_Physical_Accuracy_Modifier() const;
		float get_Total_Magical_Attack_Range_Modifier() const;
		float get_Total_Magical_Damage_Modifier() const;
		float get_Total_Rate_Of_Magical_Attacks_Modifier() const;
		float get_Total_Magical_Accuracy_Modifier() const;
		float get_Total_Movement_Speed_Modifier() const;
		float get_Total_Maximum_Stamina_Modifier() const;
		float get_Total_Rate_Of_Stamina_Regeneration_Modifier() const;
		float get_Total_Maximum_Mana_Modifier() const;
		float get_Total_Rate_Of_Mana_Regeneration_Modifier() const;
		float get_Total_Maximum_Health_Modifier() const;
		float get_Total_Rate_Of_Health_Regeneration_Modifier() const;
		float get_Total_Physical_Defense_Modifier() const;
		float get_Total_Magical_Defense_Modifier() const;
		float get_Total_Block_Chance_Modifier() const;
		float get_Total_Evasion_Modifier() const;

		//'Getters' and 'Setters' for private member variables
		std::uint16_t get_Containing_Object_Pointer_Vector_Index() const;
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);
};

#endif
