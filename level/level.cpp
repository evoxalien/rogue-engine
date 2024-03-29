//Level cpp file
#include "level.h"

Level::Level(std::string level_Path)
{
	(*this).level_File.open(level_Path);
	if((*this).level_File)
	{
		{
			std::string temporary_String;
			float temporary_Float;

			(*this).level_File >> temporary_String;	//"background"
			(*this).level_File >> temporary_Float;	//bgX
			(*this).level_File >> temporary_Float;	//bgY
			(*this).level_File >> temporary_Float;	//w
			(*this).level_File >> temporary_Float;	//h
			(*this).level_File >> temporary_String;	//background image file
			(*this).level_File >> temporary_String;	//"platforms"
		}

		(*this).level_File >> (*this).number_Of_Objects_In_Level;

		if((*this).number_Of_Objects_In_Level > Level::maximum_Number_Of_Objects)
		{
			std::cerr << "The number of Objects requested to generate (" << number_Of_Objects_In_Level << ") exceeds the maximum number of Objects available for a level (" << Level::maximum_Number_Of_Objects << "); " << Level::maximum_Number_Of_Objects << " Objects will be created." << std::endl;
			(*this).number_Of_Objects_In_Level = Level::maximum_Number_Of_Objects;
		}

		float temporary_X_Position = 0;
		float temporary_Y_Position = 0;
		float temporary_Angle_In_Radians = 0;
		int temporary_Body_Type = 2;
		bool temporary_Check_For_Dynamic_Tunneling = false;
		bool temporary_Use_Fixed_Rotation = false;
		float temporary_Linear_Damping = 0;
		float temporary_Angular_Damping = 0;
		float temporary_Gravity_Scale = 1;
		bool temporary_Allow_Physics_Sleep = false;
		bool temporary_Initialize_Awake = true;
		bool temporary_Initialize_Active = true;
		float temporary_Density = 0;
		float temporary_Friction = 0;
		float temporary_Restitution = 0;
		uint16 temporary_Exists_In_Layers = 1;
		uint16 temporary_Collides_With_Layers = 1;
		int temporary_Group_Index = 0;
		float temporary_X_Length = 1;
		float temporary_Y_Length = 1;
		float temporary_X_Velocity = 0;
		float temporary_Y_Velocity = 0;
		std::string temporary_String;

		for(int i = 0; i < (*this).number_Of_Objects_In_Level; i++)
		{
			(*this).level_File >> temporary_X_Position;
			(*this).level_File >> temporary_Y_Position;
			(*this).level_File >> temporary_Angle_In_Radians;
			(*this).level_File >> temporary_Body_Type;
			(*this).level_File >> temporary_Check_For_Dynamic_Tunneling;
			(*this).level_File >> temporary_Use_Fixed_Rotation;
			(*this).level_File >> temporary_Linear_Damping;
			(*this).level_File >> temporary_Angular_Damping;
			(*this).level_File >> temporary_Gravity_Scale;
			(*this).level_File >> temporary_Allow_Physics_Sleep;
			(*this).level_File >> temporary_Initialize_Awake;
			(*this).level_File >> temporary_Initialize_Active;
			(*this).level_File >> temporary_Density;
			(*this).level_File >> temporary_Friction;
			(*this).level_File >> temporary_Restitution;
			(*this).level_File >> temporary_Exists_In_Layers;
			(*this).level_File >> temporary_Collides_With_Layers;
			(*this).level_File >> temporary_Group_Index;
			(*this).level_File >> temporary_X_Length;
			(*this).level_File >> temporary_Y_Length;
			(*this).level_File >> temporary_X_Velocity;
			(*this).level_File >> temporary_Y_Velocity;
			(*this).level_File >> temporary_String;							//Reads in the image path but does nothing with it at the moment, can be used for Animation later
			(*this).level_Objects_Array[i] = Object(temporary_X_Position, temporary_Y_Position, temporary_Angle_In_Radians, temporary_Body_Type, temporary_Check_For_Dynamic_Tunneling, temporary_Use_Fixed_Rotation, temporary_Linear_Damping, temporary_Angular_Damping, temporary_Gravity_Scale, temporary_Allow_Physics_Sleep, temporary_Initialize_Awake, temporary_Initialize_Active, temporary_Density, temporary_Friction, temporary_Restitution, temporary_Exists_In_Layers, temporary_Collides_With_Layers, temporary_Group_Index, (temporary_X_Length / 2.0), (temporary_Y_Length / 2.0), temporary_X_Velocity, temporary_Y_Velocity, temporary_String);
			//(*this).level_Objects_Array[i] = temporary_Object;
		}
		(*this).level_File.close();
	}
	else
	{
		std::cerr << "File failed to open." << std::endl;
	}
}

void Level::update_All()
{
	Object::step_Box2D_World();
	for(std::uint16_t i = 0; i < (*this).number_Of_Objects_In_Level; i++)
	{
		(*this).level_Objects_Array[i].update();
	}
}

void Level::render_All()
{
	for(std::uint16_t i = 0; i < (*this).number_Of_Objects_In_Level; i++)
	{
		(*this).level_Objects_Array[i].render();
	}
}

