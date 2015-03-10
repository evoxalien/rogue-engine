//physics.cpp
#include "physics.h"

using namespace std;

double Physics::frame_Rate = 1;
double Physics::time_Of_Next_Collision = 0;

double Physics::x_Gravity = 0;//9.80665;
double Physics::y_Gravity = 9.80665;
double Physics::z_Gravity = -9.80665;

Physics::Physics()
{
	(*this).x_Length = 0;
	(*this).y_Length = 0;
	(*this).z_Length = 0;

	(*this).x_Position = 0;
	(*this).y_Position = 0;
	(*this).z_Position = 0;

	(*this).x_Velocity = 0;
	(*this).y_Velocity = 0;

	(*this).x_Acceleration = 0;
	(*this).y_Acceleration = 0;

	(*this).x_Force = 0;
	(*this).y_Force = 0;

	(*this).angle = 0;
	(*this).elasticity = 1;
	(*this).mass = 1;

//	(*this).objects_Collided_With_This_Frame = {};
}

Physics::Physics(double x_Length, double y_Length, double x_Position, double x_Velocity, double x_Acceleration, double elasticity, double mass)
{
	(*this).x_Length = x_Length;
	(*this).y_Length = y_Length;
	(*this).z_Length = 0;

	(*this).x_Position = x_Position;
	(*this).y_Position = 0;
	(*this).z_Position = 0;

	(*this).x_Velocity = x_Velocity;
	(*this).y_Velocity = 0;

	(*this).x_Acceleration = x_Acceleration;
	(*this).y_Acceleration = 0;

	(*this).x_Force = 0;
	(*this).y_Force = 0;

	(*this).angle = 0;
	(*this).elasticity = elasticity;
	(*this).mass = mass;

//	(*this).objects_Collided_With_This_Frame = {};
}

/*Physics::Physics(double x_Position, double y_Position, double x_Velocity, double y_Velocity, double x_Acceleration, double y_Acceleration, double mass)
{
	(*this).x_Length = 0;
	(*this).y_Length = 0;
	(*this).z_Length = 0;

	(*this).x_Position = x_Position;
	(*this).y_Position = y_Position;
	(*this).z_Position = 0;

	(*this).x_Velocity = x_Velocity;
	(*this).y_Velocity = y_Velocity;

	(*this).x_Acceleration = x_Acceleration;
	(*this).y_Acceleration = y_Acceleration;

	(*this).x_Force = 0;
	(*this).y_Force = 0;

	(*this).angle = 0;
	(*this).elasticity = 0;
	(*this).mass = mass;

//	(*this).objects_Collided_With_This_Frame = {};
}*/

Physics::Physics(double x_Length, double y_Length, double z_Length, double x_Position, double y_Position, double z_Position, double x_Velocity, double y_Velocity, double x_Acceleration, double y_Acceleration, double angle, double elasticity, double mass)
{
	(*this).x_Length = x_Length;
	(*this).y_Length = y_Length;
	(*this).z_Length = z_Length;

	(*this).x_Position = x_Position;
	(*this).y_Position = y_Position;
	(*this).z_Position = z_Position;

	(*this).x_Velocity = x_Velocity;
	(*this).y_Velocity = y_Velocity;

	(*this).x_Acceleration = x_Acceleration;
	(*this).y_Acceleration = y_Acceleration;

	(*this).x_Force = 0;
	(*this).y_Force = 0;

	(*this).angle = angle;
	(*this).elasticity = elasticity;
	(*this).mass = mass;

//	(*this).objects_Collided_With_This_Frame = {};
}

void Physics::move()
{
	(*this).x_Position = (*this).x_Position + ((*this).x_Velocity / Physics::frame_Rate);
	(*this).y_Position = (*this).y_Position + ((*this).y_Velocity / Physics::frame_Rate);
}

void Physics::half_Move()
{
	(*this).x_Position = (*this).x_Position + (((*this).x_Velocity / Physics::frame_Rate) / 2);
	(*this).y_Position = (*this).y_Position + (((*this).y_Velocity / Physics::frame_Rate) / 2);
}

void Physics::negative_Half_Move()
{
	(*this).x_Position = (*this).x_Position - (((*this).x_Velocity / Physics::frame_Rate) / 2);
	(*this).y_Position = (*this).y_Position - (((*this).y_Velocity / Physics::frame_Rate) / 2);
}

