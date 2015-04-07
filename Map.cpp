#ifndef MAP_CPP_
#define MAP_CPP_
#include "Map.h"
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

Map::Map()
{
	numPlatforms = 0;
	textColor = {0, 0, 0, 0xFF};
	camera.setBoundRect(0,0,5000,5000);
	render = NULL;
	drawText = false;
	moveStep = 1;
	cState = Testing;
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

	if(rightClickMenuText != NULL)
	{
		for(int x = 0; x < 10; x++)
		{
			rightClickMenuText[x].free();
		}
	}

}

bool Map::parseMapFile(std::string filePath, SDL_Renderer* r)
{
	render = r;

	textTexture.setRenderer(render);
	textTexture.setFont("calibri", 500);
	textTexture.loadTextRender("FUCK", textColor);
	
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
		platforms[x].render(platCoords[x*2] - camera.getCamX(), platCoords[x*2+1] - camera.getCamY());
	}
	if(drawText)
		textTexture.render(0,0);
	if(rightClickMenuShown)
		displayPlatMenu();
}

void Map::updateMap()
{
	
}

void Map::createPlatMenu(int plat)
{
	int index = 0;
	std::stringstream ss;
	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Texture File", textColor);
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender(platforms[plat].getFilePath(), textColor);
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("X Coordinate", textColor);
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platCoords[plat*2];
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	ss.str(std::string());
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Y Coordinate", textColor);
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platCoords[plat*2+1];
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	ss.str(std::string());
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Width", textColor);
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platforms[plat].getWidth();
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	ss.str(std::string());
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Height", textColor);
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platforms[plat].getHeight();
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	ss.str(std::string());
}

void Map::destroyPlatMenu()
{
	for(int x = 0; x < 10; x++)
	{
		rightClickMenuText[x].free();
	}
}

void Map::displayPlatMenu()
{
	for(int x = 0; x < 10; x++)
	{
		rightClickMenuText[x].render(menuX, menuY + x * 20);
	}
}

void Map::rightClickAction(InputClass input)
{
	if(input.getMouseButton(3))
	{
		if(!rightClickMenuShown)
		{
			int x = mouseOverPlat(input);
			if(x > 0)
			{
				menuX = input.getMouseX();
				menuY = input.getMouseY();
				rightClickMenuShown = true;
				createPlatMenu(x);
			}
		}
	}
	if(input.getMouseButton(1))
	{
		if(rightClickMenuShown)
		{
			rightClickMenuShown = false;
			destroyPlatMenu();
		}
	}
}

void Map::mapEditorUpdate(InputClass input)
{
	switch(input.getKeyDown())
	{
		case SDLK_0 : cState = Testing; break;
		case SDLK_1 : cState = Select; break;
		case SDLK_2 : cState = Info; break;
	}
	if(cState == Testing)
    {
		//FUCK
		if(input.getKeyDown() == SDLK_f)
		{
			drawText = !drawText;
		}
		//move camera with wasd
		if(input.getKeyDown() == SDLK_w)
		{
			camera.Update_Camera(camera.getCamX(), camera.getCamY() - moveStep);
		}
		if(input.getKeyDown() == SDLK_s)
		{
			camera.Update_Camera(camera.getCamX(), camera.getCamY() + moveStep);
		}
		if(input.getKeyDown() == SDLK_a)
		{
			camera.Update_Camera(camera.getCamX() - moveStep, camera.getCamY());
		}
		if(input.getKeyDown() == SDLK_d)
		{
			camera.Update_Camera(camera.getCamX() + moveStep, camera.getCamY());
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
					platCoords[x*2+1] -= moveStep;
				}
			}
		}
		if(input.getKeyDown() == SDLK_DOWN)
		{
			for(int x = 0; x < numPlatforms; x++)
			{
				if(platSelected[x])
				{
					platCoords[x*2+1] += moveStep;
				}
			}
		}
		if(input.getKeyDown() == SDLK_RIGHT)
		{
			for(int x = 0; x < numPlatforms; x++)
			{
				if(platSelected[x])
				{
					platCoords[x*2] += moveStep;
				}
			}
		}
		if(input.getKeyDown() == SDLK_LEFT)
		{
			for(int x = 0; x < numPlatforms; x++)
			{
				if(platSelected[x])
				{
					platCoords[x*2] -= moveStep;
				}
			}
		}

		//Change the move speed of platforms
			if(input.getKeyDown() == SDLK_MINUS)
		{ // Move things slower!!
			moveStep--;
			if(moveStep <= 0)
				moveStep = 1;
			cout << "Key - Pressed" << endl;
		}
		
		if(input.getKeyDown() == SDLK_EQUALS)
		{ //Move things faster!
			moveStep++;
			if(moveStep > 10)
				moveStep = 10;
			cout << "Key = Pressed" << endl;
		}

			//add new platform with p key
		if(input.getKeyDown() == SDLK_p && numPlatforms < PLATMAX)
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
			int x = mouseOverPlat(input);
			if(x != -1)
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

			//select platforms with left mouse button
		if(input.getMouseButton(1))
		{
			int x = mouseOverPlat(input);
			if(x != -1)
			{
				platSelected[x] = true;
				platforms[x].setColor(0x77,0x77,0x77);
			}
		}

			//deselect platforms with right mouse button
		if(input.getMouseButton(3))
		{
			int x = mouseOverPlat(input);
			if(x != -1)
			{
				int x = mouseOverPlat(input);
				if(x != -1)
				{
					platSelected[x] = false;
					platforms[x].setColor(0xFF,0xFF,0xFF);
				}
			}	
		}
	}
	if(cState == Select)
	{
		if(input.getMouseButton(3))
		{
			int x = mouseOverPlat(input);
			if(x != -1)
			{
				platSelected[x] = true;
				keyboardInput = "";
				SDL_StartTextInput();
			}
		}

		if(SDL_IsTextInputActive())
		{
			if(input.getKeyDown() == SDLK_BACKSPACE)
			{
				if(keyboardInput.length() > 0)
				{
					keyboardInput.pop_back();
				}
			}

			if(input.getKeyDown() == SDLK_RETURN)
			{
				if(atoi(keyboardInput.c_str()) != 0)
				{
					for(int x = 0; x < numPlatforms; x++)
					{
						if(platSelected[x])
						{
							platSelected[x] = false;
							platforms[x].setWidth(atoi(keyboardInput.c_str()));
							SDL_StopTextInput();
						}
					}
				}
			}
		}

		if(input.getEvent().type == SDL_TEXTINPUT)
		{
			keyboardInput += input.getEvent().text.text;
		}
	}
	if(cState == Info)
	{
		rightClickAction(input);
	}
}

int Map::mouseOverPlat(InputClass input)
{
	for(int x = numPlatforms - 1; x > 0; x--)
	{
		if(input.getMouseX() + camera.getCamX() >= platCoords[x*2] &&
			input.getMouseX() + camera.getCamX() <= platCoords[x*2] + platforms[x].getWidth() &&
			input.getMouseY() + camera.getCamY() >= platCoords[x*2+1] &&
			input.getMouseY() + camera.getCamY() <= platCoords[x*2+1] + platforms[x].getHeight())
		{
			return x;
		}
	}
	return -1;
}
#endif