#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

#include <Box2D/Box2D.h>

class Vector
{
public:
	float i, j;
	
	Vector();
	Vector(float i, float j);

	Vector  operator-  () const;
	
	Vector  operator+  (const Vector& add) const;
	Vector& operator+= (const Vector& add);
	
	Vector  operator-  (const Vector& sub) const;
	Vector& operator-= (const Vector& sub);
	
	Vector  operator*  (const float scale) const;
	Vector  operator/  (const float scale) const;
	
	bool    operator== (const Vector& test) const;
	
	float Cross (const Vector& cross) const;
	float Dot   (const Vector&   dot) const;
	
	float Len() const;
	Vector Norm() const;
	
	b2Vec2 b2() const;
};

#endif