void Physics::accelerate()
{
	//cout << "x_Velocity before = " << (*this).x_Velocity << endl;
	//cout << "x_Acceleration before = " << (*this).x_Acceleration << endl;
	//cout << "x_Acceleration / frame_Rate = " << ((*this).x_Acceleration / Physics::frame_Rate);
	(*this).x_Velocity = (*this).x_Velocity + ((*this).x_Acceleration / Physics::frame_Rate);
	(*this).y_Velocity = (*this).y_Velocity + ((*this).y_Acceleration / Physics::frame_Rate);
	//cout << "x_Velocity after = " << (*this).x_Velocity << endl;
	//cout << "x_Acceleration after = " << (*this).x_Acceleration << endl;
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
		(*this).x_Acceleration = (*this).x_Force / (*this).mass;
		(*this).x_Force = 0;
		(*this).y_Acceleration = (*this).y_Force / (*this).mass;
		(*this).y_Force = 0;
	}
	else
	{
		cout << "Not sure what to do with a mass of 0 at the moment" << endl;
	}
}

void Physics::clear_Object()
{
	(*this).x_Length = 0;
	(*this).y_Length = 0;
	(*this).z_Length = 0;

	(*this).x_Position = 0;
	(*this).y_Position = 0;
	(*this).z_Position = 0;

	(*this).x_Velocity = 0;
	(*this).y_Velocity = 0;

	(*this).x_Acceleration = 0;
	(*this).y_Acceleration = 0;

	(*this).x_Force = 0;
	(*this).y_Force = 0;

	(*this).angle = 0;
	(*this).elasticity = 1;
	(*this).mass = 1;

	(*this).objects_Collided_With_This_Frame.clear();
}

void Physics::display_Information()
{
	cout << "x_Position = " << (*this).x_Position << endl;
	cout << "y_Position = " << (*this).y_Position << endl;
	//cout << (*this).z_Position << endl;
	cout << "x_Length = " << (*this).x_Length << endl;
	cout << "y_Length = " << (*this).y_Length << endl;
	//cout << (*this).z_Length << endl;
	//cout << (*this).angle << endl;
	cout << "x_Velocity = " << (*this).x_Velocity << endl;
	cout << "y_Velocity = " << (*this).y_Velocity << endl;
	cout << "x_Acceleration = " << (*this).x_Acceleration << endl;
	cout << "y_Acceleration = " << (*this).y_Acceleration << endl << endl;
	//cout << (*this).elasticity << endl;
	//cout << (*this).mass << endl << endl;	
}

