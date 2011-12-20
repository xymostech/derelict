/*
 * Editor class
 *
 * Holds editable objects, and allows
 * interaction to edit them
 */

#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include <vector>
#include <GL/glfw.h>

#include "Floor.h"

#include "Mouse.h"
#include "Key.h"

#include "Vector.h"

using std::vector;

class Editor
{
	vector<Floor> floors_;

	Vector* grabbed_pt_;

	Vector cam_pos_;
	Vector pan_start_;

	int mode_;

	enum Mode {
		MODE_NOTHING,
		MODE_MOVE_POINT,
		MODE_PAN,
		MODE_ADD_POINT
	};

	void DrawHandle();
public:
	Editor();

	void Update();

	void Draw();
};

#endif
