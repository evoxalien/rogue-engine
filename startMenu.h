#ifndef STARTMENU_H_INCLUDED

#define STARTMENU_H_INCLUDED

#include "sdlIncludes.h"
//#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
#include "input.h"
// #include "Gamepad.h"
#include "log.h"
using namespace std;

class startMenu
{
	InputClass input;
public:
   void MenuChoices(SDL_Keycode e, int EngineActiveState);
   void Update();
   void Draw();

};


/*
This controls how the player controls the menu
O and P control debug toggle
BACKSPACE WILL TAKE YOU TO THE MAIN MENU
UP  changes to the RED Menu
DOWN changes to the GREEN Menu
LEFT changes to the ALL Menu
RIGHT changes to the BLUE Menu
T take you to the player
M takes you to the map editor
   enum EngineState
   {
      Loading, //0
      RootMenu, //1
      EngineStartMenu, //2
      EngineSettingMenu, //3
      EngineMenu1, //4
      EngineMenu2, //5
      EngineMen3, //6
      MapEditor, //7
      MapEditorMenu1, //8
      MapEditorMenu2, //9
      GameRootMenu, //10
      GameSettingMenu, //11
      GameMenu1, //12
      GameMenu2, //13
      GameMenu3, //14
      GameLoading, //15
      GamePlaying1, //16
      GamePlaying2, //17
      GameMultiplayer, //18
      Test1, //19
      Test2, //20
      Test3 //21
   };
*/
//Had no return type so I turned it to void. - John V.
void startMenu::MenuChoices(SDL_Keycode e, int EngineActiveState)
{
   if (e==SDLK_p)
   {
      debug_log.print = true;
   }
   if (e==SDLK_o)
   {
      debug_log.print = false;
   }


}

void startMenu::Update()
{


}


void startMenu::Draw()
{


}

#endif