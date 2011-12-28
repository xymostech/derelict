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

#include "WorldObject.h"

#include "Floor.h"
#include "Wall.h"

#include "Mouse.h"
#include "Key.h"

#include "Vector.h"

using std::vector;

class Editor
{
	vector<WorldObject*> objects_;

	Vector* grabbed_pt_;

	Vector cam_pos_;
	Vector pan_start_;

	Vector store_pt_;

	enum Mode {
		MODE_NOTHING,
		MODE_MOVE_POINT,
		MODE_PAN,
		MODE_ADD_FLOOR_1,
		MODE_ADD_FLOOR_2,
		MODE_ADD_WALL_1,
		MODE_ADD_WALL_2
	} mode_;

	void DrawHandle(Vector pos);

	Vector AdjustedMousePos();
public:
	Editor();

	void Update();

	void Draw();
};

#endif
