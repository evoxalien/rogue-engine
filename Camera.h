#ifndef CAMERA_H_
#define CAMERA_H_
#include "SDLincludes.h"
#include <string>

using namespace std;
//Last updated: 3/12/15

class Camera
{
private: 

	//CAMERA BOUNDING AREA
	SDL_Rect BOUND_RECT;

	//CAMERA CONSTANTS
	const int CAMERA_WIDTH = 1024;
	const int CAMERA_HEIGHT = 512;

	//CAMERA TYPE
	string CAMERA_TYPE;

	//CINEMATIC
	bool CINEMATIC;

	//CHECK BOUNDS
	void CheckBounds();

public:
	//CONSTRUCTOR
	Camera(SDL_Rect bRect, int iType);
	Camera(int SCREEN_WIDTH,int CAMERA_HEIGHT);
	//Camera();
	~Camera();

	//RETURN FUNCTIONS FOR VALUES
	int getCamX();
	int getCamY();
	int getCamW();
	int getCamH();

	SDL_Rect getRect();

    //CAMERA VIEWPORT
	SDL_Rect camera;
	
	//FUNCTION
	void MoveCamUP();
	void MoveCamDOWN();
	void MoveCamLEFT();
	void MoveCamRIGHT();


	//SETTING THE CAMERA MODE EITHER FOR CINEMATICS
	void Cinematic_Mode(bool);

	//UPDATE THE CAMERA ON SCREEN
	void Update_Camera(int,int,int,int);

	//DRAW CAMERA TO SCREEN
	//void Draw_Camera(SDL_Renderer* gRenderer);

};

#endif
