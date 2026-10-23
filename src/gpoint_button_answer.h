#ifndef GPOINT_BUTTON_ANSWER_H
#define GPOINT_BUTTON_ANSWER_H

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/variant/string.hpp>
#include <string>
#include <cstdio>
#include "global.h"
#include <array>



namespace godot {

	class GPointButtonAnswer : public Button {
		GDCLASS(GPointButtonAnswer, Button)

	private:
		int var, loc_iter;
		std::string text;

	protected:
		static void _bind_methods();
		int get_var() const;
		void set_var(const int p_var);
		int get_iter() const;
		void set_iter(const int p_iter);

	public:
		GPointButtonAnswer();
		~GPointButtonAnswer();

		void _pressed();
	};

}

#endif