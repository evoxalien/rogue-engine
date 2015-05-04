#ifndef POPUPMENU_H_
#define POPUPMENU_H_

#include "sdlIncludes.h"
#include "texture.h"
#include <iostream>

const int ENTRYMAX = 100;

class PopupMenu
{
private:
	int menuX, menuY;
	int valueX;
	int maxLength;
	int numEntries;
	int fontSize;
	std::string fontName;
	Texture entryTexts[ENTRYMAX*2];
	SDL_Rect entryRects[ENTRYMAX];
	SDL_Color fontColor;

public:
	PopupMenu();
	~PopupMenu();
	void setRenderer(SDL_Renderer* render);
	void addMenuEntry(std::string entryName, std::string entryValue);
	void setLocation(int xLoc, int yLoc);
	void setTextColor(SDL_Color fColor);
	void destroyMenu();
	void setMenuProperties(std::string fName, int fSize, SDL_Color fColor);
	void displayMenu(int camX, int camY);
	SDL_Rect getEntryRect(int index);
	int getNumEntries();
	int getMenuX();
	int getMenuY();
	int getValueX();
};

PopupMenu::PopupMenu()
{
	menuX = 0;
	menuY = 0;
	valueX = 0;
	maxLength = 0;
	numEntries = 0;
}

PopupMenu::~PopupMenu()
{
	for(int x = 0; x < numEntries; x++)
	{
		entryTexts[x*2].free();
		entryTexts[x*2+1].free();
	}
}

void PopupMenu::setRenderer(SDL_Renderer* render)
{
	for(int x = 0; x < ENTRYMAX; x++)
	{
		entryTexts[x].setRenderer(render);
	}
}

void PopupMenu::setMenuProperties(std::string fName, int fSize, SDL_Color fColor)
{
	fontName = fName;
	fontSize = fSize;
	fontColor = fColor;
}

void PopupMenu::setTextColor(SDL_Color fColor)
{
	fontColor = fColor;
}

void PopupMenu::destroyMenu()
{
	std::cerr << "Destorying menu\n";
	for(int x = 0; x < numEntries; x++)
	{
		entryTexts[x*2].free();
		entryTexts[x*2+1].free();
	}
	numEntries = 0;
	maxLength = 0;
	std::cerr << "Menu Destroyed\n";
}

void PopupMenu::setLocation(int xLoc, int yLoc)
{
	menuX = xLoc;
	menuY = yLoc;
}

void PopupMenu::addMenuEntry(std::string entryName, std::string entryValue)
{
	std::cerr << "Adding entry\n";
	entryName += "   ";
	entryTexts[numEntries*2].setFont(fontName, fontSize);
	entryTexts[numEntries*2].loadTextRender(entryName, fontColor);

	entryTexts[numEntries*2+1].setFont(fontName, fontSize);
	entryTexts[numEntries*2+1].loadTextRender(entryValue, fontColor);

	std::cerr << entryName << " " << entryValue << endl;

	if(entryTexts[numEntries*2].getWidth() > maxLength)
	{
		maxLength = entryTexts[numEntries*2].getWidth();
		valueX = menuX + maxLength;
	}

	if(numEntries == 0)
	{
		entryRects[numEntries].x = menuX;
		entryRects[numEntries].y = menuY;
		entryRects[numEntries].w = entryTexts[numEntries*2].getWidth() + entryTexts[numEntries*2+1].getWidth();
		entryRects[numEntries].h = entryTexts[numEntries*2].getHeight();
	}
	else
	{
		entryRects[numEntries].x = menuX;
		entryRects[numEntries].y = entryRects[numEntries-1].y + entryRects[numEntries-1].h;
		entryRects[numEntries].w = (valueX - entryRects[numEntries-1].x) + entryTexts[numEntries*2+1].getWidth();
		entryRects[numEntries].h = entryTexts[numEntries*2].getHeight();
	}

	numEntries++;

	int entryLength = 0;
	for(int x = 0; x < numEntries; x++)
	{
		if(entryRects[x].w > entryLength)
		{
			entryLength = entryRects[x].w;
		}
	}

	for(int x = 0; x < numEntries; x++)
	{
		entryRects[x].w = entryLength;
	}
	std::cerr << "Entry added\n";
}

void PopupMenu::displayMenu(int camX, int camY)
{
	for(int x = 0; x < numEntries; x++)
	{
		entryTexts[x*2].render(entryRects[x].x - camX, entryRects[x].y - camY);
		entryTexts[x*2+1].render(valueX - camX, entryRects[x].y - camY);
	}
}

int PopupMenu::getNumEntries()
{
	return numEntries;
}

SDL_Rect PopupMenu::getEntryRect(int index)
{
	if(index < numEntries)
	{
		return entryRects[index];
	}

	SDL_Rect tempRect;
	tempRect.x = 0;
	tempRect.y = 0;
	tempRect.w = 0;
	tempRect.h = 0;

	return tempRect;
}

int PopupMenu::getMenuX()
{
	return menuX;
}

int PopupMenu::getMenuY()
{
	return menuY;
}

int PopupMenu::getValueX()
{
	return valueX;
}

#endif