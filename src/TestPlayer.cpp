#include <UnitTest++.h>

#include "Player.h"

TEST_FIXTURE(Player, PlayerJump) {
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	Jump();

	BeginUpdate();
	EndUpdate();

	CHECK_CLOSE(GetPos().i, 0, 0.01);
	CHECK(GetPos().j > 0);
}

TEST_FIXTURE(Player, PlayerMove) {
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	Right();

	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	CHECK(GetPos().i < 0);

	Left();

	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	CHECK_CLOSE(GetPos().i, 0, 0.01);
}

TEST_FIXTURE(Player, PlayerOnGround) {
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	CHECK(OnGround());

	Right();
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	CHECK(OnGround());

	Left();
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	CHECK(OnGround());

	Jump();
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	EndUpdate();

	CHECK(!OnGround());
}

TEST_FIXTURE(Player, PlayerSlantedGround) {
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, -5), Vector(5, 5)));
	EndUpdate();

	CHECK_CLOSE(GetPos().j, 0, 0.02);

	Left();

	BeginUpdate();
	HandleFloor(Floor(Vector(-5, -5), Vector(5, 5)));
	EndUpdate();

	CHECK_CLOSE(GetPos().j, GetPos().i, 0.02);
}

TEST_FIXTURE(Player, PlayerWall) {
	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	HandleWall(Wall(Vector(0.1, -5), Vector(0.1, 5)));
	EndUpdate();

	Left();

	BeginUpdate();
	HandleFloor(Floor(Vector(-5, 0), Vector(5, 0)));
	HandleWall(Wall(Vector(0.1, -5), Vector(0.1, 5)));
	EndUpdate();

	CHECK_CLOSE(GetPos().i, 0, 0.02);
}
