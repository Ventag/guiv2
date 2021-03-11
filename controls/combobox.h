#pragma once
#include "basecontrol.h"

namespace guiv2 {

	class ComboBox : public BaseControl {

	private:
		int* value;
		std::vector<std::pair<int, std::string>> values;
		bool open = false;
		const int COMBOBOX_HEIGHT = 18;
	protected:
	public:
		ComboBox(std::string name, int x, int y, int w) {
			this->m_name = name;
			this->m_offset_x = x;
			this->m_offset_y = y;
			this->m_w = w;
			this->m_h = 16 + COMBOBOX_HEIGHT;
			this->m_type = ControlType::COMBOBOX;
		}

		ComboBox(std::string name) {
			this->m_name = name;
			this->m_offset_x = 0;
			this->m_offset_y = 0;
			this->m_w = 100;
			this->m_h = 16 + COMBOBOX_HEIGHT;
			this->m_type = ControlType::COMBOBOX;
		}

		void Think();

		void Render();

		void SetWidth(int width) {
			this->m_w = width;
		}

		void SetValue(int* value) {
			this->value = value;
		}

		void AddItem(int value, std::string name) {
			values.push_back(std::pair<int, std::string>(value, name));
		}
	};
}