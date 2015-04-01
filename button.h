#ifndef BUTTON_H_INCLUDED

#define BUTTON_H_INCLUDED

#include <stdio.h>
#include <string>
#include "SDLincludes.h"
#include "easyShapes.h"

class button
{
private:
   SDL_Texture *buttonTexture;
   SDL_Texture *textTexture;
   SDL_Renderer *rendererCopy;
   TTF_Font *font;
   shape buttonBox;

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
   void setPos(int xIn, int yIn);
   void setText(string textIn);
   void setTextColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   void setButtonColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   void setFontSize(int size);
   void setButtonTexture(SDL_Texture *buttonTextureIn);
   bool isClicked(int x, int y);
   bool draw();
   bool draw(SDL_Renderer *rendererIn);
   
   
   string text;
   SDL_Color textColor;
   SDL_Rect textBox;

};

button::button()
{
   if(!TTF_WasInit())
   {
      if(TTF_Init() < 0)
      {
         printf("TTF_Init() failed: %s\n", TTF_GetError());
      }
   }
   
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   if(font == NULL)
      printf("font not found!!\n");
   
   text = "button";
   textBox = {0, 0, 5, 5};
   textColor = {0, 0, 0};
   buttonBox.setColor(255, 0, 0);
   rendererCopy = NULL;
}

button::button(SDL_Texture *buttonTextureIn)
{
   if(!TTF_WasInit())
   {
      if(TTF_Init() < 0)
      {
         printf("TTF_Init() failed: %s\n", TTF_GetError());
      }
   }
   
   buttonTexture = buttonTextureIn;
   font = TTF_OpenFont( "calibri.ttf", 28);
   if(font == NULL)
      printf("font not found!!\n");
   
   text = "button";
   textBox = { 0, 0, 5, 5};
   textColor = { 0, 0, 0 };
   buttonBox.setColor(255, 0, 0);
   rendererCopy = NULL;
}

button::button(SDL_Renderer *rendererIn)
{
   if(!TTF_WasInit())
   {
      if(TTF_Init() < 0)
      {
         printf("TTF_Init() failed: %s\n", TTF_GetError());
      }
   }
   
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   if(font == NULL)
      printf("font not found!!\n");

   text = "button";
   textBox = { 0, 0, 5, 5};
   textColor = { 0, 0, 0 };
   buttonBox.setColor(255, 0, 0);
   rendererCopy = rendererIn;
   
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
   
   SDL_SetTextureColorMod(textTexture, textColor.r, textColor.g, textColor.b);
   
   SDL_FreeSurface(textSurface);
}


button::button(SDL_Renderer *rendererIn, string tempText)
{
   if(!TTF_WasInit())
   {
      if(TTF_Init() < 0)
      {
         printf("TTF_Init() failed: %s\n", TTF_GetError());
      }
   }
   
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   if(font == NULL)
      printf("font not found!!\n");
   
   text = tempText;
   textBox = { 0, 0, 5, 5};
   buttonBox.setColor(255, 0, 0);
   rendererCopy = rendererIn;
   
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
   
   SDL_SetTextureColorMod(textTexture, textColor.r, textColor.g, textColor.b);
   
   SDL_FreeSurface(textSurface);
}

button::button(SDL_Renderer *rendererIn, string tempText,int xIn, int yIn,int wIn,int hIn)
{
   if(!TTF_WasInit())
   {
      if(TTF_Init() < 0)
      {
         printf("TTF_Init() failed: %s\n", TTF_GetError());
      }
   }
   
   buttonTexture = NULL;
   font = TTF_OpenFont( "calibri.ttf", 28);
   if(font == NULL)
      printf("font not found!!\n");
   
   text = tempText;
   textBox = { xIn, yIn, wIn, hIn};
   textColor = {0, 0, 0};
   buttonBox.setColor(255, 0, 0);
   rendererCopy = rendererIn;
   
   SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
   if(textSurface == NULL )
   {
      printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
   }
   
   SDL_DestroyTexture(textTexture);
   
   textTexture = SDL_CreateTextureFromSurface(rendererCopy, textSurface );
   if(textTexture == NULL )
   {
      printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
   }
   
   SDL_SetTextureColorMod(textTexture, textColor.r, textColor.g, textColor.b);
   
   SDL_FreeSurface(textSurface);
}

void button::setRenderer(SDL_Renderer *rendererIn)
{
   rendererCopy = rendererIn;
   buttonBox.setRenderer(rendererCopy);
   printf("renderer pointer coppied!\n");
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
   
   SDL_SetTextureColorMod(textTexture, textColor.r, textColor.g, textColor.b);
   
   SDL_FreeSurface(textSurface);
}

void button::setWidth(int wIn)
{
   textBox.w = wIn;
   buttonBox.box.w = wIn;
}

void button::setHeight(int hIn)
{
   textBox.h = hIn;
   buttonBox.box.h = hIn;
}

void button::setX(int xIn)
{
   textBox.x = xIn;
   buttonBox.box.x = xIn;
}

void button::setY(int yIn)
{
   textBox.y = yIn;
   buttonBox.box.y = yIn;
}

void button::setPos(int xIn, int yIn)
{
   textBox.x = xIn;
   buttonBox.box.x = xIn;
   
   textBox.y = yIn;
   buttonBox.box.y = yIn;
}

void button::setText(string textIn)
{
   text = textIn;
   
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
   
   SDL_SetTextureColorMod(textTexture, textColor.r, textColor.g, textColor.b);
   
   SDL_FreeSurface(textSurface);
}

void button::setTextColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   textColor = {rIn, gIn, bIn};
   
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
   
   SDL_SetTextureColorMod(textTexture, textColor.r, textColor.g, textColor.b);
   
   SDL_FreeSurface(textSurface);
}

void button::setButtonColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   buttonBox.setColor(rIn, gIn, bIn);
}

void button::setFontSize(int size)
{
   font = TTF_OpenFont( "calibri.ttf", size);
   
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
   
   SDL_SetTextureColorMod(textTexture, textColor.r, textColor.g, textColor.b);
   
   SDL_FreeSurface(textSurface);
}

bool button::isClicked(int x, int y)
{
   if(x > textBox.x && x < (textBox.x + textBox.w))
      if(y > textBox.y && y < (textBox.y + textBox.h))
	     return true;

   return false;
}

void button::setButtonTexture(SDL_Texture *buttonTextureIn)
{
   buttonTexture = buttonTextureIn;
}

bool button::draw()
{
   if(rendererCopy == NULL)
      return false;
   
   if(buttonTexture == NULL)
   {
      buttonBox.drawSquare();
      SDL_RenderCopyEx(rendererCopy, textTexture, NULL, &textBox, 0.0, NULL, SDL_FLIP_NONE);
	  return true;
   }
   else
   {
      SDL_RenderCopyEx(rendererCopy, buttonTexture, NULL, &textBox, 0.0, NULL, SDL_FLIP_NONE);
      return true;
   }
}

bool button::draw(SDL_Renderer *rendererIn)
{

   if(buttonTexture == NULL)
   {
      buttonBox.drawSquare(rendererIn);
	  SDL_RenderCopyEx(rendererCopy, textTexture, NULL, &textBox, 0.0, NULL, SDL_FLIP_NONE);
	  return true;
   }
   else
   {
      SDL_RenderCopyEx(rendererIn, buttonTexture, NULL, &textBox, 0.0, NULL, SDL_FLIP_NONE);
	  return true;
   }
}

#endif