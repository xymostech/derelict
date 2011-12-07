#include <UnitTest++.h>

#include "Wall.h"

TEST(WallSize) {
	Wall w(Vector(0, -5), Vector(0, 5));

	CHECK( w.OnLeft(Vector(-1, 0)));
	CHECK(!w.OnLeft(Vector( 1, 0)));

	CHECK( w.Between(Vector(0,  0)));
	CHECK(!w.Between(Vector(0, -6)));
	CHECK(!w.Between(Vector(0,  6)));
	
	CHECK_CLOSE(w. Left(), -0.1, 0.01);
	CHECK_CLOSE(w.Right(),  0.1, 0.01);
}
