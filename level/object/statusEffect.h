//Status_Effect header file
#ifndef STATUS_EFFECT_H
#define STATUS_EFFECT_H

enum class Status_Effect_States : std::uint8_t
{
	Inactive,
	Active
};

class Status_Effect
{
	private:
		//Private static class variables

		//Private member variables
		Status_Effect_States status_Effect_State;

		float strength_Modifier;
		float strength_Multiplier_Modifier;
		float dexterity_Modifier;
		float dexterity_Multiplier_Modifier;
		float endurance_Modifier;
		float endurance_Multiplier_Modifier;
		float intelligence_Modifier;
		float intelligence_Multiplier_Modifier;
		float perception_Modifier;
		float perception_Multiplier_Modifier;

		float carrying_Capacity_Modifier;
		float carrying_Capacity_Multiplier_Modifier;

		float vision_Range_Modifier;
		float vision_Range_Multiplier_Modifier;
		float hearing_Range_Modifier;
		float hearing_Range_Multiplier_Modifier;

		float physical_Attack_Range_Modifier;
		float physical_Attack_Range_Multiplier_Modifier;
		float physical_Damage_Modifier;
		float physical_Damage_Multiplier_Modifier;
		float rate_Of_Physical_Attacks_Modifier;
		float rate_Of_Physical_Attacks_Multiplier_Modifier;
		float physical_Accuracy_Modifier;
		float physical_Accuracy_Multiplier_Modifier;

		float magical_Attack_Range_Modifier;
		float magical_Attack_Range_Multiplier_Modifier;
		float magical_Damage_Modifier;
		float magical_Damage_Multiplier_Modifier;
		float rate_Of_Magical_Attacks_Modifier;
		float rate_Of_Magical_Attacks_Multiplier_Modifier;
		float magical_Accuracy_Modifier;
		float magical_Accuracy_Multiplier_Modifier;

		float movement_Speed_Modifier;
		float movement_Speed_Multiplier_Modifier;

		float maximum_Stamina_Modifier;
		float maximum_Stamina_Multiplier_Modifier;
		float rate_Of_Stamina_Regeneration_Modifier;
		float rate_Of_Stamina_Regeneration_Multiplier_Modifier;

		float maximum_Mana_Modifier;
		float maximum_Mana_Multiplier_Modifier;
		float rate_Of_Mana_Regeneration_Modifier;
		float rate_Of_Mana_Regeneration_Multiplier_Modifier;

		float maximum_Health_Modifier;
		float maximum_Health_Multiplier_Modifier;
		float rate_Of_Health_Regeneration_Modifier;
		float rate_Of_Health_Regeneration_Multiplier_Modifier;

		float physical_Defense_Modifier;
		float physical_Defense_Multiplier_Modifier;
		float magical_Defense_Modifier;
		float magical_Defense_Multiplier_Modifier;
		float block_Chance_Modifier;
		float block_Chance_Multiplier_Modifier;
		float evasion_Modifier;
		float evasion_Multiplier_Modifier;

		std::uint16_t containing_Object_Pointer_Vector_Index;
		std::uint8_t active_Status_Effects_Index;

	public:
		//Public static class variables

		//Public member variables

		//Constructors and Destructors
		Status_Effect();

		//Static functions

		//Member functions
		void display_Information() const;
		void update();

		//'Getters' and 'Setters' for private member variables
		Status_Effect_States get_Status_Effect_State() const;
		void set_Status_Effect_State(const Status_Effect_States);

		float get_Strength_Modifier() const;
		void set_Strength_Modifier(const float);

		float get_Strength_Multiplier_Modifier() const;
		void set_Strength_Multiplier_Modifier(const float);

		float get_Dexterity_Modifier() const;
		void set_Dexterity_Modifier(const float);

		float get_Dexterity_Multiplier_Modifier() const;
		void set_Dexterity_Multiplier_Modifier(const float);

		float get_Endurance_Modifier() const;
		void set_Endurance_Modifier(const float);

		float get_Endurance_Multiplier_Modifier() const;
		void set_Endurance_Multiplier_Modifier(const float);

		float get_Intelligence_Modifier() const;
		void set_Intelligence_Modifier(const float);

		float get_Intelligence_Multiplier_Modifier() const;
		void set_Intelligence_Multiplier_Modifier(const float);

		float get_Perception_Modifier() const;
		void set_Perception_Modifier(const float);

		float get_Perception_Multiplier_Modifier() const;
		void set_Perception_Multiplier_Modifier(const float);

		float get_Carrying_Capacity_Modifier() const;
		void set_Carrying_Capacity_Modifier(const float);

		float get_Carrying_Capacity_Multiplier_Modifier() const;
		void set_Carrying_Capacity_Multiplier_Modifier(const float);

		float get_Vision_Range_Modifier() const;
		void set_Vision_Range_Modifier(const float);

		float get_Vision_Range_Multiplier_Modifier() const;
		void set_Vision_Range_Multiplier_Modifier(const float);

		float get_Hearing_Range_Modifier() const;
		void set_Hearing_Range_Modifier(const float);

		float get_Hearing_Range_Multiplier_Modifier() const;
		void set_Hearing_Range_Multiplier_Modifier(const float);

