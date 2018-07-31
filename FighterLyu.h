#pragma once
#include "Fighter.h"

class FighterLyu : public Fighter
{
private:
	void SetHitboxs() override;
	void SetAtkboxs() override;
public:
	FighterLyu();
	~FighterLyu();
};

