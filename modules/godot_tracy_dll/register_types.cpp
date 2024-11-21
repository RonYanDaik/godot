#include "register_types.h"

#include "core/config/engine.h"
#include "tracy_profiler.h"

#ifdef TRACY_ENABLE
#pragma comment(lib, "modules/godot_tracy_dll/tracy/library/win32/x64/Release/TracyProfiler.lib")
#endif

void initialize_godot_tracy_dll_module(ModuleInitializationLevel p_level) {
	if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE) {
#ifdef TRACY_ENABLE
		print_line("The TRACY profiler is enabled.");
		TracyProfiler::init_singleton();
#endif

	} else if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE) {
#ifdef TRACY_ENABLE
		ClassDB::register_class<TracyProfiler>();
		Engine::get_singleton()->add_singleton(Engine::Singleton("TracyProfiler", TracyProfiler::get_singleton()));
#endif
	}
}

void uninitialize_godot_tracy_dll_module(ModuleInitializationLevel p_level) {
	if (p_level == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE) {
#ifdef TRACY_ENABLE
		TracyProfiler::finalize_singleton();
#endif
	}
}
