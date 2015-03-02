#ifndef INPUT_H_INCLUDED

#define INPUT_H_INCLUDED

#include "Gamepad.h"
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
   Playing,
   leveledup,
   Paused,
   levelSelect
};
//keyboard david 
//http://lazyfoo.net/tutorials/SDL/04_key_presses/index.php

class basicInput
{
private:
   bool mouseArray[5];
   int x, y;
   SDL_Event event;

   void getMouseButtonStates()
   {
      if(event.type == SDL_MOUSEBUTTONDOWN)
      {
         mouseArray[event.button.button - 1] = true;
      }
      if(event.type == SDL_MOUSEBUTTONUP)
      {
         mouseArray[event.button.button - 1] = false;
      }
   }
public:
   InputClass()
   {
      x = y = 0;
      for(int i = 0; i < 5; i++)
      {
         mouseArray[i] = false;  
      }
   }

   void update(SDL_Event e)
   {
      event = e;
      SDL_GetMouseState(&x, &y);
      getMouseButtonStates();
   }

   SDL_Keycode getKeyDown()
   {
      if(event.type == SDL_KEYDOWN)
      {
         return event.key.keysym.sym;
      }
      return -1;
   }

   SDL_Keycode getKeyUp()
   {
      if(event.type == SDL_KEYUP)
      {
         return event.key.keysym.sym;
      }
      return -1;
   }

   bool getMouseButton(int index)
   {
      if(index >= 0 && index <= 5)
      {
         return mouseArray[index - 1];
      }
      return false;
   }

   int getMouseX()
   {
      return x;
   }

   int getMouseY()
   {
      return y;
   }
};




#endif

