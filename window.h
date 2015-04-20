#ifndef WINDOW_H_INCLUDED

#define WINDOW_H_INCLUDED

#include <stdio.h>
#include "SDLincludes.h"
#include <string>


class Window
{
   private:
   SDL_Window *windowPointer;
   SDL_Renderer *windowRenderer;
   int width;
   int height;
   
   public:
   Window();
   //Window(string windowText);
   Window(int staticWindow);
   Window(int x, int y);
   Window(int x, int y,int w, int h);
   ~Window();
   
   SDL_Renderer* getRenderer();
   //void setTitle(string titleIn)
   void update(SDL_Event& windowEvent);
   int getWidth();
   int getHeight();
   bool isWindowEvent(SDL_Event& event);
   bool thisWindowEvent(SDL_Event& windowEvent);
   bool render();
   
   int ID;
   bool mouseFocus;
   bool keyboardFocus;
   bool fullScreen;
   bool minimized;   
};

Window::Window()
{
   if(!SDL_WasInit(SDL_INIT_EVERYTHING))
   {
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
      {
         printf("SDL Component failed to initialize Error: %s", SDL_GetError());
      }
   }
   
   width = 1024;
   height = 720;
   windowPointer = SDL_CreateWindow("Rogue Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   if(windowPointer == NULL)
   {
      printf("Window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   ID = SDL_GetWindowID(windowPointer);
   windowRenderer = SDL_CreateRenderer(windowPointer, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if(windowRenderer == NULL)
   {
      printf("renderer for window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

/*Window::Window(string windowText)
{
   if(!SDL_WasInit(SDL_INIT_EVERYTHING))
   {
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
      {
         printf("SDL Component failed to initialize Error: %s", SDL_GetError());
      }
   }
   
   width = 1024;
   height = 720;
   windowPointer = SDL_CreateWindow(windowText.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   if(windowPointer == NULL)
   {
      printf("Window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   ID = SDL_GetWindowID(windowPointer);
   windowRenderer = SDL_CreateRenderer(windowPointer, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if(windowRenderer == NULL)
   {
      printf("renderer for window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}*/

Window::Window(int staticWindow)
{
   if(!SDL_WasInit(SDL_INIT_EVERYTHING))
   {
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
      {
         printf("SDL Component failed to initialize Error: %s", SDL_GetError());
      }
   }
   
   width = 1024;
   height = 720;
   
   if(staticWindow == 1)
      windowPointer = SDL_CreateWindow("Rogue Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
   else
      windowPointer = SDL_CreateWindow("Rogue Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   
   if(windowPointer == NULL)
   {
      printf("Window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   ID = SDL_GetWindowID(windowPointer);
   windowRenderer = SDL_CreateRenderer(windowPointer, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if(windowRenderer == NULL)
   {
      printf("renderer for window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Window::Window(int x, int y)
{
   if(!SDL_WasInit(SDL_INIT_EVERYTHING))
   {
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
      {
         printf("SDL Component failed to initialize Error: %s", SDL_GetError());
      }
   }
   
   width = 1024;
   height = 720;
   if(x > 0 && y > 0)
      windowPointer = SDL_CreateWindow("Rogue Engine", x, y, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   else
   {
      printf("Window position invalid! Using default window position\n");
      windowPointer = SDL_CreateWindow("Rogue Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);   
   }
   
   if(windowPointer == NULL)
   {
      printf("Window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   ID = SDL_GetWindowID(windowPointer);
   windowRenderer = SDL_CreateRenderer(windowPointer, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if(windowRenderer == NULL)
   {
      printf("renderer for window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Window::Window(int x, int y,int w, int h)
{
   if(!SDL_WasInit(SDL_INIT_EVERYTHING))
   {
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
      {
         printf ("SDL Component failed to initialize Error: %s", SDL_GetError());
      }
   }
   if(x > 0 && y > 0 && w > 0 && h > 0)
   {
      width = w;
      height = h;
      windowPointer = SDL_CreateWindow("Rogue Engine", x, y, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   }
   else
   {
      printf("Window deminsions are invalid! Using default window size\n");
	  width = 1024;
      height = 720;
      windowPointer = SDL_CreateWindow("Rogue Engine", x, y, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   }
   if(windowPointer == NULL)
   {
      printf( "Window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   ID = SDL_GetWindowID(windowPointer);
   
   windowRenderer = SDL_CreateRenderer(windowPointer, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if(windowRenderer == NULL)
   {
      printf( "renderer for window failed to be created! SDL Error: %s\n", SDL_GetError());
   }
   
   SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Window::~Window()
{
   SDL_DestroyRenderer(windowRenderer);
   SDL_DestroyWindow(windowPointer);
}

SDL_Renderer* Window::getRenderer()
{
   return windowRenderer;
}

/*void Window::setTitle(string titleIn)
{
   SDL_SetWindowTitle( windowPointer, titleIn.c_str());
}*/

void Window::update(SDL_Event& windowEvent)
{
   //Check if event belongs to this window and is a window event
   if(windowEvent.type == SDL_WINDOWEVENT && windowEvent.window.windowID == ID)
   {
      //updates state of window
      switch(windowEvent.window.event)
      {
         case SDL_WINDOWEVENT_SIZE_CHANGED:
              width = windowEvent.window.data1;
              height = windowEvent.window.data2;
              break;
         
         case SDL_WINDOWEVENT_ENTER:
              mouseFocus = true;
              break;
         
		 case SDL_WINDOWEVENT_LEAVE:
              mouseFocus = false;
              break;
			  
         case SDL_WINDOWEVENT_FOCUS_GAINED:
              keyboardFocus = true;
              break;
         
		 case SDL_WINDOWEVENT_FOCUS_LOST:
              keyboardFocus = false;
              break;
		 
		 case SDL_WINDOWEVENT_MINIMIZED:
              minimized = true;
              break;
		 
		 case SDL_WINDOWEVENT_MAXIMIZED:
              minimized = false;
              break;
		 
		 case SDL_WINDOWEVENT_RESTORED:
              minimized = false;
              break;
      }
   }
}

int Window::getWidth()
{
   return width;
}

int Window::getHeight()
{
   return height;
}

bool Window::isWindowEvent(SDL_Event& event)
{
   if(event.type == SDL_WINDOWEVENT)
      return true;
   else
      return false;
}

bool Window::thisWindowEvent(SDL_Event& windowEvent)
{
   if(windowEvent.type == SDL_WINDOWEVENT && windowEvent.window.windowID == ID)
      return true;
   else
      return false;
}

bool Window::render()
{
   SDL_RenderPresent(windowRenderer);
}

#endif