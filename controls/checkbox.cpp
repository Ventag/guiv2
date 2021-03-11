#include "..\helpers\bounds.h"
#include "..\framework.h"

namespace guiv2 {

	void CheckBox::Think() {

		this->m_x += this->m_offset_x;
		this->m_y += this->m_offset_y;

		if (guiv2::ctx.m_handled_click)
			return;

		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		auto size = D3D::GetTextSize(this->m_name, font);
		auto mpos = g_input.m_mouse;

		if (g_input.IsCursorInBounds(this->m_x - 15, this->m_y, this->m_x + this->m_w, this->m_y + this->m_h)
			&& g_input.GetKeyPress(VK_LBUTTON)) {
			if (this->val != nullptr)
				this->val->set<bool>(!this->val->get<bool>());
				*this->value = this->val->get<bool>();
				guiv2::ctx.m_handled_click = !guiv2::ctx.m_handled_click;
		}
	}

	void CheckBox::Render() {

		D3D::Rect(vec2_t(this->m_x - 15, this->m_y), vec2_t(10, this->m_h), Color(255, 255, 255), 1);

		if (*this->value == true) {
			D3D::RectFilled(vec2_t(this->m_x - 14, this->m_y + 1), vec2_t(7, this->m_h - 3), Color(212, 212, 212));
		}

		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		auto size = D3D::GetTextSize(this->m_name, font);
		D3D::Text(vec2_t(this->m_x, this->m_y - (this->m_h / 2)), this->m_name, Color(220, 220, 220), D3D::D3D9Fonts[D3D::EFonts::VERDANA], EFontFlags::FONTFLAG_NONE);// , D3D::EStringAlign::TEXT_ALIGN_LEFT_CENTER);

		D3D::Rect(vec2_t(this->m_x - 15, this->m_y), vec2_t(this->m_w, this->m_h), Color(255, 0, 0));
	}
}