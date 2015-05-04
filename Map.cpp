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
	textColor = {0xFF, 0xFF, 0xFF, 0xFF};
	inputTextColor = {0, 0, 0, 0xFF};
	camera.setBoundRect(0,0,5000,5000);
	render = NULL;
	drawText = false;
	movePlatform = false;
	anchorPointsShown = false;
	mouseOverMenuEntry = false;
	moveStep = 1;
	cState = Testing;
	mState = Properties;
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

	menuSelectionTexture.free();

	currentInputStringTexture.free();
	
	cursorTextTexture.free();
}

bool Map::parseMapFile(std::string filePath, SDL_Renderer* r)
{
	render = r;

	ifstream inputFile;

	filePath = filePath + ".txt";
	std::string filePath2 = "../resources/maps/" + filePath;
	cout << filePath2 << endl;
	inputFile.open(filePath2);

	if(!inputFile)
		return false;

	string inputStr = "";
	string texturePath = "";
	int w = 0, h = 0;

	while(inputFile >> inputStr)
	{
//		if(inputStr == "background")
//		{
			backgroundTexture.setRenderer(render);

			inputFile >> bgX;
			inputFile >> bgY;
			inputFile >> w;
			inputFile >> h;
			inputFile >> texturePath;

			backgroundTexture.loadTexture(texturePath);
			backgroundTexture.setWidth(w);
			backgroundTexture.setHeight(h);
//		}
		inputFile >> inputStr;
//		if(inputStr == "platforms")
//		{
			inputFile >> numPlatforms;
			for(int x = 0; x < numPlatforms;x++)
			{
				platSelected[x] = false;
				platforms[x].setRenderer(render);

				inputFile >> platCoords[x*2];
				inputFile >> platCoords[x*2+1];
				{
					bool temporary_Boolean;
					int temporary_Integer;
					float temporary_Float;
					uint16 temporary_Unsigned_16bit_Integer;

					inputFile >> temporary_Float; //Initial Angle in Radians
					inputFile >> temporary_Integer; //Body type of the Object (0 for Static, 1 for Kinematic, 2 for Dynamic)
					inputFile >> temporary_Boolean; //Boolean for whether the Object should check for tunneling against Dynamic bodies, usually turned on for very fast objects such as bullets (0 only checks against Static and Kinematic bodies, 1 includes Dynamic bodies as well)
					inputFile >> temporary_Boolean; //Boolean for whether to use fixed rotation (0 uses rotations, 1 fixes rotation)
					inputFile >> temporary_Float; //Linear Damping slows Objects as they travel, not 100% sure how it affects movement, but I believe it's a constant force against the direction of movement so the Object eventually halts
					inputFile >> temporary_Float; //Angular Damping slows an Objects rotation, similar to Linear Damping but will cause the Object to stop spinning over time
					inputFile >> temporary_Float; //The Gravity Scale is a multiplier to determine how much force the Box2D World exerts on the Object
					inputFile >> temporary_Boolean; //Boolean for whether Physics Sleep is allowed; if it is on, the Object enters a low-maintenence state until collided with (0 is no sleep, 1 is sleep enabled)
					inputFile >> temporary_Boolean; //Boolean for whether the Object should enter into the World as 'Awake' or 'Asleep', see above (0 is Asleep, 1 is Awake)
					inputFile >> temporary_Boolean; //Boolean for whether the Object should enter int othe World as 'Active' or 'Inactive'; I can't recall for sure, but I believe Inactive will be treated as if it's not present until activated (0 is Inactive, 1 is Active)
					inputFile >> temporary_Float; //Density of the fixture that will be applied to the Object; higher densities will result in larger weights for the same size; I belive 0 should be avoided
					inputFile >> temporary_Float; //The Friction of the fixture that will be applied to the Object; higher frictions will result in a faster loss of momentum when Objects come in constant contact with the Object
					inputFile >> temporary_Float; //The Restitution of the fixture that will be applied to the Object; should generally be confined between 0 and 1- 0 will result in Objects sticking to one another, 1 will have them bounce apart with the energy conserved- most likely uses the lowest of the two in collisions
					inputFile >> temporary_Unsigned_16bit_Integer; //Layers the Object exists in- each bit of the 16 bit unsigned integer represents a layer; if the bit is 1, the Object exists in that layer, if 0, it does not
					inputFile >> temporary_Unsigned_16bit_Integer; //Layers the Object can collide with- each bit of the 16 bit unsigned integer represents a layer; if the bit is 1, the Object may potentially collide with another Object which exists in that layer
					inputFile >> temporary_Integer; //Group Index of the Object- if 0, Object will collide with all other Objects which share both the existing layers and colliding layers; if the value pair of colliding objects are different, the same rules will apply; 
													//if the pair is positive and the same, they will collide regardless of layers, and if the pair is negative and the same, they will never collide, regardless of layers
 				}
				inputFile >> w;
				inputFile >> h;

				float tempFloat;
				inputFile >> tempFloat;
				inputFile >> tempFloat;

				inputFile >> texturePath;
				platforms[x].loadTexture(texturePath);
				platforms[x].setWidth(w);
				platforms[x].setHeight(h);
			}
//		}
	}

	pMenu.setRenderer(render);
	pMenu.setMenuProperties("calibri", 20, textColor);

	cursorTextTexture.setRenderer(render);
	cursorTextTexture.setFont("calibri", 12);
	cursorTextTexture.loadTextRender("   Testing", textColor);

	for(int x = 0; x < 4; x++)
	{
		anchorPoints[x].setRenderer(render);
		anchorPoints[x].loadTexture("../resources/img/shapes/WhiteSquare.png");
		anchorPoints[x].setColor(0x77, 0x77, 0x77);
	}

	menuSelectionTexture.setRenderer(render);
	menuSelectionTexture.loadTexture("../resources/img/shapes/WhiteSquare.png");
	menuSelectionTexture.setColor(0x44, 0x44, 0x44);

	currentInputStringBackground.setRenderer(render);
	currentInputStringBackground.loadTexture("../resources/img/shapes/WhiteSquare.png");

	currentInputStringTexture.setRenderer(render);
	currentInputStringTexture.setFont("calibri", 20);

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
		outFile << "0 ";	//Initial Angle in Radians
		outFile << "2 ";	//Body type of the Object (0 for Static, 1 for Kinematic, 2 for Dynamic)
		outFile << "0 ";	//Boolean for whether the Object should check for tunneling against Dynamic bodies, usually turned on for very fast objects such as bullets (0 only checks against Static and Kinematic bodies, 1 includes Dynamic bodies as well)
		outFile << "0 ";	//Boolean for whether to use fixed rotation (0 uses rotations, 1 fixes rotation)
		outFile << "0 ";	//Linear Damping slows Objects as they travel, not 100% sure how it affects movement, but I believe it's a constant force against the direction of movement so the Object eventually halts
		outFile << "0 ";	//Angular Damping slows an Objects rotation, similar to Linear Damping but will cause the Object to stop spinning over time
		outFile << "1 ";	//The Gravity Scale is a multiplier to determine how much force the Box2D World exerts on the Object
		outFile << "0 ";	//Boolean for whether Physics Sleep is allowed; if it is on, the Object enters a low-maintenence state until collided with (0 is no sleep, 1 is sleep enabled)
		outFile << "1 ";	//Boolean for whether the Object should enter into the World as 'Awake' or 'Asleep', see above (0 is Asleep, 1 is Awake)
		outFile << "1 ";	//Boolean for whether the Object should enter int othe World as 'Active' or 'Inactive'; I can't recall for sure, but I believe Inactive will be treated as if it's not present until activated (0 is Inactive, 1 is Active)

		//outFile << number of fixtures;
		//for(/*number of fixtures the Object has*/)		//Will be implemented in the future when we have support for multiple fixtures
		//{
		outFile << "1 ";		//Density of the fixture that will be applied to the Object; higher densities will result in larger weights for the same size; I belive 0 should be avoided
		outFile << ".5 ";		//The Friction of the fixture that will be applied to the Object; higher frictions will result in a faster loss of momentum when Objects come in constant contact with the Object
		outFile << ".8 ";		//The Restitution of the fixture that will be applied to the Object; should generally be confined between 0 and 1- 0 will result in Objects sticking to one another, 1 will have them bounce apart with the energy conserved- most likely uses the lowest of the two in collisions
		outFile << "1 ";		//Layers the Object exists in- each bit of the 16 bit unsigned integer represents a layer; if the bit is 1, the Object exists in that layer, if 0, it does not
		outFile << "65535 ";	//Layers the Object can collide with- each bit of the 16 bit unsigned integer represents a layer; if the bit is 1, the Object may potentially collide with another Object which exists in that layer
		outFile << "0 ";		//Group Index of the Object- if 0, Object will collide with all other Objects which share both the existing layers and colliding layers; if the value pair of colliding objects are different, the same rules will apply; 
								//if the pair is positive and the same, they will collide regardless of layers, and if the pair is negative and the same, they will never collide, regardless of layers
		//outFile << shape of Object;
		outFile << (platforms[x].getWidth()) << " ";		//Will change in the future depending on the shape of the Object
		//cout << (platforms[x].getWidth()) << " " << (platforms[x].getWidth() /2) << endl;
		outFile << (platforms[x].getHeight()) << " ";	//Will change in the future depending on the shape of the Object
		//cout << (platforms[x].getHeight()) << " " << (platforms[x].getHeight() /2) << endl;
		outFile << "0 0\n";
		//}
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

	menuShown = false;

	movePlatform = false;

	mouseOverMenuEntry = false;

	anchorPointsShown = false;
	for(int x = 0; x < 4; x++)
	{
		anchorPointSelected[x] = false;
	}

	pMenu.destroyMenu();

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
		
	if(menuShown)
	{
		if(mouseOverMenuEntry)
		{
			menuSelectionTexture.render(menuSelectionRect.x - camera.getCamX(), menuSelectionRect.y - camera.getCamY(), menuSelectionRect.w, menuSelectionRect.h);
		}

		pMenu.displayMenu(camera.getCamX(), camera.getCamY());

		if(SDL_IsTextInputActive())
		{
			SDL_Rect tempRect;
			tempRect.x = pMenu.getValueX() - camera.getCamX();
			tempRect.y = menuSelectionRect.y - camera.getCamY();
			tempRect.w = (menuSelectionRect.x - camera.getCamX() + menuSelectionRect.w) - tempRect.x;
			tempRect.h = menuSelectionRect.h;

			currentInputStringBackground.render(tempRect.x, tempRect.y, tempRect.w, tempRect.h);

			currentInputStringTexture.render(tempRect.x, tempRect.y);
		}
	}

	if(anchorPointsShown)
	{
		displayAnchorPoints();
	}

	cursorTextTexture.render(cursorX, cursorY);
}

