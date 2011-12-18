#include "Cam.h"

Cam::Cam() :
	zoom_(1)
{
	screen_size_[0] = screen_size_[1] = 0;
}

void Cam::SetupProjection() {
	glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glViewport(0, 0, Width(), Height());

		float frac = Width() / (float) Height();
		glFrustum(-.5*frac,
			   .5*frac,
			  -.5,
			   .5,
			  1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void Cam::SetupView() {
	glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(pos_.i, pos_.j, -5,
		          pos_.i, pos_.j,  0,
			  0,      1,       0);
}

Cam& Cam::I() {
	static Cam instance;
	return instance;
}

void GLFWCALL Cam::ResizeCallback(int width, int height) {
	I().screen_size_[0] = width;
	I().screen_size_[1] = height;

	I().SetupProjection();
	I().SetupView();
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

void Cam::SetZoom(float zoom) {
	zoom_ = zoom;

	SetupProjection();
}

void Cam::SetPos(Vector pos) {
	pos_ = pos;

	SetupView();
}

float Cam::GetZoom() {
	return zoom_;
}

Vector Cam::GetPos() {
	return pos_;
}
