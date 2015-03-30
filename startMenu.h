#ifndef STARTMENU_H_INCLUDED

#define STARTMENU_H_INCLUDED

#include "SDLincludes.h"
//#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
#include "input.h"
#include "Gamepad.h"
#include "log.h"
using namespace std;

class startMenu
{
	InputClass input;
public:
	int MenuChoices(SDL_Keycode e, int gameState);
   void Update();
   void Draw();

};


/*
This controls how the player controls the menu
O and P control debug toggle
BACKSPACE WILL TAKE YOU TO THE MAIN MENU
UP  changes to the RED Menu
DOWN changes to the GREEN Menu
LEFT changes to the ALL Menu
RIGHT changes to the BLUE Menu
T take you to the player
M takes you to the map editor
   enum EngineState
   {
      Waiting,//0
      PlayingGame,//1
      MapEditor,//2
      StartMenu,//3
      Loading,//4
      leveledup,//5
      Paused,//6
      levelSelect,//7
      all,//8
      Red,//9
      Green,//10
      Blue//11
   };
*/

int startMenu::MenuChoices(SDL_Keycode e, int gameState)
{
   if (e==SDLK_p)
   {
      debug_log.print = true;
   }
   if (e==SDLK_o)
   {
      debug_log.print = false;
   }
   if (e==SDLK_UP&&gameState==3)
   {
      return 9;
   }
   if (e==SDLK_BACKSPACE)
   {
      return 3;
   }
   if (e==SDLK_DOWN&&gameState==3)
   {
      return 10;
   }
   if (e==SDLK_LEFT&&gameState==3)
   {
      return 8;
   }
   if (e==SDLK_RIGHT&&gameState==3)
   {
      return 11;
   }

}

void startMenu::Update()
{


}


void startMenu::Draw()
{


}

#endif