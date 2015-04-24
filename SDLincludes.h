
#ifdef WINDOWS

	#include "SDL.h"
	#include "SDL_image.h"
	#include "SDL_mixer.h"
	#include "SDL_ttf.h"
	#include "SDL_thread.h"
	#include "SDL_timer.h"


#endif

#ifdef LINUX

	#include "SDL2/SDL.h"
	#include "SDL2/SDL_image.h"
	#include "SDL2/SDL_ttf.h"
	#include "SDL2/SDL_mixer.h"

#endif

#ifdef MAC

	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
	#include <SDL2/SDL_mixer.h>
	#include <SDL2/SDL_thread.h>
	#include <SDL2/SDL_timer.h>

#endif