void Physics::check_For_Collisions(vector<Physics*>& physics_Pointer_Vector)
{
	bool pair_Has_Collided = false;
	vector<double> collision_Times;
	//cout << physics_Pointer_Vector.size() << endl;
	for(int i = 0; i < physics_Pointer_Vector.size(); i++)
	{
		//if(physics_Pointer_Vector[i] != NULL)
		//{
		for(int j = i + 1; j < physics_Pointer_Vector.size(); j++)
		{
			//if(physics_Pointer_Vector[j] != NULL)
			//{
			if((*physics_Pointer_Vector[i]).x_Position <= ((*physics_Pointer_Vector[j]).x_Position + (*physics_Pointer_Vector[j]).x_Length))
			{
				if(((*physics_Pointer_Vector[i]).x_Position + (*physics_Pointer_Vector[i]).x_Length) >= (*physics_Pointer_Vector[j]).x_Position)
				{
					if((*physics_Pointer_Vector[i]).y_Position <= ((*physics_Pointer_Vector[j]).y_Position + (*physics_Pointer_Vector[j]).y_Length))
					{
						if(((*physics_Pointer_Vector[i]).y_Position + (*physics_Pointer_Vector[i]).y_Length) >= (*physics_Pointer_Vector[j]).y_Position)
						{
							//cout << "Collision between:" << endl;
							for(int k = 0; k < (*physics_Pointer_Vector[i]).objects_Collided_With_This_Frame.size(); k++)
							{
								if((*physics_Pointer_Vector[i]).objects_Collided_With_This_Frame[k] == physics_Pointer_Vector[j])
								{
									pair_Has_Collided = true;
									//cout << "Pair has already collided." << endl;
								}
							}
							//if(((*physics_Pointer_Vector[i]).get_Has_Collided_This_Frame() == false) || ((*physics_Pointer_Vector[j]).get_Has_Collided_This_Frame() == false))
							if(pair_Has_Collided == false)
							{
								//(*physics_Pointer_Vector[i]).set_Has_Collided_This_Frame(true);
								//(*physics_Pointer_Vector[j]).set_Has_Collided_This_Frame(true);
								resolve_Collisions(physics_Pointer_Vector[i], physics_Pointer_Vector[j]);
							}
							pair_Has_Collided = false;
						}
						else
						{
							//cout << "4th check, no collision between:" << endl;
						}
					}
					else
					{
						//cout << "3rd check, no collision between:" << endl;
					}
				}
				else
				{
					//cout << "2nd check, no collision between:" << endl;
				}
			}
			//}
			else
			{
				//cout << "1st check, no collision between:" << endl;
			}
			//(*physics_Pointer_Vector[i]).display_Information();
			//(*physics_Pointer_Vector[j]).display_Information();
		}
		//}
	}
	
	/*for(int i = 0; i < physics_Pointer_Vector.size(); i++)
	{
		for(int j = i + 1; j < physics_Pointer_Vector.size(); j++)
		{
			if(((*physics_Pointer_Vector[i]).x_Position + ((*physics_Pointer_Vector[i]).x_Velocity * (1 / Physics::frame_Rate))) <= (((*physics_Pointer_Vector[j]).x_Position + (*physics_Pointer_Vector[j]).x_Length) + ((*physics_Pointer_Vector[j]).x_Velocity * (1 / Physics::frame_Rate))))
			{
				cout << "Entered first if" << endl;
				cout << ((*physics_Pointer_Vector[i]).x_Position + ((*physics_Pointer_Vector[i]).x_Velocity * (1 / Physics::frame_Rate))) << " <= " << (((*physics_Pointer_Vector[j]).x_Position + (*physics_Pointer_Vector[j]).x_Length) + ((*physics_Pointer_Vector[j]).x_Velocity * (1 / Physics::frame_Rate))) << endl;
				if((((*physics_Pointer_Vector[i]).x_Position + (*physics_Pointer_Vector[i]).x_Length) + ((*physics_Pointer_Vector[i]).x_Velocity * (1 / Physics::frame_Rate))) >= (((*physics_Pointer_Vector[j]).x_Position) + ((*physics_Pointer_Vector[j]).x_Velocity * (1 / Physics::frame_Rate))))
				{
					cout << "Entered second if" << endl;
					cout << (((*physics_Pointer_Vector[i]).x_Position + (*physics_Pointer_Vector[i]).x_Length) + ((*physics_Pointer_Vector[i]).x_Velocity * (1 / Physics::frame_Rate))) << " >= " << (((*physics_Pointer_Vector[j]).x_Position) + ((*physics_Pointer_Vector[j]).x_Velocity * (1 / Physics::frame_Rate))) << endl;
					if(((*physics_Pointer_Vector[i]).y_Position + ((*physics_Pointer_Vector[i]).y_Velocity * (1 / Physics::frame_Rate))) <= (((*physics_Pointer_Vector[j]).y_Position + (*physics_Pointer_Vector[j]).y_Length) + ((*physics_Pointer_Vector[j]).y_Velocity * (1 / Physics::frame_Rate))))
					{
						cout << "Entered third if" << endl;
						cout << ((*physics_Pointer_Vector[i]).y_Position + ((*physics_Pointer_Vector[i]).y_Velocity * (1 / Physics::frame_Rate))) << " <= " << (((*physics_Pointer_Vector[j]).y_Position + (*physics_Pointer_Vector[j]).y_Length) + ((*physics_Pointer_Vector[j]).y_Velocity * (1 / Physics::frame_Rate))) << endl;
						if((((*physics_Pointer_Vector[i]).y_Position + (*physics_Pointer_Vector[i]).y_Length) + ((*physics_Pointer_Vector[i]).y_Velocity * (1 / Physics::frame_Rate))) >= (((*physics_Pointer_Vector[j]).y_Position) + ((*physics_Pointer_Vector[j]).y_Velocity * (1 / Physics::frame_Rate))))
						{
							cout << "Entered final if" << endl;
							cout << (((*physics_Pointer_Vector[i]).y_Position + (*physics_Pointer_Vector[i]).y_Length) + ((*physics_Pointer_Vector[i]).y_Velocity * (1 / Physics::frame_Rate))) << " >= " << (((*physics_Pointer_Vector[j]).y_Position) + ((*physics_Pointer_Vector[j]).y_Velocity * (1 / Physics::frame_Rate))) << endl;
							cout << "Collision in next frame between: " << i << " and " << j << endl;
							(*physics_Pointer_Vector[i]).display_Information();
							(*physics_Pointer_Vector[j]).display_Information();
						}
					}
				}
			}
		}
	}*/
	
	//cout << "Displaying all objects: " << endl << endl;
	//for(int i = 0; i < physics_Pointer_Vector.size(); i++)
	//{
	//	(*physics_Pointer_Vector[i]).display_Information();
	//}
}

