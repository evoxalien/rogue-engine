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
	SDL_Rect fullMenuRect;
	SDL_Rect menuChoiceRects[10];
	int menuIndex;

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
	void createPlatMenu(int plat, SDL_Rect menuRect);
	void destroyPlatMenu();
	void displayPlatMenu();
	void processKeyboard(InputClass input, InputClass prevInput);
	void processMouse(InputClass input, InputClass prevInput);
	void rightClickAction(InputClass input, InputClass prevInput);
	void leftClickAction(InputClass input, InputClass prevInput);
	void mapEditorUpdate(InputClass input, InputClass prevInput);
	void unfocus();
	void exportMapFile(Uint32 timeStamp);
	bool mouseOverRect(InputClass input, SDL_Rect rect);
};

#endif