//Level header file
#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include <string>
#include "TextureList.h"
#include "../SDLincludes.h"
#include "object/object.h" //Includes all main Box2D headers, "behavior.h", "attributes.h" which includes <algorithm>, "equipment.h" which includes <vector> and "item.h" which includes <iostream> and <cstdint>, and "status_effects.h" which includes "status_effect"

class Level
{
	private:
		//Private static class variables
		const static std::uint16_t maximum_Number_Of_Objects = 100;
		const static std::uint16_t maximum_Number_Of_Textures = 25;
        TetureList textureList;
		//Private member variables
		std::ifstream level_File;
		std::uint16_t number_Of_Objects_In_Level;
		Object level_Objects_Array[Level::maximum_Number_Of_Objects];
		std::string level_Texture_Names_Array[Level::maximum_Number_Of_Textures];
		
		SDL_Renderer* levelRenderer;

	public:
		//Public static class variables

		//Public member variables

		//Constructors and Destructors
		Level();
		Level(std::string);
		Level(std::string,SDL_Renderer*);

		//Static functions

		//Member functions
		void update();
		bool draw();

		//'Getters' and 'Setters' for private member variables
		bool loadLevel(std::string);
		void setRenderer(SDL_Renderer*);
		void setPosition(int index,int x, int y);
		b2Vec2 getPosition(int index);
		int getX(int index);
		int getY(int index);
		int getObjectCount();
};
#endif
