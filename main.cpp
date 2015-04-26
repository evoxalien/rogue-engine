#include "gameroot.h"
#include "maproot.h"
#include "menu.h"
#include "window.h"
#include "engineState.h"
#include "SDLincludes.h"

using namespace std;

EngineState currentState;
Window *sideWindow = new Window(50,50,200,720);
extern int SideMenuThread(void *ptr);

int main(int argc, char *argv[])
{
   currentState.main = true;
   Window *mainWindow = new Window();
   menu *mainMenu = NULL;
   maproot *aMap = NULL;
   gameroot *theGame = NULL;  
   SDL_Thread *thread;

   /*
   //Create a thread to run the side menu through all game states
   thread = SDL_CreateThread(SideMenuThread, "SideMenuThread", (void *)NULL);

   //Checks if thread was created properly, if so thread runs separately from main
   if (NULL == thread)
   {
      printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
   } 
   else 
   {
      SDL_DetachThread(thread);
   }
   */

   
   do
   {
      mainMenu = new menu(mainWindow, &currentState);
      mainMenu->execute();
      delete mainMenu;
   
      if(currentState.isGameRunning())
      {
         //Runs actual game loop
         theGame = new gameroot(mainWindow, &currentState);
         theGame->execute();
         delete theGame;
      }
	  else if(currentState.isMapeditorRunning())
	  {
	     //Runs the map editor's functions
         aMap = new maproot(mainWindow, &currentState);
         aMap->execute();
         delete aMap;
      }
   }while(currentState.isMainRunning());
   
   delete mainWindow;
   delete sideWindow;
   
   SDL_Quit();
   
   return 0;
}

// Thread that runs the side menu
extern int SideMenuThread(void *ptr)
{
   menu *sideMenu = NULL;
      
   while(currentState.isMainRunning())
   {
      sideMenu = new menu(sideWindow, &currentState);
	  sideMenu->execute();
	  delete sideMenu;
   }
}
