#ifndef MAP_H_
#define MAP_H_

#include "SDLincludes.h"
#include "Texture.h"

class Map
{
private:
	Texture platforms[100];
	int platCoords[200];
	int numPlatforms;

public:
	Map();
	~Map();
	bool parseMapFile(std::string,SDL_Renderer*);
	void renderMap();
	void updateMap();
};

#endif