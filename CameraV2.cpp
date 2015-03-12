#include "Camera.h"

//Constructor: 
//Takes screens width and height,
//camera type either STATIC or NONSTATIC --> default is nonstatic
void Camera::Camera(/*int SCREEN_WIDTH, int SCREEN_HEIGHT*/ SDL_Rect bRect, string sType)
{
	//bounding rectangles
	BOUND_RECT = bRect;

	if(sType != NULL)
	{
		if(sType == "NONSTATIC" || sType == "STATIC")
		{
			CAMERA_TYPE = sType;
		}
		
	}else
		{
			CAMERA_TYPE = "NONSTATIC";
		}

	//iSCREEN_WIDTH = SCREEN_WIDTH;
	//iSCREEN_HEIGHT = SCREEN_HEIGHT;
	
	CINEMATIC = false;
	camera = { 0, 0, CAMERA_WIDTH, CAMERA_HEIGHT};


}//End of Constructor


void Camera::Camera(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	CAMERA_TYPE = "STATIC";
	BOUND_RECT = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
}
void Camera::Set_Camera_Mode(bool bCinematic)
{
	CINEMATIC = bCinematic;
}

//Update Camera:
//Takes the player's positions and dimensions 
//to update the camera position if the camera is not currently static
void Camera::update_Camera(int xPlayerPos,int yPlayerPos, int widthPlayer, int heightPlayer)
{
	if(CAMERA_TYPE != "STATIC" || CINEMATIC != true){
	camera.x = ( (xPlayerPos + widthPlayer / 2 ) -  CAMERA_WIDTH / 2 );
	camera.y = ( (yPlayerPos + heightPlayer / 2 ) -  CAMERA_HEIGHT / 2 );

	
				if( camera.x < 0 )
				{ 
					camera.x = 0;
				}
				if( camera.y < 0 )
				{
					camera.y = 0;
				}

				if( camera.x > BOUND_RECT.w - camera.w )
				{
					camera.x = BOUND_RECT.w - camera.w;
				}
				if( camera.y > BOUND_RECT.h - camera.h )
				{
					camera.y = BOUND_RECT.h - camera.h;
				}


				/*if( camera.x > iSCREEN_WIDTH - camera.w )
				{
					camera.x = iSCREEN_WIDTH - camera.w;
				}
				if( camera.y > iSCREEN_HEIGHT - camera.h )
				{
					camera.y = iSCREEN_HEIGHT - camera.h;
				}*/
	}
	else
	{
		return;
	}

}//End of Update

//Draw Camera:
//Drawing the camera to the screen
//void Camera::draw_Camera(SDL_Renderer* gRenderer)
//{
//	SDL_RenderPresent( gRenderer );
//}
