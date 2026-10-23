#include "speed_changer.h"
#include "global.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

Speedch::Speedch() {
    // Initialize any variables here.
}

Speedch::~Speedch() {
    // Add your cleanup here.
}

void Speedch::_bind_methods() {
}

void Speedch::_process(double delta) 
{
   set_speed_scale(global_speed+0.05);
}