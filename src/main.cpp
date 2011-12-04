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

void Cube() {
	glBegin(GL_QUADS);
		glVertex3f(-0.25, -0.25, -0.25);
		glVertex3f( 0.25, -0.25, -0.25);
		glVertex3f( 0.25,  0.25, -0.25);
		glVertex3f(-0.25,  0.25, -0.25);

		glVertex3f(-0.25, -0.25,  0.25);
		glVertex3f( 0.25, -0.25,  0.25);
		glVertex3f( 0.25,  0.25,  0.25);
		glVertex3f(-0.25,  0.25,  0.25);

		glVertex3f(-0.25, -0.25, -0.25);
		glVertex3f(-0.25,  0.25, -0.25);
		glVertex3f(-0.25,  0.25,  0.25);
		glVertex3f(-0.25, -0.25,  0.25);

		glVertex3f( 0.25, -0.25, -0.25);
		glVertex3f( 0.25,  0.25, -0.25);
		glVertex3f( 0.25,  0.25,  0.25);
		glVertex3f( 0.25, -0.25,  0.25);

		glVertex3f(-0.25, -0.25, -0.25);
		glVertex3f(-0.25, -0.25,  0.25);
		glVertex3f( 0.25, -0.25,  0.25);
		glVertex3f( 0.25, -0.25, -0.25);

		glVertex3f(-0.25,  0.25, -0.25);
		glVertex3f(-0.25,  0.25,  0.25);
		glVertex3f( 0.25,  0.25,  0.25);
		glVertex3f( 0.25,  0.25, -0.25);
	glEnd();

	glColor3f(1, 1, 1);

	glBegin(GL_LINE_LOOP);
		glVertex3f(-0.25, -0.25, -0.25);
		glVertex3f( 0.25, -0.25, -0.25);
		glVertex3f( 0.25,  0.25, -0.25);
		glVertex3f(-0.25,  0.25, -0.25);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex3f(-0.25, -0.25,  0.25);
		glVertex3f( 0.25, -0.25,  0.25);
		glVertex3f( 0.25,  0.25,  0.25);
		glVertex3f(-0.25,  0.25,  0.25);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-0.25, -0.25, -0.25);
		glVertex3f(-0.25, -0.25,  0.25);

		glVertex3f( 0.25, -0.25, -0.25);
		glVertex3f( 0.25, -0.25,  0.25);

		glVertex3f( 0.25,  0.25, -0.25);
		glVertex3f( 0.25,  0.25,  0.25);

		glVertex3f(-0.25,  0.25, -0.25);
		glVertex3f(-0.25,  0.25,  0.25);
	glEnd();
}

void Pyramid() {
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 0.5, 0);
		
		glVertex3f(0, -.25, -.433);
		glVertex3f(-.375, -.25, .2165);
		glVertex3f( .375, -.25, .2165);
		glVertex3f(0, -.25, -.433);
	glEnd();

	glColor3f(1, 1, 1);

	glBegin(GL_LINES);
		glVertex3f(0, 0.5, 0);
		glVertex3f(0, -.25, -.433);

		glVertex3f(0, 0.5, 0);
		glVertex3f(-.375, -.25, .2165);

		glVertex3f(0, 0.5, 0);
		glVertex3f( .375, -.25, .2165);
	glEnd();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(0, 0, 0);

	Cube();

	glPushMatrix();

	glTranslatef(0, 0, 5.0);

	glColor3f(1, 0, 0);

	Pyramid();

	glTranslatef(0, 0, 5.0);

	glColor3f(0, 1, 0);

	Cube();

	glPopMatrix();
	
	//glBegin(GL_TRIANGLE_STRIP);
		//glVertex2f( 0,  0);
		//glVertex2f(1,  0);
		//glVertex2f( 0, 1);
	//glEnd();

	//glColor3f(1, 0, 0);

	//glBegin(GL_TRIANGLE_STRIP);
		//glVertex3f( 0, 0, 1);
		//glVertex3f( 1, 0, 1);
		//glVertex3f( 0, 1, 1);
	//glEnd();

	//glColor3f(0, 1, 0);

	//glBegin(GL_TRIANGLE_STRIP);
		//glVertex3f( 0, 0, 2);
		//glVertex3f( 1, 0, 2);
		//glVertex3f( 0, 1, 2);
	//glEnd();
}

void Update() {
	if(Key::I().Pressed('D')) {
		Vector pos = Cam::I().GetPos();
		pos.i -= 0.1;
		Cam::I().SetPos(pos);
	} else if(Key::I().Pressed('A')) {
		Vector pos = Cam::I().GetPos();
		pos.i += 0.1;
		Cam::I().SetPos(pos);
	}
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
