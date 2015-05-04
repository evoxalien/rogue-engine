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

	//CAMERA VIEWPORT
	SDL_Rect camera;

	//CAMERA CONSTANTS
	const int CAMERA_WIDTH = 1280;
	const int CAMERA_HEIGHT = 720;

	//CAMERA TYPE
	string CAMERA_TYPE;

	float camera_X_Float;
	float camera_Y_Float;

	//CINEMATIC
	bool CINEMATIC;

	//CHECK BOUNDS
	void CheckBounds();
	void check_Bounds_Floats();

public:
	//CONSTRUCTOR
	Camera();
	Camera(SDL_Rect bRect, int iType);
	Camera(int levelWidth,int levelHeight);
	//Camera();
	~Camera();

	//RETURN FUNCTIONS FOR VALUES
	int getCamX();
	int getCamY();
	int getCamW();
	int getCamH();
	float get_Camera_X_Float();
	float get_Camera_Y_Float();

	void setBoundRect(int brX, int brY, int brW, int brH);

	//SETTING THE CAMERA MODE EITHER FOR CINEMATICS
	void Cinematic_Mode(bool);

	//UPDATE THE CAMERA ON SCREEN
	void Update_Camera(int camX,int camY);
	void update_Camera_Floats(float, float);

	//DRAW CAMERA TO SCREEN
	//void Draw_Camera(SDL_Renderer* gRenderer);

};

#endif
