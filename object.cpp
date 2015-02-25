//object.cpp
#include "object.h"

using namespace std;

std::vector<Object*> Object::object_Pointer_Vector;
std::vector<Physics*> Object::physics_Pointer_Vector;

Object::Object()
{
	(*this).physics = Physics();
	Object::physics_Pointer_Vector.push_back(&((*this).physics));
	(*this).object_Pointer_Vector_Index = Object::object_Pointer_Vector.size();
	Object::object_Pointer_Vector.push_back(this);
}

Object::Object(Physics physics)
{
	(*this).physics = physics;
	Object::physics_Pointer_Vector.push_back(&((*this).physics));
	(*this).object_Pointer_Vector_Index = Object::object_Pointer_Vector.size();
	Object::object_Pointer_Vector.push_back(this);
}

Object::~Object()
{
	Object::object_Pointer_Vector[(*this).object_Pointer_Vector_Index] = NULL;
	Object::physics_Pointer_Vector[(*this).object_Pointer_Vector_Index] = NULL;
}

void Object::check_For_Collisions()
{
	
}

void Object::display_Information()
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

int Object::get_Object_Pointer_Vector_Index()
{
	return (*this).object_Pointer_Vector_Index;
}
