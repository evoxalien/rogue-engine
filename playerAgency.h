#ifndef PLAYERAGENCY_H_INCLUDED

#define PLAYERAGENCY_H_INCLUDED

#include "SDLincludes.h"
//#include "SDL.h"
#include <stdio.h>
#include <string>
#include "inputDavid.h"
using namespace std;


class playerAgency
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
   int    playerHealth;
   int    playerMovementSpeed;
   string playerInputMode;

public:
   SDL_Rect whiteBoxRect;
   SDL_Rect whiteBoxRect1;
   int    playerX;
   int    playerY;
   int    playerW;
   int    playerH;
   int    intializePlayer(int playerIndex1);
   void updateControls(int playerIndex1);
   void updatePlayer();
   void setPlayerIndex(int    playerIndex1);
   void setPlayerName(string playerName1);
   void setPlayerUp(string playerUp1);
   void setPlayerDown(string playerDown1);
   void setPlayerLeft(string playerLeft1);
   void setPlayerRight(string playerRight1);
   void setPlayerActivate(string playerActivate1);
   void setPlayerUse(string playerUse1);
   void setPlayerAttack(string playerAttack1);
   void setPlayerSpecial(string playerSpecial1);
   void setPlayerPause(string playerPause1);
   void setPlayerHealth(int    playerHealth1);
   void setPlayerMovementSpeed(int    playerMovementSpeed1);
   void setPlayerInputMode(string playerInputMode1);
   void setPlayerX(int X1);
   void setPlayerY(int Y1);
   void setPlayerW(int W1);
   void setPlayerH(int H1);
   int    getPlayerIndex();
   string getPlayerName();
   string getPlayerUp();
   string getPlayerDown();
   string getPlayerLeft();
   string getPlayerRight();
   string getPlayerActivate();
   string getPlayerUse();
   string getPlayerAttack();
   string getPlayerSpecial();
   string getPlayerPause();
   int    getPlayerHealth();
   int    getPlayerMovementSpeed();
   string getPlayerInputMode();
   int getPlayerX();
   int getPlayerY();
   int getPlayerW();
   int getPlayerH();
   void playerButtonPress(SDL_Keycode e);
};
#endif

int playerAgency::intializePlayer(int playerIndex)
{
   if(playerIndex==0)//player 1
   {
      setPlayerIndex(playerIndex);
      setPlayerName("player1");
      setPlayerUp("w");
      setPlayerDown("s");
      setPlayerLeft("a");
      setPlayerRight("d");
      setPlayerActivate("e");
      setPlayerUse("e");
      setPlayerAttack("space");
      setPlayerSpecial("q");
      setPlayerPause("enter");
      setPlayerHealth(200);
      setPlayerMovementSpeed(5);
      setPlayerInputMode("keyboard");
      setPlayerX(0);
      setPlayerY(0);
      setPlayerW(10);
      setPlayerH(10);
   whiteBoxRect.x = getPlayerX();
   whiteBoxRect.y = getPlayerY();
   whiteBoxRect.w = getPlayerW();
   whiteBoxRect.h = getPlayerH();

   }
    if(playerIndex==1)//player 2
   {
      setPlayerIndex(playerIndex);
      setPlayerName("player2");
      setPlayerUp("i");
      setPlayerDown("j");
      setPlayerLeft("k");
      setPlayerRight("l");
      setPlayerActivate("o");
      setPlayerUse("o");
      setPlayerAttack("m");
      setPlayerSpecial("u");
      setPlayerPause("enter");
      setPlayerHealth(200);
      setPlayerMovementSpeed(5);
      setPlayerInputMode("keyboard");
      setPlayerX(0);
      setPlayerY(0);
      setPlayerW(10);
      setPlayerH(10);
   whiteBoxRect1.x =getPlayerX();
   whiteBoxRect1.y =getPlayerY();
   whiteBoxRect1.w =getPlayerW();
   whiteBoxRect1.h =getPlayerH();

   }
}

void    playerAgency::setPlayerIndex(int  playerIndex1)
{
      playerIndex=playerIndex1;
}
void playerAgency::setPlayerName(string playerName1)
{
   playerName=playerName1;
}
void playerAgency::setPlayerUp(string playerUp1)
{
   playerUp=playerUp1;
}
void playerAgency::setPlayerDown(string playerDown1)
{
   playerDown=playerDown1;
}
void playerAgency::setPlayerLeft(string playerLeft1)
{
   playerLeft=playerLeft1;
}
void playerAgency::setPlayerRight(string playerRight1)
{
   playerRight=playerRight1;
}
void playerAgency::setPlayerActivate(string playerActivate1)
{
   playerActivate=playerActivate1;
}
void playerAgency::setPlayerUse(string playerUse1)
{
   playerUse=playerUse1;
}
void playerAgency::setPlayerAttack(string playerAttack1)
{
   playerAttack=playerAttack1;
}
void playerAgency::setPlayerSpecial(string playerSpecial1)
{
   playerSpecial=playerSpecial1;
}
void playerAgency::setPlayerPause(string playerPause1)
{
   playerPause=playerPause1;
}
void    playerAgency::setPlayerHealth(int    playerHealth1)
{
   playerHealth=playerHealth1;
}
void    playerAgency::setPlayerMovementSpeed(int    playerMovementSpeed1)
{
   playerMovementSpeed=playerMovementSpeed1;
}
void playerAgency::setPlayerInputMode(string playerInputMode1)
{
   playerInputMode=playerInputMode1;
}
void playerAgency::setPlayerX(int X1)
{    playerX=X1;}
void playerAgency::setPlayerY(int Y1)
{    playerY=Y1;}
void playerAgency::setPlayerW(int W1)
{    playerW=W1;}
void playerAgency::setPlayerH(int H1)
{    playerH=H1;}
int    playerAgency::getPlayerIndex()
{
   return playerIndex;
}
string playerAgency::getPlayerName()
{
   return playerName;
}
string playerAgency::getPlayerUp()
{
   return playerUp;
}
string playerAgency::getPlayerDown()
{
   return playerDown;
}
string playerAgency::getPlayerLeft()
{
   return playerLeft;
}
string playerAgency::getPlayerRight()
{
   return playerRight;
}
string playerAgency::getPlayerActivate()
{
   return playerActivate;
}
string playerAgency::getPlayerUse()
{
   return playerUse;
}
string playerAgency::getPlayerAttack()
{
   return playerAttack;
}
string playerAgency::getPlayerSpecial()
{
   return playerSpecial;
}
string playerAgency::getPlayerPause()
{
   return playerPause;
}
int    playerAgency::getPlayerHealth()
{
   return playerHealth;
}
int    playerAgency::getPlayerMovementSpeed()
{
   return playerMovementSpeed;
}
string playerAgency::getPlayerInputMode()
{
   return playerInputMode;
}
int playerAgency::getPlayerX()
{  return playerX;}
int playerAgency::getPlayerY()
{  return playerY;}
int playerAgency::getPlayerW()
{  return playerW;}
int playerAgency::getPlayerH()
{  return playerH;}

void playerAgency::playerButtonPress(SDL_Keycode e)
{ 
      switch(e)
      {
         case(SDLK_s) :
            playerY++; break;
         case(SDLK_w) :
            playerY--; break;
         case(SDLK_d) :
            playerX++; break;
         case(SDLK_a) :
            playerX--; break;
      }
      whiteBoxRect.x = getPlayerX();
      whiteBoxRect.y = getPlayerY();
}

