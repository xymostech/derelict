#include "Editor.h"

Editor::Editor() {
	
}

void Editor::Update() {
	
}

void Editor::Draw() {
	glPushMatrix();
		glTranslatef(p1.i, p1.j, 0);

		glColor3f(0, 0, 0);

		glBegin(GL_POLYGON);
		for(float angle=0; angle<2*M_PI; angle += M_PI/4) {
			glVertex2f(cos(angle), sin(angle));
		}
		glEnd();
	glPopMatrix();
}
