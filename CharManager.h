#pragma once
#include "Fighter.h"
#include "FighterLyu.h"
#include "FighterMonkey.h"
#include "FighterPharaoh.h"
#include "FighterGreece.h"
#include "FighterOtaku.h"

typedef enum {
	eP1,
	eP2,
	eDraw,
	eNone
} eVictory;

class CharManager
{
private:
	int frame;

	Fighter *p1, *p2;
	int p1_hp, p2_hp;
	
	eVictory victory, output_vic;
	Font message;

	bool isControl;

	Sound se_kick;

public:
	CharManager(eFighter p1_fighter, eFighter p2_fighter);
	~CharManager();

	void Update();
	void Draw();
	void Reset();

	void SetControl(bool flag) { isControl = flag; }

	eVictory GetVictory() { return output_vic; }

	Fighter GetP1() { return *p1; }
	Fighter GetP2() { return *p2; }
};

//target‚Æother‚ÌˆÊ’u‚ð”ä‚×‚Ätarget‚ÌŒü‚«‚ð•Ï‚¦‚é
void CheckDirection(Fighter &target, Fighter other);
bool CheckHitbox(Fighter &target, Fighter other);