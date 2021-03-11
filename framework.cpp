#include "framework.h"

#include "controls/basecontrol.h"
#include "controls/form.h"

#include "../cstrike/input/input.h"

namespace guiv2 {

	Context ctx;

	void Context::Initialize() {

		bool default_value = false;

		mainform = new guiv2::Form("Main Window", 10, 10, 500, 460);

		auto tab = new Tab("unneeded", 10, 30, 480, 400);
		tab->AddTab("First");

		auto slider = new Slider("slider", 10, 25, 440);
		slider->SetMinMax(0.f, 100.f);
		tab->AddTabElement("First", slider);

		static int ival = 0;
		auto combobox = new ComboBox("combobox", 10, 45, 440);
		combobox->SetValue(&ival);
		combobox->AddItem(0, "first");
		combobox->AddItem(1, "second");
		combobox->AddItem(2, "third");
		tab->AddTabElement("First", combobox);

		auto group = new Groupbox("", 10, 10, 460, 380);
		auto box3 = new CheckBox("testsbox3"); box3->SetValue(&default_value);
		auto box4 = new CheckBox("testsbox4"); box4->SetValue(&default_value);
		auto box5 = new CheckBox("testsbox5"); box5->SetValue(&default_value);
		auto box6 = new CheckBox("testsbox6"); box6->SetValue(&default_value);
		auto box7 = new CheckBox("testsbox7"); box7->SetValue(&default_value);
		auto box8 = new CheckBox("testsbox8"); box8->SetValue(&default_value);
		auto box9 = new CheckBox("testsbox9"); box9->SetValue(&default_value);
		auto box10 = new CheckBox("testsbox10"); box10->SetValue(&default_value);
		auto box11 = new CheckBox("testsbox11"); box11->SetValue(&default_value);
		auto box12 = new CheckBox("testsbox12"); box12->SetValue(&default_value);
		auto box13 = new CheckBox("testsbox13"); box13->SetValue(&default_value);
		auto box14 = new CheckBox("testsbox14"); box14->SetValue(&default_value);
		auto box15 = new CheckBox("testsbox15"); box15->SetValue(&default_value);
		auto box16 = new CheckBox("testsbox16"); box16->SetValue(&default_value);
		auto box17 = new CheckBox("testsbox17"); box17->SetValue(&default_value);
		auto box18 = new CheckBox("testsbox18"); box18->SetValue(&default_value);
		auto box19 = new CheckBox("testsbox19"); box19->SetValue(&default_value);
		auto box20 = new CheckBox("testsbox20"); box20->SetValue(&default_value);
		auto box21 = new CheckBox("testsbox21"); box21->SetValue(&default_value);
		auto box22 = new CheckBox("testsbox22"); box22->SetValue(&default_value);
		auto box23 = new CheckBox("testsbox23"); box23->SetValue(&default_value);
		auto box24 = new CheckBox("testsbox24"); box24->SetValue(&default_value);
		auto box25 = new CheckBox("testsbox25"); box25->SetValue(&default_value);
		auto box26 = new CheckBox("testsbox26"); box26->SetValue(&default_value);
		auto box27 = new CheckBox("testsbox27"); box27->SetValue(&default_value);
		auto box28 = new CheckBox("testsbox28"); box28->SetValue(&default_value);
		auto box29 = new CheckBox("testsbox29"); box29->SetValue(&default_value);
		auto box30 = new CheckBox("testsbox30"); box30->SetValue(&default_value);
		auto box31 = new CheckBox("testsbox31"); box31->SetValue(&default_value);

		group->AddElement(box3);
		group->AddElement(box4);
		group->AddElement(box5);
		group->AddElement(box6);
		group->AddElement(box7);
		group->AddElement(box8);
		group->AddElement(box9);
		group->AddElement(box10);
		group->AddElement(box11);
		group->AddElement(box12);
		group->AddElement(box13);
		group->AddElement(box14);
		group->AddElement(box15);
		group->AddElement(box16);
		group->AddElement(box17);
		group->AddElement(box18);
		group->AddElement(box19);
		group->AddElement(box20);
		group->AddElement(box21);
		group->AddElement(box22);
		group->AddElement(box23);
		group->AddElement(box24);
		group->AddElement(box25);
		group->AddElement(box26);
		group->AddElement(box27);
		group->AddElement(box28);
		group->AddElement(box29);
		group->AddElement(box30);
		group->AddElement(box31);

		tab->AddTabElement("Second", group);


		tab->AddTab("Visuals");


		mainform->AddChild(tab);
	}

	void Context::PreFrame() {
		this->m_handled_click = false;
	}

	void Context::OnFrame() {
		mainform->Think();
		mainform->Render();
	}

	void Context::PostFrame() {

		auto mousedata = g_input.m_mouse;
		this->m_mouse_x = mousedata.x;
		this->m_mouse_y = mousedata.y;
	}
}