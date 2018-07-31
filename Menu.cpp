#include "Menu.h"

Menu::Menu(ISceneChanger* changer) : BaseScene(changer)
{
}

void Menu::Initialize()
{
	if (!FontManager::Register(L"Font/SSF4_ABUKET.ttf")) { return; }

	f_title = Font(120, L"SSF4 ABUKET", FontStyle::Outline);
	f_title.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));

	f_message = Font(60, L"SSF4 ABUKET", FontStyle::Outline);
	f_message.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));

	background = Texture(Image(L"Image/background_00.png"));

	items.push_back(L"Versus");
	items.push_back(L"Config");
	items.push_back(L"Quit");

	select_num = 0;
}

void Menu::Finalize()
{
}

void Menu::Update()
{
	/*
	if (Input::KeySpace.clicked) {
		mSceneChanger->ChangeScene(eScene_Game);
	}
	*/

	if (Input::KeyUp.clicked || Gamepad(0).povForward.clicked) {
		select_num--;

		if (select_num < 0) {
			select_num = 0;
		}
	}
	if (Input::KeyDown.clicked || Gamepad(0).povBackward.clicked) {
		select_num++;

		if (select_num >= items.size()) {
			select_num = items.size() - 1;
		}
	}

	if (Input::KeyEnter.clicked || Gamepad(0).button(0).clicked) {
		switch (select_num)
		{
		case 0:
			mSceneChanger->ChangeScene(eScene_CharSelect);
			break;
		case 1:
			break;
		case 2:
			System::Exit();
			break;
		}
	}
}

void Menu::Draw()
{
	background.draw();
	
	f_title(L"Menu").drawCenter(250, 200);

	for (int i = 0; i < items.size(); i++) {

		if (select_num == i) {
			f_message(items[i]).draw({ 700, 320 + (i * 110) }, Color(255, 255, 0));
		}
		else {
			f_message(items[i]).draw(800, 320 + (i * 110));
		}
	}
}
