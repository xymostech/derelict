/*
 * main.cpp
 *
 * main file for derelict app
 *
 * starts GLUT and runs callbacks
 */

#include <iostream>
#include <GL/glfw.h>

void Init() {
	glClearColor(1, 1, 1, 0);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}	


int main(int argc, char ** argv) {
	glfwInit();

	glfwOpenWindow(800, 600, 0, 0, 0, 0, 16, 0, GLFW_WINDOW);

	Init();

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
