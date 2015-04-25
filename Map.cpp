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
	movePlatform = false;
	anchorPointsShown = false;
	moveStep = 1;
	cState = Testing;
	for(int x = 0; x < 4; x++)
	{
		anchorPointSelected[x] = false;
	}
	SDL_StopTextInput();
}

Map::~Map()
{
	for(int x = 0; x < numPlatforms; x++)
	{
		platforms[x].free();
	}

	for(int x = 0; x < 10; x++)
	{
		rightClickMenuText[x].free();
	}

	cursorTextTexture.free();
}

bool Map::parseMapFile(std::string filePath, SDL_Renderer* r)
{
	render = r;

	ifstream inputFile;

	filePath = "../resources/maps/" + filePath + ".txt";

	inputFile.open(filePath);

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

	cursorTextTexture.setRenderer(render);
	cursorTextTexture.setFont("calibri", 12);
	cursorTextTexture.loadTextRender("   Testing", textColor);

	for(int x = 0; x < 4; x++)
	{
		anchorPoints[x].setRenderer(render);
		anchorPoints[x].loadTexture("img/shapes/WhiteSquare.png");
		anchorPoints[x].setColor(0x77, 0x77, 0x77);
	}

	inputFile.close();

	return true;
}

void Map::exportMapFile(Uint32 timeStamp)
{
	std::ostringstream stringStream;
	stringStream << timeStamp;

	ofstream outFile;
	outFile.open("../resources/maps/Map_" + stringStream.str() + ".txt");

	outFile << "background " << bgX << " " << bgY << " ";
	outFile << backgroundTexture.getWidth() << " ";
	outFile << backgroundTexture.getHeight() << "\n";
	outFile << backgroundTexture.getFilePath() << "\n";

	outFile << "platforms " << numPlatforms << "\n";

	for(int x = 0; x < numPlatforms; x++)
	{
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

	rightClickMenuShown = false;

	movePlatform = false;

	anchorPointsShown = false;
	for(int x = 0; x < 4; x++)
	{
		anchorPointSelected[x] = false;
	}

	destroyPlatMenu();

	if(SDL_IsTextInputActive())
	{
		SDL_StopTextInput();
	}
}

void Map::renderMap()
{
	if(backgroundTexture.getFilePath() != "")
	{
		backgroundTexture.render(bgX - camera.getCamX(), bgY - camera.getCamY());
	}

	for(int x = 0; x < numPlatforms; x++)
	{
		platforms[x].render(platCoords[x*2] - camera.getCamX(), platCoords[x*2+1] - camera.getCamY());
	}
		
	if(rightClickMenuShown)
	{
		displayPlatMenu();
	}

	if(anchorPointsShown)
	{
		displayAnchorPoints();
	}

	cursorTextTexture.render(cursorX, cursorY);
}

void Map::createPlatMenu(int plat, int x, int y)
{
	x += camera.getCamX();
	y += camera.getCamY();
	
	int index = 0;
	std::stringstream ss;
	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Texture File", textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender(platforms[plat].getFilePath(), textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("X Coordinate", textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platCoords[plat*2];
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	ss.str(std::string());
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Y Coordinate", textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platCoords[plat*2+1];
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	ss.str(std::string());
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Width", textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platforms[plat].getWidth();
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	ss.str(std::string());
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	rightClickMenuText[index].loadTextRender("Height", textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
	y += rightClickMenuText[index].getHeight();
	index++;

	rightClickMenuText[index].setRenderer(render);
	rightClickMenuText[index].setFont("calibri", 20);
	ss << platforms[plat].getHeight();
	rightClickMenuText[index].loadTextRender(ss.str(), textColor);
	menuChoiceRects[index] = {x, y, rightClickMenuText[index].getWidth(), rightClickMenuText[index].getHeight()};
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
		rightClickMenuText[x].render(menuChoiceRects[x].x - camera.getCamX(), menuChoiceRects[x].y - camera.getCamY());
	}
}

void Map::destroyAnchorPoints()
{
	for(int x = 0; x < 4; x++)
	{
		anchorPoints[x].free();
	}
}

void Map::displayAnchorPoints()
{
	for(int x = 0; x < numPlatforms; x++)
	{
		if(platSelected[x])
		{
			anchorPoints[0].render(platCoords[x*2] - anchorPoints[0].getWidth() - camera.getCamX(), platCoords[x*2+1] - anchorPoints[0].getHeight() - camera.getCamY());
			anchorPoints[1].render(platCoords[x*2] + platforms[x].getWidth() - camera.getCamX(), platCoords[x*2+1] - anchorPoints[1].getHeight() - camera.getCamY());
			anchorPoints[2].render(platCoords[x*2] - anchorPoints[2].getWidth() - camera.getCamX(), platCoords[x*2+1] + platforms[x].getHeight() - camera.getCamY());
			anchorPoints[3].render(platCoords[x*2] + platforms[x].getWidth() - camera.getCamX(), platCoords[x*2+1] + platforms[x].getHeight() - camera.getCamY());
		}
	}
}

/**************************************

Keyboard input processing

***************************************/

void Map::processKeyboard(InputClass input, InputClass prevInput)
{
	switch(cState)
	{
		//Cursor state is Testing
		case Testing :
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
				platforms[numPlatforms].loadTexture("img/shapes/OrangeSquare.png");
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
				for(int x = numPlatforms - 1; x >= 0; x--)
				{
					if(mouseOverRect(input, {platCoords[x*2],platCoords[x*2+1],platforms[x].getWidth(),platforms[x].getHeight()}))
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
						break;
					}
				}
			}
		break;
		//Cursor State is Select
		case Select :
			
		break;
		//Cursor state is Info
		case Info :
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
					switch(menuIndex)
					{
						case 0 : 
						for(int x = 0; x < numPlatforms; x++)
						{
							if(platSelected[x])
							{
								platSelected[x] = false;
								string s = platforms[x].getFilePath();
								int w = platforms[x].getWidth();
								int h = platforms[x].getHeight();
								if(!platforms[x].loadTexture(keyboardInput))
								{
									platforms[x].loadTexture(s);
								}
								platforms[x].setWidth(w);
								platforms[x].setHeight(h);
								SDL_StopTextInput();
							}
						}
						break;
						case 1 : 
						if(atoi(keyboardInput.c_str()) != 0)
						{
							for(int x = 0; x < numPlatforms; x++)
							{
								if(platSelected[x])
								{
									platSelected[x] = false;
									platCoords[x*2] = atoi(keyboardInput.c_str());
									SDL_StopTextInput();
								}
							}
						}
						break;
						case 2 :
						if(atoi(keyboardInput.c_str()) != 0)
						{
							for(int x = 0; x < numPlatforms; x++)
							{
								if(platSelected[x])
								{
									platSelected[x] = false;
									platCoords[x*2+1] = atoi(keyboardInput.c_str());
									SDL_StopTextInput();
								}
							}
						}
						break;
						case 3 : 
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
						break;
						case 4 :
						if(atoi(keyboardInput.c_str()) != 0)
						{
							for(int x = 0; x < numPlatforms; x++)
							{
								if(platSelected[x])
								{
									platSelected[x] = false;
									platforms[x].setHeight(atoi(keyboardInput.c_str()));
									SDL_StopTextInput();
								}
							}
						}
						break;
					}
				}
			}

			if(input.getEvent().type == SDL_TEXTINPUT)
			{
				keyboardInput += input.getEvent().text.text;
			}
		break; 
	}
}

