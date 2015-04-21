//Attributes header file; friend of Object class
#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include <algorithm>

class Attributes
{
	private:
		//Private static class variables
		//The following variables contain the 'rules' of how much certain attributes contribute to other attributes for all Objects
		static float carrying_Capacity_Per_Strength;
		static float carrying_Capacity_Per_Endurance;
		static float vision_Range_Per_Perception;
		static float hearing_Range_Per_Perception;
		static float physical_Damage_Per_Strength;
		static float rate_Of_Physical_Attacks_Per_Dexterity;
		static float physical_Accuracy_Per_Dexterity;
		static float physical_Accuracy_Per_Perception;
		static float magical_Damage_Per_Intelligence;
		static float rate_Of_Magical_Attacks_Per_Dexterity;
		static float magical_Accuracy_Per_Dexterity;
		static float magical_Accuracy_Per_Perception;
		static float movement_Speed_Per_Dexterity;
		static float maximum_Stamina_Per_Endurance;
		static float rate_Of_Stamina_Regeneration_Per_Endurance;
		static float maximum_Mana_Per_Intelligence;
		static float rate_Of_Mana_Regeneration_Per_Intelligence;
		static float maximum_Health_Per_Endurance;
		static float rate_Of_Health_Regeneration_Per_Endurance;
		static float physical_Defense_Per_Endurance;
		static float magical_Defense_Per_Endurance;
		static float block_Chance_Per_Dexterity;
		static float block_Chance_Per_Perception;
		static float evasion_Per_Dexterity;
		static float evasion_Per_Perception;

		//Private member variables
		std::uint16_t containing_Object_Pointer_Vector_Index;	//The index of the Object in which the Attributes member resides inside of the static Object Pointer Vector in the Object class

		//'Innate' attributes of the Object; they are further modified by attribute rules, equipment, and status effects
		float strength;						//An estimate of the Physical prowess of the Object, and can be increased as level increases; affects carrying_Capacity (Indirectly affects movement_Speed), and physical_Damage
		float dexterity;					//An estimate of how agile the Object is, and can be increased as level increases; affects accuracy, rate_Of_Physical_Attacks, physical_Accuracy, rate_Of_Magical_Attacks, magical_Accuracy, movement_Speed, block_Chance, and evasion
		float endurance;					//An estimate of how much Physical perseverence an Object has, and can be increased as level increases; affects carrying_Capacity (Indirectly affects movement_Speed), maximum_Stamina, rate_Of_Stamina_Regeneration, maximum_Health, rate_Of_Health_Regeneration, physical_Defense, magical_Defense, and block_Chance
		float intelligence;					//An estimate of the magical prowess an Object has, and can be increased as level increases; affects magical_Damage, maximum_Mana, and rate_Of_Mana_Regeneration
		float perception;					//An estimate of how observant the Object is of its surroundings and changes in the environment, and can be increased as level increases; affects vision_Range, hearing_Range, physical_Accuracy, magical_Accuracy, block_Chance, and evasion

		float experience;					//The total amount of 'experience' the Object has accumulated, which, when certain thresholds are reached, increases the Level; typically used for the Players and persistent friendly NPCs
		float level;						//An estimate of the approximate difficulty of an Object or strength of a Player; is governed by the Experience of Players, and allows the growth of Strength, Dexterity, Endurance, and/or Perception upon an increase

		float carrying_Capacity;			//The maximum weight that the Object may carry while still being able to perform intense actions unrestricted- further modified by Strength and Endurance
		float amount_Carried;				//The current amount of weight that the Object is carrying within its inventory and equipped items

		float vision_Range;					//The maximum distance at which the Object may clearly identify a target in front of it- modified by Perception
		float hearing_Range;				//The maximum distance at which the Object may clearly distinguish a noise produced around it- modified by Perception

		float physical_Attack_Range;		//The maximum range at which the Object may potentially hit a target with its natural body; further modified by weapon statistics
		float physical_Damage;				//The amount of health reduced on the target with a successful attack from the equipped weapon- further modified by weapon statistics and Strength for most weapons
		float rate_Of_Physical_Attacks;		//The maximum number of attacks that can be made in one second with the current weapon- modified by weapon statistics and Dexterity for most weapons
		float physical_Accuracy;			//A relative measure of the likelihood of a blow successfully damaging a target within range before their Evasion- modified by weapon statistics, Perception, and Dexterity for most weapons

		float magical_Attack_Range;			//The maximum range at which the Object may potentially hit a target with the currently equipped 'spell'; modified by equipment
		float magical_Damage;				//The amounts of health reduced on the target with a successful hit from the equipped 'spell'- modified by equipment and Intelligence for most 'spells'
		float rate_Of_Magical_Attacks;		//The maximum number of spells that could be cast in one second with the currently equipped 'spell'- modified by equipment and Dexterity for most 'spells'
		float magical_Accuracy;				//A relative measure of the likelihood of a 'spell' successfully damaging a target within range before their Evasion- modified by Perception and Dexterity for most 'spells'

