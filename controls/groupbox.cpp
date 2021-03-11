#include "..\framework.h"

namespace guiv2 {

	void Groupbox::Think() {

		/* handle scrolling */
		if(g_input.m_scroll != 0 
			&& g_input.IsCursorInBounds(this->m_x, this->m_y, this->m_x + this->m_w, this->m_y + this->m_h)
			&& this->scrollable) {
			this->offset_render_height += 10 * g_input.m_scroll; // multiply by sign, are we going up or down?
			this->offset_render_height = std::clamp(this->offset_render_height, (this->offset_render_height_max * -1) - 10, 0);
		}

		/* update controls */
		this->offset_height_additive = this->scrollable ? 5 : -5;
		std::for_each(std::begin(this->children), std::end(this->children), [this](BaseControl* c) {
			c->SetX(this->m_x + 20);
			c->SetY(this->m_y + this->offset_render_height + this->offset_height_additive - c->m_offset_y);
			c->SetW(this->m_w - (40));
			c->Think();
			this->offset_height_additive += c->m_h + 5;
		});
	}

	void Groupbox::Render() {
		
		float height = this->m_h;
		float height_max = this->m_h + this->offset_render_height_max;

		D3D::SetLimit(std::pair<vec2_t, vec2_t>(vec2_t(this->m_x, this->m_y), vec2_t(this->m_w, this->m_h)));
		std::for_each(std::begin(this->children), std::end(this->children), [this](BaseControl* c) {
			c->Render();
		});
		D3D::ResetLimit();

		if (this->scrollable) {

			float scrollbar_height = (height / height_max) * this->m_h;
			float scrollbar_pos = std::min(std::max(-(this->offset_render_height / height_max) * height, 2.f), height - scrollbar_height - 2.f);

			D3D::RectFilled(vec2_t(this->m_x + this->m_w - 8, this->m_y), vec2_t(8, this->m_h), Color(125, 125, 125));

			D3D::RectFilled(vec2_t(this->m_x + this->m_w - 6, this->m_y + scrollbar_pos), vec2_t(4, scrollbar_height), Color(101, 101, 101));
		}

		D3D::Rect(vec2_t(this->m_x, this->m_y), vec2_t(this->m_w, this->m_h), Color(125, 125, 125));

	}

	void Groupbox::AddElement(BaseControl* control) {

		if (!control) 
			throw "Groupbox::AddElement - control is null";

		this->offset_render_height += control->m_h + 5; // move padding constant elsewhere?

		this->offset_render_height_max = this->offset_render_height - this->m_h;
		if (this->offset_render_height_max > 0) {
			this->scrollable = true;
		}

		this->children.push_back(control);
	}
}