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
	return (diff_.Cross(p-l_) < 0) &&
	       (p.i > l_.i) &&
	       (p.i < r_.i);
}

float Floor::SurfacePoint(float x) {
	return m_ * x + b_;
}
