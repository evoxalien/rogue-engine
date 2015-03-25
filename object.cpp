//object.cpp
#include "object.h"

using namespace std;

//Initialization of static Object members
std::vector<Object*> Object::object_Pointer_Vector;
std::vector<Physics*> Object::physics_Pointer_Vector;
std::vector<std::vector<std::vector<Physics*>>> Object::physics_Segments;

int Object::number_Of_X_Physics_Segments = 1;
int Object::number_Of_Y_Physics_Segments = 1;

int Object::screen_X_Length = 1;
int Object::screen_Y_Length = 1;

//Default Object Constructor; assigns a default Physics to the Object and adds a pointer to the Object to the Object pointer vector and a pointer to the Physics to the Physics pointer vector
Object::Object()
{
	(*this).physics = Physics();
	Object::physics_Pointer_Vector.push_back(&((*this).physics));
	(*this).object_Pointer_Vector_Index = Object::object_Pointer_Vector.size();
	Object::object_Pointer_Vector.push_back(this);
}

//Object Constructor; if the initial Physics of an Object is known, passing it as an argument will create an Object with the same Physics
Object::Object(Physics physics)
{
	(*this).physics = physics;
	Object::physics_Pointer_Vector.push_back(&((*this).physics));
	(*this).object_Pointer_Vector_Index = Object::object_Pointer_Vector.size();
	Object::object_Pointer_Vector.push_back(this);
}

//Object Deconstructor; when an Object is deleted or goes out of scope, the Object pointer vector will swap the last element with the one deleted and remove the previous last element before deleting the Object from memory
Object::~Object()
{
	Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()] = Object::object_Pointer_Vector[Object::object_Pointer_Vector.size()];		//Changes pointer stored in the deconstructing object's index to be a pointer to the last object in the vector
	Object::physics_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()] = Object::physics_Pointer_Vector[Object::physics_Pointer_Vector.size()];	//A similar change to the Physics pointers; will need to be modified in the future
	(*Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()]).object_Pointer_Vector_Index = (*this).get_Object_Pointer_Vector_Index();//Changes the index of the object which previously had its pointer at the end to its new position in the vector 
	Object::object_Pointer_Vector.pop_back();																											//Removes the last element of the object pointer vector since it's effectively been moved to a new index
	Object::physics_Pointer_Vector.pop_back();																											//A similar change to the Physics pointers; will need to be modified in the future
}