void Physics::resolve_Collisions(Physics* physics_A, Physics* physics_B)
{
	if(((((*physics_A).x_Position - (*physics_B).x_Position) <= 0) && (((*physics_A).x_Velocity - (*physics_B).x_Velocity) > 0)) || ((((*physics_A).x_Position - (*physics_B).x_Position) >= 0) && (((*physics_A).x_Velocity - (*physics_B).x_Velocity) < 0)) || ((((*physics_A).y_Position - (*physics_B).y_Position) <= 0) && (((*physics_A).y_Velocity - (*physics_B).y_Velocity) > 0)) || ((((*physics_A).y_Position - (*physics_B).y_Position) >= 0) && (((*physics_A).y_Velocity - (*physics_B).y_Velocity) < 0)))
	{
	cout.precision(25);
	double physics_A_Squared_Velocity = ((*physics_A).x_Velocity * (*physics_A).x_Velocity) + ((*physics_A).y_Velocity * (*physics_A).y_Velocity);
	double physics_B_Squared_Velocity = ((*physics_B).x_Velocity * (*physics_B).x_Velocity) + ((*physics_B).y_Velocity * (*physics_B).y_Velocity);
	(*physics_A).objects_Collided_With_This_Frame.push_back(physics_B);
	(*physics_B).objects_Collided_With_This_Frame.push_back(physics_A);
	//(*physics_A).set_Has_Collided_This_Frame(true);
	//(*physics_B).set_Has_Collided_This_Frame(true);
	
	
	double physics_A_X_Frame_Of_Reference = (*physics_A).x_Velocity - (*physics_B).x_Velocity;
	double physics_A_Y_Frame_Of_Reference = (*physics_A).y_Velocity - (*physics_B).y_Velocity;
	double physics_B_X_Frame_Of_Reference = (*physics_B).x_Velocity - (*physics_A).x_Velocity;
	double physics_B_Y_Frame_Of_Reference = (*physics_B).y_Velocity - (*physics_A).y_Velocity;
	//cout << "physics_A_Squared_Velocity = " << physics_A_Squared_Velocity << endl;
	//cout << "physics_B_Squared_Velocity = " << physics_B_Squared_Velocity << endl;
	//cout << "physics_A_X_Frame_Of_Reference = " << physics_A_X_Frame_Of_Reference << endl;
	//cout << "physics_A_Y_Frame_Of_Reference = " << physics_A_Y_Frame_Of_Reference << endl;
	//cout << "physics_B_X_Frame_Of_Reference = " << physics_B_X_Frame_Of_Reference << endl;
	//cout << "physics_B_Y_Frame_Of_Reference = " << physics_B_Y_Frame_Of_Reference << endl;
	//cout << "physics_A Frame_Of_Reference Tangent = " << atan2(physics_A_Y_Frame_Of_Reference, physics_A_X_Frame_Of_Reference) * (180 / 3.1415926535898) << endl;
	//cout << "physics_B Frame_Of_Reference Tangent = " << atan2(physics_B_Y_Frame_Of_Reference, physics_A_X_Frame_Of_Reference) * (180 / 3.1415926535898) << endl;
	double physics_A_Velocity_Direction = atan2((*physics_A).y_Velocity, (*physics_A).x_Velocity) * (180 / 3.1415926535898);
	double physics_B_Velocity_Direction = atan2((*physics_B).y_Velocity, (*physics_B).x_Velocity) * (180 / 3.1415926535898);
	double angle_Of_Collision = atan2((((*physics_A).y_Position + ((*physics_A).y_Length / 2.0)) - ((*physics_B).y_Position + ((*physics_B).y_Length / 2.0))), (((*physics_A).x_Position + ((*physics_A).x_Length / 2.0)) - ((*physics_B).x_Position + ((*physics_B).x_Length / 2.0)))) * (180 / 3.1415926535898);
	double elasticity = min((*physics_A).elasticity, (*physics_B).elasticity);
	//cout << "physics_A_Velocity_Direction = " << physics_A_Velocity_Direction << endl;
	//cout << "physics_B_Velocity_Direction = " << physics_B_Velocity_Direction << endl;
	//cout << "angle_Of_Collision = " << angle_Of_Collision << endl;
	//cout << "(*physics_A).x_Velocity = " << (*physics_A).x_Velocity << endl;
	//cout << "(*physics_A).y_Velocity = " << (*physics_A).y_Velocity << endl;
	//cout << "(*physics_B).x_Velocity = " << (*physics_B).x_Velocity << endl;
	//cout << "(*physics_B).y_Velocity = " << (*physics_B).y_Velocity << endl << endl;
	//cout << "(*physics_A).mass = " << (*physics_A).mass << endl;
	//cout << "(*physics_B).mass = " << (*physics_B).mass << endl << endl;

	//if(elasticity  == 0)
	//{
	//	cout << "elasticity = 0" << endl;
	//	(*physics_A).x_Velocity = (((*physics_A).x_Velocity * (*physics_A).mass) + ((*physics_B).x_Velocity * (*physics_B).mass)) / ((*physics_A).mass + (*physics_B).mass);
	//	(*physics_B).x_Velocity = (((*physics_A).x_Velocity * (*physics_A).mass) + ((*physics_B).x_Velocity * (*physics_B).mass)) / ((*physics_A).mass + (*physics_B).mass);
	//}
	//else
	//if(elasticity == 1)
	//{
		
	//}
	//{
//		cout << "elasticity != 0" << endl;
//		cout << "Enter the elasticity: ";
//		cin >> elasticity;
	//	double x_Momentum = ((*physics_A).x_Velocity * (*physics_A).mass) + ((*physics_B).x_Velocity * (*physics_B).mass);
		//double y_Momentum = ((*physics_A).y_Velocity * (*physics_A).mass) + ((*physics_B).y_Velocity * (*physics_B).mass);
	//	double x_Kinetic_Energy = .5 * (((*physics_A).mass * (*physics_A).x_Velocity * (*physics_A).x_Velocity) + ((*physics_B).mass * (*physics_B).x_Velocity * (*physics_B).x_Velocity));
		//double y_Kinetic_Energy = .5 * (((*physics_A).mass * (*physics_A).y_Velocity * (*physics_A).y_Velocity) + ((*physics_B).mass * (*physics_B).y_Velocity * (*physics_B).y_Velocity));
	//	cout << "x_Momentum = " << x_Momentum << endl;
	//	cout << "x_Kinetic_Energy = " << x_Kinetic_Energy << endl;
		//cout << "y_Momentum = " << y_Momentum << endl;
		//cout << "y_Kinetic_Energy = " << y_Kinetic_Energy << endl << endl;
	//	double temp = (*physics_A).x_Velocity;//(((*physics_A).x_Velocity * (*physics_A).mass) + ((*physics_B).x_Velocity * (*physics_B).mass)) / ((*physics_A).mass + (*physics_B).mass);
		double inelastic_Collision_X_Velocities = cos(angle_Of_Collision) * ((((*physics_A).x_Velocity * (*physics_A).mass) + ((*physics_B).x_Velocity * (*physics_B).mass)) / ((*physics_A).mass + (*physics_B).mass)) * (1 - elasticity);
		double elastic_Collision_Physics_A_X_Velocity = cos(angle_Of_Collision) * (((((*physics_A).x_Velocity * ((*physics_A).mass - (*physics_B).mass)) + (2 * (*physics_B).mass * (*physics_B).x_Velocity)) / ((*physics_A).mass + (*physics_B).mass))) * elasticity;
		double elastic_Collision_Physics_B_X_Velocity = cos(angle_Of_Collision) * (((((*physics_B).x_Velocity * ((*physics_B).mass - (*physics_A).mass)) + (2 * (*physics_A).mass * (*physics_A).x_Velocity)) / ((*physics_A).mass + (*physics_B).mass))) * elasticity;
		double inelastic_Collision_Y_Velocities = sin(angle_Of_Collision) * ((((*physics_A).y_Velocity * (*physics_A).mass) + ((*physics_B).y_Velocity * (*physics_B).mass)) / ((*physics_A).mass + (*physics_B).mass)) * (1 - elasticity);
		double elastic_Collision_Physics_A_Y_Velocity = sin(angle_Of_Collision) * (((((*physics_A).y_Velocity * ((*physics_A).mass - (*physics_B).mass)) + (2 * (*physics_B).mass * (*physics_B).y_Velocity)) / ((*physics_A).mass + (*physics_B).mass))) * elasticity;
		double elastic_Collision_Physics_B_Y_Velocity = sin(angle_Of_Collision) * (((((*physics_B).y_Velocity * ((*physics_B).mass - (*physics_A).mass)) + (2 * (*physics_A).mass * (*physics_A).y_Velocity)) / ((*physics_A).mass + (*physics_B).mass))) * elasticity;

		//if((*physics_A).x_Position + (*physics_A).x_Length < (*physics_B).x_Position)
		//{
		//}
		//(*physics_A).x_Velocity = (((*physics_A).mass - (*physics_B).mass) / ((*physics_A).mass + (*physics_B).mass)) * (*physics_A).x_Velocity;
		//(*physics_B).x_Velocity = ((2 * (*physics_A).mass) / ((*physics_A).mass + (*physics_B).mass)) * temp;
		//double temp = (*physics_A).x_Velocity;
		//(*physics_A).x_Velocity = ((((*physics_A).x_Velocity * ((*physics_A).mass - (*physics_B).mass)) + (2 * (*physics_B).mass * (*physics_B).x_Velocity)) / ((*physics_A).mass + (*physics_B).mass));
		//(*physics_B).x_Velocity = ((((*physics_B).x_Velocity * ((*physics_B).mass - (*physics_A).mass)) + (2 * (*physics_A).mass * temp)) / ((*physics_A).mass + (*physics_B).mass));//((2 * (*physics_A).mass) / ((*physics_A).mass + (*physics_B).mass)) * temp;

		//Physics::time_Of_Next_Collision = 
		double physics_A_Required_X_Force = (((inelastic_Collision_X_Velocities + elastic_Collision_Physics_A_X_Velocity) - (*physics_A).get_X_Velocity()) * (*physics_A).get_Mass() * Physics::get_Frame_Rate());//, (*physics_A).get_X_Force();// * Physics::get_Frame_Rate();
		double physics_A_Required_Y_Force = ((inelastic_Collision_Y_Velocities + elastic_Collision_Physics_A_Y_Velocity) - (*physics_A).get_Y_Velocity()) * (*physics_A).get_Mass() * Physics::get_Frame_Rate();//, (*physics_A).get_Y_Force();// * Physics::get_Frame_Rate();
		double physics_B_Required_X_Force = ((inelastic_Collision_X_Velocities + elastic_Collision_Physics_B_X_Velocity) - (*physics_B).get_X_Velocity()) * (*physics_B).get_Mass() * Physics::get_Frame_Rate();//, (*physics_B).get_X_Force();// * Physics::get_Frame_Rate();
		double physics_B_Required_Y_Force = ((inelastic_Collision_Y_Velocities + elastic_Collision_Physics_B_Y_Velocity) - (*physics_B).get_Y_Velocity()) * (*physics_B).get_Mass() * Physics::get_Frame_Rate();//, (*physics_B).get_Y_Force();// * Physics::get_Frame_Rate();
	//	if(abs(((inelastic_Collision_X_Velocities + elastic_Collision_Physics_A_X_Velocity) - (*physics_A).get_X_Velocity()) * (*physics_A).get_Mass() * Physics::get_Frame_Rate()) > abs((*physics_A).get_X_Force()))
	//	{
//			if(abs(((inelastic_Collision_X_Velocities + elastic_Collision_Physics_A_X_Velocity) - (*physics_A).get_X_Velocity())) > .1)
//			{
				(*physics_A).set_X_Force(physics_A_Required_X_Force);
//			}
	//	}
	//	if(abs(((inelastic_Collision_Y_Velocities + elastic_Collision_Physics_A_Y_Velocity) - (*physics_A).get_Y_Velocity()) * (*physics_A).get_Mass() * Physics::get_Frame_Rate()) > abs((*physics_A).get_Y_Force()))
	//	{
//			if(abs(((inelastic_Collision_Y_Velocities + elastic_Collision_Physics_A_Y_Velocity) - (*physics_A).get_Y_Velocity())) > .1)
//			{
				(*physics_A).set_Y_Force(physics_A_Required_Y_Force);
//			}
	//	}
	//	if(abs(((inelastic_Collision_X_Velocities + elastic_Collision_Physics_B_X_Velocity) - (*physics_B).get_X_Velocity()) * (*physics_B).get_Mass() * Physics::get_Frame_Rate()) > abs((*physics_B).get_X_Force()))
	//	{
//			if(abs(((inelastic_Collision_X_Velocities + elastic_Collision_Physics_B_X_Velocity) - (*physics_B).get_X_Velocity())) > .1)
//			{
				(*physics_B).set_X_Force(physics_B_Required_X_Force);
//			}
	//	}
	//	if(abs(((inelastic_Collision_Y_Velocities + elastic_Collision_Physics_B_Y_Velocity) - (*physics_B).get_Y_Velocity()) * (*physics_B).get_Mass() * Physics::get_Frame_Rate()) > abs((*physics_B).get_Y_Force()))
	//	{
//			if(abs(((inelastic_Collision_Y_Velocities + elastic_Collision_Physics_B_Y_Velocity) - (*physics_B).get_Y_Velocity())) > .1)
//			{
				(*physics_B).set_Y_Force(physics_B_Required_Y_Force);
//			}
	//	}

		//cout << "Desired physics A Y velocity: " << inelastic_Collision_Y_Velocities + elastic_Collision_Physics_A_Y_Velocity << endl;
		//cout << "Desired physics B Y velocity: " << inelastic_Collision_Y_Velocities + elastic_Collision_Physics_B_Y_Velocity << endl;
		//cout << "physics_A_Required_X_Force = " << physics_A_Required_X_Force << endl;
		//cout << "physics_A_Required_Y_Force = " << physics_A_Required_Y_Force << endl;
		//cout << "physics_B_Required_X_Force = " << physics_B_Required_X_Force << endl;
		//cout << "physics_B_Required_Y_Force = " << physics_B_Required_Y_Force << endl << endl;
		//(*physics_A).set_X_Force(physics_A_Required_X_Force);
		//(*physics_A).set_Y_Force(physics_A_Required_Y_Force);
		//(*physics_B).set_X_Force(physics_B_Required_X_Force);
		//(*physics_B).set_Y_Force(physics_B_Required_Y_Force);
		//(*physics_A).x_Velocity = inelastic_Collision_X_Velocities + elastic_Collision_Physics_A_X_Velocity;
		//(*physics_B).x_Velocity = inelastic_Collision_X_Velocities + elastic_Collision_Physics_B_X_Velocity;
		//(*physics_A).y_Velocity = inelastic_Collision_Y_Velocities + elastic_Collision_Physics_A_Y_Velocity;
		//(*physics_B).y_Velocity = inelastic_Collision_Y_Velocities + elastic_Collision_Physics_B_Y_Velocity;

	//	x_Momentum = ((*physics_A).x_Velocity * (*physics_A).mass) + ((*physics_B).x_Velocity * (*physics_B).mass);
	//	x_Kinetic_Energy = .5 * (((*physics_A).mass * (*physics_A).x_Velocity * (*physics_A).x_Velocity) + ((*physics_B).mass * (*physics_B).x_Velocity * (*physics_B).x_Velocity));
	//	cout << "x_Momentum = " << x_Momentum << endl;
	//	cout << "x_Kinetic_Energy = " << x_Kinetic_Energy << endl;
		//cout << "y_Momentum = " << y_Momentum << endl;
		//cout << "y_Kinetic_Energy = " << y_Kinetic_Energy << endl << endl;
	//}
	//double temporary_X_Velocity = (*physics_A).x_Velocity;
	//(*physics_A).x_Velocity = (*physics_B).x_Velocity * ((*physics_A).mass / (*physics_B).mass);
	//(*physics_B).x_Velocity = temporary_X_Velocity * ((*physics_B).mass / (*physics_A).mass);

	//cout << "(*physics_A).x_Velocity = " << (*physics_A).x_Velocity << endl;
	//cout << "(*physics_B).x_Velocity = " << (*physics_B).x_Velocity << endl;
	//cout << "(*physics_A).y_Velocity = " << (*physics_A).y_Velocity << endl;
	//cout << "(*physics_B).y_Velocity = " << (*physics_B).y_Velocity << endl << endl;

//	for(int i = Object::object_Vector_Index; i < Object::object_Vector.size(); i++)
//	{
//		if((*this).x_Position > Object::(*object_Vector[i]).x_Position)
//		{
//			
//		}
	}
}

