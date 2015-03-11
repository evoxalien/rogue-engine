#ifndef ROOM_H_
#define ROOM_H_

#include <SDL.h>
#include "Texture.h"

class Room
{
	private:
		Texture baseTexture;

	public:
		SDL_Rect baseRect;

		Room()
		{
			baseRect = {0,0,0,0};
			renderer = NULL;
		}

		void setRenderer(SDL_Renderer* render)
		{
			baseTexture.setRenderer(render);
		}

		const SDL_Rect* getBaseRect()
		{
			return &baseRect;
		}

		void setBaseTexture(std::string path)
		{
			if(!baseTexture.loadTexture(path))
				printf("Failed to load texture");
		}

		void update()
		{
			baseTexture.setWidth(baseRect.w);
			baseTexture.setHeight(baseRect.h);
		}

		void render(int camX, int camY)
		{
			baseTexture.render(baseRect.x - camX, baseRect.y - camY);
		}
};

#endif