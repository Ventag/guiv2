#pragma once
namespace guiv2 {
	class Bounds {
	public:
		bool Inside(int x, int y, int w, int h);
	};

	extern Bounds g_bounds;
}