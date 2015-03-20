#ifndef STARTMENU_H_INCLUDED

#define STARTMENU_H_INCLUDED

#include "SDLincludes.h"
//#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
#include "input.h"
#include "Gamepad.h"
using namespace std;

class startMenu
{
	InputClass input;
public:
	void MenuChoices(SDL_Keycode e);
	/* data */
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

*/

void playerAgency::MenuChoices(SDL_Keycode e)
{
   if (e==SDLK_p)
   {
      debug_log.print = true;
   }
   if (e==SDLK_o)
   {
      debug_log.print = false;
   }
   if (e==SDLK_UP&&gamestate==StartMenu)
   {
      gamestate=Red;
   }
   if (e==SDLK_BACKSPACE)
   {
      gamestate=StartMenu;
   }
   if (e==SDLK_DOWN&&gamestate==StartMenu)
   {
      gamestate=Green;

   }
   if (e==SDLK_LEFT&&gamestate==StartMenu)
   {
      gamestate=all;

   }
   if (e==SDLK_RIGHT&&gamestate==StartMenu)
   {
      gamestate=Blue;

   }
   // if (e==SDLK_BACKSLASH&&gamestate==StartMenu)
   // {
   //    gamestate=Playing;
   // }


}
