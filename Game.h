#pragma once
#include "BaseScene.h"
#include "CharManager.h"

#define GAME_TIME 20
#define GAME_ROUND 5

class Game : public BaseScene
{
private:
	bool isGameFinished, isRoundFinished;
	int select_count;

	Font fontS, fontM, fontL;

	int frame;
	int round;
	int p1_wins, p2_wins;

	int time, end_time;

	CharManager *char_mgr;

	Texture background;

	Sound bgm_00;
	Sound se_start;

	void RoundReset();
	void GameOverUpdate();
	void GameOverDraw();

public:
	Game(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};

