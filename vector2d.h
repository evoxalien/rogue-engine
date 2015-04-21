#ifndef VECTOR_2D
#define VECTOR_2D

#include <math.h>

// Used Daniel Soltyka's Vector Library as my guidline for this.
// Source : http://www.danielsoltyka.com/programming/2010/05/30/c-vector2d-rectangle-classes/

class Vector2D
{

public:
	Vector2D( float x = 0.0, float y = 0.0 );
	~Vector2D() {};

	void Rotate( const float angle );
	float Magnitude() const;
	float Normalize();
	float DotProduct( const Vector2D& v2 ) const;
	float CrossProduct( const Vector2D& v2 ) const;

	static Vector2D Zero();
	static float Distance( const Vector2D& v1, const Vector2D& v2 );

	Vector2D& operator = ( const Vector2D& v2 );

	Vector2D& operator += ( const Vector2D& v2 );
	Vector2D& operator -= ( const Vector2D& v2 );
	Vector2D& operator *= ( const float scalar );
	Vector2D& operator /= ( const float scalar );

	const Vector2D operator + ( const Vector2D& v2 ) const;
	const Vector2D operator - ( const Vector2D& v2 ) const;
	const Vector2D operator * ( const float scalar ) const;
	const Vector2D operator / ( const float scalar ) const;

	bool operator == ( const Vector2D& v2 ) const;
	bool operator != ( const Vector2D& v2 ) const;

	float x;
	float y;

};

#endif
