#include "WorldObject.h"

WorldObject::WorldObject(Type t) :
	t_(t)
{
	
}

Vector& WorldObject::Point(int i) {
	return pts_.at(i);
}

void WorldObject::AddPoint(const Vector& pt) {
	pts_.push_back(pt);
}

size_t WorldObject::NumPoints() {
	return pts_.size();
}

WorldObject::Type WorldObject::GetType() {
	return t_;
}
