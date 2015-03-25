//physics.h

//There's a lot of commented out code that was for testing, just ignore it for now

//To do:Different shape definitions, proper friction, gravity/anti-gravity 'wells' (diminishing, non-diminishing, single-dimensional, radial)

#ifndef PHYSICS_H
#define PHYSICS_H
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Object;	//Forward declaration allowing Object to be referenced within Physics

class Physics
{
	private:
		//Private Static class variables
		static double frame_Rate;				//The number of times the Physics system should execute if the program continues at the same rate
		//static double time_Of_Next_Collision;	//Not currently implemented

		static double x_Gravity;	//The amount of acceleration that will be present on all mobile objects in the X direction; positive is right, negative is left
		static double y_Gravity;	//The amount of acceleration that will be present on all mobile objects in the Y direction; positive is down, negative is up
		static double z_Gravity;	//The amount of acceleration that will be present on all mobile objects in the Z direction; positive is down, negative is up

		//Private member variables
		double x_Length;			//The length of the rectangle along the X axis
		double y_Length;			//The length of the rectangle along the Y axis
		double z_Length;			//The length of the rectangle along the Z axis

		double x_Position;			//The X position of the left side of a rectangle
		double y_Position;			//The Y position of the top side of a rectangle
		double z_Position;			//Currently not fully supported; will generally be used as a depth or layer

		double x_Velocity;			//The speed and direction along the X axis the object would cover in 1 second
		double y_Velocity;			//The speed and direction along the Y axis the object would cover in 1 second

		double x_Acceleration;		//The rate at which the object's velocity along the X axis is changing per second
		double y_Acceleration;		//The rate at which the object's velocity along the Y axis is changing per second

		double x_Force;				//The rate at which the object's acceleration along the X axis is changing per second, divided by the mass of the object
		double y_Force;				//The rate at which the object's acceleration along the Y axis is changing per second, divided by the mass of the object

		double angle;				//Not currently implemented; will be the angle the rectangle is rotated
		double elasticity;			//How much an object will 'bounce' when there is a collision; should typically be between 0 and 1. The lower value of a pair is used in collision resolution
		double mass;				//The weight of the object in Kilograms

		std::vector<Physics*> objects_Collided_With_This_Frame;	//A vector of pointers to the Physics of Objects that the object has collided with in the current frame

	public:
		//Constructors
		Physics();
		Physics(double, double, double, double, double, double, double);
		Physics(double, double, double, double, double, double, double, double, double, double, double, double, double);

		//Static functions used in collision resolution
		static void check_For_Collisions(vector<Physics*>&);
		static void resolve_Collisions(Physics*, Physics*);

		//Member functions
		void move();
		void half_Move();
		void accelerate();
		//void accelerate(double, double);
		//void accelerate(double, double, double);
		//void accelerate(double, double, double, double, double);
		//void stop(double);
		//void calculate_Forces(double, double);
		void add_Force(double, double);
		void apply_Forces();
		void clear_Objects_Collided_With_This_Frame();

		void clear_Object();
		void display_Information();

		//'Getters' and 'Setters' for private static class variables
		const static double get_X_Gravity();
		static void set_X_Gravity(double);

		const static double get_Y_Gravity();
		static void set_Y_Gravity(double);

		const static double get_Z_Gravity();
		static void set_Z_Gravity(double);

		const static double get_Frame_Rate();
		static void set_Frame_Rate(double);

		//'Getters' and 'Setters' for private member variables
		const double get_X_Length();
		void set_X_Length(double);

		const double get_Y_Length();
		void set_Y_Length(double);

		const double get_X_Position();
		void set_X_Position(double);

		const double get_Y_Position();
		void set_Y_Position(double);

		const double get_X_Velocity();
		void set_X_Velocity(double);

		const double get_Y_Velocity();
		void set_Y_Velocity(double);

		const double get_X_Acceleration();
		void set_X_Acceleration(double);

		const double get_Y_Acceleration();
		void set_Y_Acceleration(double);

		const double get_X_Force();
		void set_X_Force(double);

		const double get_Y_Force();
		void set_Y_Force(double);

		const double get_Angle();
		void set_Angle(double);

		const double get_Elasticity();
		void set_Elasticity(double);

		const double get_Mass();
		void set_Mass(double);

		const vector<Physics*> get_Objects_Collided_With_This_Frame();
		void set_Objects_Collided_With_This_Frame(vector<Physics*>);
};
#endif
