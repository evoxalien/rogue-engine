#ifndef MAP_CPP_
#define MAP_CPP_
#include "Map.h"
#include <fstream>
#include <sstream>

Map::Map()
{
	numPlatforms = 0;
	camera.setBoundRect(0,0,5000,5000);
	render = NULL;
}

Map::~Map()
{
	if(platforms != NULL)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			platforms[x].free();
		}
	}

}

bool Map::parseMapFile(std::string filePath, SDL_Renderer* r)
{
	render = r;
	ifstream inputFile;
	inputFile.open(filePath);

	if(!inputFile)
		return false;

	inputFile >> numPlatforms;

	string shape = "";
	string texturePath = "";
	int w = 0, h = 0;
	for(int x = 0; x < numPlatforms;x++)
	{
		platSelected[x] = false;
		platforms[x].setRenderer(render);
		inputFile >> shape;
		if(shape == "quad")
		{
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

	inputFile.close();

	return true;
}

void Map::exportMapFile(Uint32 timeStamp)
{
	std::ostringstream stringStream;
	stringStream << timeStamp;

	ofstream outFile;
	outFile.open("maps/Map_" + stringStream.str() + ".txt");

	outFile << numPlatforms << "\n";

	for(int x = 0; x < numPlatforms; x++)
	{
		outFile << "quad ";
		outFile << platCoords[x*2] << " ";
		outFile << platCoords[x*2+1] << " ";
		outFile << platforms[x].getWidth() << " ";
		outFile << platforms[x].getHeight() << "\n";
		outFile << platforms[x].getFilePath() << "\n";
	}

	outFile.close();
	cout << "Map file saved\n";
}

void Map::unfocus()
{
	for(int x = 0; x < numPlatforms; x++)
	{
		platSelected[x] = false;
		platforms[x].setColor(0xFF,0xFF,0xFF);
	}
}

void Map::renderMap()
{
	for(int x = 0; x < numPlatforms; x++)
	{
		platforms[x].render(platCoords[x*2] - camera.getCamX(), platCoords[x*2+1]- camera.getCamY());
	}
}

void Map::updateMap()
{
	
}

void Map::mapEditorUpdate(InputClass input)
{
	//move camera with wasd
	if(input.getKeyDown() == SDLK_w)
	{
		camera.Update_Camera(camera.getCamX(), camera.getCamY() - 1);
	}
	if(input.getKeyDown() == SDLK_s)
	{
		camera.Update_Camera(camera.getCamX(), camera.getCamY() + 1);
	}
	if(input.getKeyDown() == SDLK_a)
	{
		camera.Update_Camera(camera.getCamX() - 1, camera.getCamY());
	}
	if(input.getKeyDown() == SDLK_d)
	{
		camera.Update_Camera(camera.getCamX() + 1, camera.getCamY() - 1);
	}

	//export current map with space key
	if(input.getKeyDown() == SDLK_SPACE)
	{
		Uint32 timeStamp = input.getEvent().key.timestamp;
		exportMapFile(timeStamp);
	}

	//move currently selected platforms with arrow keys
	if(input.getKeyDown() == SDLK_UP)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2+1]--;
			}
		}
	}
	if(input.getKeyDown() == SDLK_DOWN)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2+1]++;
			}
		}
	}
	if(input.getKeyDown() == SDLK_RIGHT)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2]++;
			}
		}
	}
	if(input.getKeyDown() == SDLK_LEFT)
	{
		for(int x = 0; x < numPlatforms; x++)
		{
			if(platSelected[x])
			{
				platCoords[x*2]--;
			}
		}
	}

	//add new platform with p key
	if(input.getKeyDown() == SDLK_p)
	{
		platforms[numPlatforms].setRenderer(render);
		platforms[numPlatforms].loadTexture("img/shapes/WhiteSquare.png");
		platforms[numPlatforms].setWidth(100);
		platforms[numPlatforms].setHeight(100);
		platSelected[numPlatforms] = false;
		platCoords[numPlatforms*2] = input.getMouseX();
		platCoords[numPlatforms*2+1] = input.getMouseY();
		numPlatforms++;
	}

	//remove platform with r key, mouse must be over platform
	if(input.getKeyDown() == SDLK_r)
	{
		for(int x = 1; x < numPlatforms; x++)
		{
			if(input.getMouseX() + camera.getCamX() >= platCoords[x*2] &&
				input.getMouseX() + camera.getCamX() <= platCoords[x*2] + platforms[x].getWidth() &&
				input.getMouseY() + camera.getCamY() >= platCoords[x*2+1] &&
				input.getMouseY() + camera.getCamY() <= platCoords[x*2+1] + platforms[x].getHeight())
			{
				for(int y = x; y < numPlatforms; y++)
				{
					platforms[y] = platforms[y+1];
					platSelected[y] = platSelected[y+1];
					platCoords[y*2] = platCoords[(y+1)*2];
					platCoords[y*2+1] = platCoords[(y+1)*2+1];
				}
				numPlatforms--;
				x--;
			}
		}
	}

	//select platforms with left mouse button
	if(input.getMouseButton(1))
	{
		for(int x = 1; x < numPlatforms; x++)
		{
			if(input.getMouseX() + camera.getCamX() >= platCoords[x*2] &&
				input.getMouseX() + camera.getCamX() <= platCoords[x*2] + platforms[x].getWidth() &&
				input.getMouseY() + camera.getCamY() >= platCoords[x*2+1] &&
				input.getMouseY() + camera.getCamY() <= platCoords[x*2+1] + platforms[x].getHeight())
			{
				platSelected[x] = true;
				platforms[x].setColor(0x77,0x77,0x77);
			}
		}
	}

	//deselect platforms with right mouse button
	if(input.getMouseButton(3))
	{
		for(int x = 1; x < numPlatforms; x++)
		{
			if(input.getMouseX() + camera.getCamX() >= platCoords[x*2] &&
				input.getMouseX() + camera.getCamX() <= platCoords[x*2] + platforms[x].getWidth() &&
				input.getMouseY() + camera.getCamY() >= platCoords[x*2+1] &&
				input.getMouseY() + camera.getCamY() <= platCoords[x*2+1] + platforms[x].getHeight())
			{
				platSelected[x] = false;
				platforms[x].setColor(0xFF,0xFF,0xFF);
			}
		}
	}
}
#endif