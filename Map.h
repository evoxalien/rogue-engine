#ifndef MAP_H_
#define MAP_H_

#include "SDLincludes.h"
#include "Texture.h"
#include "input.h"
#include "Camera.cpp"

class Map
{
private:
	bool drawText;
	SDL_Color textColor;
	Texture textTexture;
	Texture platforms[100];
	int platCoords[200];
	bool platSelected[100];
	int numPlatforms;
	Camera camera;
	SDL_Renderer* render;
	enum CursorState
	{
		Testing,
		Select
	};

	CursorState cState;

public:
	Map();
	~Map();
	bool parseMapFile(std::string filePath,SDL_Renderer* render);
	void renderMap();
	void updateMap();
	void mapEditorUpdate(InputClass input);
	void unfocus();
	void exportMapFile(Uint32 timeStamp);
	int mouseOverPlat(InputClass input);
};

#endif