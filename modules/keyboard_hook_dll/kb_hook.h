#pragma once

#include "core/config/engine.h"
#include "core/object/object.h"

class Multikeyboard: public Object {
	GDCLASS(Multikeyboard, Object);

	static Multikeyboard *singleton;

public:
	static void _bind_methods();

	bool has_background_key(int key_code);
	void add_background_key(int key_code);

	static void init_singleton();
	static void finalize_singleton();

	static Multikeyboard *get_singleton();

    List<uint32_t> bg_registred_keys;
};
