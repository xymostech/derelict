#include "Wall.h"

Wall::Wall(Vector b, Vector t) :
	b_(b),
	t_(t)
{
	
}

bool Wall::OnLeft(Vector p) {
	return (p.i < b_.i);
}

bool Wall::Between(Vector p) {
	return (p.j < t_.j) && (p.j > b_.j);
}

float Wall::Left() {
	return b_.i - 0.1;
}

float Wall::Right() {
	return b_.i + 0.1;
}

void Wall::Draw() {
	glColor3f(0, 0, 0);

	glBegin(GL_LINES);
		glVertex2f(b_.i, b_.j);
		glVertex2f(b_.i, t_.j);
	glEnd();
}
