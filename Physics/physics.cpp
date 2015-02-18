//physics.cpp
#include "physics.h"

using namespace std;

double Physics::frame_Rate = 30;
//double Physics::inverse_Frame_Rate = (1.0 / 30.0);

double Physics::x_Gravity = -9.80665;
double Physics::y_Gravity = -9.80665;
double Physics::z_Gravity = 0;//-9.80665;

Physics::Physics()
{
	(*this).x_Position = 0;
	(*this).y_Position = 0;
	(*this).z_Position = 0;
	(*this).x_Length = 0;
	(*this).y_Length = 0;
	(*this).z_Length = 0;
	(*this).angle = 0;
	(*this).x_Velocity = 0;
	(*this).y_Velocity = 0;
	(*this).x_Acceleration = 0;
	(*this).y_Acceleration = 0;
	(*this).elasticity = 0;
	(*this).mass = 0;

	(*this).x_Force = 0;
	(*this).y_Force = 0;
}

Physics::Physics(double x_Position, double y_Position, double x_Velocity, double y_Velocity, double x_Acceleration, double y_Acceleration, double mass)
{
	(*this).x_Position = x_Position;
	(*this).y_Position = y_Position;
	(*this).x_Velocity = x_Velocity;
	(*this).y_Velocity = y_Velocity;
	(*this).x_Acceleration = x_Acceleration;
	(*this).y_Acceleration = y_Acceleration;
	(*this).mass = mass;

	(*this).elasticity = 1;
	(*this).x_Force = 0;
	(*this).y_Force = 0;
}

Physics::Physics(double x_Position, double y_Position, double z_Position, double x_Length, double y_Length, double z_Length, double angle, double x_Velocity, double y_Velocity, double x_Acceleration, double y_Acceleration, double elasticity, double mass)
{
	(*this).x_Position = x_Position;
	(*this).y_Position = y_Position;
	(*this).z_Position = z_Position;
	(*this).x_Length = x_Length;
	(*this).y_Length = y_Length;
	(*this).z_Length = z_Length;
	(*this).angle = angle;
	(*this).x_Velocity = x_Velocity;
	(*this).y_Velocity = y_Velocity;
	(*this).x_Acceleration = x_Acceleration;
	(*this).y_Acceleration = y_Acceleration;
	(*this).elasticity = elasticity;
	(*this).mass = mass;

	(*this).x_Force = 0;
	(*this).y_Force = 0;
}

void Physics::move()
{
	(*this).x_Position = (*this).x_Position + ((*this).x_Velocity / Physics::frame_Rate);
	//cout << "((*this).x_Position = " << (*this).x_Position << "(*this).x_Velocity = " << (*this).x_Velocity << endl;
	(*this).y_Position = (*this).y_Position + ((*this).y_Velocity / Physics::frame_Rate);
	//cout << "((*this).y_Position = " << (*this).y_Position << "(*this).y_Velocity = " << (*this).y_Velocity << endl << endl;
}

void Physics::accelerate()
{
	(*this).x_Velocity = (*this).x_Velocity + ((*this).x_Acceleration / Physics::frame_Rate);
	(*this).y_Velocity = (*this).y_Velocity + ((*this).y_Acceleration / Physics::frame_Rate);
}

//void Physics::accelerate(double x_Acceleration, double y_Acceleration)
//{
//	(*this).x_Velocity = (*this).x_Velocity + (x_Acceleration / Physics::frame_Rate);
//	(*this).y_Velocity = (*this).y_Velocity + (y_Acceleration / Physics::frame_Rate);
//}

//void Physics::accelerate(double x_Force, double y_Force, double time)
//{
//	while(time > 0)
//	{
//		(*this).x_Velocity = (*this).x_Velocity + (x_Force / Physics::frame_Rate);
//		(*this).y_Velocity = (*this).x_Velocity + (y_Force / Physics::frame_Rate);
//		time = time - (1.0 / Physics::frame_Rate);
//	}
//}

