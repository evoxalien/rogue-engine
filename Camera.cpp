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
	(*this).camera_X_Float = 0;
	(*this).camera_Y_Float = 0;


}//End of Constructor

//Constructor: 
//Takes Screen width and height, default is static
Camera::Camera(int levelWidth, int levelHeight)
{
	CAMERA_TYPE = "STATIC";
	BOUND_RECT = {0, 0, levelWidth, levelHeight};
	camera = { 0, 0, CAMERA_WIDTH, CAMERA_HEIGHT};
	(*this).camera_X_Float = 0;
	(*this).camera_Y_Float = 0;
}

Camera::Camera()
{
	CAMERA_TYPE = "STATIC";
	BOUND_RECT = {0,0,0,0};
	camera = {0,0,CAMERA_WIDTH,CAMERA_HEIGHT};
	(*this).camera_X_Float = 0;
	(*this).camera_Y_Float = 0;
}

Camera::~Camera()
{

}

void Camera::setBoundRect(int brX, int brY, int brW, int brH)
{
	BOUND_RECT = {brX, brY, brW, brH};
}

//Return Functions:
//Different return function values
int Camera::getCamX(){return camera.x;}
int Camera::getCamY(){return camera.y;}
int Camera::getCamW(){return camera.w;}
int Camera::getCamH(){return camera.h;}

float Camera::get_Camera_X_Float()
{
	return (*this).camera_X_Float;
}

float Camera::get_Camera_Y_Float()
{
	return (*this).camera_Y_Float;
}

//Bounderies:
//Checks bounds for the camera not to overlap edge of level
void Camera::CheckBounds()
{
	if( camera.x < BOUND_RECT.x )
	{ 
		camera.x = BOUND_RECT.x;
	}
	if( camera.y < BOUND_RECT.y )
	{
		camera.y = BOUND_RECT.y;
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

void Camera::check_Bounds_Floats()
{
	if( (*this).camera_X_Float < BOUND_RECT.x )
	{ 
		(*this).camera_X_Float = BOUND_RECT.x;
	}
	if( (*this).camera_Y_Float < BOUND_RECT.y )
	{
		(*this).camera_Y_Float = BOUND_RECT.y;
	}

	if( (*this).camera_X_Float > BOUND_RECT.w - camera.w )
	{
		(*this).camera_X_Float = BOUND_RECT.w - camera.w;
	}
	if( (*this).camera_Y_Float > BOUND_RECT.h - camera.h )
	{
		(*this).camera_Y_Float = BOUND_RECT.h - camera.h;
	}
}

//Cinematic Mode:
void Camera::Cinematic_Mode(bool bCinematic)
{
	CINEMATIC = bCinematic;
}

//Update Camera:
//Updates camera's x and y to the integers passed in
void Camera::Update_Camera(int camX, int camY)
{
	camera.x = camX;
	camera.y = camY;
	CheckBounds();

}//End of Update

void Camera::update_Camera_Floats(float camera_X_Float, float camera_Y_Float)
{
	(*this).camera_X_Float = camera_X_Float;
	(*this).camera_Y_Float = camera_Y_Float;
	(*this).check_Bounds_Floats();
}
