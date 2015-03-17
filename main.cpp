#include <stdio.h>
#include "SDLincludes.h"
//#include "gameroot.h"
//#include "mapEditor.h"
#include "demo.h"
using namespace std;



//Just the main. Very boring
int main(int argc, char *argv[])
{
   bool Running;
   SDL_Event Event;
   demo *firstDemo;
   
   
   if(argc == 2)
   {
      if(argv[1][0] == '1')
	     printf("Starting Debug...\n");
		 firstDemo = new demo();
		 
		 return firstDemo->execute();
		 
   }
   else
   {
      
   }
   
   //gameroot theGame;

   //return theGame.execute();
   return 0;
}