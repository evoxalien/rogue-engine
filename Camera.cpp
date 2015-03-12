#include "Camera.h"

//Constructor: 
//Takes a bounding rectangle,
//camera type either STATIC or NONSTATIC --> default is nonstatic
Camera::Camera(SDL_Rect bRect, int iType)
{
	//Bounding Rectangles
	BOUND_RECT = bRect;

	if(iType != 0)
	{
		CAMERA_TYPE = "STATIC";
	}else
	{
		CAMERA_TYPE = "NONSTATIC";
	}


	CINEMATIC = false;
	camera = { 0, 0, CAMERA_WIDTH, CAMERA_HEIGHT};


}//End of Constructor

//Constructor: 
//Takes Screen width and height, default is nonstatic
Camera::Camera(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	CAMERA_TYPE = "STATIC";
	BOUND_RECT = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
}

Camera::~Camera()
{

}


//Return Functions:
//Different return function values
int Camera::getCamX(){return camera.x;}
int Camera::getCamY(){return camera.y;}
int Camera::getCamW(){return camera.w;}
int Camera::getCamH(){return camera.h;}

//Bounderies:
//Checks bounds for the camera not to overlap edge of screen
void Camera::CheckBounds()
{
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

}

//Cinematic Mode:
void Camera::Cinematic_Mode(bool bCinematic)
{
	CINEMATIC = bCinematic;
}

//Update Camera:
//Takes the player's positions and dimensions 
//to update the camera position if the camera is not currently static
void Camera::Update_Camera(int xPlayerPos,int yPlayerPos, int widthPlayer, int heightPlayer)
{
	if(CAMERA_TYPE != "STATIC" || CINEMATIC != true){
		camera.x = ( (xPlayerPos + widthPlayer / 2 ) -  CAMERA_WIDTH / 2 );
		camera.y = ( (yPlayerPos + heightPlayer / 2 ) -  CAMERA_HEIGHT / 2 );

		CheckBounds();
	}
	else
	{
		return;
	}

}//End of Update
