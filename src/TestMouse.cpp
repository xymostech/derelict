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

	Mouse::MouseButton(0, true);
	Mouse::I().Update();
	Mouse::MouseButton(0, false);

	CHECK( Mouse::I().Pressed(0, Mouse::EDGE));
	CHECK(!Mouse::I().Pressed(0, Mouse::HELD));

	Mouse::I().Update();

	CHECK(!Mouse::I().Pressed(0, Mouse::EDGE));
	CHECK( Mouse::I().Pressed(0, Mouse::HELD));
}

TEST(MouseMove) {
	Mouse::MouseMove(10, 10);
	
	CHECK_EQUAL(Mouse::I().Pos().i, 10);
	CHECK_EQUAL(Mouse::I().Pos().j, 10);
}
