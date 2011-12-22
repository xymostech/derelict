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
	bool mouse_button_[2][3];

	Mouse();
	Mouse(Mouse const&);
	void operator=(Mouse const&);
public:
	static Mouse& I();

	static void GLFWCALL MouseMove(int x, int y);
	static void GLFWCALL MouseButton(int button, int action);

	void Update();
	
	Vector Pos();
	Vector WorldPos();
	
	enum State {
		PRESSED  = 0x01,
		RELEASED = 0x02,
		HELD     = 0x04,
		EDGE     = 0x08
	};

	bool Pressed(int button, int state = PRESSED);
};

#endif
