/*
 * Mouse class
 *
 * Handles callbacks for mouse movements
 */

#ifndef MOUSE_H
#define MOUSE_H

#include <GL/glfw.h>

#include "Cam.h"

#include "Vector.h"

class Mouse
{
	Vector pos_;
	bool mouse_button_[3];

	Mouse();
	Mouse(Mouse const&);
	void operator=(Mouse const&);
public:
	static Mouse& I();

	static void GLFWCALL MouseMove(int x, int y);
	static void GLFWCALL MouseButton(int button, int action);

	Vector Pos();
	Vector WorldPos();
	
	bool Pressed(int button);
};

#endif
