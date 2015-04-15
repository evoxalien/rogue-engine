#ifndef MENU_H_INCLUDED

#define MENU_H_INCLUDED

#include "SDLincludes.h"
#include <stdio.h>
#include <string>
#include "input.h"
#include "Texture.h"
#include "button.h"

using namespace std;

class menu
{
private:
   bool Running;
   int menuChoice;
   SDL_Window *window;
   SDL_Renderer *renderer;
   Texture texture;
   SDL_Event Event;
   bool initialize();
   InputClass input;
   button startButton;
   button exitButton;
   button mapButton;
  
 
public:
   menu(); 
   bool loadContent();
   int execute();
   void OnEvent(SDL_Event *Event);
   void update();
   void draw();
   void close();
};

//Simple initializes
menu::menu()
{
   Running = false;
   window = NULL;
   renderer = NULL;
}


//Initialize all the SDL
bool menu::initialize()
{
   //Tests SDL components, important to call before other SDL operations
   //https://wiki.libsdl.org/SDL_Init
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
   {
      printf ("SDL Component failed to initialize Error: %s", SDL_GetError());
      return false;
   }
   
   //Tests SDL font components
   if(!TTF_WasInit())
   {
      if(TTF_Init() < 0)
      {
         printf("TTF_Init() failed: %s\n", TTF_GetError());
      }
   }

   //Calls and tests function to create SDL Window (documentation in link)
   //https://wiki.libsdl.org/SDL_CreateWindow
   if((window = SDL_CreateWindow( "Start Menu",  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, 720, 800, SDL_WINDOW_SHOWN )) == NULL)
   {
      printf ("Window Error: %s", SDL_GetError());
      return false;
   }

   //Creates SDL Renderer. Renderer renders assets to SDL windows
   //Can be used to draw .bmp images to window (example in link)
   //https://wiki.libsdl.org/SDL_CreateRenderer
   renderer = SDL_CreateRenderer (window , - 1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;
   
   startButton.setRenderer(renderer);
   startButton.setFont("times");
   startButton.setWidth(720);
   startButton.setHeight(266);
   startButton.setButtonColor(255, 255, 255);
   startButton.setText("Start Game");
   
   mapButton.setRenderer(renderer);
   mapButton.setFont("times");
   mapButton.setWidth(720);
   mapButton.setHeight(266);
   mapButton.setY(266);
   mapButton.setButtonColor(255, 255, 255);
   mapButton.setText("Edit Map");
   
   exitButton.setRenderer(renderer);
   exitButton.setFont("times");
   exitButton.setWidth(720);
   exitButton.setHeight(266);
   exitButton.setY(532);
   exitButton.setButtonColor(255, 255, 255);
   exitButton.setText("Exit Engine");
   
   //Tests if renderer initialized properly
   if (renderer == NULL)
   {
      printf ("Render Error: %s", SDL_GetError());
      return false;
   }

   //set render draw color property
   SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

   //tell texture the renderer to use
   texture.setRenderer(renderer);
   
   //initialize image subsystem to load png files
   int imgFlags = IMG_INIT_PNG;
   if(!(IMG_Init(imgFlags) & imgFlags))
   {
      printf("SDL_Image could not be initialized. SDL_Image error : %s\n", IMG_GetError());
      return false;
   }
   
   //clear event stack
   while(SDL_PollEvent(&Event));

   //sets boolean to true. This boolean determines if the game loop continues
   Running = true;
  
   return true;
}

//Load textures and other content here
bool menu::loadContent()
{

   if(!texture.loadTexture("../../images/dino.png"))
   {
      error_log << "Texture failed to load.\n";
      return false;
   }
   texture.setWidth(720);
   texture.setHeight(1024);
   
   return true;

}

//Event checking for game loop 
//Handles Events such as clicks and button pushes
//https://wiki.libsdl.org/SDL_Event
void menu::OnEvent(SDL_Event *Event)
{
   //Check if event is the clicking of the exit (SDL_QUIT)
   if(Event->type == SDL_QUIT)
   {
      menuChoice = 3;
      Running = false;
   }
}

//Does nothing. Math and physics later
void menu::update()
{
   while(SDL_PollEvent(&Event))
   {
      //Updates input object, holding current buttons pressed
      input.update(Event);
	  
	  if(input.getMouseButton(1))
	     if(startButton.isClicked(input.getMouseX(),input.getMouseY()))
		 {
		    menuChoice = 1;
			Running = false;
		 }
      
	  if(input.getMouseButton(1))
	     if(mapButton.isClicked(input.getMouseX(),input.getMouseY()))
		 {
		    menuChoice = 2;
			Running = false;
		 }
		    
      if(input.getMouseButton(1))
	     if(exitButton.isClicked(input.getMouseX(),input.getMouseY()))
		 {
		    menuChoice = 3;
			Running = false;
		 }
	  
	  //Checking if X has been clicked
      OnEvent(&Event);
	  
   }  
      
}
   
//Draws to screen
void menu::draw()
{
   //Clear screen
   SDL_RenderClear(renderer);
   
   startButton.draw();
   mapButton.draw();
   exitButton.draw();
   
   //update screen
   SDL_RenderPresent(renderer);
}

//Actual game loop
int menu::execute()
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
   return menuChoice;
}

//Free all the assets
void menu::close()
{
   texture.free();
 
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   
   TTF_Quit();
   IMG_Quit();
   SDL_Quit();
}

#endif