void Map::createMenu(int plat, int x, int y)
{

	x += camera.getCamX();
	y += camera.getCamY();

	
	pMenu.setLocation(x, y);
	
	std::stringstream ss;
	
	if(mState == Properties)
	{
		pMenu.addMenuEntry("Texture Properties", "");
		pMenu.addMenuEntry("Physics Properties", "");
	}
	else
	if(mState == TextureProps)
	{
		pMenu.addMenuEntry("Texture File", platforms[plat].getFilePath());

		ss << platCoords[plat*2];
		pMenu.addMenuEntry("X Coordinate", ss.str());
		ss.str(std::string());

		ss << platCoords[plat*2+1];
		pMenu.addMenuEntry("Y Coordinate", ss.str());
		ss.str(std::string());

		ss << platforms[plat].getWidth();
		pMenu.addMenuEntry("Width", ss.str());
		ss.str(std::string());

		ss << platforms[plat].getHeight();
		pMenu.addMenuEntry("Height", ss.str());
		ss.str(std::string());
	}
	else
	if(mState == PhysicsProps)
	{
		pMenu.addMenuEntry("Physics Stuff", "Bullshit");
		pMenu.addMenuEntry("Fucking", "Bullshit");
		pMenu.addMenuEntry("Long entry is long", "Such Bullshit");
	}
}

