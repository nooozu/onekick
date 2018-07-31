#pragma once
#include "Character.h"

typedef enum {
	eMonkey,
	ePharaoh,
	eGreece,
	eLyu,
	eOtaku,
} eFighter;

class Fighter : public Character
{
protected:
	bool isAlive;

	int frame;

	//0 : wait
	//1 : jump
	//2 : jump_kick
	//3 : back_jump
	//4 : back_jump_kick
	//5 : down
	Texture image[6];

	std::vector<Basebox> atkboxs;
	std::vector<Basebox> hitboxs;

	void DrawTexture(Texture t);

	virtual void SetHitboxs() {};
	virtual void SetAtkboxs() {};
public:
	Fighter();
	Fighter(int x, int y, int w, int h);
	~Fighter();

	void Reset();
	void Update() override;
	void Draw() override;
	void DrawInfo(int x, int y);

	void SetPos(int x, int y) { this->pos.x = x, this->pos.y = y; }

	void SetIsAlive(bool flag) { isAlive = flag; }
	bool GetIsAlive() { return isAlive; }

	std::vector<Basebox> get_atkboxs() { return atkboxs; }
	std::vector<Basebox> get_hitboxs() { return hitboxs; }
};
