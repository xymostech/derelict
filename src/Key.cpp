#include "Key.h"

const int Key::caps_[128] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x31, 0x27, 0x33, 0x34, 0x35, 0x37, 0x22,
	0x39, 0x30, 0x38, 0x3d, 0x3c, 0x5f, 0x3e, 0x3f,
	0x29, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26,
	0x2a, 0x28, 0x3b, 0x3a, 0x2c, 0x2b, 0x2e, 0x2f,
	0x32, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
	0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
	0x68, 0x69, 0x6a, 0x7b, 0x7c, 0x7d, 0x36, 0x2d,
	0x7e, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
	0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
	0x48, 0x49, 0x4a, 0x5b, 0x5c, 0x5d, 0x60, 0x00
};

Key::Key() {
	
}

Key& Key::I() {
	static Key instance;
	return instance;
}

bool Key::KeyCheck(int past, int special, int key) {
	if(special) {
		return keys_[past][1][key];
	} else {
		if((key >= 'A' && key <= 'Z') ||
		   (key >= 'a' && key <= 'z')) {
			return keys_[past][0][key] ||
			       keys_[past][0][caps_[key]];
		} else {
			return keys_[past][0][key] ||
			       (keys_[past][0][caps_[key]] &&
			        (keys_[past][1][GLFW_KEY_LSHIFT-GLFW_KEY_SPECIAL] ||
				 keys_[past][1][GLFW_KEY_RSHIFT-GLFW_KEY_SPECIAL]));
		}
	}
}

void Key::KeyEvent(int key, int action) {
	int special = !!(key&GLFW_KEY_SPECIAL);
	key &= GLFW_KEY_SPECIAL-1;

	I().keys_[0][special][key] = action;
}

bool Key::Pressed(int key, int flags) {
	int special = !!(key&GLFW_KEY_SPECIAL);
	key &= GLFW_KEY_SPECIAL-1;
	bool pressed = true;

	if(flags & PRESSED) {
		pressed &= KeyCheck(0, special, key);
	}
	if(flags & RELEASED) {
		pressed &= !KeyCheck(0, special, key);
	}
	if(flags & HELD) {
		pressed &= (KeyCheck(0, special, key) ==
		            KeyCheck(1, special, key));
	}
	if(flags & EDGE) {
		pressed &= (KeyCheck(0, special, key) !=
		            KeyCheck(1, special, key));
	}

	return pressed;
}

void Key::Update() {
	memcpy(keys_[1], keys_[0], 256);
}
