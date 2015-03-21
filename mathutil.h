#ifndef MATH_UTILITIES
#define MATH_UTILITIES
#include "vector2d.h"
#define MMM_PIE_ 3.14159265358979323846  /* pi */

/* Purpose: Generate a New Random Double */

static double NextDouble()
{
	return (double)rand();
}

/* Purpose: Generate a New Random Float Constrained by a Min and Max */

static float NextFloat( float minValue, float maxValue)
{
	return (float)NextDouble() * (maxValue - minValue) + minValue;
}

/* Purpose: Generate a New Random Vector Constrained by a Min and Max */

static Vector2D NextVector2( float minLength, float maxLength)
{
	double theta = NextDouble() * 2 * MMM_PIE_;
	float length = NextFloat(minLength, maxLength);
	Vector2D returnValue(length * (float)cos(theta), length * (float)sin(theta));
	return returnValue;
}

#endif