#include "Floor.h"

Floor::Floor(Vector l, Vector r) :
	l_(l),
	r_(r),
	diff_(r-l),
	m_((r.j-l.j)/(r.i-l.i)),
	b_(l.j-m_*l.i)
{

}

bool Floor::Below(Vector p) {
	return (diff_.Cross(p-l_) < 0);
}

bool Floor::Inside(Vector p) {
	return (p.i > l_.i) &&
	       (p.i < r_.i);
}

float Floor::SurfacePoint(float x) {
	return m_ * x + b_;
}

void Floor::Draw() {
	glColor3f(0, 0, 0);
	
	glBegin(GL_LINES);
		glVertex2f(l_.i, l_.j);
		glVertex2f(r_.i, r_.j);
	glEnd();
}
