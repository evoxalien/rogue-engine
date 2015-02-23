#ifndef PLAYERAGENCY_H_INCLUDED

#define PLAYERAGENCY_H_INCLUDED


#include "SDL.h"
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
   void setPlayerIndex();
   void setPlayerName();
   void setPlayerUp();
   void setPlayerDown();
   void setPlayerLeft();
   void setPlayerRight();
   void setPlayerActivate();
   void setPlayerUse();
   void setPlayerAttack();
   void setPlayerSpecial();
   void setPlayerPause();
   void setPlayerHealth();
   void setPlayerMovementSpeed();
   void setPlayerInputMode();
};
#endif

