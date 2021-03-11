#pragma once

namespace guiv2
{
	enum class ControlType {
		BASE_CONTROL = 0,
		FORM,
		GROUP,
		TAB,
		CHECKBOX,
		SLIDER,
		COMBOBOX
	};

	class BaseControl {

	public:
		int m_y, m_x;

		int m_offset_x, m_offset_y;

		int m_h, m_w;
		int m_max_h, m_max_w;
		int m_render_h, m_render_w;

		std::string m_name;

		ControlType m_type;

		value* val;
	public:

		BaseControl() {}

		BaseControl(std::string name) {
			this->m_name = name;
		}

		BaseControl(std::string name, int x, int y) {
			this->m_name = name;
			this->m_offset_x = x;
			this->m_offset_y = y;
		}

		BaseControl(std::string name, int x, int y, int w, int h) {
			this->m_name = name;
			this->m_offset_x = x;
			this->m_offset_y = y;
			this->m_w = w;
			this->m_h = h;
		}

		void SetX(int x) { this->m_x = x + m_offset_x; }
		void SetY(int y) { this->m_y = y + m_offset_y; }
		void SetW(int w) { this->m_w = w; }

		virtual void Think() = 0;
		virtual void Render() = 0;
	};
}