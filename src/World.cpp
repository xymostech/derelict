#include "World.h"

World::World() {

}

void World::AddObject(WorldObject* obj) {
	objects_.push_back(obj);
}

void World::Load(string file) {
	fstream f(file.c_str());
	string type;

	if(!f.good())
		return;

	while(!f.eof()) {
		f >> type;
		if(type == "floor") {
			float x1, y1, x2, y2;
			f >> x1 >> y1 >> x2 >> y2;

			AddObject(new Floor(Vector(x1, y1),
			                    Vector(x2, y2)));
		} else if(type == "wall") {
			float x1, y1, x2, y2;
			f >> x1 >> y1 >> x2 >> y2;

			AddObject(new Wall(Vector(x1, y1),
			                   Vector(x2, y2)));
		}
	}
}

void World::Update() {
	p_.HandleControls();

	p_.BeginUpdate();

	vector<WorldObject*>::iterator object_it, object_end = objects_.end();
	for(object_it=objects_.begin(); object_it!=object_end; ++object_it) {
		switch((*object_it)->GetType()) {
			case WorldObject::FLOOR:
				p_.HandleFloor(*(Floor*)*object_it);
				break;
			case WorldObject::WALL:
				p_.HandleWall(*(Wall*)*object_it);
				break;
		}
	}

	p_.EndUpdate();

	p_.CenterCam();
}

void World::Draw() {
	vector<WorldObject*>::iterator object_it, object_end = objects_.end();
	for(object_it=objects_.begin(); object_it!=object_end; ++object_it) {
		(*object_it)->Draw();
	}

	p_.Draw();
}
