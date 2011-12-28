#include "Floor.h"

Floor::Floor(Vector l, Vector r) :
	WorldObject(WorldObject::FLOOR)
{
	AddPoint(l);
	AddPoint(r);
	Update();
}

bool Floor::Below(Vector p) {
	return (diff_.Cross(p-Point(0)) < 0);
}

bool Floor::Inside(Vector p) {
	return (p.i > Point(0).i) &&
	       (p.i < Point(1).i);
}

float Floor::SurfacePoint(float x) {
	return m_ * x + b_;
}

void Floor::Draw() {
	glColor3f(0, 0, 0);
	
	glBegin(GL_LINES);
		glVertex2f(Point(0).i, Point(0).j);
		glVertex2f(Point(1).i, Point(1).j);
	glEnd();
}

void Floor::Update() {
	if(Point(0).i > Point(1).i) {
		Vector hold = Point(0);
		Point(0) = Point(1);
		Point(1) = hold;
	}

	diff_ = Point(1)-Point(0);
	m_ = (Point(1).j-Point(0).j)/(Point(1).i-Point(0).i);
	b_ = Point(0).j-m_*Point(0).i;
}
