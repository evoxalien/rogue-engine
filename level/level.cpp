//Level cpp file
#include "level.h"

Level::Level(std::string level_Path)
{
	(*this).level_File.open(level_Path);
	if((*this).level_File)
	{
		int number_Of_Objects = 0;
		(*this).level_File >> number_Of_Objects;

		if(number_Of_Objects > Level::maximum_Number_Of_Objects)
		{
			std::cerr << "The number of Objects requested to generate (" << number_Of_Objects << ") exceeds the maximum number of Objects available for a level (" << Level::maximum_Number_Of_Objects << "); " << Level::maximum_Number_Of_Objects << " Objects will be created." << std::endl;
			number_Of_Objects = Level::maximum_Number_Of_Objects;
		}

		float temporary_X_Position = 0;
		float temporary_Y_Position = 0;
		float temporary_Angle_In_Radians = 0;
		int temporary_Body_Type = 2;
		bool temporary_Check_For_Dynamic_Tunneling = false;
		bool temporary_Use_Fixed_Rotation = false;
		float temporary_Linear_Damping = 0;
		float temporary_Angular_Damping = 0;
		float temporary_Gravity_Scale = 0;
		bool temporary_Allow_Physics_Sleep = false;
		bool temporary_Initialize_Awake = true;
		bool temporary_Initialize_Active = true;
		float temporary_Density = 0;
		float temporary_Friction = 0;
		float temporary_Restitution = 0;
		uint16 temporary_Exists_In_Layers = 1;
		uint16 temporary_Collides_With_Layers = 1;
		int temporary_Group_Index = 0;
		float temporary_X_Half_Length = 1;
		float temporary_Y_Half_Length = 1;
		for(int i = 0; i < number_Of_Objects; i++)
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
			(*this).level_File >> temporary_X_Half_Length;
			(*this).level_File >> temporary_Y_Half_Length;
			(*this).level_Objects_Array[i] = Object(temporary_X_Position, temporary_Y_Position, temporary_Angle_In_Radians, temporary_Body_Type, temporary_Check_For_Dynamic_Tunneling, temporary_Use_Fixed_Rotation, temporary_Linear_Damping, temporary_Angular_Damping, temporary_Gravity_Scale, temporary_Allow_Physics_Sleep, temporary_Initialize_Awake, temporary_Initialize_Active, temporary_Density, temporary_Friction, temporary_Restitution, temporary_Exists_In_Layers, temporary_Collides_With_Layers, temporary_Group_Index, temporary_X_Half_Length, temporary_Y_Half_Length);
			//(*this).level_Objects_Array[i] = temporary_Object;
		}
		(*this).level_File.close();
	}
}

void Level::display_Information() const
{
//	float time_Step = (1.0 / 60);
//	(*Object::active_World_Pointer).Step(time_Step,6,2);
//	for(int i = 0; i < (*this).number_Of_Objects_In_Level; i++)
//	{
//	}
}
