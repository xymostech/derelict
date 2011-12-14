/*
 * Editmain.cpp
 *
 * main file for world editor app
 */

#include <iostream>
#include <GL/glfw.h>

#include "Key.h"
#include "Cam.h"
#include "World.h"

#include "DisplayFuncs.h"

World w;

void Init() {
	glClearColor(1, 1, 1, 0);

	w.Load("world/main.world");
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	w.Draw();

	glPushMatrix();

	glTranslatef(0, 0, 5.0);

	glColor3f(1, 0, 0);

	Pyramid();

	glTranslatef(0, 0, 5.0);

	glColor3f(0, 1, 0);

	Cube();

	glPopMatrix();
}

void Update() {
	w.Update();
}

int main(int argc, char ** argv) {
	glfwInit();

	glfwOpenWindow(800, 600, 0, 0, 0, 0, 16, 0, GLFW_WINDOW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	Init();

	glfwSetKeyCallback(Key::KeyEvent);
	glfwSetWindowSizeCallback(Cam::ResizeCallback);

	bool running = true;

	while(running) {
		Display();

		Update();
		Key::I().Update();

		glfwSwapBuffers();

		running = !glfwGetKey(GLFW_KEY_ESC) &&
		          glfwGetWindowParam(GLFW_OPENED);
		
		glfwSleep(0.01);
	}

	glfwCloseWindow();

	glfwTerminate();
}
