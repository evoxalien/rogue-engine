#ifndef CAMERA_H_
#define CAMERA_H_
#include "SDLincludes.h"
#include <string>
#include "Texture.h"
#include "Input.h"

class Camera
{
private: 
int iSCREEN_WIDTH;
int iSCREEN_HEIGHT;

//CAMERA CONSTANTS
const int CAMERA_WIDTH = 640;
const int CAMERA_HEIGHT = 480;

//CAMERA TYPE
string CAMERA_TYPE;

//CINEMATIC
bool CINEMATIC;

public:
	//CONSTRUCTOR
	Camera(int,int,string);
	~Camera();

	//SETTING THE CAMERA MODE EITHER FOR CINEMATICS
	void Set_Camera_Mode(bool);

	//UPDATE THE CAMERA ON SCREEN
	void update_Camera(int,int);

	//DRAW CAMERA TO SCREEN
	void draw_Camera(SDL_Renderer* gRenderer);

}

#endif
