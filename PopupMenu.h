#ifndef POPUPMENU_H_
#define POPUPMENU_H_

#include "SDLincludes.h"
#include "Texture.h"
#include "Camera.cpp"
#include <iostream>

const int ENTRYMAX = 100;

class PopupMenu
{
private:
	int menuX, menuY;
	Texture entryTexts[ENTRYMAX];
	shape easyShapes;
	button entryButtons[ENTRYMAX];
	SDL_Render* renderer;

public:
	PopupMenu();
	~PopupMenu();
	void addMenuEntry();
	void addMenuButton();
	void displayMenu();
};

PopupMenu::PopupMenu(SDL_Render* render)
{
	menuX = 0;
	menuY = 0;
	renderer = render;
}

PopupMenu::~PopupMenu()
{

}

void PopupMenu::addMenuEntry()
{

}

void PopupMenu::addMenuButton()
{

}

void PopupMenu::displayMenu()
{

}

#endif