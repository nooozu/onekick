#include "Game.h"
#include <ctime>

Game::Game(ISceneChanger* changer) : BaseScene(changer)
{
}

void Game::Initialize()
{
	isGameFinished = false;
	isRoundFinished = false;

	if (!FontManager::Register(L"Font/SSF4_ABUKET.ttf")) { return; }

	fontS = Font(40, L"SSF4 ABUKET", FontStyle::Outline);
	fontS.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));
	fontM = Font(80, L"SSF4 ABUKET", FontStyle::Outline);
	fontM.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));
	fontL = Font(120, L"SSF4 ABUKET", FontStyle::Outline);
	fontL.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));

	char_mgr = new CharManager(p1_fighter, p2_fighter);

	round = 1;
	p1_wins = 0, p2_wins = 0;

	srand((unsigned)std::time(NULL));
	int r = rand() % 3;
	switch (r)
	{
	case 0:
		background = Texture(Image(L"Image/background_00.png"));
		break;
	case 1:
		//background = Texture(Image(L"Image/background_01.png"));
		//break;
	case 2:
		background = Texture(Image(L"Image/Colosseum.jpg"));
		break;
	default:
		background = Texture(Image(L"Image/background_00.png"));
		break;
	}

	se_start = Sound(L"Sound/gong-played1.mp3");
	bgm_00 = Sound(L"Sound/battle30.mp3");
	bgm_00.setLoop(true);
	bgm_00.setVolume(0.2);
	bgm_00.play();

	RoundReset();
}

void Game::Finalize()
{
	delete char_mgr;
	char_mgr = NULL;
}

void Game::RoundReset()
{
	frame = 0;
	end_time = 0;
	time = 60 * GAME_TIME;
}

void Game::Update()
{
	char_mgr->Update();

	char_mgr->SetControl(false);

	if (!isGameFinished) {
		if (frame < 60) {

		}
		else if (frame < 120) {

			if (frame == 100) {
				se_start.play();
			}
		}
		else {
			char_mgr->SetControl(true);

			time--;
			if (time < 0) {
				time = 0;
			}
		}
	}

	//勝利判定
	switch (char_mgr->GetVictory()) {
	case eP1:
		p1_wins++;
		break;
	case eP2:
		p2_wins++;
		break;
	}

	//時間切れ
	if (time <= 0) {
		isRoundFinished = true;
		int p1_len = fabs(WW_X / 2 - char_mgr->GetP1().get_pos().x);
		int p2_len = fabs(WW_X / 2 - char_mgr->GetP2().get_pos().x);

		if (p1_len < p2_len) {
			p1_wins++;
		}
		else {
			p2_wins++;
		}
	}

	//ラウンドリセット
	if (char_mgr->GetVictory() != eNone || time <= 0) {

		char_mgr->Reset();
		RoundReset();

		round++;
		
		isRoundFinished = false;
	}

	if (isRoundFinished) {
		end_time++;
	}

	if (p1_wins >= GAME_ROUND || p2_wins >= GAME_ROUND) {
		isGameFinished = true;
		bgm_00.stop();
	}

	if (isGameFinished) {
		GameOverUpdate();
	}

	frame++;
}

void Game::Draw()
{
	background.draw();

	if (time < 60 * 10) {
		Line(WW_X / 2, 0, WW_X / 2, WW_Y).draw(5, Color(255, 0, 0, 255 * ((600 - time) / 600.0)));
	}

	if (isGameFinished) {
		//f_title(L"GAME_OVER").drawCenter(640, 360);
		if (p1_wins >= GAME_ROUND) {
			fontL(L"P1 WINS").drawCenter(640, 360);
		}
		if (p2_wins >= GAME_ROUND) {
			fontL(L"P2 WINS").drawCenter(640, 360);
		}
	}
	else {
		if (frame < 60) {
			fontL(L"ROUND", round).drawCenter(640, 360);
		}
		else if (frame < 120) {
			fontL(L"FIGHT").drawCenter(640, 360);
		}

		if (isRoundFinished && time <= 0) {
			fontL(L"Draw").drawCenter(640, 360);
		}
	}

	fontM(time / 60).drawCenter(640, 60);

	double center_interval = 60;
	
	{
		//P1 勝利カウント
		double x = 640;
		double y = 80;
		double r = 10;
		for (int i = 0; i < GAME_ROUND; i++) {
			Circle(x - center_interval * 1.3 - (i * (r + 15)), y, r).draw(Palette::Gray);

			if (i + 1 <= p1_wins) {
				Circle(x - center_interval * 1.3 - (i * (r + 15)), y, r * 0.8).draw(Palette::Red);
			}
			else {
				Circle(x - center_interval * 1.3 - (i * (r + 15)), y, r * 0.8).draw();
			}
		}
	}

	{
		//P2 勝利カウント
		double x = 640;
		double y = 80;
		double r = 10;
		for (int i = 0; i < GAME_ROUND; i++) {
			Circle(x + center_interval * 1.3 + (i * (r + 15)), y, r).draw(Palette::Gray);

			if (i + 1 <= p2_wins) {
				Circle(x + center_interval * 1.3 + (i * (r + 15)), y, r * 0.8).draw(Palette::Red);
			}
			else {
				Circle(x + center_interval * 1.3 + (i * (r + 15)), y, r * 0.8).draw();
			}
		}
	}

	char_mgr->Draw();

	if (isGameFinished) {
		GameOverDraw();
	}
}


void Game::GameOverUpdate()
{
	if (Input::KeyUp.clicked || Gamepad(0).povForward.clicked) {
		select_count = 0;
	}
	if (Input::KeyDown.clicked || Gamepad(0).povBackward.clicked) {
		select_count = 1;
	}

	if (Input::KeyEnter.clicked || Gamepad(0).button(0).clicked) {
		switch (select_count)
		{
		case 0:
			mSceneChanger->ChangeScene(eScene_Game);
			break;
		case 1:
			mSceneChanger->ChangeScene(eScene_Menu);
			break;
		default:
			break;
		}
	}
}

void Game::GameOverDraw()
{
	int width = 200;
	int height = 120;
	int x = WW_X / 2 - width / 2;
	int y = (WW_Y / 2 + 200) - height / 2;
	RoundRect(x, y, width, height, 5).draw(Palette::Black);

	width *= 0.95;
	height *= 0.9;
	x = WW_X / 2 - width / 2;
	y = (WW_Y / 2 + 200) - height / 2;
	RoundRect(x, y, width, height, 5).draw(Palette::Gray);

	x = WW_X / 2;
	y = (WW_Y / 2 + 200);

	fontS(L"RePlay").drawCenter(x, y - 20, ((select_count == 0) ? Palette::Yellow : Palette::White));
	fontS(L"Quit").drawCenter(x, y + 25, ((select_count == 1) ? Palette::Yellow : Palette::White));
}