//The function assigns the Physics of active Objects to the appropriate locations in the 2-dimensional Physics segments vectors for the current frame and calls Physics::check_For_Collisions to check for and resolve collisions inside the segments
void Object::check_For_Collisions()
{
	int i = 0;
	int j = 0;
	int k = 0;
	/*cout << "    ";
	for(; i < Object::number_Of_X_Physics_Segments; i++)
	{
		if(i < 9)
		cout << (i + 1) << " ";
		else
		cout << (i + 1);
	}
	cout << endl;
	for(i = 0; i < Object::number_Of_Y_Physics_Segments; i++)
	{
		if(i < 9)
		cout << (i + 1) << ": ";
		else
		cout << (i + 1) << ":";
		for(j = 0; j < Object::number_Of_X_Physics_Segments; j++)
		{
			cout << " X";
		}
		cout << endl;
	}*/


	if(Object::number_Of_X_Physics_Segments != Object::physics_Segments.size())
	{
		//for(i = 0; i < physics_Segments.size(); i++)
		//{
		//	Object::physics_Segments[i].clear();
		//}
		Object::physics_Segments.clear();
		for(i = 0; i < Object::number_Of_X_Physics_Segments; i++)
		{
			vector<vector<Physics*>> temporary_X_Vector;
			for(j = 0; j < Object::number_Of_Y_Physics_Segments; j++)
			{
				vector<Physics*> temporary_Y_Vector;
				temporary_X_Vector.push_back(temporary_Y_Vector);
			}
			Object::physics_Segments.push_back(temporary_X_Vector);
		}
	}
	for(i = 0; i < Object::physics_Segments.size(); i++)
	{
		for(j = 0; j < Object::physics_Segments[i].size(); j++)
		{
			Object::physics_Segments[i][j].clear();
		}
	}
	for(i = 0; i < Object::physics_Pointer_Vector.size(); i++)
	{
		//cout << "[" << static_cast<int>((*Object::physics_Pointer_Vector[i]).get_X_Position() / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments())) << "] [" << static_cast<int>((*Object::physics_Pointer_Vector[i]).get_Y_Position() / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments())) << "]" << endl;
		//Object::physics_Segments[static_cast<int>((*Object::physics_Pointer_Vector[i]).get_X_Position() / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments()))][static_cast<int>((*Object::physics_Pointer_Vector[i]).get_Y_Position() / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments()))].push_back(physics_Pointer_Vector[i]);
		//if(static_cast<int>((*Object::physics_Pointer_Vector[i]).get_X_Position() / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments())) != static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_X_Position() + (*Object::physics_Pointer_Vector[i]).get_X_Length()) / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments())))
		for(j = static_cast<int>((*Object::physics_Pointer_Vector[i]).get_X_Position() / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments())); j <= static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_X_Position() + (*Object::physics_Pointer_Vector[i]).get_X_Length()) / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments())); j++)
		{
			for(k = static_cast<int>((*Object::physics_Pointer_Vector[i]).get_Y_Position() / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments())); k <= static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_Y_Position() + (*Object::physics_Pointer_Vector[i]).get_Y_Length()) / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments())); k++)
			{
				//cout << "[" << j << "] [" << k << "]" << endl;
				Object::physics_Segments[j][k].push_back(Object::physics_Pointer_Vector[i]);
			}
			//Object::physics_Segments[static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_X_Position() + (*Object::physics_Pointer_Vector[i]).get_X_Length()) / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments()))][static_cast<int>((*Object::physics_Pointer_Vector[i]).get_Y_Position() / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments()))].push_back(physics_Pointer_Vector[i]);
			//if(static_cast<int>((*Object::physics_Pointer_Vector[i]).get_Y_Position() / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments())) != static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_Y_Position() + (*Object::physics_Pointer_Vector[i]).get_Y_Length()) / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments())))
			//{
			//	Object::physics_Segments[static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_X_Position() + (*Object::physics_Pointer_Vector[i]).get_X_Length()) / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments()))][static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_Y_Position() + (*Object::physics_Pointer_Vector[i]).get_Y_Length()) / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments()))].push_back(physics_Pointer_Vector[i]);
			//}
		}
		//if(static_cast<int>((*Object::physics_Pointer_Vector[i]).get_Y_Position() / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments())) != static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_Y_Position() + (*Object::physics_Pointer_Vector[i]).get_Y_Length()) / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments())))
		//{
		//	Object::physics_Segments[static_cast<int>((*Object::physics_Pointer_Vector[i]).get_X_Position() / (static_cast<double>(Object::screen_X_Length) / Object::get_Number_Of_X_Physics_Segments()))][static_cast<int>(((*Object::physics_Pointer_Vector[i]).get_Y_Position() + (*Object::physics_Pointer_Vector[i]).get_Y_Length()) / (static_cast<double>(Object::screen_Y_Length) / Object::get_Number_Of_Y_Physics_Segments()))].push_back(physics_Pointer_Vector[i]);
		//}
	}
	for(i = 0; i < Object::number_Of_X_Physics_Segments; i++)
	{
		for(j = 0; j < Object::number_Of_Y_Physics_Segments; j++)
		{
			//cout << "[" << i << "] [" << j << "]: " << endl;
			//send physics_Segments[i][j] to resolve collisions
			Physics::check_For_Collisions(physics_Segments[i][j]);
			for(k =0; k < Object::physics_Segments[i][j].size(); k++)
			{
				//cout << "[" << i << "] [" << j << "]: " << endl;
				//(*Object::physics_Segments[i][j][k]).display_Information();
			}
		}
	}
	for(i = 0; i < Object::physics_Pointer_Vector.size(); i++)
	{
		(*Object::physics_Pointer_Vector[i]).clear_Objects_Collided_With_This_Frame();
	}
}

//Used for testing; displays useful information in the console log related to the Object's contents
const void Object::display_Information()
{
	cout << "size of vector = " << Object::object_Pointer_Vector.size() << endl;
	cout << "capacity of vector = " << Object::object_Pointer_Vector.capacity() << endl;
	cout << "max capacity of vector = " << Object::object_Pointer_Vector.max_size() << endl << endl;
	for(int i = 0; i < Object::object_Pointer_Vector.size(); i++)
	{
		cout << endl << "Object index = " << (*Object::object_Pointer_Vector[i]).get_Object_Pointer_Vector_Index() << endl;
		cout << "(*object_Pointer_Vector [" << i << "]).physics.display_Information = " << endl;
		(*Object::object_Pointer_Vector[i]).physics.display_Information();
	}
}


//'Getters' and 'Setters' for static Object members
void Object::set_Number_Of_X_Physics_Segments(int number_Of_X_Physics_Segments)
{
	Object::number_Of_X_Physics_Segments = number_Of_X_Physics_Segments;
}

const int Object::get_Number_Of_X_Physics_Segments()
{
	return Object::number_Of_X_Physics_Segments;
}

void Object::set_Number_Of_Y_Physics_Segments(int number_Of_Y_Physics_Segments)
{
	Object::number_Of_Y_Physics_Segments = number_Of_Y_Physics_Segments;
}

const int Object::get_Number_Of_Y_Physics_Segments()
{
	return Object::number_Of_Y_Physics_Segments;
}

void Object::set_Screen_X_Length(int screen_X_Length)
{
	Object::screen_X_Length = screen_X_Length;
}

const int Object::get_Screen_X_Length()
{
	return Object::screen_X_Length;
}

void Object::set_Screen_Y_Length(int screen_Y_Length)
{
	Object::screen_Y_Length = screen_Y_Length;
}

const int Object::get_Screen_Y_Length()
{
	return Object::screen_Y_Length;
}

//'Getters' and 'Setters' for private member variables
void Object::set_Object_Pointer_Vector_Index(int object_Pointer_Vector_Index)
{
	(*this).object_Pointer_Vector_Index = object_Pointer_Vector_Index;
}

const int Object::get_Object_Pointer_Vector_Index()
{
	return (*this).object_Pointer_Vector_Index;
}
