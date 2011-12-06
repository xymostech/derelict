#include <UnitTest++.h>

#include "Floor.h"

TEST(FlatFloor) {
	Floor f(Vector(0, 0), Vector(10, 0));
	
	CHECK( f.Below(Vector(5, -1)));
	CHECK(!f.Below(Vector(5,  1)));

	CHECK(!f.Below(Vector(-1 , -1)));
	CHECK(!f.Below(Vector( 11, -1)));

	CHECK_CLOSE(f.SurfacePoint(0 ), 0, 0.01);
	CHECK_CLOSE(f.SurfacePoint(5 ), 0, 0.01);
	CHECK_CLOSE(f.SurfacePoint(10), 0, 0.01);
}

TEST(SlopeFloor) {
	Floor f(Vector(0, 0), Vector(8, 6));

	CHECK( f.Below(Vector(4, 2)));
	CHECK(!f.Below(Vector(4, 4)));

	CHECK(!f.Below(Vector(-4 , -4)));
	CHECK(!f.Below(Vector( 12,  8)));

	CHECK_CLOSE(f.SurfacePoint(0), 0, 0.01);
	CHECK_CLOSE(f.SurfacePoint(4), 3, 0.01);
	CHECK_CLOSE(f.SurfacePoint(8), 6, 0.01);
}
