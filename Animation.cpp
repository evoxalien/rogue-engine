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
		PosX = x;
		PosY = y;
		amountofFramesX = framesX;
		amountofFramesY = framesY;
		frameSpeed = 4;
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

void Animation::SetFramerate(int speed)
{
	frameSpeed = speed;
}

void Animation::Update(int frame)
	{
		// to count to a certaint number then change frame, milliseconds since last frame
		if (active)
			if(frame % frameSpeed == 0)
				frameCounter++;

		//cout << "FrameCounter " << frameCounter << endl;
		if (frameCounter >= amountofFramesX)
		{
			currentFrameX = 0;
			frameCounter = 0;
		}
		currentFrameX = getFrameWidth() * frameCounter;
		
		
		SourceRect = {(int)currentFrameX, (int)currentFrameY * getFrameHeight(), getFrameWidth(), getFrameHeight()};
	}

void Animation::Draw()
	{
		//SourceRect = {(int)currentFrameX, (int)currentFrameY * getFrameHeight(), getFrameWidth(), getFrameHeight()};
		//printf("Drawing Image");
//		Image.render(PosX,PosY, &SourceRect);
//		(*this).Image.render(static_cast<int>(((*this).getPosX() - (*Object::camera_Pointer).getCamX()) * Object::meters_Per_Pixel), static_cast<int>(((*this).getPosY() - (*Object::camera_Pointer).getCamY()) * Object::meters_Per_Pixel), (*this).getFrameWidth() * (*this).frame_Width_Scaling_Factor  * Object::meters_Per_Pixel, (*this).getFrameHeight() * (*this).frame_Height_Scaling_Factor  * Object::meters_Per_Pixel, &(*this).SourceRect);
		(*this).Image.render(static_cast<int>(((*this).getPosX() - (*Object::camera_Pointer).get_Camera_X_Float()) * Object::meters_Per_Pixel), static_cast<int>(((*this).getPosY() - (*Object::camera_Pointer).get_Camera_Y_Float()) * Object::meters_Per_Pixel), (*this).getFrameWidth() * (*this).frame_Width_Scaling_Factor  * Object::meters_Per_Pixel, (*this).getFrameHeight() * (*this).frame_Height_Scaling_Factor  * Object::meters_Per_Pixel, &(*this).SourceRect);
//		(*this).Image.render(static_cast<int>(((*this).getPosX() - (*Object::camera_Pointer).get_Camera_X_Float()) * Object::meters_Per_Pixel), static_cast<int>(((*this).getPosY() - (*Object::camera_Pointer).get_Camera_Y_Float()) * Object::meters_Per_Pixel), (*this).getFrameWidth() * (*this).frame_Width_Scaling_Factor  * Object::meters_Per_Pixel, (*this).getFrameHeight() * (*this).frame_Height_Scaling_Factor  * Object::meters_Per_Pixel, &(*this).SourceRect);
		//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}

void Animation::Draw(float x_Position, float y_Position, float player_Width, float player_Height)
{
//		(*this).Image.render(static_cast<int>(((*this).getPosX() - (*Object::camera_Pointer).get_Camera_X_Float()) * Object::meters_Per_Pixel), static_cast<int>(((*this).getPosY() - (*Object::camera_Pointer).get_Camera_Y_Float()) * Object::meters_Per_Pixel), (*this).getFrameWidth() * (*this).frame_Width_Scaling_Factor  * Object::meters_Per_Pixel, (*this).getFrameHeight() * (*this).frame_Height_Scaling_Factor  * Object::meters_Per_Pixel, &(*this).SourceRect)
//		(*this).Image.render(static_cast<int>(((*this).getPosX() - (*Object::camera_Pointer).getCamX()) * Object::meters_Per_Pixel), static_cast<int>(((*this).getPosY() - (*Object::camera_Pointer).getCamY()) * Object::meters_Per_Pixel), player_Width * Object::meters_Per_Pixel, player_Height * Object::meters_Per_Pixel, &(*this).SourceRect);
		(*this).Image.render(static_cast<int>((x_Position - (*Object::camera_Pointer).get_Camera_X_Float()) * Object::meters_Per_Pixel), static_cast<int>((y_Position - (*Object::camera_Pointer).get_Camera_Y_Float()) * Object::meters_Per_Pixel), static_cast<float>(player_Width) * Object::meters_Per_Pixel, static_cast<float>(player_Height) * Object::meters_Per_Pixel, &(*this).SourceRect);
}
