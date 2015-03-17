#include"gameroot.h"

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
   //Tests SDL components, important to call before other SDL operations
   //https://wiki.libsdl.org/SDL_Init
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
   {
      return false;
   }

   //Calls and tests function to create SDL Window (documentation in link)
   //https://wiki.libsdl.org/SDL_CreateWindow
   //SCREEN_WIDTH of 1024 and SCREEN_HEIGHT of 720 passed in as well as window name
   if((window = SDL_CreateWindow( "Rogue Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 720, SDL_WINDOW_SHOWN )) == NULL)
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

}

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