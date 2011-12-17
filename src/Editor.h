/*
 * Editor class
 *
 * Holds editable objects, and allows
 * interaction to edit them
 */

#ifndef EDITOR_H
#define EDITOR_H

#include <GL/glfw.h>

#include "Mouse.h"

#include "Vector.h"

class Editor
{
	Vector p1;
public:
	Editor();

	void Update();

	void Draw();
};

#endif
