#include "register_types.h"

#include "parallax.h"
#include "false_button.h"
#include "true_button.h"
#include "speed_changer.h"
#include "global.h"
#include "parallaxL.h"
#include "answer_button_sprite.h"
#include "gpoint_button_answer.h"
#include "gpoint.h"
#include "gtimer_revers.h"


#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<ParallaxBG>();
	ClassDB::register_class<Fspeed>();
	ClassDB::register_class<Speedch>();
	ClassDB::register_class<Tspeed>();
	ClassDB::register_class<ParallaxL>();
	ClassDB::register_class<AnswerButtonSprite>();
	ClassDB::register_class<GPointButtonAnswer>();
	ClassDB::register_class<GPoint>();
	ClassDB::register_class<GTimerRevers>();
	
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}