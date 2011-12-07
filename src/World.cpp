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
	// Implement after adding other draw functions
}
