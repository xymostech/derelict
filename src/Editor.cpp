#include "Editor.h"

Editor::Editor() {
	mode_ = 0;
}

void Editor::DrawHandle() {
	glBegin(GL_POLYGON);
		for(float ang = 0; ang < 2*M_PI; ang += M_PI/8) {
			glVertex2f(0.03 * cos(ang), 0.03 * sin(ang));
		}
	glEnd();

	glBegin(GL_LINE_LOOP);
		for(float ang = 0; ang < 2*M_PI; ang += M_PI/8) {
			glVertex2f(0.2 * cos(ang), 0.2 * sin(ang));
		}
	glEnd();
}

void Editor::Update() {
	if(mode_ == 0) {
		if(Mouse::I().Pressed(0)) {
			if((p1 - Mouse::I().WorldPos()).Len() < 0.2) {
				grabbed_ = true;
				grabbed_pt_ = &p1;
			} else if((p2 - Mouse::I().WorldPos()).Len() < 0.2) {
				grabbed_ = true;
				grabbed_pt_ = &p2;
			}
			if(grabbed_)
				*grabbed_pt_ = Mouse::I().WorldPos();
			mode_ = 1;
		}
	} else if(mode_ == 1) {
		if(!Mouse::I().Pressed(0)) {
			mode_ = 0;
			grabbed_ = false;
		} else {
			if(grabbed_)
				*grabbed_pt_ = Mouse::I().WorldPos();
		}
		
	}
}

void Editor::Draw() {
	glPushMatrix();
		glTranslatef(p1.i, p1.j, 0);

		glColor3f(0, 0, 0);

		DrawHandle();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(p2.i, p2.j, 0);

		glColor3f(0, 0, 0);

		DrawHandle();
	glPopMatrix();
}
