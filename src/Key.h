/*
 * Key class
 *
 * Handles callbacks from keypresses and stores
 * them so they can be accessed later
 */

#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

#include <GL/glfw.h>

class Key
{
	static const int caps_[128];

	bool keys_[2][2][128];

	Key();
	Key(Key const&);
	void operator=(Key const&);

	bool KeyCheck(int past, int special, int key);
public:
	static Key& I();

	static void GLFWCALL KeyEvent(int key, int action);

	bool Pressed(int key, int flags = PRESSED);

	void Update();

	enum {
		PRESSED  = 0x01,
		RELEASED = 0x02,
		HELD     = 0x04,
		EDGE     = 0x08
	};
};

#endif