//void Physics::accelerate(double x_Force, double y_Force, double time, double x_Position, double y_Position)
//{
//	while(time > 0)
//	{
//		(*this).x_Velocity = (*this).x_Velocity + (x_Force / Physics::frame_Rate);
//		(*this).y_Velocity = (*this).x_Velocity + (y_Force / Physics::frame_Rate);
//		time = time - (1.0 / Physics::frame_Rate);
//	}
//}

//void Physics::stop(double time)
//{
//	if(time > 0)
//	{
//		double x_Velocity_Increment = (*this).x_Velocity / (Physics::frame_Rate * time);
//		double y_Velocity_Increment = (*this).y_Velocity / (Physics::frame_Rate * time);
//		while(time > (1.0 / Physics::frame_Rate))
//		{
//			(*this).x_Velocity = (*this).x_Velocity - x_Velocity_Increment;
//			(*this).y_Velocity = (*this).y_Velocity - y_Velocity_Increment;
//			(*this).move();
//			time = time - (1.0 / Physics::frame_Rate);
//			cout << "time = " << time << endl;
//			(*this).display_Information();
//		}
//		time = 0;
//		(*this).x_Velocity = 0;
//		(*this).y_Velocity = 0;
//		cout << "time = " << time << endl;
//		(*this).display_Information();
//	}
//}

//void Physics::calculate_Forces(double x_Force, double y_Force)
//{
//	(*this).x_Forces.push_back(x_Force);
//	(*this).y_Forces.push_back(y_Force);
//	(*this).y_Force = 0;
//	for(int i = (*this).y_Forces.size() - 1; i >= 0; i--)
//	{
//		(*this).y_Force = (*this).y_Force + (*this).y_Forces[i];
//	}
//}

void Physics::add_Force(double x_Force, double y_Force)
{
	(*this).x_Force = (*this).x_Force + x_Force;
	(*this).y_Force = (*this).y_Force + y_Force;
}

void Physics::apply_Forces()
{
	if((*this).mass > 0)
	{
		//for(int i = (*this).x_Forces.size() - 1; i >= 0; i--)
		//{
		//	(*this).x_Acceleration = (*this).x_Acceleration + ((*this).x_Forces[i] / ((*this).mass * Physics::frame_Rate));
		//	(*this).x_Forces.pop_back();
		//}
		(*this).x_Acceleration = (*this).x_Force / (*this).mass;//(*this).x_Acceleration + ((*this).x_Force / ((*this).mass * Physics::frame_Rate));
		(*this).x_Force = 0;
		(*this).y_Acceleration = (*this).y_Force / (*this).mass;//(*this).y_Acceleration + ((*this).y_Force / ((*this).mass * Physics::frame_Rate));
		(*this).y_Force = 0;
//		for(int i = (*this).y_Forces.size() - 1; i >= 0; i--)
//		{
//			(*this).y_Acceleration = (*this).y_Acceleration + ((*this).y_Forces[i] / ((*this).mass * Physics::frame_Rate));
//			(*this).y_Forces.pop_back();
//		}
	}
	else
	{
		cout << "Not sure what to do with a mass of 0 at the moment" << endl;
	}
	/*for(std::vector<double>::iterator i = (*this).x_Forces.end(); i != (*this).x_Forces.begin(); i--)
	{
		(*this).x_Acceleration = (*this).x_Acceleration + *i;
		x_Forces.pop_back();
	}
	for(std::vector<double>::iterator i = (*this).y_Forces.end(); i != (*this).y_Forces.begin() - 1; i--)
	{
		(*this).y_Acceleration = (*this).y_Acceleration + *i;
		y_Forces.pop_back();
	}*/
//	(*this).z_Acceleration
}

