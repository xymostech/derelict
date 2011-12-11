/*
 * World class
 * 
 * Holds different objects in the world
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::fstream;

#include "Floor.h"
#include "Wall.h"
#include "Player.h"

class World {
	vector<Floor> floors_;
	vector<Wall> walls_;

	Player p_;
public:
	World();

	void AddFloor(Floor f);
	void AddWall(Wall w);

	void Load(string file);

	void Update();

	void Draw();
};

#endif
