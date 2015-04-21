#ifndef Sound_Manager_H
#define Sound_Manager_H
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <map>

using namespace std;

enum soundType{
	SoundMusic = 0, SoundSFX = 1
};

class Sound_Manager{
public:
	static Sound_Manager* Instance()
	{
		if(pInstance == 0){
			pInstance= new Sound_Manager();
			return pInstance;
		}
		return pInstance;
	}

	int x;

	void Init();

	bool Load_Sound(std::string fileName, std::string id, int i);

	void Play_Sound(std::string id, int looping);

	void Play_Music(std::string id, int looping);

	void Stop_Sound();
	void Stop();
	
	void Unload_Sound(std::string id, int i);

	std::map<std::string, Mix_Chunk*>m_SFX;
	std::map<std::string, Mix_Music*>m_MUSIC;

	Sound_Manager();
	~Sound_Manager();

	Sound_Manager(const Sound_Manager&);
	Sound_Manager &operator=(const Sound_Manager&);

private:
	static Sound_Manager* pInstance;

};

#endif
