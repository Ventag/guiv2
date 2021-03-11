#include "..\framework.h"

namespace guiv2 {

	void Tab::AddTab(std::string name) {

		this->tabs.push_back(name);
		if (this->tabs.size() <= 1)
			this->active_tab = name;
	}

	void Tab::AddTabElement(std::string name, BaseControl* child) {

		this->children.push_back(std::pair(name, child));

		/*if (child->m_type == ControlType::SLIDER) {
			child->m_w = this->m_w - 15;
		}*/
	}

	void Tab::Think() {

		// handle logic for selecting an active tab
		auto m = g_input.m_mouse;
		int width_additive = this->m_x;
		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		for (auto it : this->tabs) {
			
			auto size = D3D::GetTextSize(it, font);
			
			if (g_input.IsCursorInBounds(width_additive, this->m_y, width_additive + size.x + 15, this->m_y + size.y + 2) 
				&& g_input.GetKeyPress(VK_LBUTTON) && !guiv2::ctx.m_handled_click) {
				this->active_tab = it;
				guiv2::ctx.m_handled_click = true;
				break;
			}

			width_additive += size.x + 15;
		}

		int height = 20; // reserve 20 for the header
		for (auto it : this->children) {

			if (it.first.compare(this->active_tab.c_str()) != 0) // is it the active tab?
				continue;

			it.second->SetX(m_x); // update the pos
			it.second->SetY(m_y + 20); // + height);

			// reserve these calcs for groupboxes
			height += it.second->m_h;

			it.second->Think(); // handle control specific logic
		}

	}

	void Tab::Render() {

		// render all tab heads
		int width_additive = this->m_x;
		auto font = D3D::D3D9Fonts[D3D::EFonts::VERDANA];
		int i = 0;

		D3D::Rect(vec2_t(this->m_x, this->m_y + 16), vec2_t(this->m_w, this->m_h), Color(140, 152, 132), 1);
		
		for (auto it : this->tabs) {

			auto textcolor = Color(183, 186, 133);
			auto size = D3D::GetTextSize(it, font);
			int subtract_y = 0;
			if (it == this->active_tab) {
				size.x += 5;
				subtract_y = 2;
			}


			D3D::Rect(vec2_t(width_additive, this->m_y - subtract_y), vec2_t(size.x + 15, size.y + subtract_y), Color(140, 152, 132), 1); // debug, render bounding box for our headers
			
			D3D::Text(vec2_t(width_additive + 5, m_y + (subtract_y > 0 ? -(subtract_y/2) : 0)), it, it == this->active_tab ? Color(183, 186, 133) : Color(220, 220, 220), font, EFontFlags::FONTFLAG_NONE);

			width_additive += size.x + 15; i++;
		}

		// render all controls
		for (auto it : this->children) {

			if (it.first == this->active_tab)
				it.second->Render();
		}
	}
}