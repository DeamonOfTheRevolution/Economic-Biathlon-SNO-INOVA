#ifndef PARALLAX
#define PARALLAX

#include <godot_cpp/classes/parallax_background.hpp>

namespace godot {

class ParallaxBG : public ParallaxBackground {
	GDCLASS(ParallaxBG, ParallaxBackground)

private:
	double speed;
	double speedn;
	Vector2 prim;

protected:
	static void _bind_methods();
	void set_speed(const double p_speed);
	double get_speed() const;

public:
	ParallaxBG();
	~ParallaxBG();

	void _process(double delta) override;
};

}

#endif