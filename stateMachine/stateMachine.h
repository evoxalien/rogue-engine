#ifndef STATEMACHINE_H_INCLUDED

#define STATEMACHINE_H_INCLUDED

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <string>
#include <stdio.h>

using namespace std;


class stateMachine
{
private:
   //The Lua interpreter
   lua_State* L;
   //Number of behaviors(states) 
   int behaviorCount;
   int currentBehavior;
   //list of behaviors
   string *behaviors;
public:
   stateMachine();
   stateMachine(string *behaviorList, int count,int enemyX, int enemyY);
   void destroy();
   void nextState();
   bool update(int playerX, int playerY);
   //x and y position of AI entity
   int x;
   int y;

};



#endif

//Marcelo's Email: irongravewarrior@gmail.com --> plz discrett math 2 previous tests