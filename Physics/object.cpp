//object.cpp
#include "object.h"

using namespace std;

std::vector<Object*> Object::object_Pointer_Vector;
int Object::number_Of_Objects = 0;

Object::Object()
{
	(*this).physics = Physics();
	(*this).object_Pointer_Vector_Index = Object::number_Of_Objects;
	Object::object_Pointer_Vector.push_back(this);
	Object::number_Of_Objects = Object::number_Of_Objects + 1;
}

Object::Object(Physics physics)
{
	(*this).physics = physics;
	(*this).object_Pointer_Vector_Index = Object::number_Of_Objects;
	Object::object_Pointer_Vector.push_back(this);
	Object::number_Of_Objects = Object::number_Of_Objects + 1;
}

void Object::display_Information()
{
	cout << "number of objects = " << Object::number_Of_Objects << endl;
	cout << "size of vector = " << Object::object_Pointer_Vector.size() << endl;
	cout << "capacity of vector = " << Object::object_Pointer_Vector.capacity() << endl;
	cout << "max capacity of vector = " << Object::object_Pointer_Vector.max_size() << endl << endl;
	for(int i = 0; i < Object::number_Of_Objects; i++)
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
