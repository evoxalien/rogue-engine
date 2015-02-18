#include "physics.h"
#include "object.h"

using namespace std;

int main()
{
	Physics physics1(0, 0, -15, 0, 0, 0, 13);
	Physics physics2(0, 0, 2, 0, 0, 0, 13);
	Physics::resolve_Collisions(physics1, physics2);
	Object object1;
	cout << object1.get_Object_Pointer_Vector_Index();
	//Object object1;
	//Object object2(physics2);
	//Object objects[7];
	//Object::display_Information();
	/*int i;
	int frame_Rate;
	Physics object4(0, 0, 0, 0, 0, 0, 1);

	do
	{
		i = 0;
		cout << "Enter a frame rate: ";
		cin >> frame_Rate;
		Physics::set_Frame_Rate(frame_Rate);
		do
		{
			object4.move();
			//object4.resolve_Collisions();
			object4.add_Force(Physics::get_X_Gravity(), Physics::get_Y_Gravity());
			object4.apply_Forces();
			object4.accelerate();
			i++;
		}
		while(i < Physics::get_Frame_Rate());
		object4.display_Information();
		object4.clear_Object();
	}
	while(frame_Rate > 0);
	object4.display_Information();*/

	return 0;
}
