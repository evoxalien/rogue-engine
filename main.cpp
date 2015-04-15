#include "gameroot.h"
#include "maproot.h"
#include "menu.h"

using namespace std;

//Just the main. Very boring
int main(int argc, char *argv[])
{
   int menuChoice;
   maproot aMap;
   gameroot theGame;  
   menu mainMenu;   
   
   //do
   //{
      menuChoice = mainMenu.execute();
   
      switch(menuChoice)
      {
         //Runs actual game loop
         case 1: theGame.execute();
	             break;
         //Runs the map editor's functions
         case 2: aMap.execute();
	             break;
      }
   //}while(menuChoice != 3);
   
   return 0;
}