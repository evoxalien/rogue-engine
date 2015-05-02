#ifndef ROOTMENU_H_
#define ROOTMENU_H_

#include "SDLincludes.h"
#include "Texture.h"
#include "input.h"
#include <string>
#include "Camera.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class RootMenu
{
public:
	Texture Choice;
	Texture Title;
	Texture Root[3];
	Texture Menu[5];
	Texture BackGround[4];
	SDL_Rect ChoiceShape;
	SDL_Rect TitleShape;
	SDL_Rect RootShape[2];
	SDL_Rect MenuShape[4];
	SDL_Rect BackGroundShape[4];
	bool p1k=false,p2k=false,p1g=false,p2g=false;
	SDL_Renderer* renderer;
	int MenuChoice;
	int index=0;
	SDL_Color textColor;
	SDL_Color menuColor;
	void initilizeMenu(SDL_Renderer *rendererIn);
	void update();
	void Draw();
	void displayPlatMenu();
	void displayPlatMenu1();
};


void RootMenu::initilizeMenu(SDL_Renderer *rendererIn)
{
	int x=720/4;
	int y=720/4;
	menuColor = {0xFF,0xA5,0x00,0xFF};
	textColor = {0xFF,0xA5,0xA5,0xFF};
	renderer=rendererIn;
	
	Root[index].setRenderer(renderer);
	Root[index].setFont("calibri", 20);
	Root[index].loadTextRender("Start", menuColor);
	RootShape[index] = {x, y, Root[index].getWidth(), Root[index].getHeight()};
	y += Root[index].getHeight();
	index++;

	Root[index].setRenderer(renderer);
	Root[index].setFont("calibri", 20);
	Root[index].loadTextRender("other start", textColor);
	RootShape[index] = {x, y, Root[index].getWidth(), Root[index].getHeight()};
	y += Root[index].getHeight();
	index++;

	index =0;
	y=720/4;
	
	Menu[index].setRenderer(renderer);
	Menu[index].setFont("calibri", 20);
	Menu[index].loadTextRender("1 player on Keyboard", menuColor);
	MenuShape[index] = {x, y, Menu[index].getWidth(), Menu[index].getHeight()};
	y += Menu[index].getHeight();
	index++;

	Menu[index].setRenderer(renderer);
	Menu[index].setFont("calibri", 20);
	Menu[index].loadTextRender("2 players on Keyboard", textColor);
	MenuShape[index] = {x, y, Menu[index].getWidth(), Menu[index].getHeight()};
	y += Menu[index].getHeight();
	index++;

	Menu[index].setRenderer(renderer);
	Menu[index].setFont("calibri", 20);
	Menu[index].loadTextRender("1 player on GamePad", textColor);
	MenuShape[index] = {x, y, Menu[index].getWidth(), Menu[index].getHeight()};
	y += Menu[index].getHeight();
	index++;
	
	Menu[index].setRenderer(renderer);
	Menu[index].setFont("calibri", 20);
	Menu[index].loadTextRender("2 players on GamePad", textColor);
	MenuShape[index] = {x, y, Menu[index].getWidth(), Menu[index].getHeight()};
	y += Menu[index].getHeight();
	index++;

	Menu[index].setRenderer(renderer);
	Menu[index].setFont("calibri", 20);
	Menu[index].loadTextRender("1 player on Each", textColor);
	MenuShape[index] = {x, y, Menu[index].getWidth(), Menu[index].getHeight()};
	y += Menu[index].getHeight();
	index++;

	x=0; y=0;
	index =0; 
	BackGround[index].setRenderer(renderer);
	BackGround[index].loadTexture("../resources/img/backgrounds/NightSky.png");
	BackGround[index].setWidth(1280 );
	BackGround[index].setHeight(720);
	index++;

	BackGround[index].setRenderer(renderer);
	BackGround[index].loadTexture("../resources/img/backgrounds/NightSky.png");
	BackGround[index].setWidth(1280 );
	BackGround[index].setHeight(720);
	index++;
	index =0;
}

void RootMenu::displayPlatMenu()
{
	BackGround[0].render(1280,720);
	for(int x = 0; x < 2; x++)
	{
		Root[x].render(RootShape[x].x , RootShape[x].y );
	}
}
void RootMenu::displayPlatMenu1()
{
	BackGround[1].render(1280,720);
	for(int x = 0; x < 5; x++)
	{
		Menu[x].render(MenuShape[x].x , MenuShape[x].y );
	}
}


#endif
