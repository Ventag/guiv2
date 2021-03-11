#pragma once
#include "basecontrol.h"

namespace guiv2 {

	class CheckBox : public BaseControl {

	private:
		bool* value = false;
	protected:
	public:
		CheckBox(std::string name, int x, int y)	{
			this->m_name = name;
			this->m_offset_x = x;
			this->m_offset_y = y;
			this->m_w = 10;
			this->m_h = 10;
			this->m_type = ControlType::CHECKBOX;
		}

		CheckBox(std::string name) {
			this->m_name = name;
			this->m_offset_x = 0;
			this->m_offset_y = 0;
			this->m_w = 10;
			this->m_h = 10;
			this->m_type = ControlType::CHECKBOX;
		}

		void Think();

		void Render();

		void SetValue(bool* value) {
			this->value = value;
		}
	};
}