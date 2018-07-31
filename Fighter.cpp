#include "Fighter.h"

Fighter::Fighter()
{
}

Fighter::Fighter(int x, int y, int w, int h)
{
	isAlive = true;

	pos.x = x;
	pos.y = y;
	width = w;
	height = h;

	frame = 0;
}

void Fighter::Reset()
{
	isAlive = true;
	frame = 0;
}

Fighter::~Fighter()
{
}

String StatusToStr(eStatus s)
{
	switch (s) {
	case WAIT:
		return L"WAIT";
		break;
	case JUMP:
		return L"JUMP";
		break;
	case KICK:
		return L"KICK";
		break;
	case BACK_JUMP:
		return L"BACK_JUMP";
		break;
	case BACK_KICK:
		return L"BACK_KICK";
		break;
	default:
		return L"NONE";
	}
}

void Fighter::Update()
{
	Character::Update();

	atkboxs.clear();
	hitboxs.clear();

	SetAtkboxs();
	SetHitboxs();
}

void Fighter::DrawTexture(Texture t)
{
	if (direction == RIGHT) {
		t.drawAt(pos);
	}
	if (direction == LEFT) {
		t.mirror().drawAt(pos);
	}
}

void Fighter::Draw()
{
	if (isAlive) {
		switch (status)
		{
		case WAIT:
			DrawTexture(image[0]);
			break;
		case JUMP:
			DrawTexture(image[1]);
			break;
		case KICK:
			DrawTexture(image[2]);
			break;
		case BACK_JUMP:
			DrawTexture(image[3]);
			break;
		case BACK_KICK:
			DrawTexture(image[4]);
			break;
		default:
			break;
		}
	}
	else {
		frame++;
		if (frame > 20) {
			DrawTexture(image[5]);
		}
		else {
			switch (status)
			{
			case WAIT:
				DrawTexture(image[0]);
				break;
			case JUMP:
				DrawTexture(image[1]);
				break;
			case KICK:
				DrawTexture(image[2]);
				break;
			case BACK_JUMP:
				DrawTexture(image[3]);
				break;
			case BACK_KICK:
				DrawTexture(image[4]);
				break;
			default:
				break;
			}
		}
	}
	

	//Character::Draw();
	/*
	for (int i = 0; i < atkboxs.size(); i++) {
		atkboxs[i].Draw(Color(0, 255, 255));
	}
	for (int i = 0; i < hitboxs.size(); i++) {
		hitboxs[i].Draw(Color(0, 255, 0));
	}
	*/
}

void Fighter::DrawInfo(int x, int y)
{
	std::vector<String> arr;
	arr.push_back(L"------INFO------");
	arr.push_back(L"x=" + ToString(pos.x));
	arr.push_back(L"y=" + ToString(pos.y));
	arr.push_back(L"status=" + StatusToStr(status));
	arr.push_back(L"jamp_power=" + ToString(i_jump));
	arr.push_back(L"direction=" + Widen((direction == RIGHT) ? "RIGHT" : "LEFT"));
	arr.push_back(L"------CONTROLLER------");
	arr.push_back(L"index=" + ToString(controller.get_index()));
	arr.push_back(L"mode=" + Widen((XInput(controller.get_index()).isConnected()) ? "gamepad" : "keyboard"));
	arr.push_back(L"jump=" + ToString(controller.get_jump()));
	arr.push_back(L"back=" + ToString(controller.get_back()));

	for (int i = 0; i < arr.size(); i++) {
		PutText(arr[i]).from(x, y);
		y += 17;
	}
}
