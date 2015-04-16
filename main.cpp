#include "gameroot.h"
#include "maproot.h"
#include "menu.h"

using namespace std;

//Just the main. Very boring
int main(int argc, char *argv[])
{
   int menuChoice;
   maproot *aMap = NULL;
   gameroot *theGame = NULL;  
   menu *mainMenu = NULL;   
   
   do
   {
      mainMenu = new menu();
	  menuChoice = mainMenu->execute();
	  delete mainMenu;
   
      switch(menuChoice)
      {
         //Runs actual game loop
         case 1: theGame = new gameroot();
		         theGame->execute();
				 delete theGame;
	             break;
         //Runs the map editor's functions
         case 2: aMap = new maproot();
		         aMap->execute();
				 delete aMap;
	             break;
      }
   }while(menuChoice != 3);
   
   return 0;
}