#pragma once
#include "basecontrol.h"

namespace guiv2 {

	class Tab : public BaseControl {

	private:
		std::vector<std::pair<std::string, BaseControl*>> children;
		std::vector<std::string> tabs;

		std::string active_tab;
	protected:
	public:
		Tab(std::string name, int x, int y, int w, int h)
		{
			this->m_name = name;
			this->m_offset_x = x;
			this->m_offset_y = y;
			this->m_w = w;
			this->m_h = h;
			this->m_type = ControlType::TAB;
		}

		void AddTab(std::string);

		void AddTabElement(std::string, BaseControl*);

		void Think();

		void Render();
	};
}