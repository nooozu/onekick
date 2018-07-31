#include "FighterPharaoh.h"

FighterPharaoh::FighterPharaoh()
{
	image[0] = Texture(L"Image/pharaoh_wait.png");
	image[1] = Texture(L"Image/pharaoh_jump.png");
	image[2] = Texture(L"Image/pharaoh_kick.png");
	image[3] = Texture(L"Image/pharaoh_jump.png");
	image[4] = Texture(L"Image/pharaoh_back_kick.png");
	image[5] = Texture(L"Image/pharaoh_down.png");

	pos.x = 0;
	pos.y = 0;
	width = DEFAULT_CHAR_WIDTH;
	height = DEFAULT_CHAR_HEIGHT;
}

FighterPharaoh::~FighterPharaoh()
{
}

void FighterPharaoh::SetAtkboxs()
{
	switch (status)
	{
	case WAIT:
		break;
	case JUMP:
		break;
	case KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 10 : -10),
			pos.y - 5,
			20, 20));
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 10 : -10),
			pos.y - 60,
			20, 20));
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 20 : -20),
			pos.y + 60,
			20, 20));
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 30 : -30),
			pos.y + 80,
			40, 20));
		break;
	case BACK_JUMP:
		break;
	case BACK_KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 35,
			100, 35));
		break;
	default:
		break;
	}
}

void FighterPharaoh::SetHitboxs()
{
	switch (status)
	{
	case WAIT:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -10 : 10),
			pos.y + 52,
			80, 60));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -10 : 10),
			pos.y,
			70, 60));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -20 : 20),
			pos.y - 40,
			70, 30));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -15 : 15),
			pos.y - 75,
			40, 50));
		break;
	case JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			80, 170));
		break;
	case KICK:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -60 : 60),
			pos.y - 70,
			55, 45));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -55 : 55),
			pos.y - 30,
			60, 40));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -30 : 30),
			pos.y + 10,
			60, 50));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 5 : -5),
			pos.y + 50,
			65, 30));
		break;
	case BACK_JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			80, 170));
		break;
	case BACK_KICK:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -50 : 50),
			pos.y - 60,
			50, 45));

		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -50 : 50),
			pos.y + 10,
			70, 80));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 30 : -30),
			pos.y + 40,
			100, 30));
		break;
	}
}