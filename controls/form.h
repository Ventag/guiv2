#pragma once
#include "basecontrol.h"

namespace guiv2 {

	class Form : public BaseControl {

	private:
		int m_header_height;

		int m_dmouse_x, m_dmouse_y;

		bool m_dragging;
		bool m_open;

		std::vector<BaseControl*> children;

	protected:

	public:
		Form(std::string name, int x, int y, int w, int h) 
		{
			this->m_name = name;
			this->m_x = x;
			this->m_y = y;
			this->m_w = w;
			this->m_h = h;
			this->m_type = ControlType::FORM;
		};

		void AddChild(BaseControl* child);

		void HandleDrag();
		
		void Think();

		void Render();
	};
}