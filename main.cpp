#include "gameroot.h"
#include "maproot.h"
#include "menu.h"
#include "window.h"
#include "SDL_thread.h"
#include "SDL_timer.h"

using namespace std;

static int TestThread(void *ptr);

//Just the main. Very boring
int main(int argc, char *argv[])
{
   int menuChoice;
   Window *mainWindow = new Window();
   Window *sideWindow = new Window(50,50,200,720);
   maproot *aMap = NULL;
   gameroot *theGame = NULL;  
   menu *mainMenu = NULL;
   SDL_Thread *thread;
   int         threadReturnValue;

   printf("\nSimple SDL_CreateThread test:");

   //Create a simple thread
   thread = SDL_CreateThread(TestThread, "TestThread", (void *)NULL);

   if (NULL == thread)
   {
      printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
   } 
   else 
   {
      SDL_WaitThread(thread, &threadReturnValue);
      printf("\nThread returned value: %d", threadReturnValue);
   }


   
   do
   {
      mainMenu = new menu(mainWindow);
	  menuChoice = mainMenu->execute();
	  delete mainMenu;
   
      switch(menuChoice)
      {
         //Runs actual game loop
         case 1: theGame = new gameroot(mainWindow);
		         theGame->execute();
				 delete theGame;
	             break;
         //Runs the map editor's functions
         case 2: aMap = new maproot(mainWindow);
		         aMap->execute();
				 delete aMap;
	             break;
      }
   }while(menuChoice != 3);
   
   delete mainWindow;
   delete sideWindow;
   
   SDL_Quit();
   
   return 0;
}

// Very simple thread. counts 0 to 9 delaying 50ms between increments
static int TestThread(void *ptr)
{
    int i;

    for (i = 0; i < 10; ++i)
	{
        printf("\nThread counter: %d", i);
        SDL_Delay(50);
    }

    return i;
}
