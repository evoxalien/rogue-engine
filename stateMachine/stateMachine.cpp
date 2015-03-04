#include"stateMachine.h"


stateMachine::stateMachine()
{
   //Initialize Lua
   L = lua_open();

   //Load Lua base libraries
   luaL_openlibs(L);

   //Load the default Script
   luaL_dofile(L, "follow.lua");
   
   
   //Load the default function name (define it)
   lua_getglobal(L, "follow");
   
   //There is only one default behavior
   count = 1;
   
   currentBehavior = 0;
   x = 0;
   
   y = 0;
}

stateMachine::stateMachine(string *behaviorList, int count,int enemyX, int enemyY)
{
   //Start with first behavior for idexing
   currentBehavior = 0;
   
   //Initialize Lua
   L = lua_open();

   //Load Lua base libraries
   luaL_openlibs(L);

   //Load script for the first behavior
   luaL_dofile(L, behaviorList[currentBehavior]+ ".lua");
   
   //Load the first function name (define it)
   lua_getglobal(L, behaviorList[currentBehavior]);
   
   x = enemyX;
   
   y = enemyY;
}

void stateMachine::destroy()
{
   //clean up Lua stuffs
   lua_close(L);
}

bool stateMachine::nextState()
{
   if((currentBehavior + 1) == count)
      return false;
   
   //step into next state
   currentBehavior++;
   
   //Pop the function currently in the Lua stack off
   //This function was the previous behavior
   lua_pop(L, 1);
   
   //Load script for the next behavior
   luaL_dofile(L, behaviorList[currentBehavior]+ ".lua");
   
   //Load the next function name (define it)
   lua_getglobal(L, behaviorList[currentBehavior]);
   
   return true;
}

bool stateMachine::update(int playerX, int playerY)
{
   //The pushing first argument for the function
	lua_pushnumber(L, playerX);

	//The pushing second argument for the function
	lua_pushnumber(L, playerY);
	
	//The pushing third argument for the function
	lua_pushnumber(L, x);

	//The pushing forth argument for the function
	lua_pushnumber(L, y);

	//call the function with 4 arguments, return 2 results
	lua_call(L, 4, 2);

	//Getting results from lua stack
	x = (int)lua_tointeger(L, -1);
	lua_pop(L, 1);
	y = (int)lua_tointeger(L, -1);
   
   return true;   
}




#endif

