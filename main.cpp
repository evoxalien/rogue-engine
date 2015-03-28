#include "gameroot.h"
#include "maproot.h"
using namespace std;

//Just the main. Very boring
int main(int argc, char *argv[])
{

   gameroot theGame;
   maproot aMap;

   theGame.execute();
   aMap.execute();
   
   return 0;
}