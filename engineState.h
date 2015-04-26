#ifndef ENGINESTATE_H_INCLUDED

#define ENGINESTATE_H_INCLUDED

class EngineState
{
   public:
   EngineState();
   
   bool isGameRunning();
   bool isMapeditorRunning();
   bool isMainRunning();
   
   bool gameroot;
   bool mapeditor;
   bool main;
};

EngineState::EngineState()
{
   gameroot = false;
   mapeditor = false;
   main =  false;
}

bool EngineState::isGameRunning()
{
   return gameroot;
}

bool EngineState::isMapeditorRunning()
{
   return mapeditor;
}

bool EngineState::isMainRunning()
{
   return main;
}

#endif