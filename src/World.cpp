#include "World.h"

World::World() {

}

void World::AddFloor(Floor f) {
	floors_.push_back(f);
}

void World::Update() {
	p_.HandleControls();

	p_.Update();
}

void World::Draw() {
	vector<Floor>::iterator it, end = floors_.end();

	for(it=floors_.begin(); it!=end; ++it) {
		it->Draw();
	}

	p_.Draw();
}
