/*
 * Wall class
 *
 * Stores a wall segment
 */
#ifndef WALL_H
#define WALL_H

#include <GL/glfw.h>

#include "WorldObject.h"

#include "Vector.h"

class Wall : public WorldObject
{
public:
	Wall(Vector b, Vector t);

	bool OnLeft(Vector p);
	bool Between(Vector p);

	float Left();
	float Right();

	void Draw();
	void Update();

	friend class Editor;
};

#endif
