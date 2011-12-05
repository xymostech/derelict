#include <UnitTest++.h>

#include "Player.h"

TEST_FIXTURE(Player, PlayerJump) {
	Jump();
	Update();

	CHECK_EQUAL(GetPos().i, 0);
	CHECK(GetPos().j > 0);
}

TEST_FIXTURE(Player, PlayerMove) {
	Right();
	Update();

	CHECK(GetPos().i < 0);

	Left();
	Update();

	CHECK_CLOSE(GetPos().i, 0, 0.01);
}

TEST_FIXTURE(Player, PlayerOnGround) {
	Update();

	CHECK(OnGround());

	Right();
	Update();

	CHECK(OnGround());

	Left();
	Update();

	CHECK(OnGround());

	Jump();
	Update();

	CHECK(!OnGround());
}
