#pragma once
#include <Siv3D.hpp>
#include "DefaultConfig.h"
#include "Basebox.h"
#include "Controller.h"

typedef enum {
	RIGHT,
	LEFT
} eDirection;

typedef enum {
	WAIT,
	JUMP,
	KICK,
	BACK_JUMP,
	BACK_KICK,
} eStatus;

class Character
{
protected:
	Point pos;
	int width, height;

	eDirection direction; //character‚ÌŒü‚«
	
	eStatus status;

	int i_jump, i_jump_max;
	int i_jump_back;
	int i_attack;
	int i_gravity;

	void CheckInput();
	void Jamp();
	void Attack();
	void InScreen();
public:
	void set_i_jump(int i) { i_jump = i; }

	Controller controller;

	Point get_pos() { return pos; }
	int get_width() { return width; }
	int get_height() { return height; }

	eStatus get_status() { return status; }

	eDirection get_direction() { return direction; }

	void set_direction(eDirection d) { direction = d; }
	void set_status(eStatus status) { this->status = status; }

	Character();
	Character(int x, int y, int w, int h);
	~Character();

	virtual void Update();
	virtual void Draw();
};

