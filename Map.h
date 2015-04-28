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
	bool anchorPointsShown;
	bool anchorPointSelected[4];
	bool movePlatform;
	Texture anchorPoints[4];
	Texture backgroundTexture;
	int bgX;
	int bgY;
	bool drawText;
	SDL_Color textColor;
	Texture cursorTextTexture;
	Texture platforms[PLATMAX];
	int platCoords[PLATMAX * 2];
	bool platSelected[PLATMAX];
	int numPlatforms;
	Camera camera;
	SDL_Renderer* render;
	int menuX;
	int menuY;
	int cursorX;
	int cursorY;
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

	enum ObjectType
	{
		Rectangle = 0,
		Circle = 1,
		Line = 2,
		Dot = 3
	};

	enum ObjectInteraction
	{
		Static = 0,
		Kinematic = 1,
		Dynamic = 2
	};

	struct Info
	{
		ObjectType objType = Rectangle;
		ObjectInteraction objInteraction = Dynamic;
		bool fixedRotation;
		

	};

	CursorState cState;
	std::string keyboardInput;


public:
	Map();
	~Map();
	bool parseMapFile(std::string filePath,SDL_Renderer* render);
	void renderMap();
	void destroyAnchorPoints();
	void displayAnchorPoints();
	void createPlatMenu(int plat, int x, int y);
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