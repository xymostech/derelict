/*
 * Editor class
 *
 * Holds editable objects, and allows
 * interaction to edit them
 */

#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include <GL/glfw.h>

#include "Mouse.h"

#include "Vector.h"

class Editor
{
	Vector p1;
	Vector p2;

	Vector* grabbed_pt_;
	bool grabbed_;

	Vector cam_pos_;
	Vector pan_start_;
	Vector pan_diff_;

	int mode_;

	enum Mode {
		MODE_NOTHING,
		MODE_MOVE_POINT,
		MODE_PAN
	};

	void DrawHandle();
public:
	Editor();

	void Update();

	void Draw();
};

#endif
