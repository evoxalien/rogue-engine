//Level header file
#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include "object/object.h"

class Level
{
	private:
		//Private static class variables
		const static std::uint8_t maximum_Number_Of_Objects = 10;

		//Private member variables
		std::ifstream level_File;
		std::uint8_t number_Of_Objects_In_Level;
		Object level_Objects_Array[Level::maximum_Number_Of_Objects];

	public:
		//Public static class variables

		//Public member variables

		//Constructors and Destructors
		Level(std::string);

		//Static functions

		//Member functions
		void display_Information();

		//'Getters' and 'Setters' for private member variables
};
#endif
