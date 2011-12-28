/*
 * WorldObject class
 *
 * All objects which exist in the world
 * inherit from this. Defines basic callbacks
 */
#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <vector>

#include "Vector.h"

class WorldObject
{
public:
	enum Type {
		FLOOR,
		WALL
	};
private:
	std::vector<Vector> pts_;

	Type t_;
public:
	WorldObject(Type t);

	virtual void Draw() = 0;
	virtual void Update() = 0;

	Vector& Point(int i);
	void AddPoint(const Vector& pt);
	size_t NumPoints();

	Type GetType();
};

#endif
