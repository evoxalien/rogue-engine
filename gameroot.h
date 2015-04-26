#ifndef GAMEROOT_H_INCLUDED

#define GAMEROOT_H_INCLUDED

#include "SDLincludes.h"
#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include "level/level.h"	//Includes level and all Object header files and all Object component header files, including Box2D's, along with <fstream>, <string>, <algorithm>, <iostream>, <vector>, <cstdint> but excluding inherited classes (Player, NonPlayerCharacter)
#include "log.h"
#include "input.h"
#include "SoundManager.h"
#include "ltimer.h"
#include "Texture.h"
#include "mathutil.h"
#include "startMenu.h"
#include "playerClass.h"
#include "gameMap.cpp"
#include "window.h"
#include "engineState.h"
/*
#include "particlemanager.h"
#include "particle.h"*/
//#include <thread>


#define FPS_INTERVAL 1.0 //Seconds

using namespace std;


class gameroot
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
   EngineState *engineState;
   SDL_Renderer *renderer;
   Texture texture;
   // Texture playerTexture;
   SDL_Event Event;
   //The frames per second timer
   LTimer fpsTimer;
   //The frames per second cap timer
   LTimer capTimer;
   enum GameState
   {
      Loading, //0
      RootMenu, //1
      EngineStartMenu, //2
      EngineSettingMenu, //3
      EngineMenu1, //4
      EngineMenu2, //5
      EngineMen3, //6
      MapEditor, //7
      MapEditorMenu1, //8
      MapEditorMenu2, //9
      GameRootMenu, //10
      GameSettingMenu, //11
      GameMenu1, //12
      GameMenu2, //13
      GameMenu3, //14
      GameLoading, //15
      GamePlaying1, //16
      GamePlaying2, //17
      GameMultiplayer, //18
      Test1, //19
      Test2, //20
      Test3 //21
   };
   
   GameState gameState;
   //GameState gameState;
   int EngineActiveState;
   playerClass Hero;
   bool initialize();
   InputClass input;
   
   gameMap GameMap;
   Sound_Manager soundManager;
 
public:
   gameroot(Window *mainWindow, EngineState *currentState); 
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
gameroot::gameroot(Window *mainWindow, EngineState *currentState)
{
   Running = false;
   window = mainWindow;
   engineState = currentState;
   renderer = NULL;
   gameState = Loading;
   
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

   renderer = window->getRenderer();
   
   //tell texture the renderer to use
   texture.setRenderer(renderer);
   
   // Hero.playerTexture.setRenderer(renderer);

   //initialize image subsystem to load png files
   int imgFlags = IMG_INIT_PNG;
   if(!(IMG_Init(imgFlags) & imgFlags))
   {
      printf("SDL_Image could not be initialized. SDL_Image error : %s\n", IMG_GetError());
      return false;
   }

   GameMap.parseMapFile("mapTree", renderer);

   //sets boolean to true. This boolean determines if the game loop continues
   Running = true;
  
   GLOBAL_FRAME_COUNTER = 0;
   fpsTimer.start();
   /*3
   previousTicks = 0;
   fps_lasttime = SDL_GetTicks(); //the last recorded time.
   fps_current = 0; //the current FPS.
   fps_frames = 0; //frames passed since the last recorded fps.
   */
   Hero.playerInitalize(1);
   Hero.InitSprite(renderer);
   Hero.init();
   //Sound Manager Initialize
   soundManager.Init();

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
   texture.setWidth(window->getWidth());
   texture.setHeight(window->getHeight());
   Hero.LoadSpriteContent();
   
   // if(!Hero.playerTexture.loadTexture("img/shapes/OrangeSquare.png"))
   // {
   //    error_log << "PLayerTexture Texture failed to load.\n";
   //    return false;
   // }
   // Hero.playerTexture.setWidth(30);
   // Hero.playerTexture.setHeight(30);

   // Test Loading of sounds
   /*if(!soundManager.Load_Sound("Song.mp3","DarkSouls",0))
	{
      printf("sound failed to load 1.\n");
      return false;
    }
   if(!soundManager.Load_Sound("Song2.mp3","A2",0))
	   {
      printf("sound failed to load 2.\n");
      return false;
   }
   if(!soundManager.Load_Sound("potion.wav","SFX",1))
	   {
      printf("sound failed to load 3.\n");
      return false;
   }
   if(!soundManager.Load_Sound("gnt.wav","gnt",1))
	   {
      printf("sound failed to load 3.\n");
      return false;
   }*/
   
   return true;

}

//Event checking for game loop 
//Handles Events such as clicks and button pushes
//https://wiki.libsdl.org/SDL_Event
void gameroot::OnEvent(SDL_Event *Event)
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
   if (Hero.playerInputMode=="Gamepad")
   {
      Hero.UpdateSDLJoy(Event);
   }
   
   if(Event->type == SDL_QUIT)
   {
      engineState->gameroot = false;
      Running = false;
   }
}

//Does nothing. Math and physics later
void gameroot::update()
{
   EngineActiveState=gameState;
   gameroot::total_Time = gameroot::total_Time + gameroot::time_Of_Previous_Frame.count();	//Add the time of the last frame to the total time

   debug_log << "test " << GLOBAL_FRAME_COUNTER << "\n";


   while(SDL_PollEvent(&Event))
   {
      //Updates input object, holding current buttons pressed
      input.update(Event);
	  
	  //Checking if X has been clicked
      OnEvent(&Event);

      if(gameState == Loading)
      {
         Hero.playerKeyPress(input.getKeyDown());
         Hero.playerKeyRelease(input.getKeyUp());
         Hero.playerUpdate(fpsTimer.getTicks());

		/* if(input.getKeyDown() == SDLK_1)
         {
			 soundManager.Play_Music("DarkSouls",-1);
         }
		 if(input.getKeyDown() == SDLK_2)
		 {
			soundManager.Play_Music("A2",-1);
		 }
		 if(input.getKeyDown() == SDLK_3)
		 {
			 soundManager.Play_Sound("SFX",0);
		 }
		 if(input.getKeyDown() == SDLK_4)
		 {
			 soundManager.Play_Sound("gnt",0);
		 }
         if(input.getKeyDown() == SDLK_p)
         {
			 soundManager.Stop_Sound();
			 soundManager.Stop();
         }*/
      }
	  
   }  
      
      

}
   
//Draws to screen
void gameroot::draw()
{
   //Start cap Timer
   capTimer.start();

   //Clear screen
   SDL_RenderClear(renderer);

   if(gameState == Loading)
   {
      GameMap.renderMap();
      // texture.render(0,0);
      // Hero.playerTexture.render(0,0);
      Hero.playerDraw();
   }
   else if(gameState == GameRootMenu)
   {
      
   }
   else if(gameState == GamePlaying1)
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


   while(Running && engineState->isGameRunning())
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
   // Hero.playerTexture.free();
   Hero.close();

  ////unloading of sounds
  // soundManager.Unload_Sound("DarkSouls",0);
  // soundManager.Unload_Sound("A2",0);
  // soundManager.Unload_Sound("SFX",1);
  // soundManager.Unload_Sound("gnt",1);


   IMG_Quit();
   TTF_Quit();
}

#endif

