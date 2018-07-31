#include "FighterLyu.h"

FighterLyu::FighterLyu()
{
	image[0] = Texture(L"Image/lyu_wait.png");
	image[1] = Texture(L"Image/lyu_jump.png");
	image[2] = Texture(L"Image/lyu_kick.png");
	image[3] = Texture(L"Image/lyu_jump.png");
	image[4] = Texture(L"Image/lyu_back_kick.png");
	image[5] = Texture(L"Image/lyu_down.png");
	
	pos.x = 0;
	pos.y = 0;
	width = DEFAULT_CHAR_WIDTH;
	height = DEFAULT_CHAR_HEIGHT;
}

FighterLyu::~FighterLyu()
{
}

void FighterLyu::SetAtkboxs()
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
			20, 20));
		atkboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 50 : -50),
			pos.y + 70,
			20, 20));
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

void FighterLyu::SetHitboxs()
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
			60, 60));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -10 : 10),
			pos.y - 40,
			70, 30));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -10 : 10),
			pos.y - 75,
			30, 40));
		break;
	case JUMP:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y,
			80, 170));
		break;
	case KICK:
		hitboxs.push_back(Basebox(
			pos.x,
			pos.y - 70,
			50, 35));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -10 : 10),
			pos.y - 30,
			40, 40));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -10 : 10),
			pos.y + 10,
			60, 50));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 30 : -30),
			pos.y + 50,
			25, 25));
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
			35, 35));
		
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? -10 : 10),
			pos.y + 10,
			70, 80));
		hitboxs.push_back(Basebox(
			pos.x + ((direction == RIGHT) ? 40 : -40),
			pos.y + 40,
			80, 30));
		break;
	}
}