#include "Editor.h"

Editor::Editor() {
	mode_ = 0;

	floors_.push_back(Floor(Vector(0, 0), Vector(3, 0)));
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
	if(mode_ == MODE_NOTHING) {
		if(Mouse::I().Pressed(0)) {
			for(size_t i=0; i<floors_.size(); ++i) {
				if((floors_[i].l_ - Mouse::I().WorldPos()).Len() < 0.2) {
					grabbed_pt_ = &floors_[i].l_;
				} else if((floors_[i].r_ - Mouse::I().WorldPos()).Len() < 0.2) {
					grabbed_pt_ = &floors_[i].r_;
				}
			}
			mode_ = MODE_MOVE_POINT;
		} else if(Mouse::I().Pressed(1)) {
			pan_start_ = Mouse::I().WorldPos();
			mode_ = MODE_PAN;
		}/* else if(Key::I().Pressed('N')) {
			mode_ = MODE_ADD_POINT;
		}*/
	} else if(mode_ == MODE_MOVE_POINT) {
		if(!Mouse::I().Pressed(0)) {
			mode_ = MODE_NOTHING;
		} else {
			if(Key::I().Pressed(GLFW_KEY_LSHIFT) ||
			   Key::I().Pressed(GLFW_KEY_RSHIFT)) {
				Vector new_pos = Mouse::I().WorldPos();

				new_pos.i = floor(new_pos.i + 0.5);
				new_pos.j = floor(new_pos.j + 0.5);

				*grabbed_pt_ = new_pos;
			} else {
				*grabbed_pt_ = Mouse::I().WorldPos();
			}
		}
	} else if(mode_ == MODE_PAN) {
		if(!Mouse::I().Pressed(1)) {
			mode_ = MODE_NOTHING;
		} else {
			cam_pos_ += pan_start_ - Mouse::I().WorldPos();
		}
	}/* else if(mode_ == MODE_ADD_POINT) {
		if(Mouse::I().Pressed(0)) {
			mode_ = MODE_NOTHING;
			pts_.push_back(Mouse::I().WorldPos());
		}
	}*/
}

void Editor::Draw() {
	Cam::I().SetPos(cam_pos_);

	for(size_t i=0; i<floors_.size(); ++i) {
		floors_[i].Draw();
		glPushMatrix();
			glTranslatef(floors_[i].l_.i, floors_[i].l_.j, 0);

			glColor3f(0, 0, 0);

			DrawHandle();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(floors_[i].r_.i, floors_[i].r_.j, 0);

			glColor3f(0, 0, 0);

			DrawHandle();
		glPopMatrix();
	}
/*
	if(mode_ == MODE_ADD_POINT) {
		glPushMatrix();
			glTranslatef(Mouse::I().WorldPos().i,
			             Mouse::I().WorldPos().j,
				     0);
			glColor3f(0, 0, 0);

			DrawHandle();
		glPopMatrix();
	}*/
}
