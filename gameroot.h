#ifndef GAMEROOT_H_INCLUDED

#define GAMEROOT_H_INCLUDED

#include "SDLincludes.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <chrono>
#include "player.h"
#include "log.h"
#include "input.h"
#include "ltimer.h"
#include "Texture.h"
#include "Map.cpp"
#include "startMenu.h"
#include "Box2D.h"
//#include <thread>

#define FPS_INTERVAL 1.0 //Seconds

using namespace std;

//This is the code to declare a "world" in Box2D that creates all 
//objects/bodies as well as applies gravity and other properties.
//Have fun Andrew
/*
b2Vec2 gravity(0.0f, -10.0f);
b2World world(gravity);
b2BodyDef groundBodyDef;
groundBodyDef.position.Set(0.0f, -10.0f);
b2Body* groundBody = world.CreateBody(&groundBodyDef);
b2PolygonShape groundBox;
groundBox.SetAsBox(50.0f, 10.0f);
groundBody->CreateFixture(&groundBox, 0.0f);
*/

class gameroot
{
private:
   static double maximum_Frame_Rate;
   static double total_Time;
   
   const int SCREEN_WIDTH = 1024;
   const int SCREEN_HEIGHT = 720;
   const int SCREEN_FPS = 60;
   const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
   static std::chrono::high_resolution_clock::time_point start_Of_Previous_Frame;
   static std::chrono::high_resolution_clock::time_point start_Of_Current_Frame;
   static std::chrono::duration<double> time_Of_Previous_Frame;
   
   bool Running;
   SDL_Window *window;
   SDL_Renderer *renderer;
   Texture texture;
   Texture player;
   SDL_Event Event;
   //The frames per second timer
   LTimer fpsTimer;
   //The frames per second cap timer
   LTimer capTimer;
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
   //GameState gameState;
   bool initialize();
   InputClass input;
  
 
public:
   gameroot(); 
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

double gameroot::maximum_Frame_Rate = 120;		//Sets the maximum number of times the main game loop can execute in a single second
double gameroot::total_Time = 0;				//The amount of time the game has run from the start of the program
std::chrono::high_resolution_clock::time_point gameroot::start_Of_Previous_Frame = std::chrono::high_resolution_clock::now();	//The time point that the previous instance of the main game loop (A 'frame') began
std::chrono::high_resolution_clock::time_point gameroot::start_Of_Current_Frame = gameroot::start_Of_Previous_Frame;			//The time point at which the currently active frame began
std::chrono::duration<double> gameroot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(start_Of_Current_Frame - start_Of_Previous_Frame);	//The length of time the previous frame took to complete


//Simple initializes
gameroot::gameroot()
{
   Running = false;
   window = NULL;
   renderer = NULL;
   engineState = Waiting;
   
}


//Initialize all the SDL
bool gameroot::initialize()
{
   //Tests SDL components, important to call before other SDL operations
   //https://wiki.libsdl.org/SDL_Init
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
   {
      printf ("SDL Component failed to initialize Error: %s", SDL_GetError());
      return false;
   }

   //Calls and tests function to create SDL Window (documentation in link)
   //https://wiki.libsdl.org/SDL_CreateWindow
   if((window = SDL_CreateWindow( "Rogue Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN )) == NULL)
   {
      printf ("Window Error: %s", SDL_GetError());
      return false;
   }

   //Creates SDL Renderer. Renderer renders assets to SDL windows
   //Can be used to draw .bmp images to window (example in link)
   //https://wiki.libsdl.org/SDL_CreateRenderer
   renderer = SDL_CreateRenderer ( window , - 1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;

   //Tests if renderer initialized properly
   if (renderer == NULL)
   {
      printf ("Render Error: %s", SDL_GetError());
      return false;
   }

   //set render draw color property
   SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

   //tell texture the renderer to use
   texture.setRenderer(renderer);
   
   player.setRenderer(renderer);

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
bool gameroot::loadContent()
{

   if(!texture.loadTexture("../../images/dino.png"))
   {
      error_log << "Texture failed to load.\n";
      return false;
   }
   texture.setWidth(SCREEN_WIDTH);
   texture.setHeight(SCREEN_HEIGHT);
   
   if(!player.loadTexture("img/shapes/OrangeSquare.png"))
   {
      error_log << "PLayer Texture failed to load.\n";
      return false;
   }
   player.setWidth(30);
   player.setHeight(30);
   
   
   return true;

}

//Event checking for game loop 
//Handles Events such as clicks and button pushes
//https://wiki.libsdl.org/SDL_Event
void gameroot::OnEvent(SDL_Event *Event)
{
   //Check if event is the clicking of the exit (SDL_QUIT)
   if(Event->type == SDL_QUIT)
   {
      Running = false;
   }
}

//Does nothing. Math and physics later
void gameroot::update()
{
   gameroot::total_Time = gameroot::total_Time + gameroot::time_Of_Previous_Frame.count();	//Add the time of the last frame to the total time

   debug_log << "test " << GLOBAL_FRAME_COUNTER << "\n";


   while(SDL_PollEvent(&Event))
   {
      //Updates input object, holding current buttons pressed
      input.update(Event);
	  
	  //Checking if X has been clicked
      OnEvent(&Event);
	  
	    
	}  
      
      if(engineState == MapEditor)
      {
         
      }


}
   
//Draws to screen
void gameroot::draw()
{
   //Start cap Timer
   capTimer.start();

   //Clear screen
   SDL_RenderClear(renderer);

   if(engineState == Waiting)
   {
      
      texture.render(0,0);
      player.render(0,0);
      
   }
   else if(engineState == PlayingGame)
   {
      
   }
   else if(engineState == MapEditor)
   {
      
   }
   
   //update screen
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
int gameroot::execute()
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
      gameroot::start_Of_Current_Frame = std::chrono::high_resolution_clock::now();		//At the start of each frame, store the current time
      gameroot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(gameroot::start_Of_Current_Frame - gameroot::start_Of_Previous_Frame);	//Number of clock cycles between frames

	  //update and redraw window
      update();
      draw();

      //std::this_thread::sleep_for(std::chrono::nanoseconds(/*calculate number of nanoseconds to wait based on maximum frame rate and time taken so far*/));
      gameroot::start_Of_Previous_Frame = gameroot::start_Of_Current_Frame;				//At the end of each frame, store the start time of the current frame to the previous frame
    }

   close() ;
   return 0;
}

//Free all the assets
void gameroot::close()
{
   texture.free();
   player.free();

   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   
   IMG_Quit();
   TTF_Quit();
   SDL_Quit();
}

#endif

