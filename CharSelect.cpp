#include "CharSelect.h"

eFighter IntToFighter(int i) {
	switch (i) {
	case 0:
		return eMonkey;
		break;
	case 1:
		return ePharaoh;
		break;
	case 2:
		return eGreece;
		break;
	case 3:
		return eLyu;
		break;
	case 4:
		return eOtaku;
		break;
	default:
		return eMonkey;
		break;
	}
}

CharSelect::CharSelect(ISceneChanger* changer) : BaseScene(changer)
{
}

void CharSelect::Initialize()
{
	if (!FontManager::Register(L"Font/SSF4_ABUKET.ttf")) { return; }

	f_title = Font(120, L"SSF4 ABUKET", FontStyle::Outline);
	f_title.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));

	f_message = Font(80, L"SSF4 ABUKET", FontStyle::Outline);
	f_message.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));

	char_count = 5;

	p1_select = 0;
	p2_select = char_count - 1;

	Image img[5];

	img[0] = Image(L"Image/monkey_wait.png");
	img[1] = Image(L"Image/pharaoh_wait.png");
	img[2] = Image(L"Image/greece_wait.png");
	img[3] = Image(L"Image/lyu_wait.png");
	img[4] = Image(L"Image/otaku_wait.png");

	for (int i = 0; i < 5; i++) {
		image[i] = Texture(img[i]);
		image_gray[i] = Texture(img[i].grayscaled());
		image_big[i] = Texture(img[i].scale(3.0));
	}

	background = Texture(Image(L"Image/CharSelect.png"));
}

void CharSelect::Finalize()
{
}

void CharSelect::Update()
{
	if (!isP1Ready) {
		if (Input::KeyA.clicked || Gamepad(0).povLeft.clicked) {
			p1_select--;
			if (p1_select < 0) {
				p1_select = char_count - 1;
			}
		}
		if (Input::KeyS.clicked || Gamepad(0).povRight.clicked) {
			p1_select++;
			if (p1_select > char_count - 1) {
				p1_select = 0;
			}
		}
	}
	
	if (!isP2Ready) {
		if (Input::KeyJ.clicked || Gamepad(1).povLeft.clicked) {
			p2_select--;
			if (p2_select < 0) {
				p2_select = char_count - 1;
			}
		}
		if (Input::KeyK.clicked || Gamepad(1).povRight.clicked) {
			p2_select++;
			if (p2_select > char_count - 1) {
				p2_select = 0;
			}
		}
	}
	

	if (Gamepad(0).button(0).clicked) {
		isP1Ready = !isP1Ready;
	}

	if (Gamepad(1).button(0).clicked) {
		isP2Ready = !isP2Ready;
	}


	if (isP1Ready && isP2Ready) {

		set_p1(IntToFighter(p1_select));
		set_p2(IntToFighter(p2_select));

		mSceneChanger->ChangeScene(eScene_Game);
	}
}

void CharSelect::Draw()
{
	background.draw();

	PutText(L"CharSelect").from(0, 0);

	double width = 150, interval = 20;
	double len = char_count * (width + interval) - interval;

	{
		int x = WW_X / 10;
		int y = WW_Y / 2 + 60;

		image_big[p1_select].drawAt(x * 2, y);
		image_big[p2_select].mirror().drawAt(x * 8, y);

		if (isP1Ready) {
			f_message(L"Ready").drawCenter(x * 2, y - 100);
		}

		if (isP2Ready) {
			f_message(L"Ready").drawCenter(x * 8, y - 100);
		}
	}

	for (int i = 0; i < char_count; i++) {
		double x = 640 + (i * (width + interval)) - len / 2;
		double y = 450;

		Rect rect = Rect(x, y, width, width + 50);

		rect.drawFrame(0, 10, Palette::Black);
		rect.draw();

		if (i == p1_select || i == p2_select) {
			image[i].draw(x - 20, y);
		}
		else {
			image_gray[i].draw(x - 20, y);
		}
	}

	double x1, x2;
	double y = 450 - 30;

	if (p1_select == p2_select) {
		x1 = 640 + ((p1_select * (width + interval)) - len / 2) + width / 2 - 30;
		x2 = 640 + ((p2_select * (width + interval)) - len / 2) + width / 2 + 30;
	}
	else {
		x1 = 640 + ((p1_select * (width + interval)) - len / 2) + width / 2;
		x2 = 640 + ((p2_select * (width + interval)) - len / 2) + width / 2;
	}

	f_title(L"VS").drawCenter(WW_X / 2, WW_Y / 2);

	f_message(L"P1").drawCenter(100, 120);
	f_message(L"P2").drawCenter(1180, 120);

	f_message(L"V").drawCenter(x1, y, Palette::Red);
	f_message(L"V").drawCenter(x2, y, Palette::Blue);
}