void Physics::resolve_Collisions(Physics physics1, Physics physics2)
{
	cout << "physics1.x_Velocity = " << physics1.x_Velocity << endl;
	cout << "physics2.x_Velocity = " << physics2.x_Velocity << endl << endl;
	cout << "physics1.mass = " << physics1.mass << endl;
	cout << "physics2.mass = " << physics2.mass << endl << endl;
	//double total_Kinetic_Energy = .5 * ((physics1.mass * physics1.x_Velocity * physics1.x_Velocity) + (physics2.mass * physics2.x_Velocity * physics2.x_Velocity));
	//double mass_Ratio_1 = physics1.mass / (physics1.mass + physics2.mass);
	//double mass_Ratio_2 = physics2.mass / (physics1.mass + physics2.mass);
	//physics1.x_Velocity = total_Kinetic_Energy * mass_Ratio_1 / (physics1.x_Velocity + physics2.x_Velocity);
	//physics2.x_Velocity = total_Kinetic_Energy * mass_Ratio_2 / (physics2.x_Velocity + physics2.x_Velocity);
	//cout << "total_Kinetic_Energy = " << total_Kinetic_Energy << endl;
	//cout << "mass_Ratio_1 = " << mass_Ratio_1 << endl;
	//cout << "mass_Ratio_2 = " << mass_Ratio_2 << endl;

	double relative_Speed = physics1.x_Velocity - physics2.x_Velocity;
	if(relative_Speed < 0)
	{
		relative_Speed = -relative_Speed;
	}

	if(physics1.elasticity == 0 || physics2.elasticity == 0)
	{
		cout << "elasticity = 0" << endl;
		double temp = ((physics1.x_Velocity * physics1.mass) + (physics2.x_Velocity * physics2.mass)) / (physics1.mass + physics2.mass);
		physics1.x_Velocity = temp;
		physics2.x_Velocity = temp;
	}
	else
	{
		cout << "elasticity != 0" << endl;
		double temp = physics1.x_Velocity;//((physics1.x_Velocity * physics1.mass) + (physics2.x_Velocity * physics2.mass)) / (physics1.mass + physics2.mass);
		double momentum = (physics1.x_Velocity * physics1.mass) + (physics2.x_Velocity * physics2.mass);
		double kinetic_Energy = .5 * ((physics1.mass * physics1.x_Velocity * physics1.x_Velocity) + (physics2.mass * physics2.x_Velocity * physics2.x_Velocity));
		cout << momentum << endl;
		cout << kinetic_Energy << endl << endl;
		//double v1f = (momentum / physics1.mass);
		//relative_Speed;
		//v1i/ * m1/ + v2i/ * m2/ = v1f * m1/ + v2f * m2/;
		//vli/ + (v2i/ * m2/ / m1/) = vlf + v2f * m2/
		//momentum / m1 = vlf + v2f * m2
		//(momentum / m1) - (v2f * m2) = vlf
		//kinetic_Energy = .5 (m1 * ((momentum / m1) - (v2f * m2))^2) + .5 (m2 * v2f^2)
		//kinetic_Energy = .5 (ml * (momentum * momentum / m1 * m1) - (2 * ((momentum / ml) * (v2f * m2))) + (v2f * m2)^2) + .5 (m2 * v2f^2)
		//m1 * v1i^2 + m2 * v2i^2 = (ml * (momentum^2 / m1^2) - (2 * ((momentum / ml) * (v2f * m2))) + (v2f * m2)^2) + (m2 * v2f^2);
		// (m1 * v1i^2 / m2) + (v2i^2) = (ml * (momentum^2 / m1^2) - (2 * ((momentum / ml) * (v2f * m2))) + (v2f * m2)^2) / m2 + v2f^2
		//(physics1.mass * ((momentum * momentum) / (physics1.mass * physics1.mass)) - ((v2f * physics2.mass) * (v2f * physics2.mass))) + (physics2.mass * v2f * v2f);
		//.5 (m1/ * v1i^2/) + .5 (m2/ * v2i^2/) = .5 (m1/ * v1f^2) + .5 (m2/ * v2f^2);
		temp = physics1.x_Velocity;
		//physics1.x_Velocity = ((physics1.mass - physics2.mass) / (physics1.mass + physics2.mass)) * physics1.x_Velocity;
		//physics2.x_Velocity = ((2 * physics1.mass) / (physics1.mass + physics2.mass)) * temp;
		physics1.x_Velocity = (((physics1.x_Velocity * (physics1.mass - physics2.mass)) + (2 * physics2.mass * physics2.x_Velocity)) / (physics1.mass + physics2.mass));
		physics2.x_Velocity = (((physics2.x_Velocity * (physics2.mass - physics1.mass)) + (2 * physics1.mass * temp)) / (physics1.mass + physics2.mass));//((2 * physics1.mass) / (physics1.mass + physics2.mass)) * temp;
		momentum = (physics1.x_Velocity * physics1.mass) + (physics2.x_Velocity * physics2.mass);
		kinetic_Energy = .5 * ((physics1.mass * physics1.x_Velocity * physics1.x_Velocity) + (physics2.mass * physics2.x_Velocity * physics2.x_Velocity));
		cout << momentum << endl;
		cout << kinetic_Energy << endl;
	}
	//double temporary_X_Velocity = physics1.x_Velocity;
	//physics1.x_Velocity = physics2.x_Velocity * (physics1.mass / physics2.mass);
	//physics2.x_Velocity = temporary_X_Velocity * (physics2.mass / physics1.mass);

	cout << "physics1.x_Velocity = " << physics1.x_Velocity << endl;
	cout << "physics2.x_Velocity = " << physics2.x_Velocity << endl << endl;
//	for(int i = Object::object_Vector_Index; i < Object::object_Vector.size(); i++)
//	{
//		if((*this).x_Position > Object::(*object_Vector[i]).x_Position)
//		{
//			
//		}
}

