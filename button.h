#ifndef BUTTON_H_INCLUDED

#define BUTTON_H_INCLUDED

#include <stdio.h>
#include <string>

class button
{
private:
   SDL_Surface *tempSurface;
   SDL_Window *windowCopy;

public:
   button(SDL_Window *windowOriganal);
   button(SDL_Window *windowOriganal, string tempText);
   button(SDL_Window *windowOriganal, string tempText,int xIn, int yIn, wIn, hIn);
   void setWidth(int wIn);
   void setHeight(int hIn);
   void setX(int xIn);
   void setY(int yIn);
   void setText(string textIn);
   bool draw();
   
   
   string text;
   SDL_Rect shape;

};

button::button(SDL_Window *windowOriganal)
{
   windowCopy = windowOriganal;
   text = "button";
   shape = { 0, 0, 5, 5};
}


button::button(SDL_Window *windowCopy, string tempText)
{
   windowCopy = windowOriganal;
   text = tempText;
   shape = { 0, 0, 5, 5};
}

button::button(SDL_Window *windowCopy, string tempText,int xIn, int yIn, wIn, hIn)
{
   windowCopy = windowOriganal;
   text = tempText;
   shape = { xIn, yIn, wIn, hIn};
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

bool button::draw()
{
   //working with font library for most complicated part
}

#endif