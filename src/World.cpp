#include "World.h"

World::World() {

}

void World::AddFloor(Floor f) {
	floors_.push_back(f);
}

void World::AddWall(Wall w) {
	walls_.push_back(w);
}

void World::Update() {
	p_.HandleControls();

	p_.BeginUpdate();

	vector<Floor>::iterator floor_it, floor_end = floors_.end();
	for(floor_it=floors_.begin(); floor_it!=floor_end; ++floor_it) {
		p_.HandleFloor(*floor_it);
	}

	vector<Wall>::iterator wall_it, wall_end = walls_.end();
	for(wall_it=walls_.begin(); wall_it!=wall_end; ++wall_it) {
		p_.HandleWall(*wall_it);
	}

	p_.EndUpdate();

	p_.CenterCam();
}

void World::Draw() {
	vector<Floor>::iterator floor_it, floor_end = floors_.end();
	for(floor_it=floors_.begin(); floor_it!=floor_end; ++floor_it) {
		floor_it->Draw();
	}

	vector<Wall>::iterator wall_it, wall_end = walls_.end();
	for(wall_it=walls_.begin(); wall_it!=wall_end; ++wall_it) {
		wall_it->Draw();
	}

	p_.Draw();
}
