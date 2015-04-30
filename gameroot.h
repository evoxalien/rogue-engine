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
#include "Texture.h"
#include "mathutil.h"
#include "startMenu.h"
#include "playerClass.h"
#include "gameMap.cpp"
#include "window.h"
#include "engineState.h"
#include "GameMenuDavid.h"
#include "Camera.h"
#include "RootMenu.h"
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
   static uint32_t total_Frame_Time;
   static std::chrono::duration<double> time_Of_Previous_Frame;
   
   bool Running;
   Window *window;
   EngineState *engineState;
   SDL_Renderer *renderer;
   Level *gameLevel;
   Texture texture;
   // Texture playerTexture;
   SDL_Event Event;

   enum GameState
   {
      Loading, //0
      RootMenu1, //1
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
   playerClass Villain;
   bool initialize();
   InputClass input;
   GameMenu GameMenuObject;
   gameMap GameMap;
   Sound_Manager soundManager;
   RootMenu rootMenuObject;
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
uint32_t gameroot::total_Frame_Time = 0;

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
	Object::SDL_Renderer_Pointer = renderer;
   
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
   gameLevel = new Level("../resources/maps/map1.txt");

   //sets boolean to true. This boolean determines if the game loop continues
   Running = true;
  
   GLOBAL_FRAME_COUNTER = 0; //This is necessary for the animation timing in the animation class. 

   Hero.playerInitalize(1);
   Hero.playerX=0;
   Hero.playerY=0;
   rootMenuObject.initilizeMenu(renderer);
   Hero.InitSprite(renderer);
   if (Hero.playerInputMode=="Gamepad")
   {
      Hero.init();
   }
   Villain.playerX=50;
   Villain.playerY=50;
   Villain.playerInitalize(2);
   Villain.InitSprite(renderer);
   if (Villain.playerInputMode=="Gamepad")
   {
      /* code */
      Villain.init();
   }
   //Sound Manager Initialize
   soundManager.Init();

   return true;
}

//Load textures and other content here
bool gameroot::loadContent()
{

    if(!texture.loadTexture("../resources/img/backgrounds/NightSky.png"))
    {
       error_log << "Texture failed to load.\n";
       return false;
    }
   
   texture.setWidth(window->getWidth());
   texture.setHeight(window->getHeight());
   Hero.LoadSpriteContent();
   Villain.LoadSpriteContent();

   
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
   if (Hero.playerInputMode=="Gamepad"&&Hero.Controller1Connected==true)
   {
      Hero.UpdateSDLJoy(Event);
   }
   if (Villain.playerInputMode=="Gamepad"&&Villain.Controller2Connected==true)
   {
      Villain.UpdateSDLJoy(Event);
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

   debug_log << "\ntest " << GLOBAL_FRAME_COUNTER << "\n";


   gameLevel->update_All();
   Hero.playerUpdate(GLOBAL_FRAME_COUNTER);
   Villain.playerUpdate(GLOBAL_FRAME_COUNTER);


   while(SDL_PollEvent(&Event))
   {
      //Updates input object, holding current buttons pressed
      input.update(Event);
	  
	  //Checking if X has been clicked
      OnEvent(&Event);

      if(gameState == Loading)
      {
         if (Hero.Controller1Connected==false)
         {
            Hero.playerKeyPress(input.getKeyDown());
            Hero.playerKeyRelease(input.getKeyUp());
         }
         if (Villain.Controller2Connected==false)
         {
            Villain.playerKeyPress(input.getKeyDown());
            Villain.playerKeyRelease(input.getKeyUp());
         }

      }

	  
   }  
      
      

}
   
//Draws to screen
void gameroot::draw()
{

   //Clear screen
   SDL_RenderClear(renderer);

   if(gameState == Loading)
   {
      texture.render(0,0);
      (*gameLevel).render_All();
      //GameMap.renderMap();
      // Hero.playerTexture.render(0,0);
      Villain.playerDraw();
      Hero.playerDraw();
   }
   else if(gameState == GameRootMenu)
   {
      
   }
   else if(gameState == GamePlaying1)
   {
         
   }
   
   rootMenuObject.displayPlatMenu();
   //update screen
   SDL_RenderPresent(renderer);
   
   ++GLOBAL_FRAME_COUNTER;// Counts up the frames in the engine at the end of every draw. 
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

      gameroot::total_Frame_Time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - gameroot::start_Of_Current_Frame).count();

      //std::this_thread::sleep_for(std::chrono::nanoseconds(/*calculate number of nanoseconds to wait based on maximum frame rate and time taken so far*/));
      //cout << endl << "Total Frame Time: " << gameroot::total_Frame_Time << endl;
      //cout << "Total Time: " << gameroot::total_Time;

      if((SCREEN_TICKS_PER_FRAME) > gameroot::total_Frame_Time)
      {
         SDL_Delay((SCREEN_TICKS_PER_FRAME) - gameroot::total_Frame_Time);
      }

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
   Villain.close();
  ////unloading of sounds
  // soundManager.Unload_Sound("DarkSouls",0);
  // soundManager.Unload_Sound("A2",0);
  // soundManager.Unload_Sound("SFX",1);
  // soundManager.Unload_Sound("gnt",1);
	if(gameLevel != nullptr)
	{
		delete gameLevel;
		gameLevel = nullptr;
	}


   IMG_Quit();
   TTF_Quit();
}

#endif

