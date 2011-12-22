#include <UnitTest++.h>

#include "Key.h"

TEST(KeyPress) {
	Key::KeyEvent('A', GLFW_PRESS);
	CHECK(Key::I().Pressed('A'));

	Key::KeyEvent('A', GLFW_RELEASE);
	CHECK(!Key::I().Pressed('A'));
}

TEST(KeyCaps) {
	Key::KeyEvent('A', GLFW_PRESS);
	CHECK(Key::I().Pressed('a'));

	Key::KeyEvent('A', GLFW_RELEASE);
	CHECK(!Key::I().Pressed('a'));

	Key::KeyEvent('1', GLFW_PRESS);
	CHECK(!Key::I().Pressed('!'));

	Key::KeyEvent('1', GLFW_PRESS);
}

TEST(KeyState) {
	Key::KeyEvent('A', GLFW_RELEASE);
	Key::I().Update();
	CHECK(!Key::I().Pressed('A', Key::PRESSED));
	CHECK( Key::I().Pressed('A', Key::RELEASED));
	CHECK(!Key::I().Pressed('A', Key::EDGE));
	CHECK( Key::I().Pressed('A', Key::HELD));

	CHECK(!Key::I().Pressed('A', Key::PRESSED  | Key::HELD));
	CHECK(!Key::I().Pressed('A', Key::PRESSED  | Key::EDGE));
	CHECK( Key::I().Pressed('A', Key::RELEASED | Key::HELD));
	CHECK(!Key::I().Pressed('A', Key::RELEASED | Key::EDGE));

	Key::KeyEvent('A', GLFW_PRESS);
	CHECK( Key::I().Pressed('A', Key::PRESSED));
	CHECK(!Key::I().Pressed('A', Key::RELEASED));
	CHECK( Key::I().Pressed('A', Key::EDGE));
	CHECK(!Key::I().Pressed('A', Key::HELD));

	CHECK(!Key::I().Pressed('A', Key::PRESSED  | Key::HELD));
	CHECK( Key::I().Pressed('A', Key::PRESSED  | Key::EDGE));
	CHECK(!Key::I().Pressed('A', Key::RELEASED | Key::HELD));
	CHECK(!Key::I().Pressed('A', Key::RELEASED | Key::EDGE));

	Key::I().Update();
	CHECK( Key::I().Pressed('A', Key::PRESSED));
	CHECK(!Key::I().Pressed('A', Key::RELEASED));
	CHECK(!Key::I().Pressed('A', Key::EDGE));
	CHECK( Key::I().Pressed('A', Key::HELD));

	CHECK( Key::I().Pressed('A', Key::PRESSED  | Key::HELD));
	CHECK(!Key::I().Pressed('A', Key::PRESSED  | Key::EDGE));
	CHECK(!Key::I().Pressed('A', Key::RELEASED | Key::HELD));
	CHECK(!Key::I().Pressed('A', Key::RELEASED | Key::EDGE));

	Key::KeyEvent('A', GLFW_RELEASE);
	CHECK(!Key::I().Pressed('A', Key::PRESSED));
	CHECK( Key::I().Pressed('A', Key::RELEASED));
	CHECK( Key::I().Pressed('A', Key::EDGE));
	CHECK(!Key::I().Pressed('A', Key::HELD));

	CHECK(!Key::I().Pressed('A', Key::PRESSED  | Key::HELD));
	CHECK(!Key::I().Pressed('A', Key::PRESSED  | Key::EDGE));
	CHECK(!Key::I().Pressed('A', Key::RELEASED | Key::HELD));
	CHECK( Key::I().Pressed('A', Key::RELEASED | Key::EDGE));

	Key::I().Update();
}