const double Physics::get_X_Gravity()
{
	return Physics::x_Gravity;
}

void Physics::set_X_Gravity(double x_Gravity)
{
	Physics::x_Gravity = x_Gravity;
}

const double Physics::get_Y_Gravity()
{
	return Physics::y_Gravity;
}

void Physics::set_Y_Gravity(double y_Gravity)
{
	Physics::y_Gravity = y_Gravity;
}

const double Physics::get_Z_Gravity()
{
	return Physics::z_Gravity;
}

void Physics::set_Z_Gravity(double z_Gravity)
{
	Physics::z_Gravity = z_Gravity;
}

const double Physics::get_Frame_Rate()
{
	return frame_Rate;
}

void Physics::set_Frame_Rate(double frame_rate)
{
	if(frame_Rate > 4)		//A frame rate of 4 indicates the last frame took over .25 seconds, which indicates there was likely a pause; 4 is arbitrarily chosen, needs to be made modifiable
	{
		Physics::frame_Rate = frame_rate;
	}
	else
	{
		Physics::frame_Rate = 60;	//Frame rate is currently assumed to be 60, needs to get access to desired frame rate later instead of a static value
	}
}

const double Physics::get_X_Length()
{
	return (*this).x_Length;
}

void Physics::set_X_Length(double x_Length)
{
	(*this).x_Length = x_Length;
}

