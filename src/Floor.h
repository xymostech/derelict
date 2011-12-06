/*
 * Floor
 *
 * Holds a floor part, which a
 * player can stand on
 */

#ifndef FLOOR_H
#define FLOOR_H

#include "Vector.h"

class Floor {
	Vector l_, r_, diff_;

	float m_, b_;
public:
	Floor(Vector l, Vector r);

	bool  Below(Vector p);
	float SurfacePoint(float x);
};

#endif
