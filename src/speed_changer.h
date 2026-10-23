#ifndef SPEEDCH
#define SPEEDCH

#include <godot_cpp/classes/animated_sprite2d.hpp>

namespace godot {

class Speedch : public AnimatedSprite2D{
    GDCLASS(Speedch, AnimatedSprite2D)

protected:
    static void _bind_methods();

public:
    Speedch();
    ~Speedch();

    void _process(double delta) override;
};

}

#endif