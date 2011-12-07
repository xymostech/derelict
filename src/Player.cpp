#include "Player.h"

Player::Player() {
	
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
