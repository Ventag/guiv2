#pragma once
#include "basecontrol.h"

namespace guiv2 {

	class Groupbox : public BaseControl {

	private:
		std::vector<BaseControl*> children;
		std::vector<std::string> tabs;

		std::string active_tab;

		int offset_render_height;
		int offset_render_height_max;

		int offset_height_additive;

		int thumb_height;

		bool scrollable;

	protected:
	public:
		Groupbox(std::string name, int x, int y, int w, int h)
		{
			this->m_name = name;
			this->m_offset_x = x;
			this->m_offset_y = y;
			this->m_w = w;
			this->m_h = h;
			this->m_type = ControlType::GROUP;
		}

		void AddElement(BaseControl*);

		void Think();

		void Render();
	};
}