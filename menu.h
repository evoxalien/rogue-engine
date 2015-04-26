#ifndef MENU_H_INCLUDED

#define MENU_H_INCLUDED

#include "SDLincludes.h"
#include <stdio.h>
#include <string>
#include "input.h"
#include "Texture.h"
#include "button.h"
#include "window.h"
#include "engineState.h"

using namespace std;

class menu
{
private:
   bool Running;
   Window *window;
   EngineState *engineState;
   SDL_Renderer *renderer;
   SDL_Event Event;
   bool initialize();
   InputClass input;
   button startButton;
   button exitButton;
   button mapButton;
  
 
public:
   menu(Window *mainWindow, EngineState *currentState);
   ~menu();
   bool loadContent();
   int execute();
   void OnEvent(SDL_Event *Event);
   void update();
   void draw();
   void close();
};

//Simple initializes
menu::menu(Window *mainWindow, EngineState *currentState)
{
   Running = false;
   window = mainWindow;
   engineState = currentState;
   renderer = NULL;
}

menu::~menu()
{
   close();
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

   renderer = window->getRenderer();
   
   int tempWidth = window->getWidth();
   int tempHeight = (window->getHeight()) / 3;
   
   startButton.setRenderer(renderer);
   startButton.setFont("times");
   startButton.setWidth(tempWidth);
   startButton.setHeight(tempHeight);
   startButton.setButtonColor(255, 255, 255);
   startButton.setText("Start Game");
   
   mapButton.setRenderer(renderer);
   mapButton.setFont("times");
   mapButton.setWidth(tempWidth);
   mapButton.setHeight(tempHeight);
   mapButton.setY(tempHeight);
   mapButton.setButtonColor(255, 255, 255);
   mapButton.setText("Edit Map");
   
   exitButton.setRenderer(renderer);
   exitButton.setFont("times");
   exitButton.setWidth(tempWidth);
   exitButton.setHeight(tempHeight);
   exitButton.setY((tempHeight + tempHeight));
   exitButton.setButtonColor(255, 255, 255);
   exitButton.setText("Exit Engine");
   
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
   return true;
}

//Event checking for game loop 
//Handles Events such as clicks and button pushes
//https://wiki.libsdl.org/SDL_Event
void menu::OnEvent(SDL_Event *Event)
{
   //Check if event is the clicking of the exit (red x)
   if(Event->type == SDL_WINDOWEVENT)
   {
      if(Event->window.windowID == window->ID)
	  {
	     if(Event->window.event == SDL_WINDOWEVENT_CLOSE)
		 {
		    Event->type = SDL_QUIT;
            SDL_PushEvent(Event);
         }
	  }
   }
   
   
   if(Event->type == SDL_QUIT)
   {
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
	  
	  if(input.getMouseButton(1) && window->thisWindowEvent(Event))
	     if(startButton.isClicked(input.getMouseX(),input.getMouseY()))
		 {
		    engineState->gameroot = true;
		    Running = false;
		 }
      
	  if(input.getMouseButton(1) && window->thisWindowEvent(Event))
	     if(mapButton.isClicked(input.getMouseX(),input.getMouseY()))
		 {
		    engineState->mapeditor = true;
			Running = false;
		 }
		    
      if(input.getMouseButton(1) && window->thisWindowEvent(Event))
	     if(exitButton.isClicked(input.getMouseX(),input.getMouseY()))
		 {
		    engineState->main = false;
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

   //close();
   return 0;
}

//Free all the assets
void menu::close()
{
   TTF_Quit();
   IMG_Quit();
}

#endif

