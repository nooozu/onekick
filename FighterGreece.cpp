#include "FighterGreece.h"

FighterGreece::FighterGreece()
{
	image[0] = Texture(L"Image/greece_wait.png");
	image[1] = Texture(L"Image/greece_jump.png");
	image[2] = Texture(L"Image/greece_kick.png");
	image[3] = Texture(L"Image/greece_jump.png");
	image[4] = Texture(L"Image/greece_back_kick.png");
	image[5] = Texture(L"Image/greece_down.png");

	pos.x = 0;
	pos.y = 0;
	width = DEFAULT_CHAR_WIDTH;
	height = DEFAULT_CHAR_HEIGHT;
}

FighterGreece::~FighterGreece()
{
}

void FighterGreece::SetAtkboxs()
{
	switch (status)
	{
	case WAIT:
		break;
	case JUMP:
		break;
	case KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 30 : -30),
			pos.y + 50,
			40, 25));
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 50 : -50),
			pos.y + 80,
			40, 25));
		break;
	case BACK_JUMP:
		break;
	case BACK_KICK:
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 70,
			100, 20));
		break;
	default:
		break;
	}
}

void FighterGreece::SetHitboxs()
{
	switch (status)
	{
	case WAIT:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -0 : 0),
			pos.y + 52,
			60, 60));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -0 : 0),
			pos.y,
			45, 60));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 10 : -10),
			pos.y - 40,
			80, 30));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -0 : 0),
			pos.y - 75,
			35, 40));
		break;
	case JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			95, 150));
		break;
	case KICK:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -45 : 45),
			pos.y - 70,
			40, 40));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -20 : 20),
			pos.y - 30,
			60, 40));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 0 : 0),
			pos.y + 10,
			60, 50));
		break;
	case BACK_JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			80, 170));
		break;
	case BACK_KICK:
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -5 : 5),
			pos.y - 70,
			40, 45));

		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 0 : 0),
			pos.y - 5,
			70, 90));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 50,
			80, 30));
		break;
	}
}