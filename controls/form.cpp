#include "..\helpers\bounds.h"
#include "..\framework.h"


namespace guiv2 {

	void Form::AddChild(BaseControl* child) {

		if (!child)
			throw std::runtime_error("child is null");

		child->SetX(this->m_x);
		child->SetY(this->m_y);

		this->children.push_back(child);
	}

	void Form::HandleDrag( ) {

		static int d_x, d_y;

		const auto mdata = g_input.m_mouse;

		if (g_input.GetKeyState(1) && this->m_dragging) {
			this->m_x = mdata.x - this->m_dmouse_x;
			this->m_y = mdata.y - this->m_dmouse_y;

			this->m_dragging = true;
		}
		else
			this->m_dragging = false;

		if (g_input.GetKeyState(1) && g_input.IsCursorInBounds(this->m_x, this->m_y, this->m_x + this->m_w, this->m_y + /*this->m_h - remove this magic var*/ 20)) {
			this->m_dmouse_x = mdata.x - this->m_x; 
			this->m_dmouse_y = mdata.y - this->m_y;

			this->m_dragging = true;
			guiv2::ctx.m_handled_click = true;
		}
	}

	void Form::Think( ) {

		if(g_input.GetKeyPress(VK_INSERT))
		//if (g_input.GetKeyPress(VK_INSERT))
		//if(GetAsyncKeyState(VK_INSERT))
			this->m_open = !this->m_open;

		if (g_input.GetKeyPress(VK_DELETE))
		//if(g_input.GetKeyState(VK_DELETE))
		{
			g_cl.print("unloading module");
			g_cl.m_keep_alive = false;
		}

		if (!this->m_open)
		{
			if (ctx.is_open)
				ctx.is_open = false;
			return;
		}
		
		ctx.is_open = true;

		auto m = g_input.m_mouse;
		// check if we're clicking close btn
		if (g_input.IsCursorInBounds(this->m_x + this->m_w - 25,
			this->m_y + 10,
			this->m_x + this->m_w - 15,
			this->m_y + 20) && g_input.GetKeyPress(VK_LBUTTON))
		{
			this->m_open = !this->m_open;
		}

		this->HandleDrag();

		// finally update positions
		std::for_each(std::begin(this->children), std::end(this->children), [this](BaseControl* c) { 
			c->SetX(this->m_x); 
			c->SetY(this->m_y); 
			c->Think();
		});
	}

	void Form::Render( ) {

		if (!this->m_open)
			return;

		D3D::CircleFilled(vec2_t(this->m_x, this->m_y), 5, Color(76, 88, 68)); // top left
		D3D::CircleFilled(vec2_t(this->m_x + this->m_w, this->m_y), 5, Color(76, 88, 68)); // top right
		D3D::CircleFilled(vec2_t(this->m_x + this->m_w, this->m_y + this->m_h), 5, Color(76, 88, 68)); // bottom right
		D3D::CircleFilled(vec2_t(this->m_x, this->m_y + this->m_h), 5, Color(76, 88, 68)); // bottom left

		const auto pos_horizontal = vec2_t(this->m_x - 5, this->m_y);
		const auto pos_vertical = vec2_t(this->m_x, this->m_y - 5);

		auto dim_horizontal = vec2_t(this->m_w + 10, this->m_h);
		auto dim_vertical = vec2_t(this->m_w, this->m_h + 10);

		D3D::RectFilled(pos_horizontal - 1, dim_horizontal + 2, Color(76, 88, 68));
		D3D::RectFilled(pos_vertical - 1, dim_vertical + 2, Color(76, 88, 68));

		// close button
		D3D::SmoothLine(vec2_t(this->m_x + this->m_w - 25, this->m_y + 20), vec2_t(this->m_x + this->m_w - 15, this->m_y + 10), true, 2.f, Color(200, 200, 200));
		D3D::SmoothLine(vec2_t(this->m_x + this->m_w - 15, this->m_y + 20), vec2_t(this->m_x + this->m_w - 25, this->m_y + 10), true, 2.f, Color(200, 200, 200));

		// title
		D3D::Text(vec2_t(this->m_x + 10, this->m_y), this->m_name, Color(200, 200, 200), D3D::D3D9Fonts[D3D::EFonts::VERDANA], D3D::EFontFlags::NONE);

		for (auto it : this->children) {

			it->Render(); // render our controls
		}
	}
}