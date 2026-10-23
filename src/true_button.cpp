#include "true_button.h"
#include "global.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

Tspeed::Tspeed() {
    // Initialize any variables here.
}

Tspeed::~Tspeed() {
    // Add your cleanup here.
}

void Tspeed::_bind_methods() {
}

void Tspeed::_process(double delta) 
{
    // if (is_pressed())
    // {
        
    // }
}

void Tspeed::_pressed() {
    global_speed+=0.2;
    point+=1;
    pass = false;
}