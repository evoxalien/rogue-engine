#ifndef GAMEMAP_H_
#define GAMEMAP_H_

#include "SDLincludes.h"
#include "Texture.h"
#include "input.h"
#include <string>
#include "Camera.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const int MAXPLATS = 100;

class gameMap
{
private:
	
	Texture backgroundTexture;
	int bgX;
	int bgY;
	SDL_Color textColor;
	Texture platforms[MAXPLATS];
	int platCoords[MAXPLATS * 2];
	bool platSelected[MAXPLATS];
	int numPlatforms;
	Camera camera;
	SDL_Renderer* render;


public:
	gameMap();
	~gameMap();
	bool parseMapFile(std::string filePath,SDL_Renderer* r);
	void renderMap();
	void updateMap();
	void processKeyboard(InputClass input);
	void processMouse(InputClass input);
	void rightClickAction(InputClass input);
	void leftClickAction(InputClass input);
	bool mouseOverRect(InputClass input, SDL_Rect rect);
};

#endif