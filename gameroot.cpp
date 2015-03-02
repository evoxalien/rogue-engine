//INCLUDES
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <string>
#include "gameroot.h"

using namespace std;

//String window_name = "Rogue Engine Window Title Here"
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;

//Simple initializes
gameroot::gameroot()
{
   Running = false;
   window = NULL;
   renderer = NULL;
   surface = NULL;
   image = NULL;
   texture = NULL;

}

//Initialize all the SDL
bool gameroot::initialize()
{

   
   //intitalize the gamestate
   gameState=StartMenu;
   
   //Tests SDL components, important to call before other SDL operations
   //https://wiki.libsdl.org/SDL_Init
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
   {
      printf ("SDL Component failed to initialize Error: %s", SDL_GetError());
      return false;
   }

   //Calls and tests function to create SDL Window (documentation in link)
   //https://wiki.libsdl.org/SDL_CreateWindow
   if((window = SDL_CreateWindow( "Rogue Engine Window Title Here", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN )) == NULL)
   {
      printf ("Window Error: %s", SDL_GetError());
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

   //set render draw color property
   SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

   //initialize image subsystem to load png files
   int imgFlags = IMG_INIT_PNG;
   if(!(IMG_Init(imgFlags) & imgFlags))
   {
      printf("SDL_Image could not be initialized. SDL_Image error : %s\n", IMG_GetError());
      return false;
   }

   //sets boolean to true. This boolean determines if the game loop continues
   Running = true;



   GLOBAL_FRAME_COUNTER = 0;
   /*
   previousTicks = 0;
   fps_lasttime = SDL_GetTicks(); //the last recorded time.
   fps_current = 0; //the current FPS.
   fps_frames = 0; //frames passed since the last recorded fps.
   */
   
   

   return true;
}

//Does Nothing. Load textures here in future
bool gameroot::loadContent()
{

   texture = loadTexture("../../images/dino.png");
   if(texture == NULL)
   {
      printf("Texture failed to load.\n");
      return false;
   }
   


   return true;

}

//Event checking for game loop 
//Handles Events such as clicks and button pushes
//https://wiki.libsdl.org/SDL_Event
void gameroot::OnEvent(SDL_Event *Event)
{
   
   //Check if event is the clicking of the exit (SDL_QUIT)
   if(Event->type == SDL_QUIT)
   {
      Running = false;
   }
   
   //This event works to track keyboard inputs
   else if (Event->type == SDL_KEYDOWN)
   {
      keyPress(&gameState,Event);
   }
}

//Does nothing. Math and physics later
void gameroot::update()
{


   //Loops here until event is handled. 
   //Never enters loop if no event is happening
   //https://wiki.libsdl.org/SDL_PollEvent
   while(SDL_PollEvent(&Event))
   {
      OnEvent(&Event);
   }
   
   
}

//Does nothing. Feel free to draw dinosaur here
void gameroot::draw()
{
   //using the renderer//

   //set render clear color to non-transparent white(0xFFFFFFFF)
   SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
   //clear screen
   SDL_RenderClear(renderer);

   //render texture to screen
   SDL_RenderCopy(renderer, texture, NULL, NULL);

   //Draw Colorful Rectangles
   //Red Rect
   SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
   //Rect params = x, y, w(width), h(height)
   SDL_Rect fillRect = {0, 0, 50, 50};
   SDL_RenderFillRect(renderer, &fillRect);
   
   //Green Rect
   SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
   fillRect = {50, 0, 50, 50};
   SDL_RenderFillRect(renderer, &fillRect);
   
   //Blue Rect
   SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
   fillRect = {100, 0, 50, 50};
   SDL_RenderFillRect(renderer, &fillRect);


   //update screen
   SDL_RenderPresent(renderer);


   /**** Massive comment block ***************************************
   //Makes window gray for first frame
   if(GLOBAL_FRAME_COUNTER == 1)
   {

      surface = SDL_GetWindowSurface(window);
      SDL_FillRect( surface, NULL, SDL_MapRGBA(surface->format, 55,55,55,55));
   }
   
   //if the frame count is more than 100 u can change the color
   //this implementaion will change once other things happen its just proof of concept
   else if (GLOBAL_FRAME_COUNTER > 100)
   {
      if(gameState==StartMenu)
         SDL_FillRect( surface, NULL, SDL_MapRGBA(surface->format, 0,0,0,0));
      if(gameState==Playing)
      {

         SDL_FillRect( surface, NULL, SDL_MapRGBA(surface->format, 85,85,85,85));
         SDL_BlitSurface( image, NULL, surface, NULL );
      }
      if(gameState==Paused)
      {
         SDL_FillRect( surface, NULL, SDL_MapRGBA(surface->format, 155,155,155,155));
      }
   }
   **********************************************************************/

   //increment frame counter 
   GLOBAL_FRAME_COUNTER++;   
   /*
   if(GLOBAL_FRAME_COUNTER % 10 == 0)
      printf("Frame Count: %d \n", GLOBAL_FRAME_COUNTER);
   previousTicks = SDL_GetTicks();
   */



   //unnecessary if using the renderer
   //SDL_UpdateWindowSurface(window);

}

//load texture function taken from lazyfoo
//we should probably make a class for loading
//and drawing media
SDL_Texture* gameroot::loadTexture(std::string path)
{
   //final surface to return
   SDL_Texture* newTexture = NULL;
   
   //load surface at path
   SDL_Surface* loadSurface = IMG_Load(path.c_str());
   if( loadSurface == NULL )
   {
      printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError() );
   }
   else
   {
      //convert surface to texture inside of renderer
      newTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
      if(newTexture == NULL)
      {
         printf("Failed to optimize image %s: %s\n", path.c_str(), SDL_GetError());
      }
      
   }
   return newTexture;
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


   while(Running)
   {
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
   SDL_DestroyTexture(texture);
   SDL_DestroyRenderer (renderer);
   SDL_FreeSurface(image);
   SDL_FreeSurface(surface);
   SDL_DestroyWindow(window);
   SDL_Quit();
}


//Just the main. Very boring
int main(int argc, char *argv[])
{

   gameroot theGame;

   return theGame.execute();

}