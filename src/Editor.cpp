#include "Editor.h"

Editor::Editor() {
	mode_ = MODE_NOTHING;
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
			for(size_t i=0; i<objects_.size()&&mode_==MODE_NOTHING; ++i) {
				for(size_t p=0; p<objects_[i]->NumPoints(); ++p) {
					if((objects_[i]->Point(p) - Mouse::I().WorldPos()).Len() < 0.2) {
						held_obj = objects_[i];
						held_pt  = p;
						mode_ = MODE_MOVE_POINT;
						break;
					}
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
			held_obj->Point(held_pt) = AdjustedMousePos();
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
			objects_.push_back(new Floor(store_pt_, AdjustedMousePos()));
			mode_ = MODE_NOTHING;
		}
	} else if(mode_ == MODE_ADD_WALL_1) {
		if(Mouse::I().Pressed(0, Mouse::PRESSED | Mouse::EDGE)) {
			store_pt_ = AdjustedMousePos();
			mode_ = MODE_ADD_WALL_2;
		}
	} else if(mode_ == MODE_ADD_WALL_2) {
		if(Mouse::I().Pressed(0, Mouse::PRESSED | Mouse::EDGE)) {
			objects_.push_back(new Wall(store_pt_, AdjustedMousePos()));
			mode_ = MODE_NOTHING;
		}
	}
}

void Editor::Draw() {
	Cam::I().SetPos(cam_pos_);

	for(size_t i=0; i<objects_.size(); ++i) {
		objects_[i]->Draw();
		for(size_t p=0; p<objects_[i]->NumPoints(); ++p) {
			DrawHandle(objects_[i]->Point(p));
		}
	}

	glColor3f(0, 0, 0);

	if(mode_ == MODE_ADD_FLOOR_1) {
		DrawHandle(AdjustedMousePos());
	} else if(mode_ == MODE_ADD_FLOOR_2) {
		Floor(store_pt_, AdjustedMousePos()).Draw();
		DrawHandle(AdjustedMousePos());
	} else if(mode_ == MODE_ADD_WALL_1) {
		DrawHandle(AdjustedMousePos());
	} else if(mode_ == MODE_ADD_WALL_2) {
		Wall(store_pt_, AdjustedMousePos()).Draw();
		DrawHandle(AdjustedMousePos());
	}
}
