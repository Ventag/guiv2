#pragma once

#include "controls/basecontrol.h"
#include "controls/form.h"
#include "controls/tab.h"
#include "controls/checkbox.h"
#include "controls/groupbox.h"
#include "controls/slider.h"
#include "controls/combobox.h"


namespace guiv2 {

	class Context {
	private:
		Form* mainform;
	public:
		void Initialize();
		void PreFrame();

		void OnFrame();

		void PostFrame();

		int m_mouse_x, m_mouse_y;

		bool m_handled_click;

		bool is_open;
	};

	extern Context ctx;
}