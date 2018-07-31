#pragma once
#include "Fighter.h"

class FighterPharaoh : public Fighter
{
private:
	void SetHitboxs() override;
	void SetAtkboxs() override;
public:
	FighterPharaoh();
	~FighterPharaoh();
};

