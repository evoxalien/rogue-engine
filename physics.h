//physics.h

//There's a lot of commented out code that was for testing, just ignore it for now

//To do: documentation, semi-elastic collisions, super-elastic collisions, 2-dimensional collisions of all types, different shape definitions,
//friction, gravity/anti-gravity 'wells' (diminishing, non-diminishing, single-dimensional, radial)

#ifndef PHYSICS_H
#define PHYSICS_H
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Physics
{
	private:
		//Private Static class variables
		static double frame_Rate;
		static double time_Of_Next_Collision;

		static double x_Gravity;
		static double y_Gravity;
		static double z_Gravity;

		//Private member variables
		double x_Length;
		double y_Length;
		double z_Length;

		double x_Position;
		double y_Position;
		double z_Position;

		double x_Velocity;
		double y_Velocity;

		double x_Acceleration;
		double y_Acceleration;

		double x_Force;
		double y_Force;

		double angle;
		double elasticity;
		double mass;

		vector<Physics*> objects_Collided_With_This_Frame;

	public:
		Physics();
		Physics(double, double, double, double, double, double, double);
		//Physics(double, double, double, double, double, double, double);
		Physics(double, double, double, double, double, double, double, double, double, double, double, double, double);

		void move();
		void half_Move();
		void negative_Half_Move();
		void accelerate();
		//void accelerate(double, double);
		//void accelerate(double, double, double);
		//void accelerate(double, double, double, double, double);
		//void stop(double);
		//void calculate_Forces(double, double);
		void add_Force(double, double);
		void apply_Forces();

		void clear_Object();
		void display_Information();

		//Static functions used in collision resolution
		static void check_For_Collisions(vector<Physics*>&);
		static void resolve_Collisions(Physics*, Physics*);

		const static void display_Gravity();

		//Getters and setters for private static class variables
		const static double get_X_Gravity();
		static void set_X_Gravity(double);

		const static double get_Y_Gravity();
		static void set_Y_Gravity(double);

		const static double get_Z_Gravity();
		static void set_Z_Gravity(double);

		const static double get_Frame_Rate();
		static void set_Frame_Rate(double);

		//Getters and setters for private members
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
		void clear_Objects_Collided_With_This_Frame();
};
#endif
