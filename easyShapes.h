//#include <SDL.h>
#ifndef EASYSHAPES_H_INCLUDED

#define EASYSHAPES_H_INCLUDED

#include <stdio.h>

//Class for storing and posting a shape to the SDL renderer
class shape
{
private:
   //pointer to reference pointer passed in
   SDL_Renderer* rendererCopy;

public:
   //Class can be used with a renderer passed in
   //or have a renderer passed in each time
   shape();
   shape(SDL_Renderer* tempRenderer);
   ~shape();
   bool drawSquare(SDL_Renderer* tempRenderer);
   bool drawSquare();
   bool drawBox(SDL_Renderer* tempRenderer);
   bool drawBox();
   bool drawLine(SDL_Renderer* tempRenderer, int x1, int y1, int x2, int y2);
   bool drawLine(int x1, int y1, int x2, int y2);
   bool drawDot(SDL_Renderer* tempRenderer, int x, int y);
   bool drawDot(int x, int y);
   void setColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   void setAlpha(Uint8 Alpha);
   void setRenderer(SDL_Renderer* tempRenderer);
   void clearRenderer();
   void clearRenderer(SDL_Renderer* tempRenderer);
   
   //Two rectangles to store position of filled or empty box
   SDL_Rect square;
   SDL_Rect box;
   
   //Values for Red, Green, Blue, and Alpha level
   Uint8         r;
   Uint8         g;
   Uint8         b;
   Uint8         a;

};

//Initialize without a renderer
shape::shape()
{
   rendererCopy = NULL;
   square = { 0, 0, 5, 5};
   box = { 0, 0, 5, 5};
   r = 0xFF;
   g = 0x00;
   b = 0x00;
   a = 0xFF; 
}

//Initialise with renderer, making draw commands easier
shape::shape(SDL_Renderer* tempRenderer)
{
   rendererCopy = tempRenderer;
   square = { 0, 0, 5, 5};
   box = { 0, 0, 5, 5};
   r = 0xFF;
   g = 0x00;
   b = 0x00;
   a = 0xFF; 
}

//Point pointer to NULL
shape::~shape()
{
    rendererCopy = NULL;
}

