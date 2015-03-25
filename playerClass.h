#ifndef PLAYERAGENCY_H_INCLUDED

#define PLAYERAGENCY_H_INCLUDED

#include "SDLincludes.h"
//#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
#include "input.h"
#include "Gamepad.h"

class playerClass
{
private:
	int    playerIndex;
	string playerName;
	string playerUp;
	string playerDown;
	string playerLeft;
	string playerRight;
	string playerActivate;
	string playerUse;
	string playerAttack;
	string playerSpecial;
	string playerPause;
	string playerBack;
	string playerJump;
	string playerExit;
	int    playerHealth;
	int    playerMovementSpeed;
	string playerInputMode;
	Gamepad gamepad;

public:
	SDL_Rect whiteBoxRect;
	int    playerX;
	int    playerY;
	int    playerW;
	int    playerH;
	// playerClass();
	// ~playerClass();
	void playerInitalizeControls(int playerIndex);
	void playerUpdate();
	void playerDraw();
	void playerButtonPress(SDL_Keycode e);
	/* data */
};


int playerClass::playerInitalize(int playerIndex)
{
	if (playerIndex==1)//player 1 file
	{
	   //parse the file
	   ifstream inputFile;
	   inputFile.open("playerConfig/Player1Script.txt");
	}
	if (playerIndex==2)//player 2 file
	{
		//parse the file
	   ifstream inputFile;
	   inputFile.open("playerConfig/Player2Script.txt");
	}

	if(!inputFile)//file failed
		return false;

	string CurrentData;
	inputFile >> playerInputMode;//"Keyboard" or "Gamepad"
	inputFile >> CurrentData;	
	inputFile >> playerActivate;
	inputFile >> CurrentData;  
	inputFile >> playerBack;
	inputFile >> CurrentData;
	inputFile >> playerUp;
	inputFile >> CurrentData;
	inputFile >> playerDown;
	inputFile >> CurrentData;
	inputFile >> playerLeft;
	inputFile >> CurrentData;
	inputFile >> playerRight;
	inputFile >> CurrentData;
	inputFile >> playerActivate;
	inputFile >> CurrentData;
	inputFile >> playerJump;
	inputFile >> CurrentData;
	inputFile >> playerHealth;
	inputFile >> CurrentData;
	inputFile >> playerPause;
	inputFile >> CurrentData;
	inputFile >> playerExit;
	inputFile >> CurrentData;
	inputFile >> playerName;

}

void playerAgency::playerButtonPress(SDL_Keycode e)
{ 
	if (e==SDLK_s)
	{
	    playerY++; 
	}
	if (e==SDLK_w)
	{
	    playerY--; 
	}
	if (e==SDLK_d)
	{
	    playerX++; 
	}
	if (e==SDLK_a)
	{
	    playerX--; 
	}
	whiteBoxRect.x = playerX;
	whiteBoxRect.y = playerY;
}

#endif
