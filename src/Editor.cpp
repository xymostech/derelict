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
	if(mode_ == MODE_NOTHING) {
		if(Mouse::I().Pressed(0)) {
			for(size_t i=0; i<pts_.size(); ++i) {
				if((pts_[i] - Mouse::I().WorldPos()).Len() < 0.2) {
					grabbed_ = true;
					grabbed_pt_ = &pts_[i];
				}
			}
			if(grabbed_)
				*grabbed_pt_ = Mouse::I().WorldPos();
			mode_ = MODE_MOVE_POINT;
		} else if(Mouse::I().Pressed(1)) {
			pan_start_ = Mouse::I().WorldPos();
			mode_ = MODE_PAN;
		} else if(Key::I().Pressed('N')) {
			mode_ = MODE_ADD_POINT;
		}
	} else if(mode_ == MODE_MOVE_POINT) {
		if(!Mouse::I().Pressed(0)) {
			mode_ = MODE_NOTHING;
			grabbed_ = false;
		} else {
			if(grabbed_)
				*grabbed_pt_ = Mouse::I().WorldPos();
		}
	} else if(mode_ == MODE_PAN) {
		if(!Mouse::I().Pressed(1)) {
			mode_ = MODE_NOTHING;
			cam_pos_ += pan_diff_;
			pan_diff_ = Vector();
		} else {
			pan_diff_ += pan_start_ - Mouse::I().WorldPos();
		}
	} else if(mode_ == MODE_ADD_POINT) {
		if(Mouse::I().Pressed(0)) {
			mode_ = MODE_NOTHING;
			pts_.push_back(Mouse::I().WorldPos());
		}
	}
}

void Editor::Draw() {
	Cam::I().SetPos(cam_pos_ + pan_diff_);

	for(size_t i=0; i<pts_.size(); ++i) {
		glPushMatrix();
			glTranslatef(pts_[i].i, pts_[i].j, 0);

			glColor3f(0, 0, 0);

			DrawHandle();
		glPopMatrix();
	}

	if(mode_ == MODE_ADD_POINT) {
		glPushMatrix();
			glTranslatef(Mouse::I().WorldPos().i,
			             Mouse::I().WorldPos().j,
				     0);
			glColor3f(0, 0, 0);

			DrawHandle();
		glPopMatrix();
	}
}
