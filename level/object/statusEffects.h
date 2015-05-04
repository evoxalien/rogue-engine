//Status_Effects header file; friend of Object class
#ifndef STATUS_EFFECTS_H
#define STATUS_EFFECTS_H
#include "statusEffect.h"

class Status_Effects
{
	private:
		std::vector<Status_Effect*> active_Status_Effect_Pointer_Vector;

		std::uint16_t containing_Object_Pointer_Vector_Index;

	public:
		//Constructors and Destructors
		Status_Effects();									//Default constructor

		//Member functions
		void display_Information() const;
		void update();

		void apply_Status_Effect(Status_Effect&);
		void remove_Status_Effect(std::uint8_t);

		float get_Total_Strength_Modifier() const;
		float get_Total_Strength_Multiplier() const;

		float get_Total_Dexterity_Modifier() const;
		float get_Total_Dexterity_Multiplier() const;

		float get_Total_Endurance_Modifier() const;
		float get_Total_Endurance_Multiplier() const;

		float get_Total_Intelligence_Modifier() const;
		float get_Total_Intelligence_Multiplier() const;

		float get_Total_Perception_Modifier() const;
		float get_Total_Perception_Multiplier() const;

		float get_Total_Carrying_Capacity_Modifier() const;
		float get_Total_Carrying_Capacity_Multiplier() const;

		float get_Total_Vision_Range_Modifier() const;
		float get_Total_Vision_Range_Multiplier() const;

		float get_Total_Hearing_Range_Modifier() const;
		float get_Total_Hearing_Range_Multiplier() const;

		float get_Total_Physical_Attack_Range_Modifier() const;
		float get_Total_Physical_Attack_Range_Multiplier() const;

		float get_Total_Physical_Damage_Modifier() const;
		float get_Total_Physical_Damage_Multiplier() const;

		float get_Total_Rate_Of_Physical_Attacks_Modifier() const;
		float get_Total_Rate_Of_Physical_Attacks_Multiplier() const;

		float get_Total_Physical_Accuracy_Modifier() const;
		float get_Total_Physical_Accuracy_Multiplier() const;

		float get_Total_Magical_Attack_Range_Modifier() const;
		float get_Total_Magical_Attack_Range_Multiplier() const;

		float get_Total_Magical_Damage_Modifier() const;
		float get_Total_Magical_Damage_Multiplier() const;

		float get_Total_Rate_Of_Magical_Attacks_Modifier() const;
		float get_Total_Rate_Of_Magical_Attacks_Multiplier() const;

		float get_Total_Magical_Accuracy_Modifier() const;
		float get_Total_Magical_Accuracy_Multiplier() const;

		float get_Total_Movement_Speed_Modifier() const;
		float get_Total_Movement_Speed_Multiplier() const;

		float get_Total_Maximum_Stamina_Modifier() const;
		float get_Total_Maximum_Stamina_Multiplier() const;

		float get_Total_Rate_Of_Stamina_Regeneration_Modifier() const;
		float get_Total_Rate_Of_Stamina_Regeneration_Multiplier() const;

		float get_Total_Maximum_Mana_Modifier() const;
		float get_Total_Maximum_Mana_Multiplier() const;

		float get_Total_Rate_Of_Mana_Regeneration_Modifier() const;
		float get_Total_Rate_Of_Mana_Regeneration_Multiplier() const;

		float get_Total_Maximum_Health_Modifier() const;
		float get_Total_Maximum_Health_Multiplier() const;

		float get_Total_Rate_Of_Health_Regeneration_Modifier() const;
		float get_Total_Rate_Of_Health_Regeneration_Multiplier() const;

		float get_Total_Physical_Defense_Modifier() const;
		float get_Total_Physical_Defense_Multiplier() const;

		float get_Total_Magical_Defense_Modifier() const;
		float get_Total_Magical_Defense_Multiplier() const;

		float get_Total_Block_Chance_Modifier() const;
		float get_Total_Block_Chance_Multiplier() const;

		float get_Total_Evasion_Modifier() const;
		float get_Total_Evasion_Multiplier() const;

		//'Getters' and 'Setters' for private member variables
		std::uint16_t get_Containing_Object_Pointer_Vector_Index() const;
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);
};

#endif
