#pragma once
#include "BaseScene.h"

class CharSelect : public BaseScene
{
private:
	Font f_title, f_message;

	int char_count;
	int p1_select, p2_select;
	bool isP1Ready, isP2Ready;

	Texture background;

	Texture image[5];
	Texture image_gray[5];
	Texture image_big[5];

public:
	CharSelect(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};