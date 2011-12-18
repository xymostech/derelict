#include "Mouse.h"

Mouse::Mouse() {

}

Mouse& Mouse::I() {
	static Mouse instance;
	return instance;
}

void GLFWCALL Mouse::MouseMove(int x, int y) {
	I().pos_.i = x;
	I().pos_.j = y;
}

void GLFWCALL Mouse::MouseButton(int button, int action) {
	if(button < 3) {
		I().mouse_button_[button] = action;
	}
}

Vector Mouse::Pos() {
	return pos_;
}

Vector Mouse::WorldPos() {
	Vector screen_pos = Cam::I().GetPos();
	Vector min_pos = Cam::I().GetMaxCoord(0);
	
	Vector new_pos = pos_;

	new_pos.i -= Cam::I().HalfWidth();
	new_pos.j -= Cam::I().HalfHeight();

	new_pos.i /= Cam::I().HalfWidth();
	new_pos.j /= Cam::I().HalfHeight();

	new_pos.i *= -1 * min_pos.i;
	new_pos.j *= -1 * min_pos.j;

	return new_pos + screen_pos;
}

bool Mouse::Pressed(int button) {
	if(button < 3) {
		return mouse_button_[button];
	} else {
		return false;
	}
}