const double Physics::get_Y_Length()
{
	return (*this).y_Length;
}

void Physics::set_Y_Length(double y_Length)
{
	(*this).y_Length = y_Length;
}

const double Physics::get_X_Position()
{
	return (*this).x_Position;
}

void Physics::set_X_Position(double x_Position)
{
	(*this).x_Position = x_Position;
}

const double Physics::get_Y_Position()
{
	return (*this).y_Position;
}

void Physics::set_Y_Position(double y_Position)
{
	(*this).y_Position = y_Position;
}

const double Physics::get_X_Velocity()
{
	return (*this).x_Velocity;
}

void Physics::set_X_Velocity(double x_Velocity)
{
	(*this).x_Velocity = x_Velocity;
}

const double Physics::get_Y_Velocity()
{
	return (*this).y_Velocity;
}

void Physics::set_Y_Velocity(double y_Velocity)
{
	(*this).y_Velocity = y_Velocity;
}

const double Physics::get_X_Acceleration()
{
	return (*this).x_Acceleration;
}

void Physics::set_X_Acceleration(double x_Acceleration)
{
	(*this).x_Acceleration = x_Acceleration;
}

const double Physics::get_Y_Acceleration()
{
	return (*this).y_Acceleration;
}

void Physics::set_Y_Acceleration(double y_Acceleration)
{
	(*this).y_Acceleration = y_Acceleration;
}