void Physics::set_X_Gravity(double x_Gravity)
{
	Physics::x_Gravity = x_Gravity;
}

void Physics::set_Y_Gravity(double y_Gravity)
{
	Physics::y_Gravity = y_Gravity;
}

void Physics::set_Z_Gravity(double z_Gravity)
{
	Physics::z_Gravity = z_Gravity;
}

const double Physics::get_X_Gravity()
{
	return Physics::x_Gravity;
}

const double Physics::get_Y_Gravity()
{
	return Physics::y_Gravity;
}

const double Physics::get_Z_Gravity()
{
	return Physics::z_Gravity;
}

void Physics::set_Frame_Rate(double frame_rate)
{
	if(frame_Rate > 0)
	{
		Physics::frame_Rate = frame_rate;
	}
	else
	{
		Physics::frame_Rate = 1;
	}
}

const double Physics::get_Frame_Rate()
{
	return frame_Rate;
}

void Physics::clear_Object()
{
	(*this).x_Position = 0;
	(*this).y_Position = 0;
	(*this).z_Position = 0;
	(*this).x_Length = 0;
	(*this).y_Length = 0;
	(*this).z_Length = 0;
	(*this).angle = 0;
	(*this).x_Velocity = 0;
	(*this).y_Velocity = 0;
	(*this).x_Acceleration = 0;
	(*this).y_Acceleration = 0;
	(*this).elasticity = 0;
	(*this).mass = 1;

	(*this).x_Force = 0;
	(*this).y_Force = 0;
}

void Physics::display_Information()
{
	cout << "x_Position = " << (*this).x_Position << endl;
//	cout << "y_Position = " << (*this).y_Position << endl;
	//cout << (*this).z_Position << endl;
	//cout << (*this).x_Length << endl;
	//cout << (*this).y_Length << endl;
	//cout << (*this).z_Length << endl;
	//cout << (*this).angle << endl;
	cout << "x_Velocity = " << (*this).x_Velocity << endl;
//	cout << "y_Velocity = " << (*this).y_Velocity << endl;
	cout << "x_Acceleration = " << (*this).x_Acceleration << endl;
//	cout << "y_Acceleration = " << (*this).y_Acceleration << endl << endl;
	//cout << (*this).elasticity << endl;
	//cout << (*this).mass << endl << endl;
	
	/*cout << "x_Forces = [";
	for(int i = 0; i < (*this).x_Forces.size(); i++)
	{
		cout << (*this).x_Forces[i] << ", ";
	}
	cout << "]" << endl << endl;
	cout << "y_Forces = [";
	for(int i = 0; i < (*this).y_Forces.size(); i++)
	{
		cout << (*this).y_Forces[i] << ", ";
	}
	cout << "]" << endl << endl;*/
}

const double Physics::get_X_Position()
{
	return (*this).x_Position;
}
