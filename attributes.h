//Attributes header file
#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include <cstdint>

enum class Object_Attributes : std::uint8_t		//Various attributes that an Object may innately possess; ensure that only the default values are used in all contained enumerators
{
	Strength,						//An estimate of the Physical prowess of the Object, and can be increased as level increases; affects Carrying_Capacity (Indirectly affects Movement_Speed), and Physical_Damage
	Dexterity,						//An estimate of how agile the Object is, and can be increased as level increases; affects Accuracy, Rate_Of_Physical_Attacks, Physical_Accuracy, Rate_Of_Magical_Attacks, Magical_Accuracy, Movement_Speed, Evasion, and Block_Chance
	Endurance,						//An estimate of how much Physical perseverence an Object has, and can be increased as level increases; affects Carrying_Capacity (Indirectly affects Movement_Speed), Maximum_Health, Rate_Of_Health_Regeneration, Physical_Defense, Magical_Defense, Block_Chance, Maximum_Stamina, and Rate_Of_Stamina_Regeneration
	Intelligence,					//An estimate of the magical prowess an Object has, and can be increased as level increases; affects Magical_Damage, Maximum_Mana, and Rate_Of_Mana_Regeneration
	Perception,						//An estimate of how observant the Object is of its surroundings and changes in the environment, and can be increased as level increases; affects Vision_Range, Hearing_Range, Physical_Accuracy, Magical_Accuracy, Block_Chance, and Evasion

	Experience,						//The total amount of 'experience' the Object has accumulated, which, when certain thresholds are reached, increases the Level; typically used for the Players and persistent friendly NPCs
	Level,							//An estimate of the approximate difficulty of an Object or strength of a Player; is governed by the Experience of Players, and allows the growth of Strength, Dexterity, Endurance, and/or Perception upon an increase

	Carrying_Capacity,				//The maximum weight that the Object may carry while still being able to perform intense actions unrestricted- further modified by Strength and Endurance
	Amount_Carried,					//The current amount of weight that the Object is carrying within its inventory and equipped items

	Vision_Range,					//The maximum distance at which the Object may clearly identify a target in front of it- modified by Perception
	Hearing_Range,					//The maximum distance at which the Object may clearly distinguish a noise produced around it- modified by Perception

	Physical_Attack_Range,			//The maximum range at which the Object may potentially hit a target with the currently equipped weapon; further modified by weapon statistics
	Physical_Damage,				//The amount of health reduced on the target with a successful attack from the equipped weapon- modified by weapon statistics and Strength for most weapons
	Rate_Of_Physical_Attacks,		//The maximum number of attacks that can be made in one second with the current weapon- modified by weapon statistics and Dexterity for most weapons
	Physical_Accuracy,				//A relative measure of the likelihood of a blow successfully damaging a target within range before their Evasion- modified by weapon statistics, Perception, and Dexterity for most weapons

	Magical_Attack_Range,			//The maximum range at which the Object may potentially hit a target with the currently equipped 'spell'; modified by equipment
	Magical_Damage,					//The amounts of health reduced on the target with a successful hit from the equipped 'spell'- modified by equipment and Intelligence for most 'spells'
	Rate_Of_Magical_Attacks,		//The maximum number of spells that could be cast in one second with the currently equipped 'spell'- modified by equipment and Dexterity for most 'spells'
	Magical_Accuracy,				//A relative measure of the likelihood of a 'spell' successfully damaging a target within range before their Evasion- modified by Perception and Dexterity for most 'spells'

	Maximum_Stamina,				//A measure of the maximum amount of 'physical energy' the Object can exert, with more intense actions, such as weapon 'special attacks' or sprinting, using more energy; modified by Endurance
	Stamina,						//The current amount of 'physical energy' the Object possesses
	Rate_Of_Stamina_Regeneration,	//The amount of Stamina that the Object will naturally recover per second; modified by Endurance and equipment
	Movement_Speed,					//The maximum velocity the object can attain under normal conditions; does not apply to falling, being knocked back, or similar events- modified by Dexterity, equipment, and the relative amount of Carrying_Capacity and Amount_Carried

	Maximum_Health,					//The maximum amount of damage that an Object may receive before dying- modified by Endurance and equipment
	Health,							//The current amount of damage that the Object can sustain; when it is 0, the Object is consided 'dead'- changes upon the Object receiving damage or healing from any source
	Rate_Of_Health_Regeneration,	//The amount of Health that the Object will naturally recover per second; modified by Endurance and equipment

	Physical_Defense,				//A relative measure of the amount of damage that an Object will mitigate from a phyiscal damage source; further modified by equipment and Endurance
	Magical_Defense,				//A relative measure of the amount of damage that an Object will mitigate from a phyiscal damage source; further modified by equipment and Endurance
	Block_Chance,					//A relative measure of the likelihood that a successful attack may be 'blocked', further mitigating a portion of the damage based on Physical_Defense or Magical_Defense- further modified by equipment, Dexterity, and Perception
	Evasion,						//A relative measure of the likelihood that an otherwise successful physical or magical attack may be avoided, mitigating all damage- modified by Dexterity and Perception

	Maximum_Mana,					//The maximum amount of 'magical energy' the Object can exert, with stronger 'spells' requiring additional 'magical energy'- modified by equipment and Intelligence
	Mana,							//The current amount of 'magical energy' the Object possesses
	Rate_Of_Mana_Regeneration,		//The amount of Mana that the Object will naturally recover per second; modified by Intelligence and equipment

	TOTAL_NUMBER_OF_ATTRIBUTES		//Ensure this value is always at the end of Attributes and cast as an appropriate integer type when used; represents the number of different valid enumerators inside of Attributes
};

class Attributes
{
	friend class Object;			//Allows access to Object's private members- Equipment and Inventory (Which are not currently implemented)

	private:
		//Private member variables
		float attributes[static_cast<std::uint16_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES)];	//An array of floats sized to the number of attributes and containing attribute data corresponding to enumerator position
		std::uint16_t containing_Object_Pointer_Vector_Index;	//The index of the Object in which the Attributes member resides inside of the static Object Pointer Vector in the Object class

	public:
		//Constructor
		Attributes();									//Default Constructor; most attributes will initialize to 1 and some to 0
		Attributes(float[static_cast<std::uint16_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES)]);	//Constructor called when an appropriately sized array containing already known data values is used

		void display_Information();						//For testing

		//'Getters' and 'Setters' for private member variables
		void set_Attributes(const float[static_cast<std::uint16_t>(Object_Attributes::TOTAL_NUMBER_OF_ATTRIBUTES)]);
		const float* get_Attributes();

		void set_Experience(const float);
		const float get_Experience();

		void set_Containing_Object_Pointer_Vector_Index(const std::uint16_t);
		const std::uint16_t get_Containing_Object_Pointer_Vector_Index();
};

#include "object.h"		//Object and its components need to have headers fully defined for some Attribute function definitions

#endif