void Map::processMenu(InputClass input)
{
	if(mState == Properties)
	{
		if(input.getMouseButton(1))
		{
			for(int x = 0; x < pMenu.getNumEntries(); x++)
			{
				if(mouseOverRect(input, pMenu.getEntryRect(x)))
				{
					int platIndex = 0;
					
					for(int y = 0; y < numPlatforms; y++)
					{
						if(platSelected[y])
						{
							platIndex = y;
							break;
						}
					}

					pMenu.destroyMenu();
					switch(x)
					{
						case 0 :
							mState = TextureProps;
							break;
						case 1 :
							mState = PhysicsProps;
							break;
					}
					createMenu(platIndex, input.getMouseX(), input.getMouseY());

					break;
				}
			}
		}
	}
	else
	if(mState == TextureProps)
	{
		if(input.getKeyDown() == SDLK_RETURN)
		{
			switch(menuIndex)
			{
				case 0 : 
				for(int x = 0; x < numPlatforms; x++)
				{
					if(platSelected[x])
					{
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
						pMenu.destroyMenu();
						createMenu(x, pMenu.getMenuX(), pMenu.getMenuY());
						break;
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
							platCoords[x*2] = atoi(keyboardInput.c_str());
							SDL_StopTextInput();
							pMenu.destroyMenu();
							createMenu(x, pMenu.getMenuX(), pMenu.getMenuY());
							break;
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
							platCoords[x*2+1] = atoi(keyboardInput.c_str());
							SDL_StopTextInput();
							pMenu.destroyMenu();
							createMenu(x, pMenu.getMenuX(), pMenu.getMenuY());
							break;
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
							platforms[x].setWidth(atoi(keyboardInput.c_str()));
							SDL_StopTextInput();
							pMenu.destroyMenu();
							createMenu(x, pMenu.getMenuX(), pMenu.getMenuY());
							break;
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
							platforms[x].setHeight(atoi(keyboardInput.c_str()));
							SDL_StopTextInput();
							pMenu.destroyMenu();
							createMenu(x, pMenu.getMenuX(), pMenu.getMenuY());
							break;
						}
					}
				}
				break;
			}
			currentInputStringTexture.free();
		}
	}
	else
	if(mState == PhysicsProps)
	{

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
						currentInputStringTexture.loadTextRender(keyboardInput, inputTextColor);
					}
				}

				processMenu(input);

				if(input.getEvent().type == SDL_TEXTINPUT)
				{
					keyboardInput += input.getEvent().text.text;
					currentInputStringTexture.loadTextRender(keyboardInput, inputTextColor);
				}
			}
		break; 
	}
}

