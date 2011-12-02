/*
 * Cam class
 *
 * Stores information about the screen and the
 * camera position
 */

#ifndef CAM_H
#define CAM_H

#include <iostream>

#include <GL/glfw.h>

class Cam {
	Cam();

	Cam(const Cam&);
	void operator=(const Cam&);
	
	int screen_size_[2];
public:
	static Cam& I();

	static void GLFWCALL ResizeCallback(int width, int height);
	
	int Width();
	int Height();
	int HalfWidth();
	int HalfHeight();
};

#endif
