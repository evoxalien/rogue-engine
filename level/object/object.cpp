//Object cpp file
#include "object.h"

//Initialization of static Object members
std::vector<Object*> Object::object_Pointer_Vector;
b2World Object::box2D_World(b2Vec2(0,-9.81));
b2BodyDef Object::box2D_Body_Definition;
b2FixtureDef Object::box2D_Fixture_Definition;
b2PolygonShape Object::box2D_Polygon_Shape;
float32 Object::physics_Time_Step = 1.0 / 60;

//Default Object constructor; adds a pointer to the Object to the Object pointer vector
Object::Object()
{
	std::cout << "Object()" << std::endl;
	(*this).physics = nullptr;

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//
Object::Object(const float x_Position, const float y_Position, const float angle_In_Radians, const int body_Type, const bool check_For_Dynamic_Tunneling, const bool use_Fixed_Rotation, const float linear_Damping, const float angular_Damping, const float gravity_Scale, const bool allow_Physics_Sleep, const bool initialize_Awake, const bool initialize_Active, const float density, const float friction, const float restitution, const uint16 exists_In_Layers, const uint16 collides_With_Layers, const int group_Index, const float x_Half_Length, const float y_Half_Length)
{
	std::cout << "Object(Physics components)" << std::endl;

	//if(Object::active_World_Pointer != nullptr)
	//{
		Object::box2D_Body_Definition.position.Set(x_Position, y_Position);
		Object::box2D_Body_Definition.angle = angle_In_Radians;
		if(body_Type == 0)
		{
			Object::box2D_Body_Definition.type = b2_staticBody;
		}
		else if(body_Type == 1)
		{
			Object::box2D_Body_Definition.type = b2_kinematicBody;
		}
		else
		{
			Object::box2D_Body_Definition.type = b2_dynamicBody;
			Object::box2D_Body_Definition.bullet = check_For_Dynamic_Tunneling;
		}
		Object::box2D_Body_Definition.fixedRotation = use_Fixed_Rotation;
		Object::box2D_Body_Definition.linearDamping = linear_Damping;
		Object::box2D_Body_Definition.angularDamping = angular_Damping;
		Object::box2D_Body_Definition.gravityScale = gravity_Scale;
		Object::box2D_Body_Definition.allowSleep = allow_Physics_Sleep;
		Object::box2D_Body_Definition.awake = initialize_Awake;
		Object::box2D_Body_Definition.active = initialize_Active;
		Object::box2D_Body_Definition.userData = this;

		(*this).physics = Object::box2D_World.CreateBody(&Object::box2D_Body_Definition);	//Create an instance of a Box2D body in the Box2D World with the definition provided from the paramaters and point the Object member 'physics' to the body

		Object::box2D_Fixture_Definition.density = density;
		Object::box2D_Fixture_Definition.friction = friction;
		Object::box2D_Fixture_Definition.restitution = restitution;
		Object::box2D_Fixture_Definition.filter.categoryBits = exists_In_Layers;	//Each bit of the 16 bit unsigned integer represents a layer; if the bit is 1, the Object exists in that layer, if 0, it does not
		Object::box2D_Fixture_Definition.filter.maskBits = collides_With_Layers;	//Each bit of the 16 bit unsigned integer represents a layer; if the bit is 1, the Object may potentially collide with another Object which exists in that layer
		Object::box2D_Fixture_Definition.filter.groupIndex = group_Index;			//If 0, Object will collide with all other Objects which share both the existing layers and colliding layers; if the value pair of colliding objects are different, the same rules will apply; if the pair is positive and the same, they will collide regardless of layers, and if the pair is negative and the same, they will never collide, regardless of layers

		Object::box2D_Polygon_Shape.SetAsBox(x_Half_Length, y_Half_Length);

		Object::box2D_Fixture_Definition.shape = &Object::box2D_Polygon_Shape;

		(*(*this).physics).CreateFixture(&Object::box2D_Fixture_Definition);		//The body will contain a fixture with the shape and attributes set by the parameters; currently only support for a single rectangle is present
	//}
	//else
	//{
	//	std::cerr << "Error: Object does not contain a pointer to the Box2D World, ensure one is created and set as the active World." << std::endl;
	//}

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Constructor for when Behavior is known; adds a pointer to the Object to the Object pointer vector and stores the index in necessary members so they can access their data
Object::Object(const Behavior behavior)
{
	std::cout << "Object(Behavior)" << std::endl;
	(*this).physics = nullptr;
	(*this).behavior = behavior;

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Constructor for when Attributes are known; adds a pointer to the Object to the Object pointer vector and stores the index in necessary members so they can access their data
Object::Object(const Attributes attributes)
{
	std::cout << "Object(Attributes)" << std::endl;
	(*this).physics = nullptr;
	(*this).attributes = attributes;		//Requires testing

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Constructor for when Behavior and Attributes are known; adds a pointer to the Object to the Object pointer vector and stores the index in necessary members so they can access their data
Object::Object(const Behavior behavior, const Attributes attributes)
{
	std::cout << "Object(Behavior, Attributes)" << std::endl;
	(*this).physics = nullptr;
	(*this).behavior = behavior;
	(*this).attributes = attributes;		//Requires testing

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

Object::Object(const Behavior behavior, const Attributes attributes, const Equipment equipment, const Status_Effects status_Effects)
{
	std::cout << "Object(Behavior, Attributes)" << std::endl;
	(*this).physics = nullptr;
	(*this).behavior = behavior;
	(*this).attributes = attributes;			//Requires testing
	(*this).equipment = equipment;				//Requires testing
	(*this).status_Effects = status_Effects;	//Requires testing

	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(Object::object_Pointer_Vector.size()));
	Object::object_Pointer_Vector.push_back(this);
}

//Copy constructor; calls the Object constructor with the members of the Object being copied from passed as arguments, which ensures the newly generated Object has its own index with the rest of the data equivalent to the Object being copied from
Object::Object(const Object &object) : Object(object.behavior, object.attributes)
{
	std::cout << "Object copy constructor" << std::endl;
}

//Move constructor; when a 'temporary' right-side Object is used in Object creation, this constructor is used; it should make use of the already allocated space, but is still in testing
Object::Object(Object&& object)
{
	std::cout << "Object move constructor" << std::endl;
	(*this) = object;
//	std::cerr << "Move constructor has been called" << std::endl;
//	(*this).physics = object.physics;
//	object.physics = nullptr;
//	(*this).behavior = object.behavior;
//	std::cerr << "2" << std::endl;
//	(*this).attributes = object.attributes;
//	(*this).equipment = object.equipment;
//	(*this).set_Object_Pointer_Vector_Index(static_cast<std::uint16_t>(object.get_Object_Pointer_Vector_Index()));
//	std::cerr << "3" << std::endl;
//	object.set_Object_Pointer_Vector_Index(Object::object_Pointer_Vector.size());
//	std::cerr << "blah" << Object::object_Pointer_Vector.size() << std::endl;
//	std::cerr << "blah2" << object.get_Object_Pointer_Vector_Index() << std::endl;
//	Object::object_Pointer_Vector.push_back(&object);
	std::cerr << "4" << std::endl;
//	object.
}

//Object Deconstructor; when an Object is deleted or goes out of scope, the Object pointer vector will swap the last element with the one deleted and remove the previous last element before deleting the Object from memory
Object::~Object()
{
	std::cout << "Object pointed at index: " << (*this).get_Object_Pointer_Vector_Index() << " is being destroyed." << std::endl;

	if((*this).physics != nullptr)
	{
		std::cerr << "About to destroy body" << std::endl;
		Object::box2D_World.DestroyBody(physics);
		std::cerr << "Body destroyed" << std::endl;
		(*this).physics = nullptr;
	}
	Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()] = Object::object_Pointer_Vector[Object::object_Pointer_Vector.size() - 1];		//Changes pointer stored in the deconstructing Object's index to be a pointer to the last Object in the vector
	(*Object::object_Pointer_Vector[(*this).get_Object_Pointer_Vector_Index()]).set_Object_Pointer_Vector_Index((*this).get_Object_Pointer_Vector_Index());	//Changes the index of the Object which previously had its pointer at the end to its new position in the vector 
	Object::object_Pointer_Vector.pop_back();																												//Removes the last element of the Object pointer vector since it's effectively been moved to a new index
}

//Used for testing; displays useful information in the console log related to the Object class
void Object::display_Information()
{
	//std::cout << "size of vector = " << Object::object_Pointer_Vector.size() << std::endl;
	//std::cout << "capacity of vector = " << Object::object_Pointer_Vector.capacity() << std::endl;
	//std::cout << "max capacity of vector = " << Object::object_Pointer_Vector.max_size() << std::endl << std::endl;
	std::cout << "Displaying information for Objects which have Physics:" << std::endl << std::endl;
	for(int i = 0; i < Object::object_Pointer_Vector.size(); i++)
	{
		if((*Object::object_Pointer_Vector[i]).physics != nullptr)
		{
			std::cout << std::endl << "Object index = " << (*Object::object_Pointer_Vector[i]).get_Object_Pointer_Vector_Index() << std::endl;
			b2Vec2 position = (*(*Object::object_Pointer_Vector[i]).physics).GetPosition();
			std::cout << "Physics- x_Position: " << position.x << " y_Position: " << position.y << std::endl;
		}
		else
		{
			std::cout << std::endl << "Object without Physics: Oject index = " << (*Object::object_Pointer_Vector[i]).get_Object_Pointer_Vector_Index() << std::endl;
			i = Object::object_Pointer_Vector.size();
		}
	}
	std::cout << std::endl;
}

//Currently will update all Objects' physics, behavior, and attributes appropriately, even in inactive levels, which may prove problematic
void Object::update()
{
	Object::box2D_World.Step(Object::physics_Time_Step, 6, 3);		//Moves and appropriately checks for collisions for all active Box2D Bodies in the Box2D World
	for(int i = 0; i < Object::object_Pointer_Vector.size(); i++)	//Iterates through all Object pointers in the Object pointer vector
	{
		(*Object::object_Pointer_Vector[i]).behavior.update();		//Updates the behavior_State of the Object and has the Object perform the appropriate action based upon its environment and behavior_Pattern
		(*Object::object_Pointer_Vector[i]).attributes.update();	//Updates health, stamina, and mana based on effective regeneration rates
	}
}

//Overloads the copy assignment operator, '=' with a normal Object as the target, to avoid changing the index contained in the appropriate members which reference the pointer to the containing Object in the Object pointer vector
Object& Object::operator=(const Object& object)
{
	std::cout << "Copy assignment operator called; process-crashing bug may occur, avoid use at the moment" << std::endl;
	uint16_t temporary_Index = (*this).get_Object_Pointer_Vector_Index();
	(*this).physics = object.physics;		//Note: Both Objects will contain a pointer to the same box2D Body at the moment which will cause strange behavior and a fatal error when the destructor for both Objects executes
	(*this).behavior = object.behavior;
	(*this).attributes = object.attributes;
	(*this).equipment = object.equipment;
	(*this).set_Object_Pointer_Vector_Index(temporary_Index);
    return *this;
}

//Overloads the move assignment operator, '=' with a 'temporary' right-side Object as the target, to move the data into the space already allocated by the temporary value, rather than copying and deleting memory; still in testing
Object& Object::operator=(Object&& object)
{
	std::cout << "Move assignment operator has been called" << std::endl;
	uint16_t temporary_Index = (*this).get_Object_Pointer_Vector_Index();
	(*this).physics = object.physics;		//The new Object will contain the box2D Body pointer generated from the Object constructor or nullptr if no Physics were generated
	object.physics = nullptr;				//On the temporary Object's destruction, it will avoid removing the Body from the box2D World, allowing the new Object to take over that Body if it had one
	(*this).behavior = object.behavior;		//Requires testing, should work
	(*this).attributes = object.attributes;	//Requires testing, should work
	(*this).equipment = object.equipment;	//Requires testing
	//(*this).inventory = object.inventory;
	//(*this).status_Effects = object.status_Effects;
	(*this).set_Object_Pointer_Vector_Index(temporary_Index);
	//object.set_Object_Pointer_Vector_Index(Object::object_Pointer_Vector.size());
//	std::cerr << "blah" << Object::object_Pointer_Vector.size() << std::endl;
//	std::cerr << "blah2" << object.get_Object_Pointer_Vector_Index() << std::endl;
//	Object::object_Pointer_Vector.push_back(&object);
//	std::cerr << "4" << std::endl;
//	object.
	return *this;
}

//Rather than storing an additional index within Object itself, a member which already requires the index is accessed for the necessary index of the Object within the static Object pointer vector
std::uint16_t Object::get_Object_Pointer_Vector_Index() const
{
	return (*this).behavior.get_Containing_Object_Pointer_Vector_Index();
}

//Updates necessary Object members to store the index within the static Object pointer vector of the Object that they are contained within
void Object::set_Object_Pointer_Vector_Index(const std::uint16_t object_Pointer_Vector_Index)
{
	(*this).behavior.set_Containing_Object_Pointer_Vector_Index(object_Pointer_Vector_Index);
	(*this).attributes.set_Containing_Object_Pointer_Vector_Index(object_Pointer_Vector_Index);
	(*this).equipment.set_Containing_Object_Pointer_Vector_Index(object_Pointer_Vector_Index);
	//(*this).animation.set_Containing_Object_Pointer_Vector_Index(object_Pointer_Vector_Index);
}
