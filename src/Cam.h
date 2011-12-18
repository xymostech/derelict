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

#include "Vector.h"

class Cam {
	Cam();

	Cam(const Cam&);
	void operator=(const Cam&);
	
	int screen_size_[2];
	float zoom_;
	Vector pos_;

	void SetupProjection();
	void SetupView();
public:
	static Cam& I();

	static void GLFWCALL ResizeCallback(int width, int height);
	
	int Width();
	int Height();
	int HalfWidth();
	int HalfHeight();

	void SetZoom(float zoom);
	void SetPos(Vector pos);

	Vector GetMaxCoord(float z);

	float  GetZoom();
	Vector GetPos();
};

#endif
