#include "false_button.h"
#include "global.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

Fspeed::Fspeed() {
    // Initialize any variables here.
}

Fspeed::~Fspeed() {
    // Add your cleanup here.
}

void Fspeed::_bind_methods() {
}

void Fspeed::_process(double delta) 
{
    // if (is_pressed())
    // {
    //     if (global_speed >= 0)
    //     {
    //         global_speed-=0.05;
    //     }
    // }
}

void Fspeed::_pressed() {
    if (global_speed >= 0.05) {
        global_speed-=0.2;
    }
    pass = false;
}