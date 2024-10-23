#include "kb_hook.h"

#include "core/math/color.h"

Multikeyboard *Multikeyboard::singleton = nullptr;

void Multikeyboard::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add_background_key","key_code"), &Multikeyboard::add_background_key);

}

void Multikeyboard::add_background_key(int key_code) {
    List<uint32_t>::Element *e = bg_registred_keys.find(key_code);
	if (!e)
        bg_registred_keys.push_back(key_code);
}


bool Multikeyboard::has_background_key(int key_code) {
    List<uint32_t>::Element *e = bg_registred_keys.find(key_code);
	if (e) return true;
    return false;
}

void Multikeyboard::init_singleton() {
    if (singleton == nullptr) {
		singleton = memnew(Multikeyboard);
	}
}

void Multikeyboard::finalize_singleton() {
    if (singleton) {
		memdelete(singleton);
		singleton = nullptr;
	}
}

Multikeyboard *Multikeyboard::get_singleton() {
	return singleton;
}

