#include "FighterOtaku.h"

FighterOtaku::FighterOtaku()
{
	image[0] = Texture(L"Image/otaku_wait.png");
	image[1] = Texture(L"Image/otaku_jump.png");
	image[2] = Texture(L"Image/otaku_kick.png");
	image[3] = Texture(L"Image/otaku_jump.png");
	image[4] = Texture(L"Image/otaku_back_kick.png");
	image[5] = Texture(L"Image/otaku_down.png");

	pos.x = 0;
	pos.y = 0;
	width = DEFAULT_CHAR_WIDTH;
	height = DEFAULT_CHAR_HEIGHT;
}

FighterOtaku::~FighterOtaku()
{
}

void FighterOtaku::SetAtkboxs()
{
	switch (status)
	{
	case WAIT:
		break;
	case JUMP:
		break;
	case KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 35 : -35),
			pos.y + 70,
			50, 20));
		break;
	case BACK_JUMP:
		break;
	case BACK_KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 20,
			100, 30));
		break;
	default:
		break;
	}
}

void FighterOtaku::SetHitboxs()
{
	switch (status)
	{
	case WAIT:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -5 : 5),
			pos.y + 35,
			70, 120));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 10 : -10),
			pos.y - 40,
			90, 30));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -5 : 5),
			pos.y - 75,
			50, 40));
		break;
	case JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			80, 170));
		break;
	case KICK:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -25 : 25),
			pos.y - 70,
			55, 50));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -5 : 5),
			pos.y - 30,
			60, 40));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 10 : -10),
			pos.y + 10,
			60, 50));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 30 : -30),
			pos.y + 50,
			50, 25));
		break;
	case BACK_JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			80, 170));
		break;
	case BACK_KICK:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -30 : 30),
			pos.y - 60,
			45, 45));

		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -20 : 20),
			pos.y + 10,
			70, 80));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 30,
			80, 30));
		break;
	}
}