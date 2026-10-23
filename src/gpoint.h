#ifndef GPOINT_H
#define GPOINT_H

#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/string.hpp>
#include <string>
#include <cstdio>
#include "global.h"


namespace godot {

	class GPoint : public Label {
		GDCLASS(GPoint, Label)

	private:
		std::string text;

	protected:
		static void _bind_methods();
		int get_point() const;
		void set_point(const int p_point);
		void increment();

	public:
		GPoint();
		~GPoint();

		void _process(double delta) override;
	};

}

#endif