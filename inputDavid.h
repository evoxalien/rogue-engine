#ifndef INPUT_H_INCLUDED

#define INPUT_H_INCLUDED


#include <stdio.h>
#include <string>

using namespace std;

//david
// enums that track things 
// game state will change based on events
// atm it changes color on the screen
enum GameState
{
   StartMenu,
   Loading,
   EndMenu,
   Playing,
   leveledup,
   Paused,
   levelSelect
};
//keyboard david 
//http://lazyfoo.net/tutorials/SDL/04_key_presses/index.php

void keyPress(GameState *gameState, SDL_Event *Event)
{
   //change the screen based on key 
   switch (Event->key.keysym.sym)
   {   
      case SDLK_UP: *gameState=StartMenu;
      break;
      case SDLK_DOWN: *gameState=EndMenu;
      break;
      case SDLK_LEFT: *gameState=Playing;
      break;
      case SDLK_RIGHT: *gameState=Paused;
      break;
      default: *gameState=leveledup;
      break;
   } 
   
}
#endif

