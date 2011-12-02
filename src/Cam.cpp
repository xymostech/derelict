#include "Cam.h"

Cam::Cam() {
	screen_size_[0] = screen_size_[1] = 0;
}

Cam& Cam::I() {
	static Cam instance;
	return instance;
}

void GLFWCALL Cam::ResizeCallback(int width, int height) {
	I().screen_size_[0] = width;
	I().screen_size_[1] = height;
}

int Cam::Width() {
	return screen_size_[0];
}

int Cam::Height() {
	return screen_size_[1];
}

int Cam::HalfWidth() {
	return screen_size_[0] / 2;
}

int Cam::HalfHeight() {
	return screen_size_[1] / 2;
}
