#ifndef PLAYERAGENCY_H_INCLUDED

#define PLAYERAGENCY_H_INCLUDED

#include "SDLincludes.h"
//#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
#include "input.h"
#include "Animation.cpp"
#include "Texture.h"
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
		SDL_Keycode playerStart;
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
		SDL_GameControllerButton playerX;
		SDL_GameControllerButton playerA;
		SDL_GameControllerButton playerB;
		SDL_GameControllerButton playerY;
		SDL_GameControllerButton playerStart;
		SDL_GameControllerButton playerBack;
		SDL_GameControllerButton playerLeftShoulder;
		SDL_GameControllerButton playerRightShoulder;
		int StickX;//int 16
		int StickY;
		bool Player1Controls[12];
	};

	// struct instances 
	PlayerControlsKeyboard playerControlsKeyboard;
	PlayerControlsGamePad playerControlsGamePad;

	string playerName;
	int    playerIndex;
	int    playerHealth;
	string playerInputMode;

public:
	struct PlayerAction //holds the flags of the buttons that are being pressed
	{
		bool  playerUp;
		bool  playerDown;
		bool  playerLeft;
		bool  playerRight;
		bool  playerActivate;
		bool  playerUse;
		bool  playerAttack;
		bool  playerSpecial;
		bool  playerStart;
		bool  playerBack;
		bool  playerJump;
		bool  playerExit;
		bool  playerLeftShoulder;
		bool playerRightShoulder;
	};
	PlayerAction Actions;
	SDL_Rect whiteBoxRect;
	int    playerX;
	int    playerY;
	int    playerW;
	int    playerH;
	int    currentFrameX;
	int    currentFrameY;
	float  playerMovementSpeed;
	bool   playerDirection; // true = facing left false facing Right
	Animation playerAnimation;
	void InitSprite(SDL_Renderer* gRenderer);
	void loadSpriteContent();
	void SDLOpenGameControllers();
	void SDLCloseGameControllers();
	void UpdateGamePad();
	void playerUpdate(int gameTime);
	void playerDraw();
	void playerButtonPress(SDL_Keycode e);
	void playerKeyPress(SDL_Keycode e);
	int  playerInitalize(int playerIndexPassed);
	void UpdateControls();
	void LoadSpriteContent();
	void playerKeyRelease(SDL_Keycode e);
	Texture playerTexture;
};


int playerClass::playerInitalize(int playerIndexPassed)
{
	ifstream inputFile;
	playerIndex=playerIndexPassed;
	if (playerIndex==1)//player 1 file
	{
	   //parse the file
	   inputFile.open("playerConfig/Player1Script.txt");
	}
	if (playerIndex==2)//player 2 file
	{
		//parse the file
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
		inputFile >> playerControlsKeyboard.playerStart;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerExit;	
	}
	string GamepadMap;
	if (playerInputMode=="Gamepad")// loads SDL_GameControllerButton type
	{
		inputFile >> CurrentData;	
		inputFile >> GamepadMap;
		playerControlsGamePad.playerA=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;  
		inputFile >> GamepadMap;
		playerControlsGamePad.playerB=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;
		inputFile >> GamepadMap;
		playerControlsGamePad.playerUp=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;
		inputFile >> GamepadMap;
		playerControlsGamePad.playerDown=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;
		inputFile >> GamepadMap;
		playerControlsGamePad.playerLeft=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;
		inputFile >> GamepadMap;
		playerControlsGamePad.playerRight=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;
		inputFile >> GamepadMap;
		playerControlsGamePad.playerX=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;
		inputFile >> GamepadMap;
		playerControlsGamePad.playerStart=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
		inputFile >> CurrentData;
		inputFile >> GamepadMap;
		playerControlsGamePad.playerBack=SDL_GameControllerGetButtonFromString(GamepadMap.c_str());
	}
	inputFile >> CurrentData;
	inputFile >> playerName;
	inputFile >> CurrentData;
	inputFile >> playerHealth;
	// LoadSpriteContent();
}


void playerClass::InitSprite(SDL_Renderer* gRenderer)
{
	playerAnimation.Initialize(playerX, playerY, 10, 8);
	playerAnimation.Image.setRenderer(gRenderer);
}

void playerClass::LoadSpriteContent()
{
	playerAnimation.LoadImage("TestCharacter.png");
	// playerAnimation.LoadImage("playerConfig/TestCharacter.png");
}

void playerClass::playerButtonPress(SDL_Keycode e)
{ 
// game pad controls

            if(e== SDLK_DOWN)
            {
                Actions.playerUp=true;       
            }
            else if ( e== SDLK_UP)
            {
                Actions.playerDown=true;            
            }
            else if (e== SDLK_RIGHT)
            {
                Actions.playerRight=true; 
            }
            else if (e== SDLK_LEFT)
            {
                Actions.playerLeft=true; 
            }
	// whiteBoxRect.x = playerX;
	// whiteBoxRect.y = playerY;
}


