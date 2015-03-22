//INCLUDES
/*
#include "SDL.h"
#include "SDL_image.h"
#include "input.h"
#include "playerAgency.h"
#include <stdio.h>
#include <string>
*/
//#include "SDLincludes.h"
//#include <stdio.h>
//#include <string>

#include "gameroot.h"
using namespace std;

//String window_name = "Rogue Engine Window Title Here"
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

double gameroot::maximum_Frame_Rate = 120;		//Sets the maximum number of times the main game loop can execute in a single second
double gameroot::total_Time = 0;				//The amount of time the game has run from the start of the program
std::chrono::high_resolution_clock::time_point gameroot::start_Of_Previous_Frame = std::chrono::high_resolution_clock::now();	//The time point that the previous instance of the main game loop (A 'frame') began
std::chrono::high_resolution_clock::time_point gameroot::start_Of_Current_Frame = gameroot::start_Of_Previous_Frame;			//The time point at which the currently active frame began
std::chrono::duration<double> gameroot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(start_Of_Current_Frame - start_Of_Previous_Frame);	//The length of time the previous frame took to complete

//The frames per second timer
LTimer fpsTimer;
//The frames per second cap timer
LTimer capTimer;


//Gamestate gamestate;
//The image we will load and show on the screen
SDL_Texture* imgTex = NULL;
SDL_Event event;
//Simple initializes
gameroot::gameroot()
{
   Running = false;
   window = NULL;
   renderer = NULL;
   surface = NULL;
   image = NULL;
   engineState = Waiting;
}


