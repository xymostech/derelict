#include <UnitTest++.h>

#include "Cam.h"

TEST(CamSize) {
	Cam::ResizeCallback(100, 150);
	CHECK_EQUAL(Cam::I().Width(), 100);
	CHECK_EQUAL(Cam::I().Height(), 150);
	CHECK_EQUAL(Cam::I().HalfWidth(), 50);
	CHECK_EQUAL(Cam::I().HalfHeight(), 75);
}
