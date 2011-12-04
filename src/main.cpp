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

	glColor3f(0, 0, 0);
	
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f( 0,  0);
		glVertex2f(1,  0);
		glVertex2f( 0, 1);
	glEnd();
}

void Update() {
	if(Key::I().Pressed('D')) {
		Vector pos = Cam::I().GetPos();
		pos.i += 0.1;
		Cam::I().SetPos(pos);
	} else if(Key::I().Pressed('A')) {
		Vector pos = Cam::I().GetPos();
		pos.i -= 0.1;
		Cam::I().SetPos(pos);
	}
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
