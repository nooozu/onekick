#pragma once
#include "Fighter.h"

class FighterMonkey : public Fighter
{
private:
	void SetHitboxs() override;
	void SetAtkboxs() override;
public:
	FighterMonkey();
	~FighterMonkey();
};

