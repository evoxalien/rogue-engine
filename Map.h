#ifndef MAP_H_
#define MAP_H_

#include "SDLincludes.h"
#include "Texture.h"

class Map
{
private:
	Texture* platforms;

public:
	Map();
	bool parseMapFile(std::string,SDL_Renderer*);
	void renderMap();
	void updateMap();
};

#endif