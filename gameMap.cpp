#ifndef GAMEMAP_CPP_
#define GAMEMAP_CPP_

#include "gameMap.h"


gameMap::gameMap()
{
	bgX = bgY = numPlatforms = 0;
	render = NULL;
	camera.setBoundRect(0,0,1280,720);
}

gameMap::~gameMap()
{
	for(int x = 0; x < numPlatforms; x++)
	{
		platforms[x].free();
	}

	backgroundTexture.free();
}

bool gameMap::parseMapFile(std::string filepath, SDL_Renderer* r)
{
	render = r;

	ifstream inputFile;
	inputFile.open(filepath);

	if(!inputFile)
		return false;

	string inputStr = "";
	string texturePath = "";
	int w = 0, h = 0;

	while(inputFile >> inputStr)
	{
		if(inputStr == "background")
		{
			backgroundTexture.setRenderer(render);

			inputFile >> bgX;
			inputFile >> bgY;
			inputFile >> w;
			inputFile >> h;
			inputFile >> texturePath;

			backgroundTexture.loadTexture(texturePath);
			backgroundTexture.setWidth(w);
			backgroundTexture.setHeight(h);
		}
		if(inputStr == "platforms")
		{
			inputFile >> numPlatforms;
			for(int x = 0; x < numPlatforms;x++)
			{
				platSelected[x] = false;
				platforms[x].setRenderer(render);

				inputFile >> platCoords[x*2];
				inputFile >> platCoords[x*2+1];
				inputFile >> w;
				inputFile >> h;
				inputFile >> texturePath;
				platforms[x].loadTexture(texturePath);
				platforms[x].setWidth(w);
				platforms[x].setHeight(h);
			}
		}
	}

	inputFile.close();

	return true;
}

void gameMap::renderMap()
{
	if(backgroundTexture.getFilePath() != "")
	{
		backgroundTexture.render(bgX - camera.getCamX(), bgY - camera.getCamY());
	}

	for(int x = 0; x < numPlatforms; x++)
	{
		platforms[x].render(platCoords[x*2] - camera.getCamX(), platCoords[x*2+1] - camera.getCamY());
	}
}

void gameMap::updateMap()
{

}

void gameMap::processKeyboard(InputClass input)
{

}

void gameMap::processMouse(InputClass input)
{

}

void gameMap::rightClickAction(InputClass input)
{

}

void gameMap::leftClickAction(InputClass input)
{

}

bool gameMap::mouseOverRect(InputClass input, SDL_Rect rect)
{
	if(input.getMouseX() + camera.getCamX() >= rect.x &&
		input.getMouseX() + camera.getCamX() <= rect.x + rect.w &&
		input.getMouseY() + camera.getCamY() >= rect.y &&
		input.getMouseY() + camera.getCamY() <= rect.y + rect.h)
	{
		return true;
	}
	return false;
}

#endif