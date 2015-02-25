/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "input.h"

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

//loads a texture from surface at string path
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//renderer to display textures to the window
SDL_Renderer* Renderer = NULL;

//The image we will load and show on the screen
SDL_Texture* imgTex = NULL;

InputClass input;
SDL_Rect whiteBoxRect;
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
         }
      }
   }


   whiteBoxRect.x = 0;
   whiteBoxRect.y = 0;
   whiteBoxRect.w = 10;
   whiteBoxRect.h = 10;

   return success;
}

bool loadMedia()
{
   //Loading success flag
   bool success = true;

   imgTex = loadTexture("img/shapes/WhiteSquare.png");

   return success;
}

void close()
{
   //Destroy Textures
   SDL_DestroyTexture(imgTex);
   imgTex = NULL;

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
         whiteBoxRect.x = input.getMouseX();
         whiteBoxRect.y = input.getMouseY();
      }

      switch(input.getKeyDown())
      {
         case(SDLK_s) :
            whiteBoxRect.y++; break;
         case(SDLK_w) :
            whiteBoxRect.y--; break;
         case(SDLK_d) :
            whiteBoxRect.x++; break;
         case(SDLK_a) :
            whiteBoxRect.x--; break;
      }
   }
}

void draw()
{
   //clear screen
   SDL_RenderClear(Renderer);

   //render texture to screen
   SDL_RenderCopy(Renderer, imgTex, NULL, &whiteBoxRect);

   //update screen
   SDL_RenderPresent(Renderer);
}

SDL_Texture* loadTexture(std::string path)
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
      //convert image to screen format
      newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);
      if(newTexture == NULL)
      {
         printf("Failed to optimize image %s: %s\n", path.c_str(), SDL_GetError());
      }
      
   }
   return newTexture;
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