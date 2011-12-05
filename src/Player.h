#ifndef PLAYER_H
#define PLAYER_H

#include "Vector.h"

class Player {
	Vector pos_;
	Vector vel_;

	bool on_ground_;
public:
	Player();

	Vector GetPos();

	void Jump();
	void Left();
	void Right();

	bool OnGround();

	void Update();
};

#endif
