/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "input.h"
#include "Texture.h"
#include "Room.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool running = true;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//renderer to display textures to the window
SDL_Renderer* Renderer = NULL;

Room room;
InputClass input;
SDL_Event event;

bool init()
{
   //Initialization flag
   bool success = true;

   //Initialize SDL
   if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
   {
      printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
      success = false;
   }
   else
   {
      //Create window
      gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
      if( gWindow == NULL )
      {
         printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
         success = false;
      }
      else
      {
         Renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
         if(Renderer == NULL)
         {
            printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
         }
         else
         {
            SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0x00);
            //Initialize PNG Loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags))
            {
               printf("SDL_Image could not be initialized: %s\n", IMG_GetError());
               success = false;
            }
            else
            {
               room.setRenderer(Renderer);
            }
         }
      }
   }


   room.baseRect.x = 0;
   room.baseRect.y = 0;
   room.baseRect.w = 10;
   room.baseRect.h = 10;

   return success;
}

bool loadMedia()
{
   //Loading success flag
   bool success = true;

   room.setBaseTexture("img/shapes/WhiteSquare.png");

   return success;
}

void close()
{
   //Destroy Renderer
   SDL_DestroyRenderer(Renderer);
   Renderer = NULL;

   //Destroy window
   SDL_DestroyWindow( gWindow );
   gWindow = NULL;

   //Quit SDL subsystems
   SDL_Quit();
   IMG_Quit();
}

void update()
{
   while(SDL_PollEvent(&event))
   {
      input.update(event);
      if(event.type == SDL_QUIT)
      {
         running = false;
      }

      if(input.getMouseButton(1))
      {
         room.baseRect.x = input.getMouseX();
         room.baseRect.y = input.getMouseY();
      }

      switch(input.getKeyDown())
      {
         case(SDLK_s) :
            room.baseRect.y++; break;
         case(SDLK_w) :
            room.baseRect.y--; break;
         case(SDLK_d) :
            room.baseRect.x++; break;
         case(SDLK_a) :
            room.baseRect.x--; break;
         case(SDLK_UP) :
            room.baseRect.y--;
            room.baseRect.h++; break;
         case(SDLK_DOWN) :
            room.baseRect.h++; break;
         case(SDLK_LEFT) :
            room.baseRect.x--; 
            room.baseRect.w++; break;
         case(SDLK_RIGHT) :
            room.baseRect.w++; break;
      }
   }

   room.update();
}

void draw()
{
   //clear screen
   SDL_RenderClear(Renderer);

   //render texture to screen
   //SDL_RenderCopy(Renderer, imgTex, NULL, &room.baseRect);
   room.render(0,0);

   //update screen
   SDL_RenderPresent(Renderer);
}

int main( int argc, char* args[] )
{
   //Start up SDL and create window
   if( !init() )
   {
      printf( "Failed to initialize!\n" );
   }
   else
   {
      //Load media
      if( !loadMedia() )
      {
         printf( "Failed to load media!\n" );
      }
      else
      {
         while(running)
         {
            update();
            draw();
         }
      }
   }

   //SDL_Delay(3000);

   //Free resources and close SDL
   close();

   return 0;
}