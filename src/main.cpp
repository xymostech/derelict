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

Player p;

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

	glBegin(GL_TRIANGLES);
		glVertex3f(0, -.25, -.433);
		glVertex3f(-.375, -.25, .2165);
		glVertex3f( .375, -.25, .2165);
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

	glBegin(GL_LINE_LOOP);
		glVertex3f(0, -.25, -.433);
		glVertex3f(-.375, -.25, .2165);
		glVertex3f( .375, -.25, .2165);
	glEnd();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(0, 0, 0);

	glPushMatrix();

	glTranslatef(p.GetPos().i,
	             p.GetPos().j,
		     0);

	Pyramid();

	glPopMatrix();

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
	if(Key::I().Pressed('D')) {
		p.Right();
	} else if(Key::I().Pressed('A')) {
		p.Left();
	}

	if(Key::I().Pressed('W') &&
	   p.OnGround()) {
		p.Jump();
	}

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
