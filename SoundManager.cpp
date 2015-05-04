#include "soundManager.h"

using namespace std;

//Constructor
Sound_Manager::Sound_Manager()
{
	if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL audio could not initialize! SDL Error: %s\n", SDL_GetError() );
	}
	Mix_OpenAudio(22050, AUDIO_S16, 2,4096);
	//Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 )
}

//Destructor
Sound_Manager::~Sound_Manager()
{
	//this.Stop_Sound();
	Mix_HaltMusic();
	//Mix_FreeMusic( m_MUSIC[x] );
	//Mix_FreeChunk( m_SFX[y] );
}

//Initialize for SDL Audio
void Sound_Manager::Init()
{
	if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL audio could not initialize! SDL Error: %s\n", SDL_GetError() );
	}
	Mix_OpenAudio(22050, AUDIO_S16, 2,4096);
	//Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
}

//Loading of sound from file location given its filename, then specify an id, 
//and type(music:0 , soundeffect:1)
bool Sound_Manager::Load_Sound(string fileName, string id, int i)
{
	if(i == 0)
	{
		Mix_Music* ptrMusic = Mix_LoadMUS(fileName.c_str());

		if(ptrMusic == 0)
		{
			return false;
		}
		m_MUSIC[id] = ptrMusic;
		return true;
	}
	if(i == 1)
	{
		Mix_Chunk* ptrChunk = Mix_LoadWAV(fileName.c_str());

		if(ptrChunk == 0)
		{
			return false;
		}
		m_SFX[id] = ptrChunk;
		return true;
	}
	return false;
}

//Function call to play the background music with id and if looping 
//(note: if called again then song will pause until called again and resume)
void Sound_Manager::Play_Music(string id, int looping){
	
	if( Mix_PlayingMusic() == 0 )
	{
		Mix_PlayMusic( m_MUSIC[id], looping );
	}
	else
	{
		if( Mix_PausedMusic() == 1 )
		{
			Mix_ResumeMusic();
		}
		else
		{
			Mix_PauseMusic();
		}
	}
}

//Function call to play a sound effect with a slight delay(tigger should handle delay may need testing)
void Sound_Manager::Play_Sound(string id, int looping){
	
			Mix_PlayChannel( -1, m_SFX[id], looping );		
		
}

//Function call to stop the background music completely to beginning
void Sound_Manager::Stop_Sound()
{
	Mix_HaltMusic();
}
void Sound_Manager::Stop()
{
	Mix_HaltChannel(0);
}

//Function call to unload the sound depending on file type (music:0 , soundeffect:1) and specified id
void Sound_Manager::Unload_Sound(string id, int i)
{
	if(i == 0)
	{
		Mix_FreeMusic( m_MUSIC[id] );
		m_MUSIC[id] = NULL;	
	}
	if(i == 1)
	{
		Mix_FreeChunk( m_SFX[id] );
		m_SFX[id] = NULL;	
	}
}
