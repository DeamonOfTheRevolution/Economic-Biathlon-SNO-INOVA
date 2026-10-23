#ifndef ANSWER_BUTTON_SPRITE_H
#define ANSWER_BUTTON_SPRITE_H

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include "global.h"
#include "string"

namespace godot {

	class AnswerButtonSprite : public AnimatedSprite2D {
		GDCLASS(AnswerButtonSprite, AnimatedSprite2D)
	
	private:
		int buf_iter, loc_iter;
		double speed, x, y, step;
		Vector2 position;

	protected:
		static void _bind_methods();
		void set_iter(int p_iter);
		int get_iter() const;
		void set_x(int p_x);
		int get_x() const;
		void set_y(int p_y);
		int get_y() const;
		void set_speed(double p_speed);
		double get_speed() const;
		void set_step(double p_step);
		double get_step() const;

	public:
		AnswerButtonSprite();
		~AnswerButtonSprite();

		void _process(double delta) override;
	};

}

#endif