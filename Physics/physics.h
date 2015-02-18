//physics.h

//There's a lot of commented out code that was for testing, just ignore it for now

//To do: documentation, semi-elastic collisions, super-elastic collisions, 2-dimensional collisions of all types, different shape definitions,
//friction, gravity/anti-gravity 'wells' (diminishing, non-diminishing, single-dimensional, radial)

#ifndef PHYSICS_H
#define PHYSICS_H
#include <iostream>

using namespace std;

class Physics
{
	private:
		static double frame_Rate;
		//static double inverse_Frame_Rate;

		static double x_Gravity;
		static double y_Gravity;
		static double z_Gravity;

		double x_Position;
		double y_Position;
		double z_Position;
		double x_Length;
		double y_Length;
		double z_Length;
		double angle;
		double x_Velocity;
		double y_Velocity;
		double x_Acceleration;
		double y_Acceleration;

		double elasticity;
		double mass;

		double x_Force;
		double y_Force;

	public:

		Physics();
		Physics(double, double, double, double, double, double, double);
		Physics(double, double, double, double, double, double, double, double, double, double, double, double, double);

		void move();
		void accelerate();
		//void accelerate(double, double);
		//void accelerate(double, double, double);
		//void accelerate(double, double, double, double, double);
		//void stop(double);
		//void calculate_Forces(double, double);
		void add_Force(double, double);
		void apply_Forces();

		static void resolve_Collisions(Physics, Physics);
		static void set_X_Gravity(double);
		static void set_Y_Gravity(double);
		static void set_Z_Gravity(double);
		const static double get_X_Gravity();
		const static double get_Y_Gravity();
		const static double get_Z_Gravity();
		const static void display_Gravity();

		static void set_Frame_Rate(double);
		const static double get_Frame_Rate();

		void clear_Object();
		void display_Information();

		const double get_X_Position();
};
#endif