/********************************************************

Mouse input processing

********************************************************/

void Map::processMouse(InputClass input, InputClass prevInput)
{
	mouseOverAction(input);
	leftClickAction(input, prevInput);
	rightClickAction(input, prevInput);
}

void Map::mouseOverAction(InputClass input)
{
	if(cState == Info)
	{
		if(!SDL_IsTextInputActive())
		{
			if(menuShown)
			{
				for(int x = 0; x < pMenu.getNumEntries(); x++)
				{
					if(mouseOverRect(input, pMenu.getEntryRect(x)))
					{
						mouseOverMenuEntry = true;
						menuSelectionRect = pMenu.getEntryRect(x);
						break;
					}
				}
			}
		}
	}
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
			for(int x = numPlatforms - 1; x >= 0; x--)
			{
				if(mouseOverRect(input, {platCoords[x*2],platCoords[x*2+1],platforms[x].getWidth(),platforms[x].getHeight()}))
				{
					unfocus();
					mState = Properties;
					platSelected[x] = true;
					menuShown = true;
					createMenu(x, input.getMouseX(), input.getMouseY());
					break;
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
			if(mState == Properties && menuShown)
			{
				processMenu(input);
			}
			else
			if(menuShown)
			{	
				if(input.getMouseButton(1))
				{
					bool itemSelected = false;
					for(int x = 0; x < pMenu.getNumEntries(); x++)
					{
						if(mouseOverRect(input, pMenu.getEntryRect(x)))
						{
							if(SDL_IsTextInputActive())
							{
								SDL_StopTextInput();
							}
							menuIndex = x;
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
						menuShown = false;
					}
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
			case SDLK_1 : 
				unfocus();
				cState = Testing;
				cursorTextTexture.loadTextRender("   Testing", textColor);
				break;
			case SDLK_2 :
				unfocus();
				cState = Select;
				cursorTextTexture.loadTextRender("   Select", textColor);
				break;
			case SDLK_3 :
				unfocus();
				cState = Info;
				cursorTextTexture.loadTextRender("   Info", textColor);
				break;
			case SDLK_4 :
				unfocus();
				cState = Doors;
				cursorTextTexture.loadTextRender("   Doors", textColor);
				break;
		}
	}

	if(input.getMouseWheel() > 0  || input.getKeyDown() == SDLK_LEFTBRACKET)
	{
		textColor = {0xFF,0xFF,0xFF,0xFF};
		cursorTextTexture.setColor(0xFF, 0xFF, 0xFF);
		pMenu.setTextColor(textColor);
	}
	if(input.getMouseWheel() < 0 || input.getKeyDown() == SDLK_RIGHTBRACKET)
	{
		textColor = {0,0,0,0xFF};
		cursorTextTexture.setColor(0, 0, 0);
		pMenu.setTextColor(textColor);
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