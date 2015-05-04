#ifndef MAP_H_
#define MAP_H_

#include "PopupMenu.h"
#include "SDLincludes.h"
#include "Texture.h"
#include "input.h"
#include <string>
#include "Camera.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const int PLATMAX = 100;

class Map
{
private:
	PopupMenu pMenu;
	bool menuShown;
	bool anchorPointsShown;
	bool anchorPointSelected[4];
	bool movePlatform;
	bool mouseOverMenuEntry;
	Texture anchorPoints[4];
	Texture backgroundTexture;
	int bgX;
	int bgY;
	bool drawText;
	SDL_Color textColor;
	SDL_Color inputTextColor;
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
	Texture menuSelectionTexture;
	Texture currentInputStringBackground;
	Texture currentInputStringTexture;
	SDL_Rect menuSelectionRect;
	int menuIndex;

	int moveStep;

	enum CursorState
	{
		Testing,
		Select,
		Info,
		Events
	};

	enum MenuState
	{
		Properties,
		TextureProps,
		PhysicsProps
	};

	struct PhysObj
	{
		float angle; //radians
		int bodyType;
		bool tunneling;
		bool fixedRotation;
		float linearDampening;
		float angularDampening;
		float gravityScale;
		bool physicsSleep;
		bool sleepAwake;
		bool activeInactive;
		float density;
		float friction;
		float restitution;
		Uint16 layer;
		Uint16 layersCanCollide;
		int collisionGroupIndex;
		float xVel;
		float yVel;
	};

	CursorState cState;
	MenuState mState;
	PhysObj physicsObjs[PLATMAX];
	std::string keyboardInput;


public:
	Map();
	~Map();
	bool parseMapFile(std::string filePath,SDL_Renderer* render);
	void renderMap();
	void destroyAnchorPoints();
	void displayAnchorPoints();
	void createMenu(int plat, int x, int y);
	void processMenu(InputClass input);
	void processKeyboard(InputClass input, InputClass prevInput);
	void processMouse(InputClass input, InputClass prevInput);
	void mouseOverAction(InputClass input);
	void rightClickAction(InputClass input, InputClass prevInput);
	void leftClickAction(InputClass input, InputClass prevInput);
	void mapEditorUpdate(InputClass input, InputClass prevInput);
	void unfocus();
	void exportMapFile(Uint32 timeStamp);
	bool mouseOverRect(InputClass input, SDL_Rect rect);
};

#endif