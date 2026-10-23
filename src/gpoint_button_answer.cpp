#include "gpoint_button_answer.h"
#include <godot_cpp/core/class_db.hpp>



using namespace godot;

void GPointButtonAnswer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_var"), &GPointButtonAnswer::get_var);
	ClassDB::bind_method(D_METHOD("set_var", "p_var"), &GPointButtonAnswer::set_var);
	ClassDB::add_property("GPointButtonAnswer", PropertyInfo(Variant::INT, "var", PROPERTY_HINT_RANGE, "0,4,0"), "set_var", "get_var");
	
	ClassDB::bind_method(D_METHOD("get_iter"), &GPointButtonAnswer::get_iter);
	ClassDB::bind_method(D_METHOD("set_iter", "p_iter"), &GPointButtonAnswer::set_iter);
	ClassDB::add_property("GPointButtonAnswer", PropertyInfo(Variant::INT, "Iter", PROPERTY_HINT_RANGE, "0,6,1"), "set_iter", "get_iter");
}

GPointButtonAnswer::GPointButtonAnswer() {
	var = 0;
	loc_iter = 0;
	set_var(var);
}

GPointButtonAnswer::~GPointButtonAnswer() {
	// Add your cleanup here.
}

void GPointButtonAnswer::_pressed() {
	if (last_var == 0 && loc_iter == iter) {
		if (answers[iter] == var) {
			point += 1;
		}
		else {
			if (point != 0)
				point -= 1;
		}
		if (iter == (std::end(answers)-std::begin(answers))) {
			iter = 0;
		}
		else {
			iter += 1;
		}
		last_var = var;
	}
}


int GPointButtonAnswer::get_var() const {
    return var;
}

void GPointButtonAnswer::set_var(const int p_var) {
	var = p_var;
	if (var == 0) {
		text = "?";
	}
	else {
		text = std::to_string(var);
	}
	set_text(godot::String(text.c_str()));
}

void GPointButtonAnswer::set_iter(int p_iter) {
	loc_iter = p_iter;
}

int GPointButtonAnswer::get_iter() const {
	return loc_iter;
}