//Initialize all the SDL
bool gameroot::initialize()
{
   dino = 0;

    r = 0, g = 0, b = 0; 
   //intitalize the gamestate

   player1.intializePlayer(0);
   player1.gamestate=player1.StartMenu;
   

   //Tests SDL components, important to call before other SDL operations
   //https://wiki.libsdl.org/SDL_Init
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
   {
      printf ("SDL Component failed to initialize Error: %s", SDL_GetError());
      return false;
   }

   //Calls and tests function to create SDL Window (documentation in link)
   //https://wiki.libsdl.org/SDL_CreateWindow
   if((window = SDL_CreateWindow( "Rogue Engine Window Title Here", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN )) == NULL)
   {
      printf ("Window Error: %s", SDL_GetError());
      return false;
   }

   //Creates SDL Renderer. Renderer renders assets to SDL windows
   //Can be used to draw .bmp images to window (example in link)
   //https://wiki.libsdl.org/SDL_CreateRenderer
   renderer = SDL_CreateRenderer ( window , - 1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;

   //Tests if renderer initialized properly
   if (renderer == NULL)
   {
      printf ("Render Error: %s", SDL_GetError());
      return false;
   }

   //set render draw color property
   SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

   //tell texture the renderer to use
   texture.setRenderer(renderer);

   //initialize map from file
   map.parseMapFile("maps/Map1.txt", renderer);

   //initialize image subsystem to load png files
   int imgFlags = IMG_INIT_PNG;
   if(!(IMG_Init(imgFlags) & imgFlags))
   {
      printf("SDL_Image could not be initialized. SDL_Image error : %s\n", IMG_GetError());
      return false;
   }

   //sets boolean to true. This boolean determines if the game loop continues
   Running = true;
  



   GLOBAL_FRAME_COUNTER = 0;
   fpsTimer.start();
   /*
   previousTicks = 0;
   fps_lasttime = SDL_GetTicks(); //the last recorded time.
   fps_current = 0; //the current FPS.
   fps_frames = 0; //frames passed since the last recorded fps.
   */

	Object::set_Number_Of_X_Physics_Segments(64);		//64 is arbitrary, but will divide the level into 64 columns to improve the efficiency of collision detection
	Object::set_Number_Of_Y_Physics_Segments(64);		//64 is arbitrary, but will divide the level into 64 rows to improve the efficiency of collision detection
	Object::set_Screen_X_Length(SCREEN_WIDTH);			//Will be changing in the future to setLevelSize(struct level_Size, int level_Number) or moved to update in the loop
	Object::set_Screen_Y_Length(SCREEN_HEIGHT);			//Will be included in setLevelSize in the future

	Physics::set_Frame_Rate(gameroot::maximum_Frame_Rate);
   
   return true;
}

//Does Nothing. Load textures here in future
bool gameroot::loadContent()
{

   if(!texture.loadTexture("../../images/dino.png"))
   {
      error_log << "Texture failed to load.\n";
      return false;
   }
   texture.setWidth(SCREEN_WIDTH);
   texture.setHeight(SCREEN_HEIGHT);
   
   imgTex = loadTexture("img/shapes/OrangeSquare.png");
   if(imgTex == NULL)
   {
      printf("Texture failed to load.\n");
      return false;
   }
   return true;

}

//Event checking for game loop 
//Handles Events such as clicks and button pushes
//https://wiki.libsdl.org/SDL_Event
void gameroot::OnEvent(SDL_Event *Event)
{
   
   //Check if event is the clicking of the exit (SDL_QUIT)
   if(Event->type == SDL_QUIT)
   {
      Running = false;
   }
   
   //This event works to track keyboard inputs
   else if (Event->type == SDL_KEYDOWN)
   {

   }
}

//Does nothing. Math and physics later
void gameroot::update()
{
	if(gameroot::time_Of_Previous_Frame.count() != 0)										//Avoid dividing by 0
	{
		Physics::set_Frame_Rate((1.0 / gameroot::time_Of_Previous_Frame.count()));			//Update Physics to know how long the previous frame took
	}
	else
	{
		Physics::set_Frame_Rate(gameroot::maximum_Frame_Rate);								//If the frame took an unregisterable amount of time, Physics uses the maximum frame rate for this frame
	}
	gameroot::total_Time = gameroot::total_Time + gameroot::time_Of_Previous_Frame.count();	//Add the time of the last frame to the total time

   debug_log << "test " << GLOBAL_FRAME_COUNTER << "\n";


   while(SDL_PollEvent(&Event))
   {
      
      input.update(Event);
      OnEvent(&Event);
      if(engineState == Waiting)
      {
         if(input.getKeyDown() == SDLK_t)
         {
            engineState = PlayingGame;
            player1.gamestate = player1.Playing;
         }
         if(input.getKeyDown() == SDLK_m)
         {
            engineState = MapEditor;
         }

      // engineState= Main.MenuChoices(input.getKeyDown(),static_cast <int>(engineState));
         // player1.MenuChoices(input.getKeyDown());
      }
      if(engineState == PlayingGame)
      {
         // player1.updateKeys(gameroot::engineState);
    if(input.getKeyDown() == SDLK_BACKSPACE)
         {
            engineState = Waiting;
            player1.gamestate = player1.StartMenu;
         }
         if (player1.gamestate==player1.Playing)
         {
            player1.playerButtonPress(input.getKeyDown());
         }
		Object::check_For_Collisions();        //Will check through the physics pointer stored in the object class for collisions; will be changing in the future to move appropriate objects as well.
      }
      if(engineState == MapEditor)
      {
         map.mapEditorUpdate(input);
         if(input.getKeyDown() == SDLK_BACKSPACE)
         {
            engineState = Waiting;
            map.unfocus();
            player1.gamestate = player1.StartMenu;
         }
      }

      //temporarily commenting this out
      //feel free to change this back if you want
      /*
      if (player1.gamestate==player1.Playing)
      {
         player1.playerButtonPress(input.getKeyDown());
		Object::check_For_Collisions();			//Will check through the physics pointer stored in the object class for collisions; will be changing in the future to move appropriate objects as well.
      }
      player1.MenuChoices(input.getKeyDown());*/


   }
   
   
}

//Does nothing. Feel free to draw dinosaur here
void gameroot::draw()
{
   //Start cap Timer
   capTimer.start();

   //using the renderer//

   //set render clear color to non-transparent white(0xFFFFFFFF)
   SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
   //clear screen
   SDL_RenderClear(renderer);

   if(engineState == Waiting)
   {
      if(player1.gamestate==player1.StartMenu)
      {
         //render texture to screen
         texture.render(0,0);
       //Draw Colorful Rectangles
         //Red Rect
         SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
         //Rect params = x, y, w(width), h(height)
         SDL_Rect fillRect = {0, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);
         
         //Green Rect
         SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
         fillRect = {50, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);
         
         //Blue Rect
         SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
         fillRect = {100, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);

         // Adding them together!

         if(r < 255 && g == 0 && b == 0)
            r += 1;
         if (r == 255 && g < 255)
            g += 1;
         if (g == 255 && b < 255)
         {
            b += 1;
            r -= 1;
         }

         if (b == 255 && r < 255)
         {
            r = g = b = 0;
         }


         SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
         fillRect = {150, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);
      }
      //Draw Colorful Rectangles
      if(player1.gamestate== player1.Red)
      {

         if(GLOBAL_FRAME_COUNTER % 3 == 0)
            dino++;


         char cTemp[100];
         string sTemp;

         sprintf(cTemp, "../../images/dino/frame_%03d.png", dino);

         debug_log << cTemp;
         debug_log << "\n";

         sTemp = cTemp;
         //stringstream 
         texture.free();
         if(!texture.loadTexture(sTemp.data()))
         {
            error_log << "Texture failed to load.\n";
            error_log << sTemp << "\n";
         }

         if(dino >= 19)
            dino = 0;

         texture.setWidth(SCREEN_WIDTH);
         texture.setHeight(SCREEN_HEIGHT);

         texture.render(0,0);
         //Red Rect
         SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
         //Rect params = x, y, w(width), h(height)
         SDL_Rect fillRect = {0, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);
      }
      if (player1.gamestate==player1.Green)
      {
         //Green Rect
         SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
         SDL_Rect fillRect = {50, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);
      }
      if(player1.gamestate==player1.Blue)
      {
         //Blue Rect
         SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
         SDL_Rect fillRect = {100, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);
         //render texture to screen
      }
      if (player1.gamestate==player1.all)
      {
         /* code */

         // Adding them together!

         if(r < 255 && g == 0 && b == 0)
            r += 1;
         if (r == 255 && g < 255)
            g += 1;
         if (g == 255 && b < 255)
         {
            b += 1;
            r -= 1;
         }

         if (b == 255 && r < 255)
         {
            r = g = b = 0;
         }


         SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
         SDL_Rect fillRect = {150, 0, 50, 50};
         SDL_RenderFillRect(renderer, &fillRect);
      }
   }
   else if(engineState == PlayingGame)
   {
      map.renderMap();
      if(player1.gamestate==player1.Playing)
      {
         SDL_RenderCopy(renderer, imgTex, NULL, &player1.whiteBoxRect);
      }
   }
   else if(engineState == MapEditor)
   {
      map.renderMap();
   }
   
   //update screen
   SDL_RenderPresent(renderer);
   ++GLOBAL_FRAME_COUNTER;   

   //If frame finished early
   int frameTicks = capTimer.getTicks();
   if( frameTicks < SCREEN_TICKS_PER_FRAME )
   {
      //Wait remaining time
      SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
   }

   //increment frame counter
}

//load texture function taken from lazyfoo
//we should probably make a class for loading
//and drawing media
SDL_Texture* gameroot::loadTexture(std::string path)
{
   //final surface to return
   SDL_Texture* newTexture = NULL;
   
   //load surface at path
   SDL_Surface* loadSurface = IMG_Load(path.c_str());
   if( loadSurface == NULL )
   {
      printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError() );
   }
   else
   {
      //convert surface to texture inside of renderer
      newTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
      if(newTexture == NULL)
      {
         printf("Failed to optimize image %s: %s\n", path.c_str(), SDL_GetError());
      }
      
   }
   return newTexture;
}

