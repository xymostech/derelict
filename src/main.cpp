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
#include "Player.h"

#include "DisplayFuncs.h"

Player p;

void Init() {
	glClearColor(1, 1, 1, 0);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	p.Draw();

	glPushMatrix();

	glTranslatef(0, 0, 5.0);

	glColor3f(1, 0, 0);

	Pyramid();

	glTranslatef(0, 0, 5.0);

	glColor3f(0, 1, 0);

	Cube();

	glPopMatrix();


	for(int i=-10; i<=10; ++i) {
		glPushMatrix();

		glTranslatef(i/2.0, -.5, 0.5);

		glColor3f(0.2, 0.2, 0.2);

		Cube();

		glTranslatef(0, 0, -0.5);

		glColor3f(0.2, 0.2, 0.2);

		Cube();

		glTranslatef(0, 0, -0.5);

		glColor3f(0.2, 0.2, 0.2);

		Cube();

		glPopMatrix();
	}
}

void Update() {
	p.HandleControls();

	p.Update();

	Cam::I().SetPos(p.GetPos());
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
