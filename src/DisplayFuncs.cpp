#include "DisplayFuncs.h"

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
