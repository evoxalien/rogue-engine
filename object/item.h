//Item header file
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstdint>

enum class Item_States : std::uint8_t		//An enumeration representing where the Object is within the game-world which affects 
{
	On_Ground,
	In_Inventory,
	Equipped
};

class Item
{
	friend class Equipment;

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

		float phyiscal_Attack_Range_Modifier;
		float phyiscal_Damage_Modifier;
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

		void display_Information();

		//'Getters' and 'Setters' for private member variables
		const std::uint16_t get_Containing_Object_Pointer_Vector_Index();
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);
};
#endif
