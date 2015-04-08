#ifndef MAP_H_
#define MAP_H_

#include "SDLincludes.h"
#include "Texture.h"
#include "Camera.cpp"
#include <iostream>

const int ENTRYMAX = 100;

class PopupMenu
{
private:
	Texture entryTexts[ENTRYMAX];
	shape easyShapes;
	button entryButtons[ENTRYMAX];

public:
	PopupMenu();
	~PopupMenu();
	addMenuEntry();
	addMenuButton();
	displayMenu();
};

#endif