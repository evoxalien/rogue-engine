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
		int playerUp;
		int playerDown;
		int playerLeft;
		int playerRight;
		int playerX;
		int playerA;
		int playerB;
		int playerY;
		int playerStart;
		int playerBack;
		int playerLeftShoulder;
		int playerRightShoulder;
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
	string playerInputMode;
	Animation playerAnimation;
	SDL_Joystick* gGameController = NULL;
	void InitSprite(SDL_Renderer* gRenderer);
	void loadSpriteContent();
	void SDLOpenGameControllers();
	void SDLCloseGameControllers();
	void UpdateGamePad();
	void playerUpdate(int gameTime);
	void playerDraw();
	void playerButtonPress(SDL_Keycode e);
	void playerKeyPress(SDL_Keycode e);
	bool playerInitalize(int playerIndexPassed);
	void UpdateControls();
	void LoadSpriteContent();
	void playerKeyRelease(SDL_Keycode e);
	bool init();
	void close();
	void UpdateSDLJoy(SDL_Event *Event);
	Texture playerTexture;
};


//Was int changed to bool to match true/false returns
bool playerClass::playerInitalize(int playerIndexPassed)
{
	ifstream inputFile;
	playerIndex=playerIndexPassed;
	if (playerIndex==1)//player 1 file
	{
	   //parse the file
	   inputFile.open("playerConfig/Player2Script.txt");
	}
	if (playerIndex==2)//player 2 file
	{
	   inputFile.open("playerConfig/Player1Script.txt");
		//parse the file
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
		inputFile >> playerControlsGamePad.playerA;
		inputFile >> CurrentData;  
		inputFile >> playerControlsGamePad.playerB;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerUp;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerDown;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerLeft;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerRight;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerX;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerStart;
		inputFile >> CurrentData;
		inputFile >> playerControlsGamePad.playerBack;
	}
	inputFile >> CurrentData;
	inputFile >> playerName;
	inputFile >> CurrentData;
	inputFile >> playerHealth;
	// LoadSpriteContent();
    
    //Needed a return type for success was throwing a warning John V.
    return true;
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

bool playerClass::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_JOYSTICK ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Check for joysticks
		if( SDL_NumJoysticks() < 1 )
		{
			printf( "Warning: No joysticks connected!\n" );
		}
		else
		{
			//Load joystick
			gGameController = SDL_JoystickOpen( 0 );
			if( gGameController == NULL )
			{
				printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
			}
		}

	}

	return success;
}
void playerClass::close()
{
	//Close game controller
	SDL_JoystickClose( gGameController );
	gGameController = NULL;
}
/*
0 up
1 down
2 left
3 right
4 start
5 back
6 Left thumbstick L3
7 Right thumbstick R3
8 Left Bumper
9 Right Bumper
10 A
11 B
12 X
13 Y
14 Xbox Button
*/
void playerClass::UpdateSDLJoy(SDL_Event *Event)
{
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerUp)==1)
	{
		Actions.playerUp=true;
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerDown)==1)
	{
		Actions.playerDown=true;
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerLeft)==1)
	{
		Actions.playerLeft=true;
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerRight)==1)
	{
		Actions.playerRight=true;
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerUp)==0)
	{
		Actions.playerUp=false;
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerDown)==0)
	{
		Actions.playerDown=false;
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerLeft)==0)
	{
		Actions.playerLeft=false;
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerRight)==0)
	{
		Actions.playerRight=false;
	}
	// if (SDL_JoystickGetButton(gGameController, 1)==1)
	// {
	// 	/* code */
	// 	printf("down\n");
	// }
	// if (SDL_JoystickGetButton(gGameController, 2)==1)
	// {
	// 	/* code */
	// 	printf("howdy2\n");
	// }
	// if (SDL_JoystickGetButton(gGameController, 3)==1)
	// {
	// 	/* code */
	// 	printf("howdy3\n");
	// }
	if (SDL_JoystickGetButton(gGameController, 5)==1)
	{
		/* code */
		printf("howdy5\n");
	}
	if (SDL_JoystickGetButton(gGameController, 4)==1)
	{
		/* code */
		printf("howdy4\n");
	}
	if (SDL_JoystickGetButton(gGameController, 6)==1)
	{
		/* code */
		printf("howdy6\n");
	}
	if (SDL_JoystickGetButton(gGameController, 7)==1)
	{
		/* code */
		printf("howdy7\n");
	}
	if (SDL_JoystickGetButton(gGameController, 8)==1)
	{
		/* code */
		printf("howdy8\n");
	}
	if (SDL_JoystickGetButton(gGameController, 9)==1)
	{
		/* code */
		printf("howdy9\n");
	}
	if (SDL_JoystickGetButton(gGameController, playerControlsGamePad.playerA)==1)
	{
		Actions.playerJump=true;
	}
	if (SDL_JoystickGetButton(gGameController, 11)==1)
	{
		/* code */
		printf("howdy11\n");
	}
	if (SDL_JoystickGetButton(gGameController, 12)==1)
	{
		/* code */
		printf("howdy12\n");
	}
	if (SDL_JoystickGetButton(gGameController, 13)==1)
	{
		/* code */
		printf("howdy13\n");
	}
	if (SDL_JoystickGetButton(gGameController, 14)==1)
	{
		/* code */
		printf("howdy14\n");
	}
	if (SDL_JoystickGetButton(gGameController, 15)==1)
	{
		/* code */
		printf("howdy15\n");
	}
	// if (Event->type == SDL_JOYBUTTONDOWN)
	// {
	// 		printf("%i\n", SDL_JoystickNumButtons(gGameController));
	// }

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
// // Poll our controllers for input.
//     if(ControllerHandles[playerIndex] != 0 && SDL_GameControllerGetAttached(ControllerHandles[playerIndex-1]))
//       {
//           Actions.playerUp = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerUp);
//           Actions.playerDown = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerDown);
//           Actions.playerLeft = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerLeft);
//           Actions.playerRight = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerRight);
//           Actions.playerStart = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerStart);
//           Actions.playerBack = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerBack);
//           Actions.playerLeftShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
//           Actions.playerRightShoulder = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
//           Actions.playerActivate = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerA);
//           Actions.playerBack = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerB);
//           Actions.playerJump = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerX);
//           Actions.playerSpecial = SDL_GameControllerGetButton(ControllerHandles[playerIndex-1], playerControlsGamePad.playerX);
//           // Actions.StickX = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTX);
//           // Actions.StickY = SDL_GameControllerGetAxis(ControllerHandles[playerIndex-1], SDL_CONTROLLER_AXIS_LEFTY);
//       }

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
