//INCLUDES
#include "SDL.h"
#include <stdio.h>
#include <string>

using namespace std;


//Global Variables
SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *image = NULL;
//String window_name = "Rogue Engine Window Title Here"
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;
bool initialize()
{

	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{

		printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError() );
		success = false;
	}


	window = SDL_CreateWindow( "Rogue Engine Window Title Here", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    // Check that the window was successfully made
    if (window == NULL) {
        // In the event that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
    	//Window Surface
    	surface = SDL_GetWindowSurface(window);
    	SDL_FillRect( surface, NULL, SDL_MapRGBA(surface->format, 55,55,55,55));
    }

return success;

}

bool loadMedia()
{
	bool success = true;

	image = SDL_LoadBMP ("rogue-engine/dino.bmp");
	if(image == NULL)
	{
		printf ("The image didn't load. Error: %s", SDL_GetError() );
		success = false;
	}


	return success;

}

void update()
{

	//SDL_BlitSurface( image, NULL, surface, NULL);

	SDL_FillRect( surface, NULL, SDL_MapRGBA(surface->format, 155,155,155,155));
}

void draw()
{

	SDL_UpdateWindowSurface( window );

}


void close()
{

    // Close and destroy the window
    SDL_DestroyWindow(window);
    window = NULL;

	SDL_Quit();
}


int main (int argc, char* argv[]){

	initialize();

	loadMedia();

	update();

	draw();

    SDL_Delay(3000);

	close();
	return 0;

}
