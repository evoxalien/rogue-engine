#ifndef INPUT_H_INCLUDED

#define INPUT_H_INCLUDED

#include "Gamepad.h"
#include <stdio.h>
#include <string>
#include "log.h"

using namespace std;

//david
// enums that track things 
// game state will change based on events
// atm it changes color on the screen
enum GameState
{
   StartMenu,
   Loading,
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
      case SDLK_UP:
		debug_log.print = true;
      break;
      case SDLK_DOWN:
		debug_log.print = false;
      break;
      case SDLK_LEFT:
      break;
      case SDLK_RIGHT:
      break;
      case SDLK_a:
      break;
      case SDLK_b:
      break;
      case SDLK_c:
      break;
      case SDLK_d:
      break;
      case SDLK_e:
      break;
      case SDLK_f:
      break;
      case SDLK_g:
      break;
      case SDLK_h:
      break;
      case SDLK_i:
      break;
      case SDLK_j:
      break;
      case SDLK_k:
      break;
      case SDLK_l:
      break;
      case SDLK_m:
      break;
      case SDLK_n:
      break;
      case SDLK_o:
      break;
      case SDLK_p:
      break;
      case SDLK_q:
      break;
      case SDLK_r:
      break;
      case SDLK_s:
      break;
      case SDLK_t:
      break;
      case SDLK_u:
      break;
      case SDLK_v:
      break;
      case SDLK_w:
      break;
      case SDLK_x:
      break;
      case SDLK_y:
      break;
      case SDLK_z:
      break;
      case SDLK_0:
      break;
      case SDLK_1:
      break;
      case SDLK_2:
      break;
      case SDLK_3:
      break;
      case SDLK_4:
      break;
      case SDLK_5:
      break;
      case SDLK_6:
      break;
      case SDLK_7:
      break;
      case SDLK_8:
      break;
      case SDLK_9:
      break;
      case SDLK_QUOTE:
      break;
      case SDLK_BACKSLASH:
      break;
      case SDLK_BACKSPACE:
      break;
      case SDLK_CAPSLOCK:
      break;
      case SDLK_DELETE:
      break;
      case SDLK_END:
      break;
      case SDLK_EQUALS:
      break;
      case SDLK_ESCAPE:
      break;
      case SDLK_HOME:
      break;
      case SDLK_INSERT:
      break;
      case SDLK_LALT:
      break;
      case SDLK_LCTRL:
      break;
      case SDLK_LEFTBRACKET:
      break;
      case SDLK_LSHIFT:
      break;
      case SDLK_MINUS:
      break;
      case SDLK_PAGEDOWN:
      break;
      case SDLK_PAGEUP:
      break;
      case SDLK_RALT:
      break;
      case SDLK_RCTRL:
      break;
      case SDLK_RETURN:
      break;
      case SDLK_RIGHTBRACKET:
      break;
      case SDLK_RSHIFT:
      break;
      case SDLK_SEMICOLON:
      break;
      case SDLK_SEPARATOR:
      break;
      case SDLK_SLASH:
      break;
      case SDLK_SPACE:
      break;
      case SDLK_TAB:
      break;
          
      default: *gameState=leveledup;
      break;
   } 
   
}
#endif

