#include "Wall.h"

Wall::Wall(Vector b, Vector t) :
	WorldObject(WorldObject::WALL)
{
	AddPoint(b);
	AddPoint(t);
}

bool Wall::OnLeft(Vector p) {
	return (p.i < Point(0).i);
}

bool Wall::Between(Vector p) {
	return (p.j < Point(1).j) && (p.j > Point(0).j);
}

float Wall::Left() {
	return Point(0).i - 0.1;
}

float Wall::Right() {
	return Point(0).i + 0.1;
}

void Wall::Draw() {
	glColor3f(0, 0, 0);

	glBegin(GL_LINES);
		glVertex2f(Point(0).i, Point(0).j);
		glVertex2f(Point(0).i, Point(1).j);
	glEnd();
}

void Wall::Update() {
	if(Point(0).j > Point(1).j) {
		Vector hold = Point(0);
		Point(0) = Point(1);
		Point(1) = hold;
	}

	Point(1).i = Point(0).i;
}