void Level::load_Level(std::string file_Path)
{
	for(std::uint16_t i = 0; i < (*this).number_Of_Objects_In_Level; i++)
	{
		Object::box2D_World.DestroyBody((*this).level_Objects_Array[i].physics);
		(*this).level_Objects_Array[i] = Object();
	}

	(*this).level_File.open(file_Path);
	if((*this).level_File)
	{
		{
			std::string temporary_String;
			float temporary_Float;

			(*this).level_File >> temporary_String;	//"background"
			(*this).level_File >> temporary_Float;	//bgX
			(*this).level_File >> temporary_Float;	//bgY
			(*this).level_File >> temporary_Float;	//w
			(*this).level_File >> temporary_Float;	//h
			(*this).level_File >> temporary_String;	//background image file
			(*this).level_File >> temporary_String;	//"platforms"
		}

		(*this).level_File >> (*this).number_Of_Objects_In_Level;

		if((*this).number_Of_Objects_In_Level > Level::maximum_Number_Of_Objects)
		{
			std::cerr << "The number of Objects requested to generate (" << number_Of_Objects_In_Level << ") exceeds the maximum number of Objects available for a level (" << Level::maximum_Number_Of_Objects << "); " << Level::maximum_Number_Of_Objects << " Objects will be created." << std::endl;
			(*this).number_Of_Objects_In_Level = Level::maximum_Number_Of_Objects;
		}

		float temporary_X_Position = 0;
		float temporary_Y_Position = 0;
		float temporary_Angle_In_Radians = 0;
		int temporary_Body_Type = 2;
		bool temporary_Check_For_Dynamic_Tunneling = false;
		bool temporary_Use_Fixed_Rotation = false;
		float temporary_Linear_Damping = 0;
		float temporary_Angular_Damping = 0;
		float temporary_Gravity_Scale = 1;
		bool temporary_Allow_Physics_Sleep = false;
		bool temporary_Initialize_Awake = true;
		bool temporary_Initialize_Active = true;
		float temporary_Density = 0;
		float temporary_Friction = 0;
		float temporary_Restitution = 0;
		uint16 temporary_Exists_In_Layers = 1;
		uint16 temporary_Collides_With_Layers = 1;
		int temporary_Group_Index = 0;
		float temporary_X_Length = 1;
		float temporary_Y_Length = 1;
		float temporary_X_Velocity = 0;
		float temporary_Y_Velocity = 0;
		std::string temporary_String;

		for(int i = 0; i < (*this).number_Of_Objects_In_Level; i++)
		{
			(*this).level_File >> temporary_X_Position;
			(*this).level_File >> temporary_Y_Position;
			(*this).level_File >> temporary_Angle_In_Radians;
			(*this).level_File >> temporary_Body_Type;
			(*this).level_File >> temporary_Check_For_Dynamic_Tunneling;
			(*this).level_File >> temporary_Use_Fixed_Rotation;
			(*this).level_File >> temporary_Linear_Damping;
			(*this).level_File >> temporary_Angular_Damping;
			(*this).level_File >> temporary_Gravity_Scale;
			(*this).level_File >> temporary_Allow_Physics_Sleep;
			(*this).level_File >> temporary_Initialize_Awake;
			(*this).level_File >> temporary_Initialize_Active;
			(*this).level_File >> temporary_Density;
			(*this).level_File >> temporary_Friction;
			(*this).level_File >> temporary_Restitution;
			(*this).level_File >> temporary_Exists_In_Layers;
			(*this).level_File >> temporary_Collides_With_Layers;
			(*this).level_File >> temporary_Group_Index;
			(*this).level_File >> temporary_X_Length;
			(*this).level_File >> temporary_Y_Length;
			(*this).level_File >> temporary_X_Velocity;
			(*this).level_File >> temporary_Y_Velocity;
			(*this).level_File >> temporary_String;							//Reads in the image path but does nothing with it at the moment, can be used for Animation later
			(*this).level_Objects_Array[i] = Object(temporary_X_Position, temporary_Y_Position, temporary_Angle_In_Radians, temporary_Body_Type, temporary_Check_For_Dynamic_Tunneling, temporary_Use_Fixed_Rotation, temporary_Linear_Damping, temporary_Angular_Damping, temporary_Gravity_Scale, temporary_Allow_Physics_Sleep, temporary_Initialize_Awake, temporary_Initialize_Active, temporary_Density, temporary_Friction, temporary_Restitution, temporary_Exists_In_Layers, temporary_Collides_With_Layers, temporary_Group_Index, (temporary_X_Length / 2.0), (temporary_Y_Length / 2.0), temporary_X_Velocity, temporary_Y_Velocity, temporary_String);
			//(*this).level_Objects_Array[i] = temporary_Object;
		}
		(*this).level_File.close();
	}
	else
	{
		std::cerr << "File failed to open; opening default empty level." << std::endl;
	}
}

void Level::setPosition(int index,int x, int y)
{
   if(index >= 0 && index < (*this).number_Of_Objects_In_Level)
      (*this).level_Objects_Array[index].setPosition(x,y);
}

b2Vec2 Level::getPosition(int index)
{
   b2Vec2 position(0.0, 0.0);
   
   if(index >= 0 && index < (*this).number_Of_Objects_In_Level)
      return (*this).level_Objects_Array[index].getPosition();
   else
      return position;
}
int Level::getX(int index)
{
   if(index >= 0 && index < (*this).number_Of_Objects_In_Level)
      return (*this).level_Objects_Array[index].getX();
   else
      return -999;
}

int Level::getY(int index)
{
   if(index >= 0 && index < (*this).number_Of_Objects_In_Level)
      return (*this).level_Objects_Array[index].getY();
   else
      return -999;
}

int Level::getObjectCount()
{
   return (*this).number_Of_Objects_In_Level;
}