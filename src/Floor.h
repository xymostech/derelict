/*
 * Floor
 *
 * Holds a floor part, which a
 * player can stand on
 */

#ifndef FLOOR_H
#define FLOOR_H

#include <GL/glfw.h>

#include "WorldObject.h"

#include "Vector.h"

class Floor : public WorldObject
{
	Vector diff_;

	float m_, b_;
public:
	Floor(Vector l, Vector r);

	bool  Below(Vector p);
	bool  Inside(Vector p);
	float SurfacePoint(float x);

	void Draw();
	void Update();

	friend class Editor;
};

#endif
