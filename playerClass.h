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
	struct PlayerAction //holds the flags of the buttons that are being pressed
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
	PlayerAction Actions;

	string playerName;
	int    playerIndex;
	int    playerHealth;
	string playerInputMode;

public:
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
	void playerInitalizeControls(int playerIndexPassed);
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
		inputFile >> playerControlsKeyboard.playerPause;
		inputFile >> CurrentData;
		inputFile >> playerControlsKeyboard.playerExit;	
	}
	if (playerInputMode=="Gamepad")// loads SDL_GameControllerButton type
	{
		// inputFile >> CurrentData;	
		// inputFile >> playerControlsGamePad.playerActivate;
		// inputFile >> CurrentData;  
		// inputFile >> playerControlsGamePad.playerBack;
		// inputFile >> CurrentData;
		// inputFile >> playerControlsGamePad.playerUp;
		// inputFile >> CurrentData;
		// inputFile >> playerControlsGamePad.playerDown;
		// inputFile >> CurrentData;
		// inputFile >> playerControlsGamePad.playerLeft;
		// inputFile >> CurrentData;
		// inputFile >> playerControlsGamePad.playerRight;
		// inputFile >> CurrentData;
		// inputFile >> playerControlsGamePad.playerJump;
		// inputFile >> CurrentData;
		// inputFile >> playerControlsGamePad.playerPause;
		// inputFile >> CurrentData;
		// inputFile >> playerControlsGamePad.playerExit;
	}
	inputFile >> CurrentData;
	inputFile >> playerName;
	inputFile >> CurrentData;
	inputFile >> playerHealth;
	// LoadSpriteContent();
}


void playerClass::InitSprite(SDL_Renderer* gRenderer)
{
	playerAnimation.Initialize(playerX, playerY, 8, 8);
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
                Actions.Up=true;       
            }
            else if ( e== SDLK_UP)
            {
                Actions.Down=true;            
            }
            else if (e== SDLK_RIGHT)
            {
                Actions.Right=true; 
            }
            else if (e== SDLK_LEFT)
            {
                Actions.Left=true; 
            }
	// whiteBoxRect.x = playerX;
	// whiteBoxRect.y = playerY;
}
void playerClass::playerKeyPress(SDL_Keycode e)
{ 
	if (playerInputMode=="Keyboard")
	{
		if (e==playerControlsKeyboard.playerUp)
		{
		    Actions.Up=true;
		}
		if (e==playerControlsKeyboard.playerDown)
		{
		    Actions.Down=true;
		}
		if (e==playerControlsKeyboard.playerRight)
		{
		    Actions.Right=true; 
		}
		if (e==playerControlsKeyboard.playerLeft)
		{
		    Actions.Left=true; 
		}
	}
}
void playerClass::playerKeyRelease(SDL_Keycode e)
{ 
	if (playerInputMode=="Keyboard")
	{
		if (e==playerControlsKeyboard.playerUp)
		{
		    Actions.Up=false;
		}
		if (e==playerControlsKeyboard.playerDown)
		{
		    Actions.Down=false;
		}
		if (e==playerControlsKeyboard.playerRight)
		{
		    Actions.Right=false; 
		}
		if (e==playerControlsKeyboard.playerLeft)
		{
		    Actions.Left=false; 
		}
		if(e== SDLK_DOWN)
        {
            Actions.Up=false;       
        }
        else if ( e== SDLK_UP)
        {
            Actions.Down=false;            
        }
        else if (e== SDLK_RIGHT)
        {
            Actions.Right=false; 
        }
        else if (e== SDLK_LEFT)
        {
            Actions.Left=false; 
        }
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
        if (playerIndex-1 == 1)
        {
          Actions.Up = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerUp);
          Actions.Down = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerDown);
          Actions.Left = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerLeft);
          Actions.Right = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerRight);
          Actions.Start = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerPause);
          Actions.Back = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerExit);
          Actions.LeftShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
          Actions.RightShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
          Actions.AButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerActivate);
          Actions.BButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerBack);
          Actions.XButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerJump);
          Actions.YButton = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_Y);
          Actions.StickX = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTX);
          Actions.StickY = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTY);
        }
        
      }

}

void playerClass::playerUpdate(int gameTime)
{
	//Animation Tracking
	playerAnimation.setActive(true);
    
    currentFrameX = playerAnimation.getFrameX();
    
	if(Actions.Down==true)
	{
		playerY += playerMovementSpeed;// * ((float)gameTime%6000);
		if (playerDirection) //true facing left false facing right
		{
			currentFrameY = 1;          
		}else{
			currentFrameY = 0;
		}
	}
	else if (Actions.Up==true)
	{
		playerY -= playerMovementSpeed; //* ((float)gameTime%6000);
		if (playerDirection) //true facing left false facing right
		{
			currentFrameY = 5;          
		}else{
			currentFrameY = 4;
		}              
	}
	else if (Actions.Right==true)
	{
		playerX += playerMovementSpeed;// * ((float)gameTime%6000);
		playerDirection=false;
		currentFrameY = 2;
	}
	else if (Actions.Left==true)
	{
		playerX -= playerMovementSpeed;// * ((float)gameTime%6000);
		playerDirection=true;
		currentFrameY = 1;
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
