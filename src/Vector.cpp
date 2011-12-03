#include "Vector.h"

Vector::Vector() : i(0), j(0)
{
	
}

Vector::Vector(float i, float j) : i(i), j(j)
{
	
}

Vector Vector::operator-  () const
{
	return Vector(-i, -j);
}

Vector Vector::operator+  (const Vector& add) const
{
	return Vector(i+add.i, j+add.j);
}

Vector& Vector::operator+= (const Vector& add)
{
	i+=add.i;
	j+=add.j;
	return *this;
}

Vector Vector::operator-  (const Vector& sub) const
{
	return Vector(i-sub.i, j-sub.j);
}

Vector& Vector::operator-= (const Vector& sub)
{
	i+=sub.i;
	j+=sub.j;
	return *this;
}
	
Vector  Vector::operator*  (const float scale) const
{
	return Vector(i*scale, j*scale);
}

Vector Vector::operator/  (const float scale) const
{
	return Vector(i/scale, j/scale);
}

bool Vector::operator== (const Vector& test) const
{
	return (*this-test).Len() < 0.01;
}

float Vector::Cross (const Vector& cross) const
{
	return i*cross.j-j*cross.i;
}

float Vector::Dot   (const Vector&   dot) const
{
	return i*dot.i+j*dot.j;
}

float Vector::Len() const
{
	return sqrt(i*i+j*j);
}

Vector Vector::Norm() const
{
    if(Len() == 0) // might want a better check for null vec
        return *this;
    else
	return *this/Len();
}

b2Vec2 Vector::b2() const
{
	return b2Vec2(i,j);
}
