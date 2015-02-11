//INCLUDES
#include "SDL.h"
#include <stdio.h>

void initialize()
{


}

void update()
{


}

void draw()
{


}

using namespace std;

int main (int argc, char* argv[]){

	initialize();

	SDL_Window *window;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"An SDL2 window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
		);


    // Check that the window was successfully made
    if (window == NULL) {
        // In the event that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);


	//loadcontent
	//unloadcontent
	//-update
	//-draw
	//drawtext
	//readwritefiles
/*
	while(true)
	{
		//Do Game

		//Update
		update();

		//Draw
		draw();
	}
*/
	SDL_Quit();
	return 0;

}
