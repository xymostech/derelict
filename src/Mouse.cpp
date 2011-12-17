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

bool Mouse::Pressed(int button) {
	if(button < 3) {
		return mouse_button_[button];
	} else {
		return false;
	}
}
