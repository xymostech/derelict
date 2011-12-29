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

#include "WorldObject.h"
#include "Floor.h"
#include "Wall.h"
#include "Player.h"

class World {
protected:
	vector<WorldObject*> objects_;

	Player p_;
public:
	World();

	void AddObject(WorldObject* obj);

	void Load(string file);

	virtual void Update();
	virtual void Draw();
};

#endif
