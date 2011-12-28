#include "Floor.h"

Floor::Floor(Vector l, Vector r) :
	WorldObject(WorldObject::FLOOR),
	diff_(r-l),
	m_((r.j-l.j)/(r.i-l.i)),
	b_(l.j-m_*l.i)
{
	AddPoint(l);
	AddPoint(r);
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

}
