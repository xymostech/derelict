#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

#include <GL/glfw.h>

class Key
{
	static const unsigned char caps_[128];

	bool keys_[2][2][128];

	Key();
	Key(Key const&);
	void operator=(Key const&);
public:
	static Key& I();

	static void GLFWCALL KeyEvent(int key, int action);

	bool Pressed(int key);
};

#endif
