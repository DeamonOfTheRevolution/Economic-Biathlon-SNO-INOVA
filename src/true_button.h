#ifndef TSPEED
#define TSPEED

#include <godot_cpp/classes/button.hpp>

namespace godot {

class Tspeed : public Button{
    GDCLASS(Tspeed, Button)

protected:
    static void _bind_methods();

public:
    Tspeed();
    ~Tspeed();

    void _process(double delta) override;
    void _pressed();
};

}

#endif