//Object cpp file
#include "object.h"

using namespace std;

//Initialization of static Object members
std::vector<Object*> Object::object_Pointer_Vector;

//Default Object Constructor; adds a pointer to the Object to the Object pointer vector
Object::Object()
{
	(*this).object_Pointer_Vector_Index = Object::object_Pointer_Vector.size();
	Object::object_Pointer_Vector.push_back(this);
}

//Object Deconstructor; when an Object is deleted or goes out of scope, the Object pointer vector will swap the last element with the one deleted and remove the previous last element before deleting the Object from memory
Object::~Object()
{
	Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()] = Object::object_Pointer_Vector[Object::object_Pointer_Vector.size() - 1];	//Changes pointer stored in the deconstructing Object's index to be a pointer to the last Object in the vector
	(*Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()]).object_Pointer_Vector_Index = (*this).get_Object_Pointer_Vector_Index();//Changes the index of the Object which previously had its pointer at the end to its new position in the vector 
	Object::object_Pointer_Vector.pop_back();																											//Removes the last element of the Object pointer vector since it's effectively been moved to a new index
}

//Used for testing; displays useful information in the console log related to the Object class
const void Object::display_Information()
{
	cout << "size of vector = " << Object::object_Pointer_Vector.size() << endl;
	cout << "capacity of vector = " << Object::object_Pointer_Vector.capacity() << endl;
	cout << "max capacity of vector = " << Object::object_Pointer_Vector.max_size() << endl << endl;
	for(int i = 0; i < Object::object_Pointer_Vector.size(); i++)
	{
		cout << endl << "Object index = " << (*Object::object_Pointer_Vector[i]).get_Object_Pointer_Vector_Index() << endl;
	}
	cout << endl;
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
