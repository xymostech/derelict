#include "WorldObject.h"

WorldObject::WorldObject(Type t) :
	t_(t)
{
	
}

Vector& WorldObject::Point(int i) {
	return pts_.at(i);
}

WorldObject::Type WorldObject::GetType() {
	return t_;
}
