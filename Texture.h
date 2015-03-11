#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "SDLincludes.h"

class Texture
{
	private:
		//The actual hardware texture
		SDL_Texture* texture;

		//Image dimensions
		int width;
		int height;

		SDL_Renderer* renderer;

		std::string filePath;

	public:
		//Initializes variables
		Texture()
		{
			width = 0;
			height = 0;
			texture = NULL;
			renderer = NULL;
			filePath = "";
		}

		//Deallocates memory
		~Texture()
		{
			free();
		}

		void setRenderer(SDL_Renderer* render)
		{
			renderer = render;
		}

		//Loads image at specified path
		bool loadTexture(std::string path)
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
		      //convert image to screen format
		      newTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
		      if(newTexture == NULL)
		      {
		      	printf("Failed to create texture from image %s: %s\n", path.c_str(), SDL_GetError());
		      }
		      else
		      {
		      	width = loadSurface->w;
		      	height = loadSurface->h;
		      }
		   }

		   SDL_FreeSurface(loadSurface);

		   filePath = path;
		   texture = newTexture;

		   return texture != NULL;
		}
		
		/*#ifdef _SDL_TTF_H
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif*/

		//Deallocates texture
		void free()
		{
			SDL_DestroyTexture(texture);
			texture = NULL;
			width = 0;
			height = 0;
			filePath = "";
		}

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue )
		{
			SDL_SetTextureColorMod(texture, red, green, blue);
		}

		//Set blending
		void setBlendMode( SDL_BlendMode blending )
		{
			SDL_SetTextureBlendMode(texture, blending);
		}

		//Set alpha modulation
		void setAlpha( Uint8 alpha )
		{
			SDL_SetTextureAlphaMod(texture, alpha);
		}
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE)
		{
			SDL_Rect renderArea = {x, y, width, height};

			if(clip != NULL)
			{
				renderArea.w = clip->w;
				renderArea.h = clip->h;
			}

			SDL_RenderCopyEx(renderer, texture, clip, &renderArea, angle, center, flip);
		}

		//Gets image dimensions
		int getWidth()
		{
			return width;
		}
		int getHeight()
		{
			return height;
		}

		//set texture dimensions
		void setWidth(int w)
		{
			width = w;
		}
		void setHeight(int h)
		{
			height = h;
		}

		std::string getFilePath()
		{
			return filePath;
		}
};

#endif