//Actual game loop
int gameroot::execute()
{
   //checks all the SDL (see above)
   if(initialize() == false)
   {
      return - 1;
   }


   if(loadContent() == false)
   {
      printf("Content loaded Improperly");
   }


   while(Running)
   {
		gameroot::start_Of_Current_Frame = std::chrono::high_resolution_clock::now();		//At the start of each frame, store the current time
		gameroot::time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(gameroot::start_Of_Current_Frame - gameroot::start_Of_Previous_Frame);	//Number of clock cycles between frames

	  //update and redraw window
      update();
      draw();

		//std::this_thread::sleep_for(std::chrono::nanoseconds(/*calculate number of nanoseconds to wait based on maximum frame rate and time taken so far*/));
		gameroot::start_Of_Previous_Frame = gameroot::start_Of_Current_Frame;				//At the end of each frame, store the start time of the current frame to the previous frame
    }

   close() ;
   return 0;
}

//Free all the assets
void gameroot::close()
{
   texture.free();
   SDL_DestroyRenderer (renderer);
   SDL_FreeSurface(image);
   SDL_FreeSurface(surface);
   SDL_DestroyWindow(window);
   SDL_Quit();
}


//Just the main. Very boring
int main(int argc, char *argv[])
{

   gameroot theGame;

   return theGame.execute();

}
