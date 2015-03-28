#include "gameroot.h"
#include "maproot.h"
using namespace std;

//Just the main. Very boring
int main(int argc, char *argv[])
{

   maproot aMap;
   gameroot theGame;   
   
   //Runs the map editor's functions
   aMap.execute();
   
   //Runs actual game loop
   theGame.execute();
   
   return 0;
}