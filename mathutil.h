#ifndef MATH_UTILITIES_
#define MATH_UTILITIES_
#include "vector2d.h"
#define MMM_PIE_ 3.14159265358979323846  /* pi */

/* Purpose: Generate a New Random Float Constrained by a Min and Max */

static float NextFloat(this auto rand, float minValue, float maxValue)
{

	return (float)rand.NextDouble() * (maxValue - minValue) + minValue;
}

/* Purpose: Generate a New Random Vector Constrained by a Min and Max */

static Vector2D NextVector2(this auto rand, float minLength, float maxLength)
{
	double theta = rand.NextDouble() * 2 * MMM_PIE_;
	float length = rand.NextFloat(minLength, maxLength);
	return new Vector2D(length * (float)cos(theta), length * (float)sin(theta));
}


#endif