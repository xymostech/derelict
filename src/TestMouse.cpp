#include <UnitTest++.h>

#include "Mouse.h"

TEST(MouseClick) {
	Mouse::MouseButton(0, true);
	Mouse::MouseButton(3, true);

	CHECK( Mouse::I().Pressed(0));
	CHECK(!Mouse::I().Pressed(3));

	Mouse::MouseButton(0, false);
	Mouse::MouseButton(3, false);

	CHECK(!Mouse::I().Pressed(0));
	CHECK(!Mouse::I().Pressed(3));
}

TEST(MouseMove) {
	Mouse::MouseMove(10, 10);
	
	CHECK_EQUAL(Mouse::I().Pos().i, 10);
	CHECK_EQUAL(Mouse::I().Pos().j, 10);
}
