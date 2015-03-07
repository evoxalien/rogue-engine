
if defined(WINDOWS)
{
	#include "SDL.h"
	#include "SDL_image.h"
}
if defined(LINUX)
{
	#include "SDL/SDL.h"
	#include "SDL/SDL_image.h"
}
else
{
	#include "SDL.h"
	#include "SDL_image.h"
}