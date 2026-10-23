#ifndef GTIMER_REVERS_H
#define GTIMER_REVERS_H

#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/string.hpp>
#include <string>
#include <cstdio>
#include "global.h"


namespace godot {

	class GTimerRevers : public Label {
		GDCLASS(GTimerRevers, Label)

	private:
		// double time;
		int hours;
		int minutes;
		int seconds;
		std::string text;
		// bool pass;
		void timer_format();

	protected:
		static void _bind_methods();
		double get_time() const;
		void set_time(const double p_time);
		bool get_pass() const;
		void set_pass(const bool p_pass);

	public:
		GTimerRevers();
		~GTimerRevers();

		void _process(double delta) override;
	};

}

#endif