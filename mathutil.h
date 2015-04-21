#ifndef MATH_UTILITIES
#define MATH_UTILITIES
#include "vector2d.h"
#define MMM_PIE_ 3.14159265358979323846  /* pi */

/* Purpose: Generate a New Random Int within Range */

static int RandNextIntRange(int minValue, int maxValue)
{
	int random = rand();
	int diff = maxValue - minValue + 1; //Includes maxValue in range
	int newRandom = random % diff;
	return minValue + newRandom;
}

/* Purpose: Generate a New Random Double */

static double RandNextDouble()
{
	return (double)rand();
}

/* Purpose: Generate a New Random Float Constrained by a Min and Max */

static float RandNextFloatRange( float minValue, float maxValue)
{
	float random = (float)rand() / (float) RAND_MAX;
	float diff = maxValue - minValue;
	float newRandom = random * diff;
	return minValue + newRandom;
}

/* Purpose: Generate a New Random Vector Constrained by a Min and Max */

static Vector2D RandNextVector2( float minLength, float maxLength)
{
	double theta = RandNextDouble() * 2 * MMM_PIE_;
	float length = RandNextFloatRange(minLength, maxLength);
	Vector2D returnValue(length * (float)cos(theta), length * (float)sin(theta));
	return returnValue;
}

#endif