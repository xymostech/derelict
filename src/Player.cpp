#include "Player.h"

Player::Player() {
	
}

void Player::SetPos(const Vector& pos) {
	pos_ = pos;
	vel_ = Vector();
	on_ground_ = false;
}

Vector Player::GetPos() {
	return pos_;
}

void Player::Jump() {
	vel_.j += 0.5;
}

void Player::Left() {
	vel_.i += 0.2;
}

void Player::Right() {
	vel_.i -= 0.2;
}

bool Player::OnGround() {
	return on_ground_;
}

void Player::BeginUpdate() {
	vel_.j -= 0.05;
	new_pos_ = pos_ + vel_;

	on_ground_ = false;
}

void Player::EndUpdate() {
	pos_ = new_pos_;
	vel_.i = 0;
}

void Player::HandleFloor(Floor f) {
	if( f.Below(new_pos_) &&
	   !f.Below(pos_) &&
	    f.Inside(new_pos_)) {
		vel_.j = 0;
		new_pos_.j = f.SurfacePoint(new_pos_.i);
		on_ground_ = true;
	}
}

void Player::HandleWall(Wall w) {
	if((w.OnLeft(pos_) !=
	    w.OnLeft(new_pos_)) &&
	   w.Between(new_pos_)) {
		if(w.OnLeft(pos_)) {
			new_pos_.i = w.Left();
		} else {
			new_pos_.i = w.Right();
		}
	}
}

void Player::HandleControls() {
	if(Key::I().Pressed('D')) {
		Right();
	} else if(Key::I().Pressed('A')) {
		Left();
	}

	if(Key::I().Pressed('W') &&
	   OnGround()) {
		Jump();
	}
}

void Player::CenterCam() {
	Cam::I().SetPos(pos_);
}

void Player::Draw() {
	glPushMatrix();

	glTranslatef(pos_.i, pos_.j, 0);

	glColor3f(0, 0, 0);

	Pyramid();

	glPopMatrix();
}
