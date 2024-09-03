#include "register_types.h"

#include "core/config/engine.h"
#include "kb_hook.h"

void initialize_keyboard_hook_dll_module(ModuleInitializationLevel p_level) {
	if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE) {
#ifdef KBHOOKDLL_ENABLE
		print_line("The keyboard_hook  is enabled.");
#endif
		Multikeyboard::init_singleton();
	//} else if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE) {
		ClassDB::register_class<Multikeyboard>();
		Engine::get_singleton()->add_singleton(Engine::Singleton("Multikeyboard", Multikeyboard::get_singleton()));
	}
}

void uninitialize_keyboard_hook_dll_module(ModuleInitializationLevel p_level) {
	if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE) {
		Multikeyboard::finalize_singleton();
	}
}
