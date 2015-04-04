//Object cpp file
#include "object.h"

//Initialization of static Object members
std::vector<Object*> Object::object_Pointer_Vector;

//Default Object constructor; adds a pointer to the Object to the Object pointer vector
Object::Object()
{
	std::cout << "Object()" << std::endl;
	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Constructor for when Behavior is known; adds a pointer to the Object to the Object pointer vector and stores the index in necessary members so they can access their data
Object::Object(const Behavior behavior)
{
	(*this).behavior = behavior;

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Constructor for when Attributes are known; adds a pointer to the Object to the Object pointer vector and stores the index in necessary members so they can access their data
Object::Object(const Attributes attributes)
{
	(*this).attributes = attributes;		//Requires testing

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Constructor for when Behavior and Attributes are known; adds a pointer to the Object to the Object pointer vector and stores the index in necessary members so they can access their data
Object::Object(const Behavior behavior, const Attributes attributes)
{
	(*this).behavior = behavior;
	(*this).attributes = attributes;		//Requires testing

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Copy constructor; calls the Object constructor with the members of the Object being copied from passed as arguments, which ensures the newly generated Object has its own index with the rest of the data equivalent to the Object being copied from
Object::Object(const Object &object) : Object(object.behavior, object.attributes)
{
}

//Move constructor; when a 'temporary' right-side Object is used in Object creation, this constructor is used; it should make use of the already allocated space, but is still in testing
Object::Object(Object&& object)
{
	std::cerr << "Move constructor has been called" << std::endl;
	(*this).behavior = object.behavior;
	std::cerr << "2" << std::endl;
	(*this).attributes = object.attributes;
	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(object.get_Object_Pointer_Vector_Index()));
	std::cerr << "3" << std::endl;
	object.set_Object_Pointer_Vector_Index(Object::object_Pointer_Vector.size());
//	std::cerr << "blah" << Object::object_Pointer_Vector.size() << std::endl;
//	std::cerr << "blah2" << object.get_Object_Pointer_Vector_Index() << std::endl;
	Object::object_Pointer_Vector.push_back(&object);
	std::cerr << "4" << std::endl;
//	object.
}

//Object Deconstructor; when an Object is deleted or goes out of scope, the Object pointer vector will swap the last element with the one deleted and remove the previous last element before deleting the Object from memory
Object::~Object()
{
	std::cout << "Object pointed at index: " << (*this).get_Object_Pointer_Vector_Index() << " is being destroyed." << std::endl;
	(*this).behavior.act();
	Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()] = Object::object_Pointer_Vector[Object::object_Pointer_Vector.size() - 1];		//Changes pointer stored in the deconstructing Object's index to be a pointer to the last Object in the vector
	(*Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()]).set_Object_Pointer_Vector_Index((*this).get_Object_Pointer_Vector_Index());	//Changes the index of the Object which previously had its pointer at the end to its new position in the vector 
	Object::object_Pointer_Vector.pop_back();																												//Removes the last element of the Object pointer vector since it's effectively been moved to a new index
}

//Used for testing; displays useful information in the console log related to the Object class
const void Object::display_Information()
{
	std::cout << "size of vector = " << Object::object_Pointer_Vector.size() << std::endl;
	std::cout << "capacity of vector = " << Object::object_Pointer_Vector.capacity() << std::endl;
	std::cout << "max capacity of vector = " << Object::object_Pointer_Vector.max_size() << std::endl << std::endl;
	for(int i = 0; i < Object::object_Pointer_Vector.size(); i++)
	{
		std::cout << std::endl << "Object index = " << (*Object::object_Pointer_Vector[i]).get_Object_Pointer_Vector_Index() << std::endl;
	}
	std::cout << std::endl;
}

//Overloads the copy assignment operator, '=' with a normal Object as the target, to avoid changing the index contained in the appropriate members which reference the pointer to the containing Object in the Object pointer vector
Object& Object::operator=(const Object& object)
{
	uint16_t temporary_Index = (*this).get_Object_Pointer_Vector_Index();
	(*this).behavior = object.behavior;
//	(*this).attributes = object.attributes;
	(*this).set_Object_Pointer_Vector_Index(temporary_Index);
}

//Overloads the move assignment operator, '=' with a 'temporary' right-side Object as the target, to move the data into the space already allocated by the temporary value, rather than copying and deleting memory; still in testing
Object& Object::operator=(Object&& object)
{
	std::cerr << "Move assignment operator has been called" << std::endl;
}

//Updates necessary Object members to store the index within the static Object pointer vector of the Object that they are contained within
void Object::set_Object_Pointer_Vector_Index(const std::uint16_t object_Pointer_Vector_Index)
{
	(*this).behavior.set_Containing_Object_Pointer_Vector_Index(object_Pointer_Vector_Index);
	(*this).attributes.set_Containing_Object_Pointer_Vector_Index(object_Pointer_Vector_Index);
	//(*this).animation.set_Containing_Object_Pointer_Vector_Index(object_Pointer_Vector_Index);
}

//Rather than storing an additional index within Object itself, a member which already requires the index is accessed for the necessary index of the Object within the static Object pointer vector
const std::uint16_t Object::get_Object_Pointer_Vector_Index()
{
	return (*this).behavior.get_Containing_Object_Pointer_Vector_Index();
}
