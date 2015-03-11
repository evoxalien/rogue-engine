//#include <SDL.h>
#include <stdio.h>

bool drawSquare(SDL_Renderer* tempRenderer, int x, int y, int width, int hieght)
{
   
   SDL_Rect fillRect = { x, y, width, hieght};
   SDL_SetRenderDrawColor( tempRenderer, 0xFF, 0x00, 0x00, 0xFF );
   SDL_RenderFillRect( tempRenderer, &fillRect );
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