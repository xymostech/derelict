/*
 * main.cpp
 *
 * main file for derelict app
 *
 * starts GLUT and runs callbacks
 */

#include <iostream>
#include <GL/glfw.h>

#include "Key.h"
#include "Cam.h"

void Init() {
	glClearColor(1, 1, 1, 0);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(
}	

int main(int argc, char ** argv) {
	glfwInit();

	glfwOpenWindow(800, 600, 0, 0, 0, 0, 16, 0, GLFW_WINDOW);

	Init();

	glfwSetKeyCallback(Key::KeyEvent);
	glfwSetWindowSizeCallback(Cam::ResizeCallback);

	bool running = true;

	while(running) {
		Display();

		glfwSwapBuffers();

		running = !glfwGetKey(GLFW_KEY_ESC) &&
		          glfwGetWindowParam(GLFW_OPENED);
	}

	glfwCloseWindow();

	glfwTerminate();
}
