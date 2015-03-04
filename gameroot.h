#ifndef GAMEROOT_H_INCLUDED

#define GAMEROOT_H_INCLUDED


#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
#include "log.h"

#define FPS_INTERVAL 1.0 //Seconds

using namespace std;


class gameroot
{
private:
   bool Running;
   SDL_Window *window;
   SDL_Renderer *renderer;
   SDL_Surface *surface;
   SDL_Surface *image;
   SDL_Texture *texture;
   SDL_Event Event;
   GameState gameState;
   bool initialize();
   int r, g, b; 


public:
   gameroot();
   bool loadContent();
   int execute();
   void OnEvent(SDL_Event *Event);
   void update();
   void draw();
   void close();
   SDL_Texture* loadTexture(std::string path);

   Uint32 GLOBAL_FRAME_COUNTER;
   Uint32 previousTicks;
   Uint32 fps_lasttime; //the last recorded time.
   Uint32 fps_current; //the current FPS.
   Uint32 fps_frames; //frames passed since the last recorded fps.

};
#endif

