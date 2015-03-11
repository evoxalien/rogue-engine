//#include <SDL.h>
#include <stdio.h>


class shape
{
private:
   SDL_Renderer* rendererCopy;

public:
   shape();
   shape(SDL_Renderer* tempRenderer);
   ~shape();
   bool drawSquare(SDL_Renderer* tempRenderer);
   bool drawBox(SDL_Renderer* tempRenderer);
   bool drawLine(SDL_Renderer* tempRenderer, int x1, int y1, int x2, int y2);
   bool drawDot(SDL_Renderer* tempRenderer, int x, int y);
   void setColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   void setAlpha(Uint8 Alpha);
   void clearRenderer();
   void clearRenderer(SDL_Renderer* tempRenderer);
   
   SDL_Rect square;
   SDL_Rect box;
   Uint8         r;
   Uint8         g;
   Uint8         b;
   Uint8         a;

};

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

shape::~shape()
 {
    rendererCopy = NULL;
 }

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

void shape::setColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   r = rIn;
   g = gIn;
   b = bIn;
}
void shape::setAlpha(Uint8 Alpha)
{
   a = Alpha;
}

void shape::clearRenderer(SDL_Renderer* tempRenderer)
{
   SDL_SetRenderDrawColor(tempRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

void shape::clearRenderer()
{
   SDL_SetRenderDrawColor(rendererCopy, 0xFF, 0xFF, 0xFF, 0xFF );
}

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

bool drawBox(SDL_Renderer* tempRenderer, int x, int y, int width, int hieght)
{
   
   SDL_Rect outlineRect = { x, y, width, hieght};
   SDL_SetRenderDrawColor( tempRenderer, 0xFF, 0x00, 0x00, 0xFF );
   SDL_RenderDrawRect( tempRenderer, &outlineRect );
   return true;
   	
}

bool drawLine(SDL_Renderer* tempRenderer, int x1, int y1, int x2, int y2)
{
   
   SDL_SetRenderDrawColor( tempRenderer, 0xFF, 0x00, 0x00, 0xFF );
   SDL_RenderDrawLine(tempRenderer, x1, y2, x2, y2);
   return true;
   	
}

bool drawDot(SDL_Renderer* tempRenderer, int x, int y)
{
   
   SDL_SetRenderDrawColor(tempRenderer, 0xFF, 0x00, 0x00, 0xFF );
   SDL_RenderDrawPoint(tempRenderer, x, y);
   return true;
   	
}