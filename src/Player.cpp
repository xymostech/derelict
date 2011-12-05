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

void Player::Update() {
	vel_.j -= 0.05;
	pos_ += vel_;

	vel_.i = 0;

	if(pos_.j < 0) {
		on_ground_ = true;
		pos_.j = 0;
		vel_.j = 0;
	} else {
		on_ground_ = false;
	}
}
