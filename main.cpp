#include "gameroot.h"
#include "maproot.h"
#include "menu.h"
#include "window.h"


using namespace std;

//Just the main. Very boring
int main(int argc, char *argv[])
{
   int menuChoice;
   Window *mainWindow = new Window();
   Window *sideWindow = new Window(50,50,200,720);
   maproot *aMap = NULL;
   gameroot *theGame = NULL;  
   menu *mainMenu = NULL;
  
   
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