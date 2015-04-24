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
   bool setFont(string fontChoice);
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

//Defualt constructor. button is at (0,0) with calibri font by default
//Unable to draw without a renderer passed in at draw time or before hand
//default text is "button"
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
   font = TTF_OpenFont( "../resources/fonts/calibri.ttf", 500);
   if(font == NULL)
      printf("font not found!!\n");
   
   text = "button";
   textBox = {0, 0, 5, 5};
   textColor = {0, 0, 0};
   buttonBox.setColor(255, 0, 0);
   rendererCopy = NULL;
}

//Initialize button with a texture for pretty buttons
//with pictures instead of text
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
   font = TTF_OpenFont( "../resources/fonts/calibri.ttf", 500);
   if(font == NULL)
      printf("font not found!!\n");
   
   text = "button";
   textBox = { 0, 0, 5, 5};
   textColor = { 0, 0, 0 };
   buttonBox.setColor(255, 0, 0);
   rendererCopy = NULL;
}

//Initialize button with renderer so that draw can be called
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
   font = TTF_OpenFont( "../resources/fonts/calibri.ttf", 500);
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

//Initialize button with renderer and text to display
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
   font = TTF_OpenFont( "../resources/fonts/calibri.ttf", 500);
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

//Initialize button with renderer, text to display, position, and demisions
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
   font = TTF_OpenFont( "../resources/fonts/calibri.ttf", 500);
   if(font == NULL)
      printf("font not found!!\n");
   
   text = tempText;
   textBox = { xIn, yIn, wIn, hIn};
   buttonBox.box.x = xIn;
   buttonBox.box.y = yIn;
   buttonBox.box.w = wIn;
   buttonBox.box.h = hIn;
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

//Function to set renderer for button after being declared
void button::setRenderer(SDL_Renderer *rendererIn)
{
   rendererCopy = rendererIn;
   buttonBox.setRenderer(rendererCopy);
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

//Set width of button, pretty simple
void button::setWidth(int wIn)
{
   textBox.w = wIn;
   buttonBox.box.w = wIn;
}

//Set height of button, pretty simple
void button::setHeight(int hIn)
{
   textBox.h = hIn;
   buttonBox.box.h = hIn;
}

//Set x position of button
void button::setX(int xIn)
{
   textBox.x = xIn;
   buttonBox.box.x = xIn;
}

//Set y position of button
void button::setY(int yIn)
{
   textBox.y = yIn;
   buttonBox.box.y = yIn;
}

//Set the position of the button in terms of x and y
void button::setPos(int xIn, int yIn)
{
   textBox.x = xIn;
   buttonBox.box.x = xIn;
   
   textBox.y = yIn;
   buttonBox.box.y = yIn;
}

//Set the text for the button to display
void button::setText(string textIn)
{
   text = textIn;
   
    if(rendererCopy == NULL)
      return;
   
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

//Sets the font the button will use, sets to default font "calibri"
//if it fails and returns false
bool button::setFont(string fontChoice)
{
   fontChoice = "../resources/fonts/" + fontChoice + ".ttf";
   font = TTF_OpenFont(fontChoice.c_str() , 500);
   if(font == NULL)
   {
      printf("font not found, using default font!!\n");
	  font = TTF_OpenFont( "../resources/fonts/calibri.ttf", 500);
      if(font == NULL)
         printf("default font not found!!\n");
		 
      return false;
   }
   
   if(rendererCopy == NULL)
      return true;
   
   
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
   
   return true;
}

//sets the RBG based color for the text of the button
void button::setTextColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   textColor = {rIn, gIn, bIn};
   
   if(rendererCopy == NULL)
      return;
   
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

//Sets the color for the button itself
void button::setButtonColor(Uint8 rIn, Uint8 gIn, Uint8 bIn)
{
   buttonBox.setColor(rIn, gIn, bIn);
}

//Sets the size of the font used. large numbers suggested
void button::setFontSize(int size)
{
   font = TTF_OpenFont( "../resources/fonts/calibri.ttf", size);
   
    if(rendererCopy == NULL)
      return;
   
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

//Returns true if x and y passed in are within the button
bool button::isClicked(int x, int y)
{
   if(x > textBox.x && x < (textBox.x + textBox.w))
      if(y > textBox.y && y < (textBox.y + textBox.h))
	     return true;

   return false;
}

//Sets the buttons texture. Using this will take the place of
//The text and colored box
void button::setButtonTexture(SDL_Texture *buttonTextureIn)
{
   buttonTexture = buttonTextureIn;
}

//function to draw button if renderer has been assigned to
//the button. If no renderer was set, function returns false
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

//Function to draw button onto any renderer passed in.
bool button::draw(SDL_Renderer *rendererIn)
{

   if(buttonTexture == NULL)
   {
      buttonBox.drawSquare(rendererIn);
	  SDL_RenderCopyEx(rendererIn, textTexture, NULL, &textBox, 0.0, NULL, SDL_FLIP_NONE);
	  return true;
   }
   else
   {
      SDL_RenderCopyEx(rendererIn, buttonTexture, NULL, &textBox, 0.0, NULL, SDL_FLIP_NONE);
	  return true;
   }
}

#endif