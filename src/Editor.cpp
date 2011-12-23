#include "Editor.h"

Editor::Editor() {
	mode_ = MODE_NOTHING;

	floors_.push_back(Floor(Vector(0, 0), Vector(3, 0)));
}

void Editor::DrawHandle(Vector pos) {
	glPushMatrix();
		glTranslatef(pos.i, pos.j, 0);

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
	glPopMatrix();
}

Vector Editor::AdjustedMousePos() {
	if(Key::I().Pressed(GLFW_KEY_LSHIFT) ||
	   Key::I().Pressed(GLFW_KEY_RSHIFT)) {
		Vector new_pos = Mouse::I().WorldPos();

		new_pos.i = floor(new_pos.i + 0.5);
		new_pos.j = floor(new_pos.j + 0.5);

		return new_pos;
	} else {
		return Mouse::I().WorldPos();
	}
}

void Editor::Update() {
	if(mode_ == MODE_NOTHING) {
		if(Mouse::I().Pressed(0)) {
			for(size_t i=0; i<floors_.size(); ++i) {
				if((floors_[i].l_ - Mouse::I().WorldPos()).Len() < 0.2) {
					grabbed_pt_ = &floors_[i].l_;
					mode_ = MODE_MOVE_POINT;
				} else if((floors_[i].r_ - Mouse::I().WorldPos()).Len() < 0.2) {
					grabbed_pt_ = &floors_[i].r_;
					mode_ = MODE_MOVE_POINT;
				} else if((walls_[i].b_ - Mouse::I().WorldPos()).Len() < 0.2) {
					grabbed_pt_ = &walls_[i].b_;
					mode_ = MODE_MOVE_POINT;
				} else if((walls_[i].t_ - Mouse::I().WorldPos()).Len() < 0.2) {
					grabbed_pt_ = &walls_[i].t_;
					mode_ = MODE_MOVE_POINT;
				}
			}
		} else if(Mouse::I().Pressed(1)) {
			pan_start_ = Mouse::I().WorldPos();
			mode_ = MODE_PAN;
		} else if(Key::I().Pressed('F')) {
			mode_ = MODE_ADD_FLOOR_1;
		} else if(Key::I().Pressed('W')) {
			mode_ = MODE_ADD_WALL_1;
		}
	} else if(mode_ == MODE_MOVE_POINT) {
		if(!Mouse::I().Pressed(0)) {
			mode_ = MODE_NOTHING;
		} else {
			*grabbed_pt_ = AdjustedMousePos();
		}
	} else if(mode_ == MODE_PAN) {
		if(!Mouse::I().Pressed(1)) {
			mode_ = MODE_NOTHING;
		} else {
			cam_pos_ += pan_start_ - Mouse::I().WorldPos();
		}
	} else if(mode_ == MODE_ADD_FLOOR_1) {
		if(Mouse::I().Pressed(0, Mouse::PRESSED | Mouse::EDGE)) {
			store_pt_ = AdjustedMousePos();
			mode_ = MODE_ADD_FLOOR_2;
		}
	} else if(mode_ == MODE_ADD_FLOOR_2) {
		if(Mouse::I().Pressed(0, Mouse::PRESSED | Mouse::EDGE)) {
			floors_.push_back(Floor(store_pt_, AdjustedMousePos()));
			mode_ = MODE_NOTHING;
		}
	} else if(mode_ == MODE_ADD_WALL_1) {
		if(Mouse::I().Pressed(0, Mouse::PRESSED | Mouse::EDGE)) {
			store_pt_ = AdjustedMousePos();
			mode_ = MODE_ADD_WALL_2;
		}
	} else if(mode_ == MODE_ADD_WALL_2) {
		if(Mouse::I().Pressed(0, Mouse::PRESSED | Mouse::EDGE)) {
			walls_.push_back(Wall(store_pt_, AdjustedMousePos()));
			mode_ = MODE_NOTHING;
		}
	}
}

void Editor::Draw() {
	Cam::I().SetPos(cam_pos_);

	for(size_t i=0; i<floors_.size(); ++i) {
		floors_[i].Draw();
		DrawHandle(floors_[i].l_);
		DrawHandle(floors_[i].r_);
	}

	for(size_t i=0; i<walls_.size(); ++i) {
		walls_[i].Draw();
		DrawHandle(walls_[i].b_);
		DrawHandle(walls_[i].t_);
	}
}
