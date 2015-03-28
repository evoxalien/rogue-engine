#ifndef GAMEROOT_H_INCLUDED

#define GAMEROOT_H_INCLUDED


//#include "SDL.h"
#include "SDLincludes.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <chrono>
#include "inputDavid.h"
#include "player.h"
#include "log.h"
#include "input.h"
#include "playerAgency.h"
#include "ltimer.h"
#include "Texture.h"
#include "Map.cpp"
#include "playerClass.h"
#include "startMenu.h"
#include "Gamepad.h"
//#include <thread>

#define FPS_INTERVAL 1.0 //Seconds

using namespace std;

class gameroot
{
private:
	static double maximum_Frame_Rate;
	static double total_Time;
	static std::chrono::high_resolution_clock::time_point start_Of_Previous_Frame;
	static std::chrono::high_resolution_clock::time_point start_Of_Current_Frame;
	static std::chrono::duration<double> time_Of_Previous_Frame;

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
   
   EngineState engineState;
//   GameState gameState;
   bool initialize();
   int r, g, b; 
   InputClass input;
   playerAgency player1;
   // playerClass Hero;
   startMenu Main;

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