/********************************************************

Mouse input processing

********************************************************/

void Map::processMouse(InputClass input, InputClass prevInput)
{
	leftClickAction(input, prevInput);
	rightClickAction(input, prevInput);
}


///////////// Right click processing //////////////////////////

void Map::rightClickAction(InputClass input, InputClass prevInput)
{
	if(input.getMouseButton(3))
	{
		if(cState == Testing)
		{
			for(int x = numPlatforms - 1; x >= 0; x--)
			{
				if(mouseOverRect(input, {platCoords[x*2],platCoords[x*2+1],platforms[x].getWidth(),platforms[x].getHeight()}))
				{
					platSelected[x] = false;
					platforms[x].setColor(0xFF,0xFF,0xFF);
					break;
				}
			}
		}
		else
		if(cState == Select)
		{
			for(int x = numPlatforms - 1; x >= 0; x--)
			{
				if(mouseOverRect(input, {platCoords[x*2],platCoords[x*2+1],platforms[x].getWidth(),platforms[x].getHeight()}))
				{
					if(!platSelected[x])
					{
						unfocus();
						platSelected[x] = true;
						anchorPointsShown = true;
						break;
					}
				}
			}
		}
		else
		if(cState == Info)
		{
			if(!rightClickMenuShown)
			{
				for(int x = numPlatforms - 1; x >= 0; x--)
				{
					if(mouseOverRect(input, {platCoords[x*2],platCoords[x*2+1],platforms[x].getWidth(),platforms[x].getHeight()}))
					{
						unfocus();
						platSelected[x] = true;
						menuX = input.getMouseX();
						menuY = input.getMouseY();
						rightClickMenuShown = true;
						createPlatMenu(x, input.getMouseX(), input.getMouseY());
						break;
					}
				}
			}
		}
	}
}

