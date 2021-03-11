#include "../framework.h"

namespace guiv2 {

	void Slider::Think() {

		this->m_x += this->m_offset_x;
		this->m_y += this->m_offset_y;

		if (guiv2::ctx.m_handled_click)
			return;

		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		auto size = D3D::GetTextSize(this->m_name, font);
		Rect control_area = Rect { this->m_x, this->m_y + (int)size.y + 2, this->m_w, 5};
		if (g_input.IsCursorInRect(control_area) && g_input.GetKeyPress(VK_LBUTTON)) {
			this->dragging = true;
		}

		if (this->dragging) {
			if (g_input.GetKeyState(VK_LBUTTON)) {
				guiv2::ctx.m_handled_click = true;
				auto mouse = g_input.m_mouse;

				float new_x;
				float ratio;

				new_x = mouse.x - this->m_x;
				if (new_x < 0) new_x = 0;
				if (new_x > (this->m_w)) new_x = this->m_w;

				ratio = new_x / float(this->m_w);

				this->value = this->min + (this->max - this->min) * ratio;
			}
			else {
				this->dragging = false;
			}
		}
	}

	void Slider::Render() {

		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		auto size = D3D::GetTextSize(this->m_name, font);

		float ratio = value / (this->max - this->min);
		float location = ratio * this->m_w;

		D3D::Rect(vec2_t(this->m_x, this->m_y + size.y + 2), vec2_t(this->m_w, 5), Color(255, 255, 255), 1);
		D3D::RectFilled(vec2_t(this->m_x, this->m_y + size.y + 2), vec2_t(location, 5), Color(0, 255, 0));

		D3D::Text(vec2_t(this->m_x, this->m_y), this->m_name, Color(220, 220, 220), D3D::D3D9Fonts[D3D::EFonts::VERDANA], EFontFlags::FONTFLAG_NONE);
	}


	void Slider::SetMinMax(float min, float max) {
		this->min = min;
		this->max = max;
	}
}