		float movement_Speed;				//The maximum velocity the object can attain under normal conditions; does not apply to falling, being knocked back, or similar events- modified by Dexterity, equipment, and the relative amount of Carrying_Capacity and Amount_Carried

		float maximum_Stamina;				//A measure of the maximum amount of 'physical energy' the Object can exert, with more intense actions, such as weapon 'special attacks' or sprinting, using more energy; modified by Endurance
		float stamina;						//The current amount of 'physical energy' the Object possesses
		float rate_Of_Stamina_Regeneration;	//The amount of Stamina that the Object will naturally recover per second; modified by Endurance and equipment

		float maximum_Mana;					//The maximum amount of 'magical energy' the Object can exert, with stronger 'spells' requiring additional 'magical energy'- modified by equipment and Intelligence
		float mana;							//The current amount of 'magical energy' the Object possesses
		float rate_Of_Mana_Regeneration;	//The amount of Mana that the Object will naturally recover per second; modified by Intelligence and equipment

		float maximum_Health;				//The maximum amount of damage that an Object may receive before dying- modified by Endurance and equipment
		float health;						//The current amount of damage that the Object can sustain; when it is 0, the Object is consided 'dead'- changes upon the Object receiving damage or healing from any source
		float rate_Of_Health_Regeneration;	//The amount of Health that the Object will naturally recover per second; modified by Endurance and equipment

		float physical_Defense;				//A relative measure of the amount of damage that an Object will mitigate from a physical damage source; further modified by equipment and Endurance
		float magical_Defense;				//A relative measure of the amount of damage that an Object will mitigate from a physical damage source; further modified by equipment and Endurance
		float block_Chance;					//A relative measure of the likelihood that a successful attack may be 'blocked', further mitigating a portion of the damage based on Physical_Defense or Magical_Defense- further modified by equipment, Dexterity, and Perception
		float evasion;						//A relative measure of the likelihood that an otherwise successful physical or magical attack may be avoided, mitigating all damage- modified by Dexterity and Perception

	public:
		//Constructor
		Attributes();									//Default Constructor; most attributes will initialize to 1 and some to 0

		//Public static functions
		//'Getters' and 'Setters' for private static variables
		const static float get_Carrying_Capacity_Per_Strength();
		static float set_Carrying_Capacity_Per_Strength(const float);

		const static float get_Carrying_Capacity_Per_Endurance();
		static float set_Carrying_Capacity_Per_Endurance(const float);

		const static float get_Vision_Range_Per_Perception();
		static float set_Vision_Range_Per_Perception(const float);

		const static float get_Hearing_Range_Per_Perception();
		static float set_Hearing_Range_Per_Perception(const float);

		const static float get_Physical_Damage_Per_Strength();
		static float set_Physical_Damage_Per_Strength(const float);

		const static float get_Rate_Of_Physical_Attacks_Per_Dexterity();
		static float set_Rate_Of_Physical_Attacks_Per_Dexterity(const float);

		const static float get_Physical_Accuracy_Per_Dexterity();
		static float set_Physical_Accuracy_Per_Dexterity(const float);

		const static float get_Physical_Accuracy_Per_Perception();
		static float set_Physical_Accuracy_Per_Perception(const float);

		const static float get_Magical_Damage_Per_Intelligence();
		static float set_Magical_Damage_Per_Intelligence(const float);

		const static float get_Rate_Of_Magical_Attacks_Per_Dexterity();
		static float set_Rate_Of_Magical_Attacks_Per_Dexterity(const float);

		const static float get_Magical_Accuracy_Per_Dexterity();
		static float set_Magical_Accuracy_Per_Dexterity(const float);

		const static float get_Magical_Accuracy_Per_Perception();
		static float set_Magical_Accuracy_Per_Perception(const float);

		const static float get_Movement_Speed_Per_Dexterity();
		static float set_Movement_Speed_Per_Dexterity(const float);

		const static float get_Maximum_Stamina_Per_Endurance();
		static float set_Maximum_Stamina_Per_Endurance(const float);

		const static float get_Rate_Of_Stamina_Regeneration_Per_Endurance();
		static float set_Rate_Of_Stamina_Regeneration_Per_Endurance(const float);

		const static float get_Maximum_Mana_Per_Intelligence();
		static float set_Maximum_Mana_Per_Intelligence(const float);

		const static float get_Rate_Of_Mana_Regeneration_Per_Intelligence();
		static float set_Rate_Of_Mana_Regeneration_Per_Intelligence(const float);

		const static float get_Maximum_Health_Per_Endurance();
		static float set_Maximum_Health_Per_Endurance(const float);

		const static float get_Rate_Of_Health_Regeneration_Per_Endurance();
		static float set_Rate_Of_Health_Regeneration_Per_Endurance(const float);

		const static float get_Physical_Defense_Per_Endurance();
		static float set_Physical_Defense_Per_Endurance(const float);

