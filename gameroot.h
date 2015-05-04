#ifndef GAMEROOT_H_INCLUDED

#define GAMEROOT_H_INCLUDED

#include "SDLincludes.h"
#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include "level/level.h"   //Includes level and all Object header files and all Object component header files, including Box2D's, along with <fstream>, <string>, <algorithm>, <iostream>, <vector>, <cstdint> but excluding inherited classes (Player, NonPlayerCharacter)
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
   const static std::uint8_t maximum_Number_Of_Levels = 50;


   
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
   Camera camera;
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
   int menuchoice=0;
   SDL_Color menuColor={0xFF,0xA5,0x00,0xFF};
   SDL_Color textColor = {0xFF,0xA5,0xA5,0xFF};
   bool newMenu=false;
   bool mTrue = true;
   int player1Choice, player2Choice, intiWorks=0;
   std::string level_File_Path_Array[gameroot::maximum_Number_Of_Levels];
   std::ifstream levels_List_File;
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

double gameroot::maximum_Frame_Rate = 120;      //Sets the maximum number of times the main game loop can execute in a single second
double gameroot::total_Time = 0;          //The amount of time the game has run from the start of the program
std::chrono::high_resolution_clock::time_point gameroot::start_Of_Previous_Frame = std::chrono::high_resolution_clock::now(); //The time point that the previous instance of the main game loop (A 'frame') began
std::chrono::high_resolution_clock::time_point gameroot::start_Of_Current_Frame = gameroot::start_Of_Previous_Frame;       //The time point at which the currently active frame began
std::chrono::duration<double> gameroot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(start_Of_Current_Frame - start_Of_Previous_Frame); //The length of time the previous frame took to complete
uint32_t gameroot::total_Frame_Time = 0;

