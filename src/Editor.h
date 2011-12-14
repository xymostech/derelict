/*
 * Editor class
 *
 * Holds editable objects, and allows
 * interaction to edit them
 */

#ifndef EDITOR_H
#define EDITOR_H

#include "Vector.h"

class Editor
{
	Vector p1;
public:
	Editor();

	void Update();

	void Draw();
}
