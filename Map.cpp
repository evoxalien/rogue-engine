#include "Map.h"
#include <fstream>

Map::Map()
{
	numPlatforms = 0;
}

Map::~Map()
{
	if(platforms != NULL)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			platforms[x].free();
		}
	}

}

bool Map::parseMapFile(std::string filePath, SDL_Renderer* render)
{
	ifstream inputFile;
	inputFile.open(filePath);
	inputFile >> numPlatforms;

	string shape = "";
	string texturePath = "";
	int w = 0, h = 0;
	for(int x = 0; x < numPlatforms;x++)
	{
		platSelected[x] = false;
		platforms[x].setRenderer(render);
		inputFile >> shape;
		if(shape == "quad")
		{
			inputFile >> platCoords[x*2];
			inputFile >> platCoords[x*2+1];
			inputFile >> w;
			inputFile >> h;
			inputFile >> texturePath;
			platforms[x].loadTexture(texturePath);
			platforms[x].setWidth(w);
			platforms[x].setHeight(h);
		}
	}

	return true;
}

void Map::renderMap()
{
	for(int x = 0; x < numPlatforms; x++)
	{
		platforms[x].render(platCoords[x*2], platCoords[x*2+1]);
	}
}

void Map::updateMap(InputClass input)
{
	if(input.getKeyDown() == SDLK_UP)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2+1]--;
			}
		}
	}
	if(input.getKeyDown() == SDLK_DOWN)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2+1]++;
			}
		}
	}
	if(input.getKeyDown() == SDLK_RIGHT)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2]++;
			}
		}
	}
	if(input.getKeyDown() == SDLK_LEFT)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2]--;
			}
		}
	}

	if(input.getMouseButton(1))
	{
		for(int x = 1; x < numPlatforms; x++)
		{
			if(input.getMouseX() >= platCoords[x*2] &&
				input.getMouseX() <= platCoords[x*2] + platforms[x].getWidth() &&
				input.getMouseY() >= platCoords[x*2+1] &&
				input.getMouseY() <= platCoords[x*2+1] + platforms[x].getHeight())
			{
				platSelected[x] = true;
				platforms[x].setColor(0x77,0x77,0x77);
			}
		}
	}

	if(input.getMouseButton(3))
	{
		for(int x = 1; x < numPlatforms; x++)
		{
			if(input.getMouseX() >= platCoords[x*2] &&
				input.getMouseX() <= platCoords[x*2] + platforms[x].getWidth() &&
				input.getMouseY() >= platCoords[x*2+1] &&
				input.getMouseY() <= platCoords[x*2+1] + platforms[x].getHeight())
			{
				platSelected[x] = false;
				platforms[x].setColor(0xFF,0xFF,0xFF);
			}
		}
	}
}