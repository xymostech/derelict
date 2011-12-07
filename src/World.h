/*
 * World class
 * 
 * Holds different objects in the world
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

using std::vector;

#include "Floor.h"
#include "Player.h"

class World {
	vector<Floor> floors_;
	Player p_;
public:
	World();

	void AddFloor(Floor f);

	void Update();

	void Draw();
};

#endif
