#pragma once
#include "BaseScene.h"

class Title : public BaseScene
{
private:
	int frame;
	bool isChange;
	Font f_title, f_message;

	Texture background;

public:
	Title(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};

