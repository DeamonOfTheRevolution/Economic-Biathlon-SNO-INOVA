#ifndef FSPEED
#define FSPEED

#include <godot_cpp/classes/button.hpp>

namespace godot {

class Fspeed : public Button{
    GDCLASS(Fspeed, Button)

protected:
    static void _bind_methods();

public:
    Fspeed();
    ~Fspeed();

    void _process(double delta) override;
    void _pressed();
};

}

#endif