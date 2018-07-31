#pragma once
#include "Fighter.h"

class FighterGreece : public Fighter
{
private:
	void SetHitboxs() override;
	void SetAtkboxs() override;
public:
	FighterGreece();
	~FighterGreece();
};