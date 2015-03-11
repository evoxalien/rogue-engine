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

void Map::updateMap()
{

}