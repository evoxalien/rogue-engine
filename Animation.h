#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "SDLincludes.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "Texture.h"

using namespace std;

class Animation
{
public:
	
	void setActive(bool value);
	bool IsActive();

	void setFrameCount(int amtX, int amtY);

	void setCurrentFrame(int xFrame, int yFrame);
	int getFrameX();
	int getFrameY();

	void setPosition(int xPos, int yPos);
	int getPosX();
	int getPosY();

	int getFrameWidth();
	int getFrameHeight();

	void Initialize( int x, int y, int framesX, int framesY);
	
	void LoadImage(string sfilename);
	Texture Image;
	void Update(int frameRate);

	void Draw();

	void SetFramerate(int speed);

private:
	int frameCounter;
	int frameSpeed;
	bool active;
	int PosX, PosY, currentFrameX, currentFrameY;
	float amountofFramesX, amountofFramesY;
	
	SDL_Rect SourceRect;

};
#endif
