#include "parallaxL.h"
#include "global.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void ParallaxL::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_speed"), &ParallaxL::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &ParallaxL::set_speed);
    ClassDB::add_property("ParallaxL", PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,100,0.01"), "set_speed", "get_speed");

	ClassDB::bind_method(D_METHOD("get_teleport"), &ParallaxL::get_teleport);
	ClassDB::bind_method(D_METHOD("set_teleport", "p_teleport"), &ParallaxL::set_teleport);
	ClassDB::add_property("ParallaxL", PropertyInfo(Variant::BOOL, "teleport", PROPERTY_HINT_RANGE, "0,1,0"), "set_teleport", "get_teleport");
}

ParallaxL::ParallaxL() {
	// Initialize any variables here.
	speed = 0.0;
	speedn = 0.0;
	Vector2 prim = Vector2(-100,0);
	teleport = true;
}

ParallaxL::~ParallaxL() {
	// Add your cleanup here.
}

void ParallaxL::set_speed(const double p_speed) {
    speedn = p_speed;
}

double ParallaxL::get_speed() const {
    return speedn;
}

void ParallaxL::set_teleport(const bool p_teleport) {
	teleport = p_teleport;
}

bool ParallaxL::get_teleport() const {
	return teleport;
}

void ParallaxL::_process(double delta) {
	speed = speedn + global_speed * 100;
	prim.x -= speed * delta;
	if(prim.x <= -1152 && teleport) {
		prim.x = -8;
	}
	set_position(prim);
}