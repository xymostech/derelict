#ifndef PLAYER_H
#define PLAYER_H

#include "Key.h"
#include "Cam.h"

#include "DisplayFuncs.h"
#include "Vector.h"

class Player {
	Vector pos_, new_pos_;
	Vector vel_;

	bool on_ground_;
public:
	Player();

	Vector GetPos();

	void Jump();
	void Left();
	void Right();

	bool OnGround();

	void BeginUpdate();
	void EndUpdate();

	void HandleControls();

	void CenterCam();
	void Draw();
};

#endif
