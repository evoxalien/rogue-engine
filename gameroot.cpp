//INCLUDES
#include "SDL.h"
#include <stdio.h>
#include <string>
#include "gameroot.h"
using namespace std;

//Global Variables
SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *image = NULL;
//String window_name = "Rogue Engine Window Title Here"
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;
//david
enum GameState
{
   StartMenu,
   Loading,
   EndMenu,
   Playing,
   leveledup,
   Paused,
   levelSelect
};  
//GameState gameState;

//Simple initializes
gameroot::gameroot()
{
   Running = false;
   window = NULL;
   renderer = NULL;
   surface = NULL;
   image = NULL;

}

//Initialize all the SDL
bool gameroot::initialize()
{
   bool success = true;
   renderer = SDL_CreateRenderer(window, -1, 0);
   GLOBAL_FRAME_COUNTER = 0;
   //Tests SDL components, important to call before other SDL operations
   //https://wiki.libsdl.org/SDL_Init


   if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
   {
      return false;
   }

   //Calls and tests function to create SDL Window (documentation in link)
   //https://wiki.libsdl.org/SDL_CreateWindow
   if((window = SDL_CreateWindow( "Rogue Engine Window Title Here", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 720, SDL_WINDOW_SHOWN )) == NULL)
   {
      return false;
   }

   //Creates SDL Renderer. Renderer renders assets to SDL windows
   //Can be used to draw .bmp images to window (example in link)
   //https://wiki.libsdl.org/SDL_CreateRenderer
   renderer = SDL_CreateRenderer ( window , - 1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;

   //Tests if renderer initialized properly
   if (renderer == NULL)
   {
      printf ("Render Error: %s", SDL_GetError());
      return false;
   }


   Running = true;

   return true;
}

//Does Nothing. Load textures here in future
bool gameroot::loadContent()
{

   return true;

}

//Event checking if X has been clicked 
//Triggers SDL_QUIT and exit program
void gameroot::OnEvent(SDL_Event *Event)
{
   if(Event->type == SDL_QUIT)
   {
      Running = false;
   }
}

//Does nothing. Math and physics later
void gameroot::update()
{
   if(GLOBAL_FRAME_COUNTER == 1)
   {
      surface = SDL_GetWindowSurface(window);
      SDL_FillRect( surface, NULL, SDL_MapRGBA(surface->format, 55,55,55,55));
   }

}

//Does nothing. Feel free to draw dinosaur here
void gameroot::draw()
{

   GLOBAL_FRAME_COUNTER++;   
   if(GLOBAL_FRAME_COUNTER % 10 == 0)
      printf("Frame Count: %d \n", GLOBAL_FRAME_COUNTER);

   SDL_UpdateWindowSurface( window );

}
//juan
//Actual game loop
int gameroot::execute()
{
   //checks all the SDL (see above)
   if(initialize() == false)
   {
      return - 1;
   }



   while(Running)
   {
      //Loops here until event is handled. 
	  //Never enters loop if no event is happening
	  //https://wiki.libsdl.org/SDL_PollEvent
      while(SDL_PollEvent(&Event))
      {
         OnEvent(&Event);
      }

	  //update and redraw window
      update();
      draw();
    }

   close() ;
   return 0;
}

//Free all the assets
void gameroot::close()
{
   SDL_DestroyRenderer (renderer);
   SDL_FreeSurface(image);
   SDL_FreeSurface(surface);
   SDL_DestroyWindow(window);
   SDL_Quit();
}
//john
// void close()
// {

//     // Close and destroy the window
//     SDL_DestroyWindow(window);
//     window = NULL;

//    SDL_Quit();
// }

//Just the main. Very boring
int main(int argc, char *argv[])
{

   gameroot theGame;

   return theGame.execute();
   //john
   // initialize();

   // loadMedia();

   // update();

   // draw();

   //  SDL_Delay(3000);

   // close();
   // return 0;
}