////////////// Left click processing ///////////////////////////

void Map::leftClickAction(InputClass input, InputClass prevInput)
{
	if(input.getMouseButton(1))
	{
		if(cState == Testing)
		{
			//select platforms with left mouse button
			for(int x = numPlatforms - 1; x >= 0; x--)
			{
				if(mouseOverRect(input, {platCoords[x*2],platCoords[x*2+1],platforms[x].getWidth(),platforms[x].getHeight()}))
				{
					platSelected[x] = true;
					platforms[x].setColor(0x77,0x77,0x77);
					break;
				}
			}
		}
		else
		if(cState == Select)
		{
			if(anchorPointsShown)
			{
				bool runLoop = true;

				for(int x = 0; x < 4; x++)
				{
					if(anchorPointSelected[x])
					{
						for(int y = 0; y < numPlatforms; y++)
						{
							if(platSelected[y])
							{
								runLoop = false;
								switch(x)
								{
									case 0 :
										platforms[y].setWidth(platforms[y].getWidth() + ((platCoords[y*2] - camera.getCamX()) - input.getMouseX() - anchorPoints[0].getWidth()/2));
										platforms[y].setHeight(platforms[y].getHeight() + ((platCoords[y*2+1] - camera.getCamY()) - input.getMouseY() - anchorPoints[0].getWidth()/2));
										platCoords[y*2] = input.getMouseX() + anchorPoints[0].getWidth()/2 + camera.getCamX();
										platCoords[y*2+1] = input.getMouseY() + anchorPoints[0].getHeight()/2 + camera.getCamY();
										break;
									case 1 :
										platforms[y].setWidth(platforms[y].getWidth() + (input.getMouseX() - anchorPoints[3].getWidth()/2) - (platCoords[y*2] + platforms[y].getWidth() - camera.getCamX()));
										platforms[y].setHeight(platforms[y].getHeight() + ((platCoords[y*2+1] - camera.getCamY()) - input.getMouseY() - anchorPoints[0].getWidth()/2));
										platCoords[y*2+1] = input.getMouseY() + anchorPoints[0].getHeight()/2 + camera.getCamY();
										break;
									case 2 :
										platforms[y].setHeight(platforms[y].getHeight() + (input.getMouseY() - anchorPoints[3].getWidth()/2) - (platCoords[y*2+1] + platforms[y].getHeight() - camera.getCamY()));
										platforms[y].setWidth(platforms[y].getWidth() + ((platCoords[y*2] - camera.getCamX()) - input.getMouseX() - anchorPoints[0].getWidth()/2));
										platCoords[y*2] = input.getMouseX() + anchorPoints[0].getWidth()/2 + camera.getCamX();
										break;
									case 3 :
										platforms[y].setWidth(platforms[y].getWidth() + (input.getMouseX() - anchorPoints[3].getWidth()/2) - (platCoords[y*2] + platforms[y].getWidth() - camera.getCamX()));
										platforms[y].setHeight(platforms[y].getHeight() + (input.getMouseY() - anchorPoints[3].getWidth()/2) - (platCoords[y*2+1] + platforms[y].getHeight() - camera.getCamY()));
										break;
								}
								break;
								x = 4;
							}
						}
					}
				}

				if(runLoop)
				{
					for(int x = numPlatforms - 1; x >= 0; x--)
					{
						if(platSelected[x])
						{
							if(mouseOverRect(input,
								{platCoords[x*2] - anchorPoints[0].getWidth(),
								platCoords[x*2+1] - anchorPoints[0].getHeight(),
								anchorPoints[0].getWidth(),
								anchorPoints[0].getHeight()}))
							{
								anchorPointSelected[0] = true;
								break;
							}
							if(mouseOverRect(input,
								{platCoords[x*2] + platforms[x].getWidth(),
								platCoords[x*2+1] - anchorPoints[1].getHeight(),
								anchorPoints[1].getWidth(),
								anchorPoints[1].getHeight()}))
							{
								anchorPointSelected[1] = true;
								break;
							}
							if(mouseOverRect(input,
								{platCoords[x*2] - anchorPoints[2].getWidth(),
								platCoords[x*2+1] + platforms[x].getHeight(),
								anchorPoints[2].getWidth(),
								anchorPoints[2].getHeight()}))
							{
								anchorPointSelected[2] = true;
								break;
							}
							if(mouseOverRect(input,
								{platCoords[x*2] + platforms[x].getWidth(),
								platCoords[x*2+1] + platforms[x].getHeight(),
								anchorPoints[3].getWidth(),
								anchorPoints[3].getHeight()}))
							{
								anchorPointSelected[3] = true;
								break;
							}
						}
					}
				}
			}
			else
			{
				for(int x = numPlatforms - 1; x >= 0; x--)
				{
					if(movePlatform)
					{
						if(platSelected[x])
						{
							platCoords[x*2] = input.getMouseX() - platforms[x].getWidth()/2 + camera.getCamX();
							platCoords[x*2+1] = input.getMouseY() - platforms[x].getHeight()/2 + camera.getCamY();
						}
					}
					else
					{
						if(mouseOverRect(input, {platCoords[x*2],platCoords[x*2+1],platforms[x].getWidth(),platforms[x].getHeight()}))
						{
							platSelected[x] = true;
							movePlatform = true;
							break;
						}
					}
				}
			}
		}
		else
		if(cState == Info)
		{
			if(rightClickMenuShown)
			{
				bool itemSelected = false;
				for(int x = 0; x < 10; x++)
				{
					if(mouseOverRect(input, menuChoiceRects[x]))
					{
						if(SDL_IsTextInputActive())
						{
							SDL_StopTextInput();
						}
						menuIndex = x/2;
						printf("Menu item %d chosen\n", menuIndex);
						keyboardInput = "";
						SDL_StartTextInput();
						itemSelected = true;
						break;
					}
				}
				if(!itemSelected)
				{
					if(SDL_IsTextInputActive())
					{
						SDL_StopTextInput();
					}
					rightClickMenuShown = false;
					destroyPlatMenu();
				}
			}
		}
	}
	if(!input.getMouseButton(1))
	{
		if(cState == Select)
		{
			if(!anchorPointsShown)
			{
				unfocus();
			}
			else
			{
				for(int x = 0; x < 4; x++)
				{
					anchorPointSelected[x] = false;
				}
			}
		}
	}
}