const double Physics::get_X_Force()
{
	return (*this).x_Force;
}

void Physics::set_X_Force(double x_Force)
{
	(*this).x_Force = x_Force;
}

const double Physics::get_Y_Force()
{
	return (*this).y_Force;
}

void Physics::set_Y_Force(double y_Force)
{
	(*this).y_Force = y_Force;
}

const double Physics::get_Angle()
{
	return (*this).angle;
}

void Physics::set_Angle(double angle)
{
	(*this).angle = angle;
}

const double Physics::get_Elasticity()
{
	return (*this).elasticity;
}

void Physics::set_Elasticity(double elasticity)
{
	(*this).elasticity = elasticity;
}

const double Physics::get_Mass()
{
	return (*this).mass;
}

void Physics::set_Mass(double mass)
{
	(*this).mass = mass;
}

const vector<Physics*> Physics::get_Objects_Collided_With_This_Frame()
{
	return (*this).objects_Collided_With_This_Frame;
}

void Physics::set_Objects_Collided_With_This_Frame(vector<Physics*> objects_Collided_With_This_Frame)
{
	(*this).objects_Collided_With_This_Frame = objects_Collided_With_This_Frame;
}

void Physics::clear_Objects_Collided_With_This_Frame()
{
	(*this).objects_Collided_With_This_Frame.clear();
}
