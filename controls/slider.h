#pragma once
#include "basecontrol.h"

namespace guiv2 {

	class Slider : public BaseControl {
	private:
		float min, max;
		bool dragging;
		float value = 0.f;
		const int SLIDER_HEIGHT = 21;
	protected:
	public:

		Slider(std::string name, int x, int y, int w) {
			this->m_name = name;
			this->m_offset_x = x;
			this->m_offset_y = y;
			this->m_w = w;
			this->m_h = SLIDER_HEIGHT;
			this->m_type = ControlType::SLIDER;
		}

		Slider(std::string name, int w) {
			this->m_name = name;
			this->m_offset_x = 0;
			this->m_offset_y = 0;
			this->m_w = w;
			this->m_h = SLIDER_HEIGHT;
			this->m_type = ControlType::SLIDER;
		}

		Slider(std::string name) {
			this->m_name = name;
			this->m_offset_x = 0;
			this->m_offset_y = 0;
			this->m_w = 0; // let this be setup by the container
			this->m_h = SLIDER_HEIGHT;
			this->m_type = ControlType::SLIDER;
		}

		void SetWidth(int w) {
			this->m_w = w;
		}

		void Think();
		void Render();

		void SetMinMax(float, float);
	};
}