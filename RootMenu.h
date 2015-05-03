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
	Texture Control[15];
	Texture BackGround[4];
	SDL_Rect ChoiceShape;
	SDL_Rect TitleShape;
	SDL_Rect RootShape[2];
	SDL_Rect MenuShape[4];
	SDL_Rect ControlShape[15];
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
	void displayPlatMenu2();
	void UpdateGameMenu1(int choice);
	void UpdateGameMenu2(int choice);
	void UpdateGameMenu3(int choice);

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
	Root[index].loadTextRender("Settings Dont touch", textColor);
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

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Player 1 Control Scheme", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("<Left Keyboard Style>", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Up           W", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Down         S", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Left         A", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Right        D", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Use 		    Z", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Activate      X", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Special       C", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Jump 		 E", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	Control[index].setRenderer(renderer);
	Control[index].setFont("calibri", 20);
	Control[index].loadTextRender("Pause          ESC", textColor);
	ControlShape[index] = {x, y, Control[index].getWidth(), Control[index].getHeight()};
	y += Control[index].getHeight();
	index++;

	index=0;

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

void RootMenu::displayPlatMenu2()
{
	BackGround[1].render(1280,720);
	for(int x = 0; x < 5; x++)
	{
		Control[x].render(ControlShape[x].x , ControlShape[x].y );
	}
}

void RootMenu::UpdateGameMenu1(int choice)
{
      switch (choice)
      {
         case 0:
         Menu[0].loadTextRender("1 player on Keyboard", menuColor);
         Menu[1].loadTextRender("2 players on Keyboard", textColor);
         Menu[2].loadTextRender("1 player on GamePad", textColor);
         Menu[3].loadTextRender("2 players on GamePad", textColor);
         Menu[4].loadTextRender("1 player on Each", textColor);
         break;
         
         case 1:
         Menu[1].loadTextRender("2 players on Keyboard", menuColor);
         Menu[0].loadTextRender("1 player on Keyboard", textColor);
         Menu[2].loadTextRender("1 player on GamePad", textColor);
         Menu[3].loadTextRender("2 players on GamePad", textColor);
         Menu[4].loadTextRender("1 player on Each", textColor);
         break;
         
         case 2:
         Menu[2].loadTextRender("1 player on GamePad", menuColor);
         Menu[0].loadTextRender("1 player on Keyboard", textColor);
         Menu[1].loadTextRender("2 players on Keyboard", textColor);
         Menu[3].loadTextRender("2 players on GamePad", textColor);
         Menu[4].loadTextRender("1 player on Each", textColor);
         break;

         case 3:
         Menu[3].loadTextRender("2 players on GamePad", menuColor);
         Menu[0].loadTextRender("1 player on Keyboard", textColor);
         Menu[1].loadTextRender("2 players on Keyboard", textColor);
         Menu[2].loadTextRender("1 player on GamePad", textColor);
         Menu[4].loadTextRender("1 player on Each", textColor);
         break;

         case 4:
         Menu[4].loadTextRender("1 player on Each", menuColor);
         Menu[0].loadTextRender("1 player on Keyboard", textColor);
         Menu[1].loadTextRender("2 players on Keyboard", textColor);
         Menu[2].loadTextRender("1 player on GamePad", textColor);
         Menu[3].loadTextRender("2 players on GamePad", textColor);
         break;
      }

}
void RootMenu::UpdateGameMenu2(int choice)
{
      switch (choice)
      {
      	case 0:
      	Control[1].loadTextRender("<Left Keyboard Style>", MenuColor);
      	Control[2].loadTextRender("Up            W", textColor);
		Control[3].loadTextRender("Down          S", textColor);
		Control[4].loadTextRender("Left          A", textColor);
		Control[5].loadTextRender("Right         D", textColor);
		Control[6].loadTextRender("Use 		     Z", textColor);
		Control[7].loadTextRender("Activate      X", textColor);
		Control[8].loadTextRender("Special       C", textColor);
		Control[9].loadTextRender("Jump 		 E", textColor);
		Control[10].loadTextRender("Pause        ESC", textColor);
		break;
		case 1:
      	Control[1].loadTextRender("<Right Keyboard Style>", MenuColor);
      	Control[2].loadTextRender("Up            UP", textColor);
		Control[3].loadTextRender("Down          DOWN", textColor);
		Control[4].loadTextRender("Left          LEFT", textColor);
		Control[5].loadTextRender("Right         RIGHT", textColor);
		Control[6].loadTextRender("Use 		     /", textColor);
		Control[7].loadTextRender("Activate      .", textColor);
		Control[8].loadTextRender("Special       M", textColor);
		Control[9].loadTextRender("Jump 		 ,", textColor);
		Control[10].loadTextRender("Pause        Enter", textColor);
		break;
		case 2;
      	Control[1].loadTextRender("<GamePad Style>", MenuColor);
      	Control[2].loadTextRender("Up            UP", textColor);
		Control[3].loadTextRender("Down          DOWN", textColor);
		Control[4].loadTextRender("Left          LEFT", textColor);
		Control[5].loadTextRender("Right         RIGHT", textColor);
		Control[6].loadTextRender("Use 		     A", textColor);
		Control[7].loadTextRender("Activate      X", textColor);
		Control[8].loadTextRender("Special       Y", textColor);
		Control[9].loadTextRender("Jump 		 B", textColor);
		Control[10].loadTextRender("Pause        Start", textColor);
		break;
      }
}
void RootMenu::UpdateGameMenu3(int choice)
{
      switch (choice)
      {
      	case 0:
      	Control[1].loadTextRender("<Left Keyboard Style>", MenuColor);
      	Control[2].loadTextRender("Up            W", textColor);
		Control[3].loadTextRender("Down          S", textColor);
		Control[4].loadTextRender("Left          A", textColor);
		Control[5].loadTextRender("Right         D", textColor);
		Control[6].loadTextRender("Use 		     Z", textColor);
		Control[7].loadTextRender("Activate      X", textColor);
		Control[8].loadTextRender("Special       C", textColor);
		Control[9].loadTextRender("Jump 		 E", textColor);
		Control[10].loadTextRender("Pause        ESC", textColor);
		break;
		case 1:
      	Control[1].loadTextRender("<Right Keyboard Style>", MenuColor);
      	Control[2].loadTextRender("Up            UP", textColor);
		Control[3].loadTextRender("Down          DOWN", textColor);
		Control[4].loadTextRender("Left          LEFT", textColor);
		Control[5].loadTextRender("Right         RIGHT", textColor);
		Control[6].loadTextRender("Use 		     /", textColor);
		Control[7].loadTextRender("Activate      .", textColor);
		Control[8].loadTextRender("Special       M", textColor);
		Control[9].loadTextRender("Jump 		 ,", textColor);
		Control[10].loadTextRender("Pause        Enter", textColor);
		break;
		case 2;
      	Control[1].loadTextRender("<GamePad Style>", MenuColor);
      	Control[2].loadTextRender("Up            UP", textColor);
		Control[3].loadTextRender("Down          DOWN", textColor);
		Control[4].loadTextRender("Left          LEFT", textColor);
		Control[5].loadTextRender("Right         RIGHT", textColor);
		Control[6].loadTextRender("Use 		     A", textColor);
		Control[7].loadTextRender("Activate      X", textColor);
		Control[8].loadTextRender("Special       Y", textColor);
		Control[9].loadTextRender("Jump 		 B", textColor);
		Control[10].loadTextRender("Pause        Start", textColor);
		break;
      }
}

#endif