//Simple initializes
gameroot::gameroot(Window *mainWindow, EngineState *currentState)
{
   Running = false;
   window = mainWindow;
   engineState = currentState;
   renderer = NULL;
   gameState = GameRootMenu; 
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
   
   gameroot::camera.setBoundRect(0,0,5000,5000);
   Object::camera_Pointer = &camera;
   Object::meters_Per_Pixel = Object::standard_Meters_Per_Pixel;
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
	for(std::uint8_t i = 0; i < gameroot::maximum_Number_Of_Levels; i++)
	{
		(*this).level_File_Path_Array[i] = "";
	}

	(*this).levels_List_File.open("../resources/maps/mapFileList.txt");
	if((*this).levels_List_File)
	{
		int i = 0;
		while((*this).levels_List_File >> (*this).level_File_Path_Array[i])
		{
			i++;
		}
	}
   
   gameLevel = new Level("../resources/maps/" + (*this).level_File_Path_Array[1] + ".txt");

   //sets boolean to true. This boolean determines if the game loop continues
   Running = true;
  
   GLOBAL_FRAME_COUNTER = 0; //This is necessary for the animation timing in the animation class. 

   rootMenuObject.initilizeMenu(renderer);
   rootMenuObject.initilizeMenu2(renderer);

   Hero.playerX=0;
   Hero.playerY=0;
   Hero.InitSprite(renderer);
   Villain.playerX=50;
   Villain.playerY=50;
   Villain.InitSprite(renderer);
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
   
   if(!soundManager.Load_Sound("Mechanolith.mp3","Levelmusic", 0))
   {
       error_log << "Sound failed to load.\n";
       return false;
    }

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
   else if((*Event).type == SDL_MOUSEWHEEL)
   {
      Object::update_Meters_Per_Pixel((*Event).wheel.y);
   }
   else if((*Event).type == SDL_KEYDOWN)
   {
	if((*this).input.getKeyDown() == SDLK_0)
	{
		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[0] + ".txt");
		std::cerr << "0" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_1)
	{
		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[1] + ".txt");
		std::cerr << "1" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_2)
	{
		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[2] + ".txt");
		std::cerr << "2" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_3)
	{
		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[3] + ".txt");
		std::cerr << "3" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_4)
	{
		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[4] + ".txt");
		std::cerr << "4" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_5)
	{
//		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[5] + ".txt");
		std::cerr << "5" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_6)
	{
//		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[6] + ".txt");
		std::cerr << "6" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_7)
	{
//		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[7] + ".txt");
		std::cerr << "7" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_8)
	{
//		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[8] + ".txt");
		std::cerr << "8" << std::endl;
	}
	else if((*this).input.getKeyDown() == SDLK_9)
	{
//		(*gameLevel).load_Level("../resources/maps/" + (*this).level_File_Path_Array[9] + ".txt");
		std::cerr << "9" << std::endl;
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
   if (Villain.playerInputMode=="Gamepad"&&Villain.Controller3Connected==true)
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

   gameroot::total_Time = gameroot::total_Time + gameroot::time_Of_Previous_Frame.count();   //Add the time of the last frame to the total time
   Object::physics_Time_Step = gameroot::time_Of_Previous_Frame.count();

   debug_log << "\ntest " << GLOBAL_FRAME_COUNTER << "\n";

   if (gameState==GamePlaying1)
   {
      (*Object::camera_Pointer).Update_Camera(((*Hero.object.physics).GetPosition().x - ((*Object::camera_Pointer).getCamW() / Object::meters_Per_Pixel / 2.0)), ((*Hero.object.physics).GetPosition().y - ((*Object::camera_Pointer).getCamH() / Object::meters_Per_Pixel / 2.0)));
      (*Object::camera_Pointer).update_Camera_Floats(((*Hero.object.physics).GetPosition().x - ((*Object::camera_Pointer).getCamW() / Object::meters_Per_Pixel / 2.0)), ((*Hero.object.physics).GetPosition().y - ((*Object::camera_Pointer).getCamH() / Object::meters_Per_Pixel / 2.0)));
      gameLevel->update_All();
      Hero.playerUpdate(GLOBAL_FRAME_COUNTER);
      Villain.playerUpdate(GLOBAL_FRAME_COUNTER);

   }
   //Game Menu Starting
   if (gameState == GameRootMenu)
   {
      switch (menuchoice)
      {
         case 0:
         rootMenuObject.Root[0].loadTextRender("Start", menuColor);
         rootMenuObject.Root[1].loadTextRender("Controls", textColor);
         break;
         case 1:
         rootMenuObject.Root[0].loadTextRender("Start", textColor);
         rootMenuObject.Root[1].loadTextRender("Controls", menuColor);
         break;
      }
   }
   if (gameState == GameMenu1)
   {
      switch (menuchoice)
      {
         case 0:
        rootMenuObject.Menu[0].loadTextRender("1 player on Keyboard", menuColor);
        rootMenuObject.Menu[1].loadTextRender("2 players on Keyboard", textColor);
        rootMenuObject.Menu[2].loadTextRender("1 player on GamePad", textColor);
        rootMenuObject.Menu[3].loadTextRender("2 players on GamePad", textColor);
        rootMenuObject.Menu[4].loadTextRender("1 player on Each", textColor);
         break;
         
         case 1:
         rootMenuObject.Menu[0].loadTextRender("1 player on Keyboard", textColor);
         rootMenuObject.Menu[1].loadTextRender("2 players on Keyboard", menuColor);
         rootMenuObject.Menu[2].loadTextRender("1 player on GamePad", textColor);
         rootMenuObject.Menu[3].loadTextRender("2 players on GamePad", textColor);
         rootMenuObject.Menu[4].loadTextRender("1 player on Each", textColor);
         break;
         
         case 2:
         rootMenuObject.Menu[0].loadTextRender("1 player on Keyboard", textColor);
         rootMenuObject.Menu[1].loadTextRender("2 players on Keyboard", textColor);
         rootMenuObject.Menu[2].loadTextRender("1 player on GamePad", menuColor);
         rootMenuObject.Menu[3].loadTextRender("2 players on GamePad", textColor);
         rootMenuObject.Menu[4].loadTextRender("1 player on Each", textColor);
         break;

         case 3:
         rootMenuObject.Menu[0].loadTextRender("1 player on Keyboard", textColor);
         rootMenuObject.Menu[1].loadTextRender("2 players on Keyboard", textColor);
         rootMenuObject.Menu[2].loadTextRender("1 player on GamePad", textColor);
         rootMenuObject.Menu[3].loadTextRender("2 players on GamePad", menuColor);
         rootMenuObject.Menu[4].loadTextRender("1 player on Each", textColor);
         break;

         case 4:
         rootMenuObject.Menu[0].loadTextRender("1 player on Keyboard", textColor);
         rootMenuObject.Menu[1].loadTextRender("2 players on Keyboard", textColor);
         rootMenuObject.Menu[2].loadTextRender("1 player on GamePad", textColor);
         rootMenuObject.Menu[3].loadTextRender("2 players on GamePad", textColor);
         rootMenuObject.Menu[4].loadTextRender("1 player on Each", menuColor);
         break;
      }
      // rootMenuObject.UpdateGameMenu1(menuchoice);
   }
   if (gameState==GameMenu2)
   {
      rootMenuObject.UpdateGameMenu2(menuchoice);
   }
   if (gameState==GameMenu3)
   {
      rootMenuObject.UpdateGameMenu3(menuchoice,player1Choice);
   }

   if (gameState==Loading)
   {
      if (Hero.p1k==true)
      {
         Hero.playerInitalize(1);
         Villain.playerInitalize(2);
      soundManager.Play_Music("Levelmusic", 20);
      }
      if (Villain.p2k==true)
      {
         Villain.playerInitalize(2);
      }
      if (Hero.p1g==true)
      {
         Hero.playerInitalize(1);
         Villain.playerInitalize(2);
         if(Hero.init()==false)
         {
            engineState->gameroot = false;
            Running = false;
         }
      }
      if (Villain.p2g==true)
      {
         Villain.playerInitalize(2);
         if (Villain.init()==false)
         {
            engineState->gameroot = false;
            Running = false;
         }
      }  
      if (Hero.mix==true&&Villain.mix==true)
      {
         Hero.playerInitalize(1);
         Villain.playerInitalize(2);
         Villain.init();
      }
      Hero.LoadSpriteContent();
      Villain.LoadSpriteContent();
      gameState=GamePlaying1;

   }
   
   while(SDL_PollEvent(&Event))
   {
      //Updates input object, holding current buttons pressed
      input.update(Event);
     
     //Checking if X has been clicked
      OnEvent(&Event);

      if (gameState== GameRootMenu)
      {
         if (input.getKeyDown()==SDLK_UP)
         {
            menuchoice--;
            if (menuchoice<0)
               menuchoice=1;
         }
         if (input.getKeyDown()==SDLK_DOWN)
         {
             menuchoice++;
            if (menuchoice>1)
               menuchoice=0;
         }
         if (input.getKeyDown()==SDLK_RETURN)
         {
            if (menuchoice==0)
               gameState=GameMenu1;
            if (menuchoice==1)
               gameState=GameMenu2;
         }
      }
      if (gameState== GameMenu1)
      {
         if (input.getKeyUp()==SDLK_RETURN)
         {
            newMenu=true;
            menuchoice=0;
         }
         if (input.getKeyDown()==SDLK_UP)
         {
            menuchoice--;
            if (menuchoice<0)
               menuchoice=4;
         }
         if (input.getKeyDown()==SDLK_DOWN)
         {
             menuchoice++;
            if (menuchoice>4)
               menuchoice=0;
         }
         if (input.getKeyDown()==SDLK_RETURN&&newMenu==true)
         {
            switch (menuchoice)
            {
               case 0:
               Hero.p1k=true;
               break;
               case 1:
               Hero.p1k=true;
               Villain.p2k=true;  
               break;
               case 2:
               Hero.p1g=true;
               break;
               case 3:
               Hero.p1g=true;
               Villain.p2g=true;
               break;
               case 4:
               Hero.mix=true;
               Villain.mix=true;
               break;
            }
            gameState=Loading;
         }
      }
      if (gameState==GameMenu2)
      {
         if (input.getKeyUp()==SDLK_RETURN)
         {
            newMenu=true;
            menuchoice=0;
         }
         if (input.getKeyDown()==SDLK_LEFT)
         {
            menuchoice--;
            if (menuchoice<0)
               menuchoice=2;
         }
         if (input.getKeyDown()==SDLK_RIGHT)
         {
             menuchoice++;
            if (menuchoice>2)
               menuchoice=0;
         }
         if (input.getKeyDown()==SDLK_RETURN&&newMenu==true)
         {
            // player1Choice=menuchoice;
            // Hero.player1Choice=player1Choice;
            newMenu=false;
            gameState=GameMenu3;
         }
      }
      if (gameState==GameMenu3)
      {
         if (input.getKeyUp()==SDLK_RETURN)
         {
            newMenu=true;
            menuchoice=0;
         }
         if (input.getKeyDown()==SDLK_LEFT)
         {
            menuchoice--;
            if (menuchoice<0)
               menuchoice=2;
         }
         if (input.getKeyDown()==SDLK_RIGHT)
         {
             menuchoice++;
            if (menuchoice>2)
               menuchoice=0;
         }
         if (input.getKeyDown()==SDLK_RETURN&&newMenu==true)
         {
            // player2Choice=menuchoice;
            // Villain.player2Choice=player2Choice;
            newMenu=false;
            gameState=GameMenu1;
         }
      }
      if(gameState == GamePlaying1)
      {
         // if (Hero.Actions.playerSpecial==true)
         // {
         //       soundManager.Play_Music("Levelmusic", 20);

         // }

         if (Hero.Controller1Connected==false&&Hero.p1k==true)
         {
            Hero.playerKeyPress(input.getKeyDown());
            Hero.playerKeyRelease(input.getKeyUp());
         }
         if (Hero.Controller1Connected==false&&Hero.mix==true)
         {
            Hero.playerKeyPress(input.getKeyDown());
            Hero.playerKeyRelease(input.getKeyUp());
         }
         if (Villain.Controller2Connected==false&&Villain.p2k==true)
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

   if(gameState == GamePlaying1)
   {
      texture.render(0,0);
      (*gameLevel).render_All();
      //GameMap.renderMap();
      // Hero.playerTexture.render(0,0);
      if (Villain.p2k==true||Villain.p2g==true||Villain.mix==true)
      {
         Villain.player_Draw_Scaled();
         /* code */
      }
      Hero.player_Draw_Scaled();
   }
    if(gameState == GameRootMenu)
   {
      rootMenuObject.displayPlatMenu();   
   }
   if(gameState == GameMenu1)
   {
      rootMenuObject.displayPlatMenu1();
   }
      if(gameState == GameMenu2)
   {
      rootMenuObject.displayPlatMenu2();
   }
      if(gameState == GameMenu3)
   {
      rootMenuObject.displayPlatMenu3();
   }
   
   //update screen
   SDL_RenderPresent(renderer);
   

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
      gameroot::start_Of_Current_Frame = std::chrono::high_resolution_clock::now();    //At the start of each frame, store the current time
      gameroot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(gameroot::start_Of_Current_Frame - gameroot::start_Of_Previous_Frame);  //Number of clock cycles between frames

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
      ++GLOBAL_FRAME_COUNTER;// Counts up the frames in the engine at the end of every draw. 

      gameroot::start_Of_Previous_Frame = gameroot::start_Of_Current_Frame;            //At the end of each frame, store the start time of the current frame to the previous frame
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
   soundManager.Unload_Sound("Levelmusic",0);
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

