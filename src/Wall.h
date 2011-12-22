/*
 * Wall class
 *
 * Stores a wall segment
 */
#ifndef WALL_H
#define WALL_H

#include <GL/glfw.h>

#include "Vector.h"

class Wall
{
	Vector b_, t_;
public:
	Wall(Vector b, Vector t);

	bool OnLeft(Vector p);
	bool Between(Vector p);

	float Left();
	float Right();

	void Draw();

	friend class Editor;
};

#endif
