#include "answer_button_sprite.h"


using namespace godot;


void AnswerButtonSprite::_bind_methods() {
	// Выставление координаты x с короторой начнется анимация
	ClassDB::bind_method(D_METHOD("get_x"), &AnswerButtonSprite::get_x);
	ClassDB::bind_method(D_METHOD("set_x", "p_x"), &AnswerButtonSprite::set_x);
	ClassDB::add_property("AnswerButtonSprite", PropertyInfo(Variant::INT, "x", PROPERTY_HINT_RANGE, "0,2000,0.01"), "set_x", "get_x");
	// Выставление координаты y с короторой начнется анимация
	ClassDB::bind_method(D_METHOD("get_y"), &AnswerButtonSprite::get_y);
	ClassDB::bind_method(D_METHOD("set_y", "p_y"), &AnswerButtonSprite::set_y);
	ClassDB::add_property("AnswerButtonSprite", PropertyInfo(Variant::INT, "y", PROPERTY_HINT_RANGE, "0,2000,0.01"), "set_y", "get_y");
	// Выставление последовательности. 1-ая мишень будет отвечать за 1-ый ответ при итераторе == 0
	ClassDB::bind_method(D_METHOD("get_iter"), &AnswerButtonSprite::get_iter);
	ClassDB::bind_method(D_METHOD("set_iter", "p_iter"), &AnswerButtonSprite::set_iter);
	ClassDB::add_property("AnswerButtonSprite", PropertyInfo(Variant::INT, "Iter", PROPERTY_HINT_RANGE, "0,6,1"), "set_iter", "get_iter");
	// Выставление скорости движения
	ClassDB::bind_method(D_METHOD("get_speed"), &AnswerButtonSprite::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &AnswerButtonSprite::set_speed);
	ClassDB::add_property("AnswerButtonSprite", PropertyInfo(Variant::FLOAT, "Speed", PROPERTY_HINT_RANGE, "0,200,0.01"), "set_speed", "get_speed");
	// Выставление растояния между мишенями, для корректного смещения
	ClassDB::bind_method(D_METHOD("get_step"), &AnswerButtonSprite::get_step);
	ClassDB::bind_method(D_METHOD("set_step", "p_step"), &AnswerButtonSprite::set_step);
	ClassDB::add_property("AnswerButtonSprite", PropertyInfo(Variant::FLOAT, "Step", PROPERTY_HINT_RANGE, "0,2000,0.01"), "set_step", "get_step");

}

AnswerButtonSprite::AnswerButtonSprite() {
	buf_iter = iter;
	loc_iter = 0;
	x = 0, y = 0, step = 150;
	speed = 10;
	position = Vector2(x, y);
	set_position(position);
}

AnswerButtonSprite::~AnswerButtonSprite() {
}

void AnswerButtonSprite::_process(double delta) {
	if (buf_iter != iter && loc_iter < iter) {
		play(godot::String(std::to_string(last_var).c_str()));
		buf_iter = iter;
	}
	if (last_var != 0 && loc_iter < buf_iter) {
		position.x -= speed;
		if (position.x == -400) {
			last_var = 0;
			play(godot::String(std::to_string(last_var).c_str()));
		}
		set_position(position);
	}
	else if (position.x > x - (step * iter) && loc_iter >= iter && loc_iter != 0 && iter != 0) {
		position.x -= speed;
		set_position(position);
	}
	
}

void AnswerButtonSprite::set_iter(int p_iter) {
	loc_iter = p_iter;
}

int AnswerButtonSprite::get_iter() const {
	return loc_iter;
}

void AnswerButtonSprite::set_x(int p_x) {
	x = p_x;
	position.x = x;
}

int AnswerButtonSprite::get_x() const {
	return x;
}

void AnswerButtonSprite::set_y(int p_y) {
	y = p_y;
	position.y = y;
}

int AnswerButtonSprite::get_y() const {
	return y;
}

void AnswerButtonSprite::set_speed(double p_speed) {
	speed = p_speed;
}

double AnswerButtonSprite::get_speed() const {
	return speed;
}

void AnswerButtonSprite::set_step(double p_step) {
	step = p_step;
}

double AnswerButtonSprite::get_step() const {
	return step;
}