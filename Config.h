#pragma once
#include "BaseScene.h"

class Config : public BaseScene
{
public:
	Config(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};

