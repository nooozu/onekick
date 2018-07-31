#include "Title.h"

Title::Title(ISceneChanger* changer) : BaseScene(changer)
{
}

void Title::Initialize()
{
	if (!FontManager::Register(L"Font/SSF4_ABUKET.ttf")){return;}

	f_title = Font(100, L"SSF4 ABUKET", FontStyle::Outline);
	f_title.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));

	f_message = Font(50, L"SSF4 ABUKET", FontStyle::Outline);
	f_message.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 2.0));

	background = Texture(Image(L"Image/Colosseum.jpg"));

	isChange = false;
	frame = 0;
}

void Title::Finalize()
{
}

void Title::Update()
{
	if (Input::AnyKeyClicked() || Gamepad(0).button(0).clicked) {
		isChange = true;
	}

	if (isChange) {
		frame++;
	}

	if (frame > 50) {
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}

void Title::Draw()
{
	background.draw();

	f_title(L"One Kick").drawCenter(640, 360);

	if (isChange) {
		if (frame % 5 == 0) {
			f_message(L"Press Start").drawCenter(640, 550);
		}
	}
	else {
		f_message(L"Press Start").drawCenter(640, 550);
	}
}
