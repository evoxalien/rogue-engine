#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "SDLincludes.h"
#include <string>
#include "Texture.h"
#include "ltimer.h"
using namespace std;

class Animation
{
public:
	//Variable Declaractions***************************************

	int frameCounter;
	int switchFrame;    //value to indicate when to switch frame

	bool active;        //track for if animation is active

	int PosX, PosY, currentFrameX, currentFrameY;

	float amountofFramesX, amountofFramesY;

	Texture Image;

	SDL_Rect SourceRect;

	//Methods******************************************************


	void setActive(bool value){ active = value; }	
	bool IsActive(){ return active; }

	void setFrameCount(int amtX, int amtY)
	{
		amountofFramesX = amtX;
		amountofFramesY = amtY;
	}

	void setCurrentFrame(int xFrame, int yFrame)
	{
		currentFrameX = xFrame;
		currentFrameY = yFrame;
	}
	int getFrameX(){return currentFrameX;}
	int getFrameY(){return currentFrameY;}

	void setPosition(int xPos, int yPos)
	{
		PosX = xPos;
		PosY = yPos;
	}
	int getPosX(){ return PosX; }
	int getPosY(){ return PosY; }

	int getFrameWidth(){ return (Image.getWidth() / (int)amountofFramesX); }

	int getFrameHeight(){ return (Image.getHeight() / (int)amountofFramesY); }


	//Initialization of Animation & Frame Settings******************
	void Initialize( int x, int y, int framesX, int framesY, string sName)
	{
		framecounter = 0;
		active = false;
		switchFrame = 100;
		this.PosX = x;
		this.PosY = y;
		this.amountofFramesX = framesX;
		this.amountofFramesY = framesY;
		if(!Image.loadTexture("../../images/"+sName+".png"))
		{
			error_log << "Texture failed to load.\n";
			return false;
		}
	}

	//Updates of Animation & Frames*********************************
	void Update(ltimer GameTime)
	{
		// to count to a certaint number then change frame, milliseconds since last frame
		if (active)
			frameCounter += (int)GameTime.getTicks();
		else
			frameCounter = 0;

		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			currentFrameX += getFrameWidth();
			if (currentFrameX >= AnimationImage.w)
				currentFrameX = 0;
		}
		SourceRect = new SDL_Rect((int)currentFrameX, (int)currentFrameY * getFrameHeight(), getFrameWidth(), getFrameHeight());
	}

	//Drawing of Animation*******************************************
	void Draw(SDL_Renderer* gRenderer)
	{
		Image.render(PosX,PosY, &SourceRect);
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
};
#endif