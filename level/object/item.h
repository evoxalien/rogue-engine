//Item header file
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstdint>

enum class Item_States : std::uint8_t		//An enumeration representing where the Object is within the game-world which affects whether it should be drawn, is able to be picked up, equipped, or removed
{
	On_Ground,
	In_Inventory,
	Equipped
};

class Item
{
	private:
		Item_States item_State;

		float strength_Modifier;
		float dexterity_Modifier;
		float endurance_Modifier;
		float intelligence_Modifier;
		float perception_Modifier;

		float level;

		float durability;

		float carrying_Capacity_Modifier;
		float weight;

		float vision_Range_Modifier;
		float hearing_Range_Modifier;

		float physical_Attack_Range_Modifier;
		float physical_Damage_Modifier;
		float rate_Of_Physical_Attacks_Modifier;
		float physical_Accuracy_Modifier;

		float magical_Attack_Range_Modifier;
		float magical_Damage_Modifier;
		float rate_Of_Magical_Attacks_Modifier;
		float magical_Accuracy_Modifier;

		float movement_Speed_Modifier;

		float maximum_Stamina_Modifier;
		float rate_Of_Stamina_Regeneration_Modifier;
		float stamina_Consumed_On_Use;

		float maximum_Mana_Modifier;
		float rate_Of_Mana_Regeneration_Modifier;
		float mana_Consumed_On_Use;

		float maximum_Health_Modifier;
		float rate_Of_Health_Regeneration_Modifier;
		float health_Consumed_On_Use;

		float physical_Defense_Modifier;
		float magical_Defense_Modifier;
		float block_Chance_Modifier;
		float evasion_Modifier;

		std::uint16_t containing_Object_Pointer_Vector_Index;

	public:
		//Constructors and Destructors
		Item();									//Default constructor

		void display_Information() const;

		//'Getters' and 'Setters' for private member variables
		Item_States get_Item_State() const;
		void set_Item_State(const Item_States);

		float get_Strength_Modifier() const;
		void set_Strength_Modifier(const float);

		float get_Dexterity_Modifier() const;
		void set_Dexterity_Modifier(const float);

		float get_Endurance_Modifier() const;
		void set_Endurance_Modifier(const float);

		float get_Intelligence_Modifier() const;
		void set_Intelligence_Modifier(const float);

		float get_Perception_Modifier() const;
		void set_Perception_Modifier(const float);

		float get_Level() const;
		void set_Level(const float);

		float get_Durability() const;
		void set_Durability(const float);

		float get_Carrying_Capacity_Modifier() const;
		void set_Carrying_Capacity_Modifier(const float);

		float get_Weight() const;
		void set_Weight(const float);

		float get_Vision_Range_Modifier() const;
		void set_Vision_Range_Modifier(const float);

		float get_Hearing_Range_Modifier() const;
		void set_Hearing_Range_Modifier(const float);

		float get_Physical_Attack_Range_Modifier() const;
		void set_Physical_Attack_Range_Modifier(const float);

		float get_Physical_Damage_Modifier() const;
		void set_Physical_Damage_Modifier(const float);

		float get_Rate_Of_Physical_Attacks_Modifier() const;
		void set_Rate_Of_Physical_Attacks_Modifier(const float);

		float get_Physical_Accuracy_Modifier() const;
		void set_Physical_Accuracy_Modifier(const float);

		float get_Magical_Attack_Range_Modifier() const;
		void set_Magical_Attack_Range_Modifier(const float);

		float get_Magical_Damage_Modifier() const;
		void set_Magical_Damage_Modifier(const float);

		float get_Rate_Of_Magical_Attacks_Modifier() const;
		void set_Rate_Of_Magical_Attacks_Modifier(const float);

		float get_Magical_Accuracy_Modifier() const;
		void set_Magical_Accuracy_Modifier(const float);

		float get_Movement_Speed_Modifier() const;
		void set_Movement_Speed_Modifier(const float);

		float get_Maximum_Stamina_Modifier() const;
		void set_Maximum_Stamina_Modifier(const float);

		float get_Rate_Of_Stamina_Regeneration_Modifier() const;
		void set_Rate_Of_Stamina_Regeneration_Modifier(const float);

		float get_Stamina_Consumed_On_Use() const;
		void set_Stamina_Consumed_On_Use(const float);

		float get_Maximum_Mana_Modifier() const;
		void set_Maximum_Mana_Modifier(const float);

		float get_Rate_Of_Mana_Regeneration_Modifier() const;
		void set_Rate_Of_Mana_Regeneration_Modifier(const float);

		float get_Mana_Consumed_On_Use() const;
		void set_Mana_Consumed_On_Use(const float);

		float get_Maximum_Health_Modifier() const;
		void set_Maximum_Health_Modifier(const float);

		float get_Rate_Of_Health_Regeneration_Modifier() const;
		void set_Rate_Of_Health_Regeneration_Modifier(const float);

		float get_Health_Consumed_On_Use() const;
		void set_Health_Consumed_On_Use(const float);

		float get_Physical_Defense_Modifier() const;
		void set_Physical_Defense_Modifier(const float);

		float get_Magical_Defense_Modifier() const;
		void set_Magical_Defense_Modifier(const float);

		float get_Block_Chance_Modifier() const;
		void set_Block_Chance_Modifier(const float);

		float get_Evasion_Modifier() const;
		void set_Evasion_Modifier(const float);

		std::uint16_t get_Containing_Object_Pointer_Vector_Index() const;
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);
};
#endif
