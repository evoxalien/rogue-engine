#ifndef BUTTON_H_INCLUDED

#define BUTTON_H_INCLUDED

#include <stdio.h>
#include <string>

class button
{
private:
   SDL_Surface *tempSurface;
   SDL_Surface *windowCopy;
   TTF_Font *font;

public:
   button(SDL_Window *windowOriganal);
   button(SDL_Window *windowOriganal, string tempText);
   button(SDL_Window *windowOriganal, string tempText,int xIn, int yIn, wIn, hIn);
   void setWidth(int wIn);
   void setHeight(int hIn);
   void setX(int xIn);
   void setY(int yIn);
   void setText(string textIn);
   void setColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   void setButtonColor(Uint8 rIn, Uint8 gIn, Uint8 bIn);
   bool draw();
   
   
   string text;
   SDL_Color textColor;
   SDL_Color buttonColor;
   SDL_Rect shape;

};

button::button(SDL_Window *windowOriganal)
{
   font = TTF_OpenFont( "lazy.ttf", 28);
   windowCopy = SDL_GetWindowSurface(windowOriganal);
   text = "button";
   shape = { 0, 0, 5, 5};
   textColor = { 255, 255, 255 };
   buttonColor = { 255, 0, 0};
}


button::button(SDL_Window *windowCopy, string tempText)
{
   font = TTF_OpenFont( "lazy.ttf", 28);
   windowCopy = SDL_GetWindowSurface(windowOriganal);
   text = tempText;
   shape = { 0, 0, 5, 5};
   buttonColor = { 255, 0, 0};
   
}

button::button(SDL_Window *windowCopy, string tempText,int xIn, int yIn, wIn, hIn)
{
   font = TTF_OpenFont( "lazy.ttf", 28);
   windowCopy = SDL_GetWindowSurface(windowOriganal);
   text = tempText;
   shape = { xIn, yIn, wIn, hIn};
   textColor = {255, 255, 255};
   buttonColor = { 255, 0, 0};
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

bool button::draw()
{
   //working with font library for most complicated part
   //currently text does not always fit in button
   tempSurface = TTF_RenderText_Solid(font, text, textColor);
   SDL_FillRect(windowCopy, shape, buttonColor);
   apply_surface( shape.x, shape.y, tempSurface, windowCopy);
}

#endif