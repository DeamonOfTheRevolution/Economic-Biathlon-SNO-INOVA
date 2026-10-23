#include "gtimer_revers.h"
#include <godot_cpp/core/class_db.hpp>
#include <cmath>
#include "godot_cpp/classes/os.hpp"

using namespace godot;

void GTimerRevers::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_time"), &GTimerRevers::get_time);
	ClassDB::bind_method(D_METHOD("set_time", "p_time"), &GTimerRevers::set_time);
	ClassDB::add_property("GTimerRevers", PropertyInfo(Variant::FLOAT, "time", PROPERTY_HINT_RANGE, "0,86400,0"), "set_time", "get_time");

	ClassDB::bind_method(D_METHOD("get_pass"), &GTimerRevers::get_pass);
	ClassDB::bind_method(D_METHOD("set_pass", "p_pass"), &GTimerRevers::set_pass);
	ClassDB::add_property("GTimerRevers", PropertyInfo(Variant::BOOL, "pass", PROPERTY_HINT_RANGE, "0,1,0"), "set_pass", "get_pass");
}

GTimerRevers::GTimerRevers() {
	// pass = false;
	// time = 60.0;
	timer_format();
}

GTimerRevers::~GTimerRevers() {
	// Add your cleanup here.
}

void GTimerRevers::_process(double delta) {
	// if (has_focus()) {
		if (!pass) {
			first_timer -= delta;
			if (first_timer < 0)
				first_timer = 0;
		}
		timer_format();
	// }
}

double GTimerRevers::get_time() const {
	return first_timer;
}

void GTimerRevers::set_time(const double p_time) {
	first_timer = p_time;
	timer_format();
}

void GTimerRevers::timer_format() {
	hours = (int)std::fmod(first_timer, 60);
	minutes = (int)std::fmod(first_timer, 3600) / 60;
	seconds = (int)std::fmod(first_timer, 86400) / 3600;
	char buffer[20];
	sprintf(buffer, "%02d:%02d:%02d", seconds, minutes, hours);
	std::string timeString = buffer;
	set_text(godot::String(timeString.c_str()));
}


bool GTimerRevers:: get_pass() const {
	return pass;
}

void GTimerRevers::set_pass(const bool p_pass) {
	pass = p_pass;
}