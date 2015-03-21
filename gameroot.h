#ifndef GAMEROOT_H_INCLUDED

#define GAMEROOT_H_INCLUDED


//#include "SDL.h"
#include "SDLincludes.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <chrono>
#include "inputDavid.h"
#include "object.h"
#include "log.h"
#include "input.h"
#include "playerAgency.h"
#include "ltimer.h"
#include "Texture.h"
#include "Map.cpp"
#include "mathutil.h"

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
   Texture texture;
   SDL_Event Event;
   int dino;
   Map map;
   enum EngineState
   {
      Waiting,
      PlayingGame,
      MapEditor
   };
   
   EngineState engineState;
//   GameState gameState;
   bool initialize();
   int r, g, b; 
   InputClass input;
   playerAgency player1;

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

