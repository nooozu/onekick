#include "Character.h"

Character::Character()
{
	status = JUMP;

	pos.x = WW_X / 2;
	pos.y = WW_Y / 2;

	width = DEFAULT_CHAR_WIDTH;
	height = DEFAULT_CHAR_HEIGHT;

	i_jump = 0;
	i_jump_max = DEFAULT_JUMP_POWER;
	i_jump_back = DEFAULT_JUMP_BACK;
	i_attack = DEFAULT_ATTACK;
	i_gravity = DEFAULT_GRAVITY;

	direction = RIGHT;
}

Character::Character(int x, int y, int w, int h)
{
	status = JUMP;

	pos.x = x;
	pos.y = y;

	width = w;
	height = h;

	i_jump = 0;
	i_jump_max = DEFAULT_JUMP_POWER;
	i_jump_back = DEFAULT_JUMP_BACK;
	i_attack = DEFAULT_ATTACK;
	i_gravity = DEFAULT_GRAVITY;

	direction = RIGHT;
}

Character::~Character()
{
}

void Character::Update()
{
	CheckInput();
	Attack();
	Jamp();
	InScreen();
}

void Character::CheckInput()
{
	switch (status) {

	case WAIT:
		if (controller.get_jump() == 1) {
			status = JUMP;
			i_jump = i_jump_max;
		}
		else if (controller.get_back() == 1) {
			status = BACK_JUMP;
			i_jump = i_jump_max;
		}
		break;

	case JUMP:
		if (controller.get_jump() == 1) {
			status = KICK;
		}
		else if (controller.get_back() == 1) {
			status = BACK_KICK;
		}
		break;

	case KICK:
		break;

	case BACK_JUMP:
		if (controller.get_jump() == 1) {
			status = KICK;
		}
		else if (controller.get_back() == 1) {
			status = BACK_KICK;
		}
		break;

	case BACK_KICK:
		break;
	}
}

void Character::Jamp()
{
	if (status == JUMP) {

		pos.y -= i_jump;
		i_jump -= 1.0;

		if (i_jump < 0.0) {
			i_jump = 0;
		}
	}
	if (status == BACK_JUMP) {

		pos.y -= i_jump;
		i_jump -= 1.0;

		if (i_jump < 0.0) {
			i_jump = 0;
		}

		//Œã‚ë•ûŒü‚É‰º‚ª‚é
		switch (direction)
		{
		case RIGHT:
			pos.x -= i_jump_back;
			break;
		case LEFT:
			pos.x += i_jump_back;
			break;
		}
	}

	//d—Í
	switch (status) {
	case JUMP:
	case BACK_JUMP:
	case KICK:
	case BACK_KICK:
		pos.y += i_gravity;
		break;
	}

	//’n–Ê‚É“–‚½‚Á‚Ä‚¢‚éê‡WAIT‚ÉˆÚs
	if (pos.y > GROUND_Y - height / 2) {
		pos.y = GROUND_Y - height / 2;
		status = WAIT;
	}
}

void Character::Attack()
{
	if (status == KICK) {
		i_jump = 0;

		switch (direction)
		{
		case RIGHT:
			pos.x += i_attack;
			break;
		case LEFT:
			pos.x -= i_attack;
			break;
		}
	}
	if (status == BACK_KICK) {

	}
}

void Character::InScreen()
{
	if (pos.x < 0 + width / 2) {
		pos.x = 0 + width / 2;
	}
	if (pos.x > WW_X - width / 2) {
		pos.x = WW_X - width / 2;
	}

	if (pos.y < 0 + height / 2) {
		pos.y = 0 + height / 2;
	}
	if (pos.y > WW_Y - height / 2) {
		pos.y = WW_Y - height / 2;
	}
}

void Character::Draw()
{
	Circle(pos.x, pos.y, 3).draw();
	Basebox(pos.x, pos.y, width, height).Draw();
}