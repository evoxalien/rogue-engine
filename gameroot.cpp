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

//The frames per second timer
LTimer fpsTimer;
//The frames per second cap timer
LTimer capTimer;

InputClass input;
playerAgency player1;
//Gamestate gamestate;
//The image we will load and show on the screen
SDL_Texture* imgTex = NULL;
SDL_Event event;

Player player;

Object immobile_Blocks[10];
Object mobile_Blocks[2];


//Simple initializes
gameroot::gameroot()
{
   Running = false;
   window = NULL;
   renderer = NULL;
   surface = NULL;
   image = NULL;
   texture = NULL;

}


//Initialize all the SDL
bool gameroot::initialize()
{

    r = 0, g = 0, b = 0; 
   //intitalize the gamestate

   player1.intializePlayer(0);
   player1.gamestate=player1.StartMenu;

	player.physics.set_X_Position(20);//player1.getPlayerX());
	player.physics.set_Y_Position(650);//player1.getPlayerY());
	player.physics.set_X_Length(25);//player1.getPlayerW());
	player.physics.set_Y_Length(25);//player1.getPlayerH());
	player.physics.set_Elasticity(.2);
	player.physics.set_Mass(30);

	immobile_Blocks[0].physics.set_X_Position(-100);
	immobile_Blocks[0].physics.set_Y_Position(-100);
	immobile_Blocks[0].physics.set_X_Length(SCREEN_WIDTH + 200);
	immobile_Blocks[0].physics.set_Y_Length(100);

	immobile_Blocks[1].physics.set_X_Position(-100);
	immobile_Blocks[1].physics.set_Y_Position(SCREEN_HEIGHT - 1);
	immobile_Blocks[1].physics.set_X_Length(SCREEN_WIDTH + 200);
	immobile_Blocks[1].physics.set_Y_Length(100);

	immobile_Blocks[2].physics.set_X_Position(-100);
	immobile_Blocks[2].physics.set_Y_Position(0);
	immobile_Blocks[2].physics.set_X_Length(100);
	immobile_Blocks[2].physics.set_Y_Length(SCREEN_HEIGHT);

	immobile_Blocks[3].physics.set_X_Position(SCREEN_WIDTH - 1);
	immobile_Blocks[3].physics.set_Y_Position(0);
	immobile_Blocks[3].physics.set_X_Length(100);
	immobile_Blocks[3].physics.set_Y_Length(SCREEN_HEIGHT);

	immobile_Blocks[4].physics.set_X_Position(400);
	immobile_Blocks[4].physics.set_Y_Position(600);
	immobile_Blocks[4].physics.set_X_Length(200);
	immobile_Blocks[4].physics.set_Y_Length(75);

	immobile_Blocks[5].physics.set_X_Position(100);
	immobile_Blocks[5].physics.set_Y_Position(500);
	immobile_Blocks[5].physics.set_X_Length(200);
	immobile_Blocks[5].physics.set_Y_Length(75);

	immobile_Blocks[6].physics.set_X_Position(800);
	immobile_Blocks[6].physics.set_Y_Position(400);
	immobile_Blocks[6].physics.set_X_Length(250);
	immobile_Blocks[6].physics.set_Y_Length(100);

	immobile_Blocks[7].physics.set_X_Position(150);
	immobile_Blocks[7].physics.set_Y_Position(200);
	immobile_Blocks[7].physics.set_X_Length(100);
	immobile_Blocks[7].physics.set_Y_Length(50);

	immobile_Blocks[8].physics.set_X_Position(850);
	immobile_Blocks[8].physics.set_Y_Position(200);
	immobile_Blocks[8].physics.set_X_Length(100);
	immobile_Blocks[8].physics.set_Y_Length(50);

	immobile_Blocks[9].physics.set_X_Position(50);
	immobile_Blocks[9].physics.set_Y_Position(350);
	immobile_Blocks[9].physics.set_X_Length(75);
	immobile_Blocks[9].physics.set_Y_Length(50);


	for(int i = 0; i < 10; i++)
	{
		immobile_Blocks[i].physics.set_Elasticity(1);
		immobile_Blocks[i].physics.set_Mass(100000000000);
	}

	mobile_Blocks[0].physics.set_X_Position(750);
	mobile_Blocks[0].physics.set_Y_Position(200);
	mobile_Blocks[0].physics.set_X_Length(50);
	mobile_Blocks[0].physics.set_Y_Length(50);

	mobile_Blocks[1].physics.set_X_Position(300);
	mobile_Blocks[1].physics.set_Y_Position(200);
	mobile_Blocks[1].physics.set_X_Length(50);
	mobile_Blocks[1].physics.set_Y_Length(50);

	for(int i = 0; i < 2; i++)
	{
		mobile_Blocks[i].physics.set_Elasticity(1);
		mobile_Blocks[i].physics.set_Mass(10000000);
//		mobile_Blocks[i].physics.set_Y_Velocity(25);
		mobile_Blocks[i].physics.set_X_Velocity(100);
	}
   

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

	Physics::set_Frame_Rate(60);
   
   return true;
}

