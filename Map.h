#ifndef MAP_H_
#define MAP_H_

#include "SDLincludes.h"
#include "Texture.h"
#include "input.h"
#include <string>
#include "Camera.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const int PLATMAX = 100;

class Map
{
private:
	bool rightClickMenuShown;
	Texture rightClickMenuText[10];
	bool drawText;
	SDL_Color textColor;
	Texture textTexture;
	Texture platforms[PLATMAX];
	int platCoords[PLATMAX * 2];
	bool platSelected[PLATMAX];
	int numPlatforms;
	Camera camera;
	SDL_Renderer* render;
	int menuX;
	int menuY;

	int moveStep;

	enum CursorState
	{
		Testing,
		Select,
		Info
	};

	CursorState cState;
	std::string keyboardInput;


public:
	Map();
	~Map();
	bool parseMapFile(std::string filePath,SDL_Renderer* render);
	void renderMap();
	void updateMap();
	void createPlatMenu(int plat);
	void destroyPlatMenu();
	void displayPlatMenu();
	void rightClickAction(InputClass input);
	void mapEditorUpdate(InputClass input);
	void unfocus();
	void exportMapFile(Uint32 timeStamp);
	int mouseOverPlat(InputClass input);
};

#endif