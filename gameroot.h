#ifndef GAMEROOT_H_INCLUDED

#define GAMEROOT_H_INCLUDED


#include "SDL.h"
#include <stdio.h>
#include <string>

using namespace std;


class gameroot
{
private:
   bool Running;
   SDL_Window *window;
   SDL_Renderer *renderer;
   SDL_Surface *surface;
   SDL_Surface *image;
   SDL_Event Event;
public:
   gameroot();
   int execute();
   bool initialize();
   bool loadContent();
   void OnEvent(SDL_Event *Event);
   void update();
   void draw();
   void close();

};
#endif

