#ifndef PLAYERAGENCY_H_INCLUDED

#define PLAYERAGENCY_H_INCLUDED

#include "SDLincludes.h"
//#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
#include "input.h"
// #include "Gamepad.h"
#include <stdint.h>

#define MAX_CONTROLLERS 4
SDL_GameController *ControllerHandles[MAX_CONTROLLERS];
SDL_Haptic *RumbleHandles[MAX_CONTROLLERS];

class playerClass 
{
private:
	struct PlayerControlsKeyboard // holds what buttons activate flags
	{
		SDL_Keycode playerUp;
		SDL_Keycode playerDown;
		SDL_Keycode playerLeft;
		SDL_Keycode playerRight;
		SDL_Keycode playerActivate;
		SDL_Keycode playerUse;
		SDL_Keycode playerAttack;
		SDL_Keycode playerSpecial;
		SDL_Keycode playerPause;
		SDL_Keycode playerBack;
		SDL_Keycode playerJump;
		SDL_Keycode playerExit;
	};
	struct PlayerControlsGamePad // holds what buttons activate flags
	{
		SDL_GameControllerButton playerUp;
		SDL_GameControllerButton playerDown;
		SDL_GameControllerButton playerLeft;
		SDL_GameControllerButton playerRight;
		SDL_GameControllerButton playerActivate;
		SDL_GameControllerButton playerUse;
		SDL_GameControllerButton playerAttack;
		SDL_GameControllerButton playerSpecial;
		SDL_GameControllerButton playerPause;
		SDL_GameControllerButton playerBack;
		SDL_GameControllerButton playerJump;
		SDL_GameControllerButton playerExit;
	};
	struct GamePad //holds the flags of the buttons that are being pressed
	{
		bool  Up;
		bool  Down;
		bool  Left;
		bool  Right;
		bool  Start;
		bool  Back;
		bool  LeftShoulder;
		bool  RightShoulder;
		bool  AButton;
		bool  BButton;
		bool  XButton;
		bool  YButton;
		int StickX;//int 16
		int StickY;
		bool Player1Controls[12];
	};

	// struct instances 
	PlayerControlsKeyboard playerControlsKeyboard;
	PlayerControlsGamePad playerControlsGamePad;
	Gamepad gamepad;

	string playerName;
	int    playerIndex;
	int    playerHealth;
	int    playerMovementSpeed;
	string playerInputMode;

public:
	SDL_Rect whiteBoxRect;
	int    playerX;
	int    playerY;
	int    playerW;
	int    playerH;
	void SDLOpenGameControllers();
	void SDLCloseGameControllers();
	void UpdateGamePad();
	void playerInitalizeControls(int playerIndexPassed);
	void playerUpdate();
	void playerDraw();
	void playerButtonPress(SDL_Keycode e);
	void playerKeyPress(SDL_Keycode e);
	/* data */
};


int playerClass::playerInitalize(int playerIndexPassed)
{
	playerIndex=playerIndexPassed;
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
	if(playerInputMode=="Keyboard") // loads SDLK data type
	{
		inputFile >> CurrentData;	
		inputFile >> playerControlsKeyboard.playerActivate;
		inputFile >> CurrentData;  
		inputFile >> playerControlsKeyboard.playerBack;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerUp;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerDown;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerLeft;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerRight;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerJump;
		inputFile >> CurrentData;	
		inputFile >> playerControlsKeyboard.playerPause;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerExit;	
	}
	if (playerInputMode=="Gamepad")// loads SDL_GameControllerButton type
	{
		inputFile >> CurrentData;	
		inputFile >> playerControlsGamePad.playerActivate;
		inputFile >> CurrentData;  
		inputFile >> playerControlsGamePad.playerBack;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerUp;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerDown;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerLeft;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerRight;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerJump;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerPause;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerExit;
	}
	inputFile >> CurrentData;
	inputFile >> playerName;
	inputFile >> CurrentData;
	inputFile >> playerHealth;

}

void playerClass::playerButtonPress()
{ 
//game pad controls
	if (playerInputMode=="Gamepad")
	{
		if (gamepad.Up)
		{
			playerY++; 
		}
		if (gamepad.Down)
		{
			playerY--; 
		}
		if (gamepad.Right)
		{
			playerX++; 
		}
		if (gamepad.Left)
		{
			playerX--; 
		}
	}
	whiteBoxRect.x = playerX;
	whiteBoxRect.y = playerY;
}
void playerClass::playerKeyPress(SDL_Keycode e)
{ 
	if (playerInputMode=="Keyboard")
	{
		if (e==playerControlsKeyboard.playerUp)
		{
		    playerY++; 
		}
		if (e==playerControlsKeyboard.playerDown)
		{
		    playerY--; 
		}
		if (e==playerControlsKeyboard.playerRight)
		{
		    playerX++; 
		}
		if (e==playerControlsKeyboard.playerLeft)
		{
		    playerX--; 
		}
	}
	whiteBoxRect.x = playerX;
	whiteBoxRect.y = playerY;
}
void playerClass::UpdateControls()
{
//update the controls //change them in menu

}
//gamepad open //should be called once by player 1 never by player 2
void playerClass::SDLOpenGameControllers()
{
    int MaxJoysticks = SDL_NumJoysticks();
    int ControllerIndex = 0;
    for(int JoystickIndex=0; JoystickIndex < MaxJoysticks; ++JoystickIndex)
    {
        if (!SDL_IsGameController(JoystickIndex))
        {
            continue;
        }
        if (ControllerIndex >= MAX_CONTROLLERS)
        {
            break;
        }
        ControllerHandles[ControllerIndex] = SDL_GameControllerOpen(JoystickIndex);
        RumbleHandles[ControllerIndex] = SDL_HapticOpen(JoystickIndex);
        if (RumbleHandles[ControllerIndex]
            && SDL_HapticRumbleInit(RumbleHandles[ControllerIndex]) != 0)
        {
            SDL_HapticClose(RumbleHandles[ControllerIndex]);
            RumbleHandles[ControllerIndex] = 0;
        }

        ControllerIndex++;
    }
}
//gamepad close //should be called once by player 1 never by player 2
void playerClass::SDLCloseGameControllers()
{
    for(int ControllerIndex = 0; ControllerIndex < MAX_CONTROLLERS; ++ControllerIndex)
    {
        if (ControllerHandles[ControllerIndex])
        {
            if (RumbleHandles[ControllerIndex])
                SDL_HapticClose(RumbleHandles[ControllerIndex]);
            SDL_GameControllerClose(ControllerHandles[ControllerIndex]);
        }
    }
}

//the file determines what buttons are sent to the controller
//so only when the "UP" button is pressed will the "UP" Flag rise
//so the player can do actions for moving up and they will happen 
//when the flag rises.

void playerClass::UpdateGamePad()
{
// Poll our controllers for input.
    if(ControllerHandles[playerIndex] != 0 && SDL_GameControllerGetAttached(ControllerHandles[playerIndex-1]))
      {
        if (playerIndex-1 == 1)
        {
          Up = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerUp);
          Down = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerDown);
          Left = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerLeft);
          Right = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerRight);
          Start = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerPause);
          Back = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerExit);
          LeftShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
          RightShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
          AButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerActivate);
          BButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerBack);
          XButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerJump);
          YButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_Y);
          StickX = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTX);
          StickY = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTY);
        }
        
      }

}



#endif
