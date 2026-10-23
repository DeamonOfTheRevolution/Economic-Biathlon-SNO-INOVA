#include "parallax.h"
#include "global.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void ParallaxBG::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_speed"), &ParallaxBG::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &ParallaxBG::set_speed);
    ClassDB::add_property("ParallaxBG", PropertyInfo(Variant::FLOAT, "speedn", PROPERTY_HINT_RANGE, "0,100,0.01"), "set_speed", "get_speed");
}

ParallaxBG::ParallaxBG() {
	// Initialize any variables here.
	speed = 0.0;
	speedn = 0.0;
	Vector2 prim = Vector2(-100,0);
}

ParallaxBG::~ParallaxBG() {
	// Add your cleanup here.
}

void ParallaxBG::set_speed(const double p_speed) {
    speedn = p_speed;
}

double ParallaxBG::get_speed() const {
    return speedn;
}

void ParallaxBG::_process(double delta) {
	speed = speedn + global_speed * 100;
	prim.x -= speed * delta;
	if(prim.x <= -1152){
		prim.x = -8;
	}
	set_offset(prim);
}