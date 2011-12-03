#include <UnitTest++.h>

#include "Key.h"

TEST(KeyPressTest) {
	Key::KeyEvent('A', GLFW_PRESS);

	CHECK(Key::I().Pressed('A', 0));

	Key::KeyEvent('A', GLFW_RELEASE);

	CHECK(!Key::I().Pressed('A', 0));
}

TEST(KeyCapsTest) {
	Key::KeyEvent('A', GLFW_PRESS);
	
	CHECK(Key::I().Pressed('a', 0));

	Key::KeyEvent('A', GLFW_RELEASE);

	CHECK(!Key::I().Pressed('a', 0));

	Key::KeyEvent('1', GLFW_PRESS);

	CHECK(!Key::I().Pressed('!', 0));

	Key::KeyEvent('1', GLFW_PRESS);
}
