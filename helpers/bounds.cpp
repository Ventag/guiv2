#include "bounds.h"
#include "..\includes.h"

namespace guiv2 {

	Bounds g_bounds{};

	bool Bounds::Inside(int x, int y, int w, int h) {
		// check if we're within the focused form aswell, perhaps even the header
		auto point = g_input.m_mouse;

		if (point.x > x && point.y > y && point.x < x + y && point.y < y + h)
			return true;

		return false;
	}
}