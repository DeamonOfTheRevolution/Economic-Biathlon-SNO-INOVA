#ifndef PARALLAXL
#define PARALLAXL

#include <godot_cpp/classes/parallax_layer.hpp>

namespace godot {

class ParallaxL : public ParallaxLayer {
	GDCLASS(ParallaxL, ParallaxLayer)

private:
	double speed;
	double speedn;
	Vector2 prim;
	bool teleport;

protected:
	static void _bind_methods();
	void set_speed(const double p_speed);
	double get_speed() const;
	void set_teleport(const bool p_teleport);
	bool get_teleport() const;

public:
	ParallaxL();
	~ParallaxL();

	void _process(double delta) override;
};

}

#endif