#include "..\framework.h"

namespace guiv2 {

	void ComboBox::Think() {
		this->m_x += this->m_offset_x;
		this->m_y += this->m_offset_y;

		if (guiv2::ctx.m_handled_click)
			return;

		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		auto size = D3D::GetTextSize(this->m_name, font);

		Rect control_area = Rect{ this->m_x, this->m_y + (int)size.y + 4, this->m_w, COMBOBOX_HEIGHT };

		if (g_input.GetKeyPress(VK_LBUTTON) && open) {
			for (int i = 0; i < values.size(); i++) {
				Rect current_item_area = Rect{this->m_x, this->m_y + (int)size.y + 4 + COMBOBOX_HEIGHT + (COMBOBOX_HEIGHT * i), this->m_w, COMBOBOX_HEIGHT };
				if(g_input.IsCursorInRect(current_item_area)) {
					*this->value = this->values.at(i).first;
					guiv2::ctx.m_handled_click = true;
					break;
				}
			}
		}

		if (g_input.IsCursorInRect(control_area)) {
			if (g_input.GetKeyPress(VK_LBUTTON)) {
				open = !open;
				guiv2::ctx.m_handled_click = true;
			}
		}
	}

	void ComboBox::Render() {

		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		auto size = D3D::GetTextSize(this->m_name, font);

		D3D::Rect(vec2_t(this->m_x, this->m_y + size.y + 2), vec2_t(this->m_w, 16), Color(255, 255, 255), 1);

		D3D::Text(vec2_t(this->m_x, this->m_y), this->m_name, Color(220, 220, 220), D3D::D3D9Fonts[D3D::EFonts::VERDANA], EFontFlags::FONTFLAG_NONE);
		D3D::Text(vec2_t(this->m_x + 5, this->m_y + size.y + 4), this->values.at(*this->value).second.c_str(), Color(220, 220, 220), D3D::D3D9Fonts[D3D::EFonts::VERDANA], EFontFlags::FONTFLAG_NONE);


		if (open) {
			//TODO: Scrollable droplist
			//D3D::SetLimit(std::pair<vec2_t, vec2_t>(vec2_t(this->m_x, this->m_y), vec2_t(this->m_w, height )));
			int height = COMBOBOX_HEIGHT * values.size();
			D3D::Rect(vec2_t(this->m_x, this->m_y + size.y + 4), vec2_t(this->m_w, COMBOBOX_HEIGHT + height), Color(90, 90, 90));
			for (int i = 0; i < values.size(); i++) {

				auto color = *value == i ? Color(0, 255, 0) : Color(255, 255, 255);

				D3D::Text(vec2_t(this->m_x + 5, this->m_y + size.y + 4 + COMBOBOX_HEIGHT + (COMBOBOX_HEIGHT * i)), values.at(i).second.c_str(), color, D3D::D3D9Fonts[D3D::EFonts::VERDANA], D3D::EFontFlags::NONE);
			}
			//D3D::ResetLimit();
		}

	}
}