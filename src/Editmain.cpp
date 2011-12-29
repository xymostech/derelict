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
#include "Mouse.h"
#include "Editor.h"

#include "DisplayFuncs.h"

Editor e;

void Init() {
	glClearColor(1, 1, 1, 0);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	e.Draw();
}

void Update() {
	e.Update();
}

int main(int argc, char ** argv) {
	glfwInit();

	glfwOpenWindow(800, 600, 0, 0, 0, 0, 16, 0, GLFW_WINDOW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	Init();

	glfwSetKeyCallback(Key::KeyEvent);
	glfwSetWindowSizeCallback(Cam::ResizeCallback);

	glfwSetMousePosCallback(Mouse::MouseMove);
	glfwSetMouseButtonCallback(Mouse::MouseButton);

	bool running = true;

	while(running) {
		Display();

		Update();
		Key::I().Update();
		Mouse::I().Update();

		glfwSwapBuffers();

		running = !glfwGetKey(GLFW_KEY_ESC) &&
		          glfwGetWindowParam(GLFW_OPENED);
		
		glfwSleep(0.01);
	}

	glfwCloseWindow();

	glfwTerminate();
}