		const static float get_Magical_Defense_Per_Endurance();
		static float set_Magical_Defense_Per_Endurance(const float);

		const static float get_Block_Chance_Per_Dexterity();
		static float set_Block_Chance_Per_Dexterity(const float);

		const static float get_Block_Chance_Per_Perception();
		static float set_Block_Chance_Per_Perception(const float);

		const static float get_Evasion_Per_Dexterity();
		static float set_Evasion_Per_Dexterity(const float);

		const static float get_Evasion_Per_Perception();
		static float set_Evasion_Per_Perception(const float);

		//Public member functions
		void display_Information();						//For testing
		void update();

		//The 'get_Effective_Attribute()' functions return the corresponding attribute plus or minus all modifications from equipment and special effects the Object is affected by; experience, level, amoutn_Carried, health, stamina, and mana already have their effective values stored, so do not have functions here and should use the regular 'get_Attribute()' functions 
		const float get_Effective_Strength();
		const float get_Effective_Dexterity();
		const float get_Effective_Endurance();
		const float get_Effective_Intelligence();
		const float get_Effective_Perception();
		const float get_Effective_Carrying_Capacity();
		const float get_Effective_Vision_Range();
		const float get_Effective_Hearing_Range();
		const float get_Effective_Physical_Attack_Range();
		const float get_Effective_Physical_Damage();
		const float get_Effective_Rate_Of_Physical_Attacks();
		const float get_Effective_Physical_Accuracy();
		const float get_Effective_Magical_Attack_Range();
		const float get_Effective_Magical_Damage();
		const float get_Effective_Rate_Of_Magical_Attacks();
		const float get_Effective_Magical_Accuracy();
		const float get_Effective_Movement_Speed();
		const float get_Effective_Maximum_Stamina();
		const float get_Effective_Rate_Of_Stamina_Regeneration();
		const float get_Effective_Maximum_Mana();
		const float get_Effective_Rate_Of_Mana_Regeneration();
		const float get_Effective_Maximum_Health();
		const float get_Effective_Rate_Of_Health_Regeneration();
		const float get_Effective_Physical_Defense();
		const float get_Effective_Magical_Defense();
		const float get_Effective_Block_Chance();
		const float get_Effective_Evasion();

		//'Getters' and 'Setters' for private member variables
		const std::uint16_t get_Containing_Object_Pointer_Vector_Index();
		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);

		const float get_Strength();
		void set_Strength(const float);

		const float get_Dexterity();
		void set_Dexterity(const float);

		const float get_Endurance();
		void set_Endurance(const float);

		const float get_Intelligence();
		void set_Intelligence(const float);

		const float get_Perception();
		void set_Perception(const float);

		const float get_Experience();
		void set_Experience(const float);

		const float get_Level();
		void set_Level(const float);

		const float get_Carrying_Capacity();
		void set_Carrying_Capacity(const float);

		const float get_Amount_Carried();
		void set_Amount_Carried(const float);

		const float get_Vision_Range();
		void set_Vision_Range(const float);

		const float get_Hearing_Range();
		void set_Hearing_Range(const float);

		const float get_Physical_Attack_Range();
		void set_Physical_Attack_Range(const float);

		const float get_Physical_Damage();
		void set_Physical_Damage(const float);

		const float get_Rate_Of_Physical_Attacks();
		void set_Rate_Of_Physical_Attacks(const float);

		const float get_Physical_Accuracy();
		void set_Physical_Accuracy(const float);

		const float get_Magical_Attack_Range();
		void set_Magical_Attack_Range(const float);

		const float get_Magical_Damage();
		void set_Magical_Damage(const float);

		const float get_Rate_Of_Magical_Attacks();
		void set_Rate_Of_Magical_Attacks(const float);

		const float get_Magical_Accuracy();
		void set_Magical_Accuracy(const float);

		const float get_Movement_Speed();
		void set_Movement_Speed(const float);

		const float get_Maximum_Stamina();
		void set_Maximum_Stamina(const float);

		const float get_Stamina();
		void set_Stamina(const float);

		const float get_Rate_Of_Stamina_Regeneration();
		void set_Rate_Of_Stamina_Regeneration(const float);

		const float get_Maximum_Mana();
		void set_Maximum_Mana(const float);

		const float get_Mana();
		void set_Mana(const float);

		const float get_Rate_Of_Mana_Regeneration();
		void set_Rate_Of_Mana_Regeneration(const float);

		const float get_Maximum_Health();
		void set_Maximum_Health(const float);

		const float get_Health();
		void set_Health(const float);

		const float get_Rate_Of_Health_Regeneration();
		void set_Rate_Of_Health_Regeneration(const float);

		const float get_Physical_Defense();
		void set_Physical_Defense(const float);

		const float get_Magical_Defense();
		void set_Magical_Defense(const float);

		const float get_Block_Chance();
		void set_Block_Chance(const float);

		const float get_Evasion();
		void set_Evasion(const float);
};

#endif