void playerClass::playerKeyPress(SDL_Keycode e)
{ 
	if (playerInputMode=="Keyboard")
	{
		if (e==playerControlsKeyboard.playerUp)
		    Actions.playerUp=true;
		if (e==playerControlsKeyboard.playerDown)
		    Actions.playerDown=true;
		if (e==playerControlsKeyboard.playerRight)
		    Actions.playerRight=true; 
		if (e==playerControlsKeyboard.playerLeft)
		    Actions.playerLeft=true; 
		if (e==playerControlsKeyboard.playerActivate)
			Actions.playerActivate=true;
		if (e==playerControlsKeyboard.playerUse)
			Actions.playerUse=true;
		if (e==playerControlsKeyboard.playerAttack)
			Actions.playerAttack=true;
		if (e==playerControlsKeyboard.playerSpecial)
			Actions.playerSpecial=true;
		if (e==playerControlsKeyboard.playerStart)
			Actions.playerStart=true;
		if (e==playerControlsKeyboard.playerBack)
			Actions.playerBack=true;
		if (e==playerControlsKeyboard.playerJump)
			Actions.playerJump=true;
		if (e==playerControlsKeyboard.playerExit)
			Actions.playerExit=true;
	}
}
void playerClass::playerKeyRelease(SDL_Keycode e)
{ 
	if (playerInputMode=="Keyboard")
	{
		if (e==playerControlsKeyboard.playerUp)
		    Actions.playerUp=false;
		if (e==playerControlsKeyboard.playerDown)
		    Actions.playerDown=false;
		if (e==playerControlsKeyboard.playerRight)
		    Actions.playerRight=false; 
		if (e==playerControlsKeyboard.playerLeft)
		    Actions.playerLeft=false; 
		if (e==playerControlsKeyboard.playerActivate)
			Actions.playerActivate=true;
		if (e==playerControlsKeyboard.playerUse)
			Actions.playerUse=true;
		if (e==playerControlsKeyboard.playerAttack)
			Actions.playerAttack=true;
		if (e==playerControlsKeyboard.playerSpecial)
			Actions.playerSpecial=true;
		if (e==playerControlsKeyboard.playerStart)
			Actions.playerStart=true;
		if (e==playerControlsKeyboard.playerBack)
			Actions.playerBack=true;
		if (e==playerControlsKeyboard.playerJump)
			Actions.playerJump=true;
		if (e==playerControlsKeyboard.playerExit)
			Actions.playerExit=true;
		if(e== SDLK_DOWN)
            Actions.playerUp=false;       
        else if ( e== SDLK_UP)
            Actions.playerDown=false;            
        else if (e== SDLK_RIGHT)
            Actions.playerRight=false; 
        else if (e== SDLK_LEFT)
            Actions.playerLeft=false; 
	}
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
          Actions.playerUp = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerUp);
          Actions.playerDown = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerDown);
          Actions.playerLeft = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerLeft);
          Actions.playerRight = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerRight);
          Actions.playerStart = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerStart);
          Actions.playerBack = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerBack);
          Actions.playerLeftShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
          Actions.playerRightShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
          Actions.playerActivate = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerA);
          Actions.playerBack = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerB);
          Actions.playerJump = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerX);
          Actions.playerSpecial = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerX);
          // Actions.StickX = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTX);
          // Actions.StickY = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTY);
      }

}

void playerClass::playerUpdate(int gameTime)
{
	//Animation Tracking
	playerAnimation.setActive(true);
    
    currentFrameX = playerAnimation.getFrameX();
    
	if(Actions.playerDown==true)
	{
		playerY += playerMovementSpeed;// * ((float)gameTime%6000);
		if (playerDirection) //true facing left false facing right
		{
			currentFrameY = 1;          
		}else{
			currentFrameY = 0;
		}
	}
	else if (Actions.playerUp==true)
	{
		playerY -= playerMovementSpeed; //* ((float)gameTime%6000);
		if (playerDirection) //true facing left false facing right
		{
			currentFrameY = 5;          
		}else{
			currentFrameY = 4;
		}              
	}
	else if (Actions.playerRight==true)
	{
		playerX += playerMovementSpeed;// * ((float)gameTime%6000);
		playerDirection=false;
		currentFrameY = 2;
	}
	else if (Actions.playerLeft==true)
	{
		playerX -= playerMovementSpeed;// * ((float)gameTime%6000);
		playerDirection=true;
		currentFrameY = 3;
	}
	else
	{
		playerAnimation.setActive(false);
		currentFrameX = 0;
	}
    //Smooth the Animation Transitions
    playerAnimation.setPosition(playerX,playerY);
    playerAnimation.setCurrentFrame(currentFrameX,currentFrameY);
    
    //Update of the Animations depending on Game Time
    playerAnimation.Update(gameTime);

}


void playerClass::playerDraw()
{
		playerAnimation.Draw();
}
#endif