//Function draws a square of the color and size stored in class
//Requires passing in a renderer
bool shape::drawSquare(SDL_Renderer* tempRenderer)
{
   if(SDL_SetRenderDrawColor(tempRenderer, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   if(SDL_RenderFillRect(tempRenderer, &square ) < 0)
   {
      printf("SDL_RenderFillRect in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   return true;
   	
}

//Function draws a square of the color and size stored in class
bool shape::drawSquare()
{
   if(rendererCopy == NULL)
   {
      printf("Renderer never set!: %s\n");
	  return false;
   }
   
   if(SDL_SetRenderDrawColor(rendererCopy, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   if(SDL_RenderFillRect(rendererCopy, &square ) < 0)
   {
      printf("SDL_RenderFillRect in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   return true;
   	
}

//Function draws an empty box of the color and size stored in class
//Requires passing in a renderer
bool shape::drawBox(SDL_Renderer* tempRenderer)
{
   if(SDL_SetRenderDrawColor(tempRenderer, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   if(SDL_RenderDrawRect(tempRenderer, &box ) < 0)
   {
      printf("SDL_RenderDrawRect in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   return true;
   	
}

//Function draws an empty box of the color and size stored in class
bool shape::drawBox()
{
   if(rendererCopy == NULL)
   {
      printf("Renderer never set!: %s\n");
	  return false;
   }
   
   if(SDL_SetRenderDrawColor(rendererCopy, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   if(SDL_RenderDrawRect(rendererCopy, &box ) < 0)
   {
      printf("SDL_RenderDrawRect in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   return true;
   	
}

//Function draws a line connecting the points passed in
//Requires passing in a renderer
bool shape::drawLine(SDL_Renderer* tempRenderer, int x1, int y1, int x2, int y2)
{
   
   if(SDL_SetRenderDrawColor(tempRenderer, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   if(SDL_RenderDrawLine(tempRenderer, x1, y2, x2, y2) < 0)
   {
      printf("SDL_RenderDrawLine in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   return true;
   	
}

//Function draws a line connecting the points passed in
bool shape::drawLine(int x1, int y1, int x2, int y2)
{
   if(rendererCopy == NULL)
   {
      printf("Renderer never set!: %s\n");
	  return false;
   }
   
   if(SDL_SetRenderDrawColor(rendererCopy, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   if(SDL_RenderDrawLine(rendererCopy, x1, y2, x2, y2) < 0)
   {
      printf("SDL_RenderDrawLine in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   return true;
   	
}

//Function draws a dot at position passed in as x, y cordinates
//Requires passing in a renderer
bool shape::drawDot(SDL_Renderer* tempRenderer, int x, int y)
{
   
   if(SDL_SetRenderDrawColor(tempRenderer, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   
   if(SDL_RenderDrawPoint(tempRenderer, x, y) < 0)
   {
      printf("SDL_RenderDrawPoint in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   return true;
   	
}

//Function draws a dot at position passed in as x, y coordinates
bool shape::drawDot(int x, int y)
{
   
   if(SDL_SetRenderDrawColor(rendererCopy, r, g, b, a) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   
   if(SDL_RenderDrawPoint(rendererCopy, x, y) < 0)
   {
      printf("SDL_RenderDrawPoint in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   return true;
   	
}

//Used to set the color of the shapes drawn by the class
void shape::setColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   r = rIn;
   g = gIn;
   b = bIn;
}

//Sets the alpha level of the shapes drawn
void shape::setAlpha(Uint8 Alpha)
{
   a = Alpha;
}

//Sets the renderer to be used by the class
void shape::setRenderer(SDL_Renderer* tempRenderer)
{
   rendererCopy = tempRenderer;
}

//Sets the renderer draw color to white
void shape::clearRenderer(SDL_Renderer* tempRenderer)
{
   if(SDL_SetRenderDrawColor(tempRenderer, 0xFF, 0xFF, 0xFF, 0xFF) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
   }
}

//Sets the renderer draw color to white
//Requires passing in a renderer
void shape::clearRenderer()
{
   if(SDL_SetRenderDrawColor(rendererCopy, 0xFF, 0xFF, 0xFF, 0xFF) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
   }
}

//Global function to draw a square without declaring an object
bool drawSquare(SDL_Renderer* tempRenderer, int x, int y, int width, int hieght)
{
   
   SDL_Rect fillRect = { x, y, width, hieght};
   if(SDL_SetRenderDrawColor( tempRenderer, 0xFF, 0x00, 0x00, 0xFF ) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   if(SDL_RenderFillRect( tempRenderer, &fillRect ) < 0)
   {
      printf("SDL_RenderFillRect in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   return true;
   	
}

//Global function to draw an empty box without declaring an object
bool drawBox(SDL_Renderer* tempRenderer, int x, int y, int width, int hieght)
{
   
   SDL_Rect outlineRect = { x, y, width, hieght};

   if(SDL_SetRenderDrawColor( tempRenderer, 0xFF, 0x00, 0x00, 0xFF ) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   
   if(SDL_RenderDrawRect( tempRenderer, &outlineRect ) < 0)
   {
      printf("SDL_RenderDrawRect in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   return true;
   	
}

//Global function to draw a line connecting two points without declaring an instance of the class
bool drawLine(SDL_Renderer* tempRenderer, int x1, int y1, int x2, int y2)
{
   
   if(SDL_SetRenderDrawColor( tempRenderer, 0xFF, 0x00, 0x00, 0xFF ) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   
   if(SDL_RenderDrawLine(tempRenderer, x1, y2, x2, y2) < 0)
   {
      printf("SDL_RenderDrawLine in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   return true;
   	
}

//Global function to draw a dot without declaring an instance of the class
bool drawDot(SDL_Renderer* tempRenderer, int x, int y)
{
   
   if(SDL_SetRenderDrawColor(tempRenderer, 0xFF, 0x00, 0x00, 0xFF ) < 0)
   {
      printf("SDL_SetRenderDrawColor in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   
   
   if(SDL_RenderDrawPoint(tempRenderer, x, y) < 0)
   {
      printf("SDL_RenderDrawPoint in shape object failed: %s\n", SDL_GetError());
      SDL_ClearError();
	  return false;
   }
   return true;
   	
}

#endif