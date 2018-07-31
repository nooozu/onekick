#include "FighterMonkey.h"

FighterMonkey::FighterMonkey()
{
	image[0] = Texture(L"Image/monkey_wait.png");
	image[1] = Texture(L"Image/monkey_jump.png");
	image[2] = Texture(L"Image/monkey_kick.png");
	image[3] = Texture(L"Image/monkey_jump.png");
	image[4] = Texture(L"Image/monkey_back_kick.png");
	image[5] = Texture(L"Image/monkey_down.png");

	pos.x = 0;
	pos.y = 0;
	width = DEFAULT_CHAR_WIDTH;
	height = DEFAULT_CHAR_HEIGHT;
}

FighterMonkey::~FighterMonkey()
{
}

void FighterMonkey::SetAtkboxs()
{
	switch (status)
	{
	case WAIT:
		break;
	case JUMP:
		break;
	case KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 50 : -50),
			pos.y + 70,
			70, 25));
		break;
	case BACK_JUMP:
		break;
	case BACK_KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 40,
			100, 20));
		break;
	default:
		break;
	}
}

void FighterMonkey::SetHitboxs()
{
	switch (status)
	{
	case WAIT:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -15 : 15),
			pos.y + 52,
			60, 60));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 10 : -10),
			pos.y,
			100, 60));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 45 : -45),
			pos.y - 50,
			55, 60));
		break;
	case JUMP:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 5 : -5),
			pos.y,
			100, 170));
		break;
	case KICK:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 10 : -10),
			pos.y - 60,
			80, 50));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -20 : 20),
			pos.y + 5,
			70, 70));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -5 : +5),
			pos.y + 35,
			70, 65));
		break;
	case BACK_JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			80, 170));
		break;
	case BACK_KICK:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y - 60,
			35, 50));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -50 : 50),
			pos.y - 50,
			55, 50));

		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -40 : 40),
			pos.y + 10,
			70, 80));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 40,
			80, 30));
		break;
	}
}