		float get_Physical_Attack_Range_Modifier() const;
		void set_Physical_Attack_Range_Modifier(const float);

		float get_Physical_Attack_Range_Multiplier_Modifier() const;
		void set_Physical_Attack_Range_Multiplier_Modifier(const float);

		float get_Physical_Damage_Modifier() const;
		void set_Physical_Damage_Modifier(const float);

		float get_Physical_Damage_Multiplier_Modifier() const;
		void set_Physical_Damage_Multiplier_Modifier(const float);

		float get_Rate_Of_Physical_Attacks_Modifier() const;
		void set_Rate_Of_Physical_Attacks_Modifier(const float);

		float get_Rate_Of_Physical_Attacks_Multiplier_Modifier() const;
		void set_Rate_Of_Physical_Attacks_Multiplier_Modifier(const float);

		float get_Physical_Accuracy_Modifier() const;
		void set_Physical_Accuracy_Modifier(const float);

		float get_Physical_Accuracy_Multiplier_Modifier() const;
		void set_Physical_Accuracy_Multiplier_Modifier(const float);

		float get_Magical_Attack_Range_Modifier() const;
		void set_Magical_Attack_Range_Modifier(const float);

		float get_Magical_Attack_Range_Multiplier_Modifier() const;
		void set_Magical_Attack_Range_Multiplier_Modifier(const float);

		float get_Magical_Damage_Modifier() const;
		void set_Magical_Damage_Modifier(const float);

		float get_Magical_Damage_Multiplier_Modifier() const;
		void set_Magical_Damage_Multiplier_Modifier(const float);

		float get_Rate_Of_Magical_Attacks_Modifier() const;
		void set_Rate_Of_Magical_Attacks_Modifier(const float);

		float get_Rate_Of_Magical_Attacks_Multiplier_Modifier() const;
		void set_Rate_Of_Magical_Attacks_Multiplier_Modifier(const float);

		float get_Magical_Accuracy_Modifier() const;
		void set_Magical_Accuracy_Modifier(const float);

		float get_Magical_Accuracy_Multiplier_Modifier() const;
		void set_Magical_Accuracy_Multiplier_Modifier(const float);

		float get_Movement_Speed_Modifier() const;
		void set_Movement_Speed_Modifier(const float);

		float get_Movement_Speed_Multiplier_Modifier() const;
		void set_Movement_Speed_Multiplier_Modifier(const float);

		float get_Maximum_Stamina_Modifier() const;
		void set_Maximum_Stamina_Modifier(const float);

		float get_Maximum_Stamina_Multiplier_Modifier() const;
		void set_Maximum_Stamina_Multiplier_Modifier(const float);

		float get_Rate_Of_Stamina_Regeneration_Modifier() const;
		void set_Rate_Of_Stamina_Regeneration_Modifier(const float);

		float get_Rate_Of_Stamina_Regeneration_Multiplier_Modifier() const;
		void set_Rate_Of_Stamina_Regeneration_Multiplier_Modifier(const float);

		float get_Maximum_Mana_Modifier() const;
		void set_Maximum_Mana_Modifier(const float);

		float get_Maximum_Mana_Multiplier_Modifier() const;
		void set_Maximum_Mana_Multiplier_Modifier(const float);

		float get_Rate_Of_Mana_Regeneration_Modifier() const;
		void set_Rate_Of_Mana_Regeneration_Modifier(const float);

		float get_Rate_Of_Mana_Regeneration_Multiplier_Modifier() const;
		void set_Rate_Of_Mana_Regeneration_Multiplier_Modifier(const float);

		float get_Maximum_Health_Modifier() const;
		void set_Maximum_Health_Modifier(const float);

		float get_Maximum_Health_Multiplier_Modifier() const;
		void set_Maximum_Health_Multiplier_Modifier(const float);

		float get_Rate_Of_Health_Regeneration_Modifier() const;
		void set_Rate_Of_Health_Regeneration_Modifier(const float);

		float get_Rate_Of_Health_Regeneration_Multiplier_Modifier() const;
		void set_Rate_Of_Health_Regeneration_Multiplier_Modifier(const float);

		float get_Physical_Defense_Modifier() const;
		void set_Physical_Defense_Modifier(const float);

		float get_Physical_Defense_Multiplier_Modifier() const;
		void set_Physical_Defense_Multiplier_Modifier(const float);

		float get_Magical_Defense_Modifier() const;
		void set_Magical_Defense_Modifier(const float);

		float get_Magical_Defense_Multiplier_Modifier() const;
		void set_Magical_Defense_Multiplier_Modifier(const float);

		float get_Block_Chance_Modifier() const;
		void set_Block_Chance_Modifier(const float);

		float get_Block_Chance_Multiplier_Modifier() const;
		void set_Block_Chance_Multiplier_Modifier(const float);

		float get_Evasion_Modifier() const;
		void set_Evasion_Modifier(const float);

		float get_Evasion_Multiplier_Modifier() const;
		void set_Evasion_Multiplier_Modifier(const float);

		std::uint16_t get_Containing_Object_Pointer_Vector_Index() const;
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);

		std::uint8_t get_Active_Status_Effects_Index() const;
		void set_Active_Status_Effects_Index(const std::uint8_t);
};
#endif
