#pragma once
#include "Fighter.h"

class FighterOtaku : public Fighter
{
private:
	void SetHitboxs() override;
	void SetAtkboxs() override;
public:
	FighterOtaku();
	~FighterOtaku();
};