//Does Nothing. Load textures here in future
bool gameroot::loadContent()
{

   texture = loadTexture("../../images/dino.png");

   if(texture == NULL)
   {
      printf("Texture failed to load.\n");
      return false;
   }
   
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
		switch((*Event).key.keysym.sym)
		{
			case SDLK_w:
				player.physics.add_Force(0, player.physics.get_Mass() * -250);
				player.physics.set_Y_Position(player.physics.get_Y_Position() - 1);
				break;
			case SDLK_a:
				player.physics.add_Force(player.physics.get_Mass() * -250, 0);
				player.physics.set_X_Position(player.physics.get_X_Position() - 1);
				break;
			case SDLK_s:
				player.physics.add_Force(0, player.physics.get_Mass() * 250);
				player.physics.set_Y_Position(player.physics.get_Y_Position() + 1);
				break;
			case SDLK_d:
				player.physics.add_Force(player.physics.get_Mass() * 250, 0);
				player.physics.set_X_Position(player.physics.get_X_Position() + 1);
				break;
			default:
				break;
		}
      //keyPress(&gameState,Event);
   }
}

//Does nothing. Math and physics later
void gameroot::update()
{

   debug_log << "test " << GLOBAL_FRAME_COUNTER << "\n";


   while(SDL_PollEvent(&Event))
   {
      
      input.update(Event);
      OnEvent(&Event);
      if(input.getMouseButton(1))
      {
         // whiteBoxRect.x = input.getMouseX();
         // whiteBoxRect.y = input.getMouseY();
      }
      if (player1.gamestate==player1.Playing)
      {
         player1.playerButtonPress(input.getKeyDown());
      }
      player1.MenuChoices(input.getKeyDown());


   }
	player.physics.half_Move();
	for(int i = 0; i < 2; i++)
	{
		mobile_Blocks[i].physics.half_Move();
	}

	Object::check_For_Collisions();			//Will check through the sectioned physics pointer vectors stored in the object class for collisions; will be changing in the future to move appropriate objects as well.

	player.physics.add_Force(Physics::get_X_Gravity() * player.physics.get_Mass(), Physics::get_Y_Gravity() * player.physics.get_Mass());
	player.physics.apply_Forces();
	player.physics.accelerate();
	player.physics.half_Move();
	for(int i = 0; i < 2; i++)
	{
		//mobile_Blocks[i].physics.add_Force(Physics::get_X_Gravity() * mobile_Blocks[i].physics.get_Mass(), Physics::get_Y_Gravity() * mobile_Blocks[i].physics.get_Mass());
		mobile_Blocks[i].physics.apply_Forces();
		mobile_Blocks[i].physics.accelerate();
		mobile_Blocks[i].physics.half_Move();
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

	SDL_Rect object_Rectangle;
   

   if(player1.gamestate==player1.StartMenu)
   {
      //render texture to screen
      SDL_RenderCopy(renderer, texture, NULL, NULL);
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

   if(player1.gamestate==player1.Playing)
   {
      SDL_RenderCopy(renderer, imgTex, NULL, &player1.whiteBoxRect);
   }
   

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	object_Rectangle = {static_cast<int>(player.physics.get_X_Position()), static_cast<int>(player.physics.get_Y_Position()), static_cast<int>(player.physics.get_X_Length()), static_cast<int>(player.physics.get_Y_Length())};
	SDL_RenderFillRect(renderer, &object_Rectangle);

	for(int i = 0; i < 2; i++)
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x55, 0x55, 0xFF);
		object_Rectangle = {static_cast<int>(mobile_Blocks[i].physics.get_X_Position()), static_cast<int>(mobile_Blocks[i].physics.get_Y_Position()), static_cast<int>(mobile_Blocks[i].physics.get_X_Length()), static_cast<int>(mobile_Blocks[i].physics.get_Y_Length())};
		SDL_RenderFillRect(renderer, &object_Rectangle);
	}

	for(int i = 0; i < 10; i++)
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		object_Rectangle = {static_cast<int>(immobile_Blocks[i].physics.get_X_Position()), static_cast<int>(immobile_Blocks[i].physics.get_Y_Position()), static_cast<int>(immobile_Blocks[i].physics.get_X_Length()), static_cast<int>(immobile_Blocks[i].physics.get_Y_Length())};
		SDL_RenderFillRect(renderer, &object_Rectangle);
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
	//double maximum_Frame_Rate = 60;											//If the developers want to include a maximum frame rate, this is it; unfinished
	double total_Time = 0;														//Keeps a running total of the amount of time that the game has been active for; temporary

	std::chrono::duration<double> time_Of_Previous_Frame;						//A variable which holds the number of clock cycles between frames from the highest resolution clock available- use .count() to convert to seconds
	auto start_Of_Previous_Frame = std::chrono::high_resolution_clock::now();	//Initializes the variable to the type best suited for the highest resolution clock
	auto start_Of_Current_Frame = start_Of_Previous_Frame;						//Initializes the variable to the type best suited for the highest resolution clock

	//cout.precision(15);														//Sets the number of decimal places for cout to display

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
		start_Of_Current_Frame = std::chrono::high_resolution_clock::now();		//At the start of each frame, store the time
		time_Of_Previous_Frame = std::chrono::duration_cast<std::chrono::duration<double>>(start_Of_Current_Frame - start_Of_Previous_Frame);	//Number of clock cycles between frames
		if(time_Of_Previous_Frame.count() != 0)									//Avoid dividing by 0
		{
			Physics::set_Frame_Rate((1.0 / time_Of_Previous_Frame.count()));	//Update Physics to know how long the previous frame took
		}
		total_Time = total_Time + time_Of_Previous_Frame.count();				//Add the time of the last frame to the total time

	  //update and redraw window
      update();
      draw();

		//Physics::set_Frame_Rate(maximum_Frame_Rate);
		start_Of_Previous_Frame = start_Of_Current_Frame;						//At the end of each frame, store the time
    }

   close() ;
   return 0;
}

//Free all the assets
void gameroot::close()
{
   SDL_DestroyTexture(texture);
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
