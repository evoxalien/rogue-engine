#include "Animation.h"

void Animation::setActive(bool value)
	{ 
		active = value; 
	}

bool Animation::IsActive()
	{ 
		return active;
	}

void Animation::setFrameCount(int amtX, int amtY)
	{
		amountofFramesX = amtX;
		amountofFramesY = amtY;
	}

void Animation::setCurrentFrame(int xFrame, int yFrame)
	{
		currentFrameX = xFrame;
		currentFrameY = yFrame;
	}

int Animation::getFrameX()
	{
		return currentFrameX;
	}

int Animation::getFrameY()
	{
		return currentFrameY;
	}

void Animation::setPosition(int xPos, int yPos)
	{
		PosX = xPos;
		PosY = yPos;
	}

int Animation::getPosX()
	{ 
		return PosX; 
	}

int Animation::getPosY()
	{ 
		return PosY; 
	}

int Animation::getFrameWidth()
	{ 
		return (Image.getWidth() / (int)amountofFramesX); 
	}

int Animation::getFrameHeight()
	{ 
		return (Image.getHeight() / (int)amountofFramesY); 
	}

void Animation::Initialize( int x, int y, int framesX, int framesY)
	{
		frameCounter = 0;
		active = false;
		switchFrame = 100;
		PosX = x;
		PosY = y;
		amountofFramesX = framesX;
		amountofFramesY = framesY;
	}

void Animation::LoadImage( string filename )
{
	if(Image.loadTexture(filename))
	{
		printf("SDL_Image Loaded");
	}
	else
	{
		printf("SDL_Image failed to load");
	}
}


void Animation::Update(int gameTime)
	{
		// to count to a certaint number then change frame, milliseconds since last frame
		if (active)
			frameCounter += ((int)gameTime%60);
		else
			frameCounter = 0;

		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			currentFrameX += getFrameWidth();
			if (currentFrameX >= Image.getWidth())
				currentFrameX = 0;
		}
		SourceRect = {(int)currentFrameX, (int)currentFrameY * getFrameHeight(), getFrameWidth(), getFrameHeight()};
	}

void Animation::Draw()
	{
		//SourceRect = {(int)currentFrameX, (int)currentFrameY * getFrameHeight(), getFrameWidth(), getFrameHeight()};
		//printf("Drawing Image");
		Image.render(PosX,PosY, &SourceRect);
		//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