void Map::mapEditorUpdate(InputClass input, InputClass prevInput)
{
	if(input.getKeyDown() == SDLK_ESCAPE)
	{
		unfocus();
	}

	if(!SDL_IsTextInputActive())
	{
		switch(input.getKeyDown())
		{
			case SDLK_0 : 
				unfocus();
				cState = Testing;
				cursorTextTexture.loadTextRender("   Testing", textColor);
				break;
			case SDLK_1 :
				unfocus();
				cState = Select;
				cursorTextTexture.loadTextRender("   Select", textColor);
				break;
			case SDLK_2 :
				unfocus();
				cState = Info;
				cursorTextTexture.loadTextRender("   Info", textColor);
				break;
		}
	}

	if(input.getMouseWheel() > 0  || input.getKeyDown() == SDLK_LEFTBRACKET)
	{
		textColor = {0xFF,0xFF,0xFF,0xFF};
		cursorTextTexture.setColor(0xFF, 0xFF, 0xFF);
	}
	if(input.getMouseWheel() < 0 || input.getKeyDown() == SDLK_RIGHTBRACKET)
	{
		textColor = {0,0,0,0xFF};
		cursorTextTexture.setColor(0, 0, 0);
	}

	cursorX = input.getMouseX();
	cursorY = input.getMouseY();
	
	processKeyboard(input, prevInput);

	processMouse(input, prevInput);
}

bool Map::mouseOverRect(InputClass input, SDL_Rect rect)
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