#ifndef BUTTON_H_INCLUDED

#define BUTTON_H_INCLUDED

#include <stdio.h>
#include <string>

class button
{
private:
   SDL_Texture *buttonTexture;
   SDL_Texture *textTexture;
   SDL_Renderer *rendererCopy;
   TTF_Font *font;

public:
   button();
   button(SDL_Texture *buttonTextureIn);
   button(SDL_Renderer *rendererIn);
   button(SDL_Renderer *rendererIn, string tempText);
   button(SDL_Renderer *rendererIn, string tempText,int xIn, int yIn,int wIn,int hIn);
   void setRenderer(SDL_Renderer *rendererIn);
   void setWidth(int wIn);
   void setHeight(int hIn);
   void setX(int xIn);
   void setY(int yIn);
   void setText(string textIn);
   void setTextColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   void setButtonColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   void setFontSize(int size);
   void setButtonTexture(SDL_Texture *buttonTextureIn);
   bool isClicked(int x, int y);
   bool draw();
   
   
   string text;
   SDL_Color textColor;
   SDL_Color buttonColor;
   SDL_Rect shape;

};

button::button()
{
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   text = "button";
   shape = { 0, 0, 5, 5};
   textColor = { 255, 255, 255 };
   buttonColor = { 255, 0, 0};
   rendererCopy = NULL;
}

button::button(SDL_Texture *buttonTextureIn)
{
   buttonTexture = buttonTextureIn;
   font = TTF_OpenFont( "calibri.ttf", 28);
   text = "button";
   shape = { 0, 0, 5, 5};
   textColor = { 255, 255, 255 };
   buttonColor = { 255, 0, 0};
   rendererCopy = NULL;
}

button::button(SDL_Renderer *rendererIn)
{
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   text = "button";
   shape = { 0, 0, 5, 5};
   textColor = { 255, 255, 255 };
   buttonColor = { 255, 0, 0};
   rendererCopy = rendererIn;
}


button::button(SDL_Renderer *rendererIn, string tempText)
{
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   text = tempText;
   shape = { 0, 0, 5, 5};
   buttonColor = { 255, 0, 0};
   rendererCopy = rendererIn;   
}

button::button(SDL_Renderer *rendererIn, string tempText,int xIn, int yIn,int wIn,int hIn)
{
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   text = tempText;
   shape = { xIn, yIn, wIn, hIn};
   textColor = {255, 255, 255};
   buttonColor = { 255, 0, 0};
   rendererCopy = rendererIn;
}

void button::setRenderer(SDL_Renderer *rendererIn)
{
   rendererCopy = rendererIn;
}

void button::setWidth(int wIn)
{
   shape.w = wIn;
}

void button::setHeight(int hIn)
{
   shape.h = hIn;
}

void button::setX(int xIn)
{
   shape.x = xIn;
}

void button::setY(int yIn)
{
   shape.y = yIn;
}

void button::setText(string textIn)
{
   text = textIn;
}

void button::setTextColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   textColor = {rIn, gIn, bIn};
}

void button::setButtonColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   buttonColor = {rIn, gIn, bIn};
}

void button::setFontSize(int size)
{
   font = TTF_OpenFont( "calibri.ttf", size);
}

bool button::isClicked(int x, int y)
{
   if(x > shape.x && x < (shape.x + shape.w))
      if(y > shape.y && y < (shape.y + shape.h))
	     return true;

   return false;
}

void button::setButtonTexture(SDL_Texture *buttonTextureIn)
{
   buttonTexture = buttonTextureIn;
}

bool button::draw()
{
   
   if(buttonTexture == NULL)
   {
      SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
      if(textSurface == NULL )
      {
         printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
      }
   
      textTexture = SDL_CreateTextureFromSurface(rendererCopy, textSurface );
      if(textTexture == NULL )
      {
         printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
      }
   
      SDL_SetTextureColorMod(textTexture, buttonColor.r, buttonColor.g, buttonColor.b);
   
      SDL_RenderCopyEx(rendererCopy, textTexture, NULL, &shape, 0.0, NULL, SDL_FLIP_NONE);
   }
   
   SDL_RenderCopyEx(rendererCopy, buttonTexture, NULL, &shape, 0.0, NULL, SDL_FLIP_NONE);
   
   return true;
}

#endif