#include "CharManager.h"

Fighter* SelectFighter(eFighter f)
{
	switch (f) {
	case eLyu:
		return new FighterLyu();
		break;
	case ePharaoh:
		return new FighterPharaoh();
		break;
	case eMonkey:
		return new FighterMonkey();
		break;
	case eGreece:
		return new FighterGreece();
		break;
	case eOtaku:
		return new FighterOtaku();
		break;
	default:
		return nullptr;
	}
}

CharManager::CharManager(eFighter p1_fighter, eFighter p2_fighter)
{
	p1 = SelectFighter(p1_fighter);
	p2 = SelectFighter(p2_fighter);

	p1->controller.set_index(0);
	p2->controller.set_index(1);

	//キャラの初期位置を変更など
	Reset();

	message = Font(120, L"SSF4 ABUKET", FontStyle::Outline);
	message.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 3.0));

	isControl = false;

	se_kick = Sound(L"Sound/kick-middle1.mp3");
}

CharManager::~CharManager()
{
	delete p1;
	delete p2;
}

void CharManager::Reset()
{
	p1_hp = 100;
	p2_hp = 100;

	p1->Reset();
	p2->Reset();

	p1->set_status(JUMP);
	p2->set_status(JUMP);

	p1->set_direction(RIGHT);
	p2->set_direction(LEFT);

	p1->SetPos((WW_X / 4) * 1, WW_Y * 2 / 3);
	p2->SetPos((WW_X / 4) * 3, WW_Y * 2 / 3);

	victory = eNone;
	output_vic = eNone;

	frame = 0;
}

void CharManager::Update()
{
	if (isControl) {
		if (p1->GetIsAlive()) {
			p1->controller.Update();
		}
		if (p2->GetIsAlive()) {
			p2->controller.Update();
		}
	}
	else {
		p1->controller.Reset();
		p2->controller.Reset();
	}

	if (victory != eNone) {
		if (frame >= 40) {
			p1->Update();
			p2->Update();
		}

		frame++;

		if (frame >= 90) {
			output_vic = victory;
		}
	}
	else {
		p1->Update();
		p2->Update();
	}

	CheckDirection(*p1, *p2);
	CheckDirection(*p2, *p1);

	if (victory == eNone) {
		if (CheckHitbox(*p1, *p2)) {
			victory = eP1;

			p2->SetIsAlive(false);
			p2->set_i_jump(30);

			se_kick.play();
		}
		if (CheckHitbox(*p2, *p1)) {
			victory = eP2;

			p1->SetIsAlive(false);
			p1->set_i_jump(30);

			se_kick.play();
		}
		if (CheckHitbox(*p1, *p2) && CheckHitbox(*p2, *p1)) {
			victory = eDraw;
			p1->SetIsAlive(false);
			p2->SetIsAlive(false);
		}
	}

	if (!p1->GetIsAlive()) {
		p1_hp -= 3;
		if (p1_hp <= 0) {
			p1_hp = 0;
			p1->set_status(BACK_JUMP);
		}
	}
	if (!p2->GetIsAlive()) {
		p2_hp -= 3;
		if (p2_hp <= 0) {
			p2_hp = 0;
			p2->set_status(BACK_JUMP);
		}
	}
}

void CharManager::Draw()
{
	double center_interval = 60;
	double hp_bar = 550;

	//P1　HPバー
	Rect(640 - center_interval - hp_bar, 30, hp_bar, 30).draw(Palette::Gray);
	Rect(640 - center_interval, 30, -hp_bar * (p1_hp / 100.0), 30).draw(Color(0, 210, 0));

	//P2　HPバー
	Rect(640 + center_interval, 30, hp_bar, 30).draw(Palette::Gray);
	Rect(640 + center_interval, 30, hp_bar * (p2_hp / 100.0), 30).draw(Color(0, 210, 0));

	p1->Draw();
	//p1->DrawInfo(10, 10);

	p2->Draw();
	//p2->DrawInfo(1100, 10);

	//Line(0, GROUND_Y, 1280, GROUND_Y).draw();

	if (frame > 0) {
		message(L"K.O.").drawCenter(640, 360);
	}
}

void CheckDirection(Fighter &target, Fighter other)
{
	if (target.get_status() == WAIT) {
		if (target.get_pos().x > other.get_pos().x) {
			target.set_direction(LEFT);
		}
		else {
			target.set_direction(RIGHT);
		}
	}
}

bool CheckHitbox(Fighter &target, Fighter other)
{
	for (int i = 0; i < target.get_atkboxs().size(); i++) {
		for (int j = 0; j < other.get_hitboxs().size(); j++) {
			if (target.get_atkboxs()[i].HitCheck(other.get_hitboxs()[j])) {
				return true;
			}
		}
	}
	return false;
}