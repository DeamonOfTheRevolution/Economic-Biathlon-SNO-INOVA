#include "gpoint.h"
#include <godot_cpp/core/class_db.hpp>
#include <cmath>

// #include "gpoint_button.h"

using namespace godot;

void GPoint::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_point"), &GPoint::get_point);
	ClassDB::bind_method(D_METHOD("set_point", "p_point"), &GPoint::set_point);
	ClassDB::add_property("GPoint", PropertyInfo(Variant::INT, "Points", PROPERTY_HINT_RANGE, "0,999,0"), "set_point", "get_point");

	// GPointButton->connect("increment", callable_mp(this, "increment"));
}

GPoint::GPoint() {
	std::string text = "Points: " + std::to_string(point);
	set_text(godot::String(text.c_str()));
}

GPoint::~GPoint() {
	// Add your cleanup here.
}

void GPoint::_process(double delta) {
	std::string text = "Points: " + std::to_string(point);
	set_text(godot::String(text.c_str()));
}

int GPoint::get_point() const {
	return point;
}

void GPoint::set_point(const int p_point) {
	point = p_point;
}

void GPoint::increment() {
	set_point(get_point() + 1);
}