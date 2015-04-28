#ifndef GAMEMENUDAVID_H_INCLUDED

#define GAMEMENUDAVID_H_INCLUDED

#include "SDLincludes.h"
#include <stdio.h>
#include <string>
#include "input.h"
#include "Texture.h"
#include "button.h"

using namespace std;

class GameMenu
{
private:
   enum GameState
   {
      Loading, //0
      RootMenu, //1
      EngineStartMenu, //2
      EngineSettingMenu, //3
      EngineMenu1, //4
      EngineMenu2, //5
      EngineMen3, //6
      MapEditor, //7
      MapEditorMenu1, //8
      MapEditorMenu2, //9
      GameRootMenu, //10
      GameSettingMenu, //11
      GameMenu1, //12
      GameMenu2, //13
      GameMenu3, //14
      GameLoading, //15
      GamePlaying1, //16
      GamePlaying2, //17
      GameMultiplayer, //18
      Test1, //19
      Test2, //20
      Test3 //21
   };
	button Button1;
	button Button2;
	button Button3;
	button Button4;
	button Button5;
	button Button6;
	InputClass input;
	SDL_Event Event;
	GameState gameState;
public:
	int gameInt;
	bool initialize(int passedEnum,SDL_Renderer *rendererIn);
	int execute();
	void OnEvent(SDL_Event *Event);
	int update();
	void draw();
	void close();
	void menu();
};

bool GameMenu::initialize(int passedEnum,SDL_Renderer *rendererIn)
{
	gameInt=passedEnum;
	gameState=(GameState)gameInt;
	if (gameState==GameRootMenu)
	{
		   Button1.setRenderer(rendererIn);
		   Button1.setFont("times");
		   Button1.setWidth(100);
		   Button1.setHeight(200);
		   Button1.setButtonColor(255, 255, 255);
		   Button1.setText("Start Game");
		   
		   Button2.setRenderer(rendererIn);
		   Button2.setFont("times");
		   Button2.setWidth(100);
		   Button2.setHeight(200);
		   Button2.setY(200);
		   Button2.setButtonColor(255, 255, 255);
		   Button2.setText("Settings");
	}
	 //initialize image subsystem to load png files
   int imgFlags = IMG_INIT_PNG;
   if(!(IMG_Init(imgFlags) & imgFlags))
   {
      printf("SDL_Image could not be initialized. SDL_Image error : %s\n", IMG_GetError());
      return false;
   }

}

int GameMenu::update()
{
	if (gameState== GameRootMenu)
	{
		input.update(Event);

		if(Button1.isClicked(input.getMouseX(),input.getMouseY()))
		{
			gameState=Loading;
			gameInt=(int)gameState;
			return gameInt;
		}

		if(Button2.isClicked(input.getMouseX(),input.getMouseY()))
		{
			gameState=GameMenu1;
			gameInt=(int)gameState;
			return gameInt;		
		}
	}
	if (gameState== GameMenu1)
	{
		Button3.setRenderer(rendererIn);
		Button3.setFont("times");
		Button3.setWidth(100);
		Button3.setHeight(200);
		Button3.setButtonColor(255, 255, 255);
		Button3.setText("1 player Keyboard");

		Button4.setRenderer(rendererIn);
		Button4.setFont("times");
		Button4.setWidth(100);
		Button4.setHeight(200);
		Button4.setY(200);
		Button4.setButtonColor(255, 255, 255);
		Button4.setText("2 player Keyboard");
		Button5.setRenderer(rendererIn);
		Button5.setFont("times");
		Button5.setWidth(100);
		Button5.setHeight(200);
		Button5.setY(400);
		Button5.setButtonColor(255, 255, 255);
		Button5.setText("1 player GamePad");

		Button6.setRenderer(rendererIn);
		Button6.setFont("times");
		Button6.setWidth(100);
		Button6.setHeight(200);
		Button6.setY(600);
		Button6.setButtonColor(255, 255, 255);
		Button6.setText("2 player GamePad");

		if(Button3.isClicked(input.getMouseX(),input.getMouseY()))
		{
			gameState=Loading;
			gameInt=(int)gameState;
			return gameInt;
		}

		if(Button4.isClicked(input.getMouseX(),input.getMouseY()))
		{
			gameState=GameMenu1;
			gameInt=(int)gameState;
			return gameInt;		
		}
		if(Button5.isClicked(input.getMouseX(),input.getMouseY()))
		{
			gameState=Loading;
			gameInt=(int)gameState;
			return gameInt;
		}

		if(Button6.isClicked(input.getMouseX(),input.getMouseY()))
		{
			gameState=GameMenu1;
			gameInt=(int)gameState;
			return gameInt;		
		}
	}
}

#endif