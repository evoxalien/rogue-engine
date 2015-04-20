#ifndef MAPROOT_H_INCLUDED

#define MAPROOT_H_INCLUDED

#include "SDLincludes.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <chrono>
#include "log.h"
#include "input.h"
#include "ltimer.h"
#include "Texture.h"
#include "Map.cpp"
#include "window.h"
//#include <thread>

#define FPS_INTERVAL 1.0 //Seconds

using namespace std;

class maproot
{
private:
   static double maximum_Frame_Rate;
   static double total_Time;
   
   const int SCREEN_FPS = 60;
   const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
   static std::chrono::high_resolution_clock::time_point start_Of_Previous_Frame;
   static std::chrono::high_resolution_clock::time_point start_Of_Current_Frame;
   static std::chrono::duration<double> time_Of_Previous_Frame;
   

   bool Running;
   Window *window;
   SDL_Renderer *renderer;
   SDL_Event Event;
   Map map;
   //The frames per second timer
   LTimer fpsTimer;
   //The frames per second cap timer
   LTimer capTimer;
  
   //GameState gameState;
   bool initialize();
   InputClass input;
   InputClass previousInput;
   
public:
   maproot(Window *mainWindow); 
   bool loadContent();
   int execute();
   void OnEvent(SDL_Event *Event);
   void update();
   void draw();
   void close();

   Uint32 GLOBAL_FRAME_COUNTER;
   Uint32 previousTicks;
   Uint32 fps_lasttime; //the last recorded time.
   Uint32 fps_current; //the current FPS.
   Uint32 fps_frames; //frames passed since the last recorded fps.

};

double maproot::maximum_Frame_Rate = 120;		//Sets the maximum number of times the main game loop can execute in a single second
double maproot::total_Time = 0;				//The amount of time the game has run from the start of the program
std::chrono::high_resolution_clock::time_point maproot::start_Of_Previous_Frame = std::chrono::high_resolution_clock::now();	//The time point that the previous instance of the main game loop (A 'frame') began
std::chrono::high_resolution_clock::time_point maproot::start_Of_Current_Frame = maproot::start_Of_Previous_Frame;			//The time point at which the currently active frame began
std::chrono::duration<double> maproot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(start_Of_Current_Frame - start_Of_Previous_Frame);	//The length of time the previous frame took to complete


//Simple initializes
maproot::maproot(Window *mainWindow)
{
   Running = false;
   window = mainWindow;
   renderer = NULL;
}


//Initialize all the SDL
bool maproot::initialize()
{
   //Tests SDL components, important to call before other SDL operations
   //https://wiki.libsdl.org/SDL_Init
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
   {
      printf ("SDL Component failed to initialize Error: %s", SDL_GetError());
      return false;
   }

   renderer = window->getRenderer();
   
   //initialize image subsystem to load png files
   int imgFlags = IMG_INIT_PNG;
   if(!(IMG_Init(imgFlags) & imgFlags))
   {
      printf("SDL_Image could not be initialized. SDL_Image error : %s\n", IMG_GetError());
      return false;
   }

   //sets boolean to true. This boolean determines if the game loop continues
   Running = true;
  

   GLOBAL_FRAME_COUNTER = 0;
   fpsTimer.start();
   /*
   previousTicks = 0;
   fps_lasttime = SDL_GetTicks(); //the last recorded time.
   fps_current = 0; //the current FPS.
   fps_frames = 0; //frames passed since the last recorded fps.
   */

   
   return true;
}

//Load textures and other content here
bool maproot::loadContent()
{

   //initialize map from file
   if(!map.parseMapFile("maps/Map1.txt", renderer))
   {
      printf("Map file failed to load!!\n");
   }
   
   return true;

}

//Event checking for game loop 
//Handles Events such as clicks and button pushes
//https://wiki.libsdl.org/SDL_Event
void maproot::OnEvent(SDL_Event *Event)
{
   //Check if event is the clicking of the exit (red x)
   if(Event->type == SDL_WINDOWEVENT)
   {
      if(Event->window.windowID == window->ID)
	  {
	     if(Event->window.event == SDL_WINDOWEVENT_CLOSE)
		 {
		    Event->type = SDL_QUIT;
            SDL_PushEvent(Event);
         }
	  }
   }
   
   
   if(Event->type == SDL_QUIT)
   {
      Running = false;
   }
}

//Does nothing. Math and physics later
void maproot::update()
{
	maproot::total_Time = maproot::total_Time + maproot::time_Of_Previous_Frame.count();	//Add the time of the last frame to the total time

   debug_log << "test " << GLOBAL_FRAME_COUNTER << "\n";


   while(SDL_PollEvent(&Event))
   {
      //Updates input object, holding current buttons pressed
      input.update(Event);
	  
	  //Checking if X has been clicked
      OnEvent(&Event);  
   
      //update current map
      map.mapEditorUpdate(input, previousInput);

      previousInput.update(Event);
   }
   
   std::chrono::high_resolution_clock::time_point time_Before_Function_Call = std::chrono::high_resolution_clock::now();				//Temporary timer for how long the Physics is taking
   std::chrono::duration<double> duration_Of_Function_Call = std::chrono::high_resolution_clock::now() - time_Before_Function_Call;	//Temporary timer
   //cout << "Duration of the function call, check_For_Collisions(), was: " << duration_Of_Function_Call.count() << " seconds." << endl;	//Temporary timer
      

}
   
//Draws to screen
void maproot::draw()
{
   //Start cap Timer
   capTimer.start();

   //Clear screen
   SDL_RenderClear(renderer);

   map.renderMap();

   SDL_RenderPresent(renderer);
   
   ++GLOBAL_FRAME_COUNTER;   

   //If frame finished early
   int frameTicks = capTimer.getTicks();
   if( frameTicks < SCREEN_TICKS_PER_FRAME )
   {
      //Wait remaining time
      SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
   }

   //increment frame counter
}

//Actual game loop
int maproot::execute()
{
   //checks all the SDL (see above)
   if(initialize() == false)
   {
      return - 1;
   }


   if(loadContent() == false)
   {
      printf("Content loaded Improperly");
   }


   while(Running)
   {
      maproot::start_Of_Current_Frame = std::chrono::high_resolution_clock::now();		//At the start of each frame, store the current time
      maproot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(maproot::start_Of_Current_Frame - maproot::start_Of_Previous_Frame);	//Number of clock cycles between frames

	  //update and redraw window
      update();
      draw();

      //std::this_thread::sleep_for(std::chrono::nanoseconds(/*calculate number of nanoseconds to wait based on maximum frame rate and time taken so far*/));
      maproot::start_Of_Previous_Frame = maproot::start_Of_Current_Frame;				//At the end of each frame, store the start time of the current frame to the previous frame
    }

   close() ;
   return 0;
}

//Free all the assets
void maproot::close()
{

   IMG_Quit();
}

#endif

