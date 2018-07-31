#pragma once
#include "BaseScene.h"

class Menu : public BaseScene
{
private:
	Font f_title, f_message;
	std::vector<String> items;

	Texture background;

	int select_num;

public:
	Menu(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};

