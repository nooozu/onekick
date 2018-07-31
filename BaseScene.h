#pragma once

#include <Siv3D.hpp>
#include "Task.h"
#include "ISceneChanger.h"
#include "Fighter.h"

//シーンの基底クラス
class BaseScene : public Task {
protected:
	ISceneChanger* mSceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス

	static eFighter p1_fighter;
	static eFighter p2_fighter;

public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}    //初期化処理をオーバーライド
	virtual void Finalize() override;        //終了処理をオーバーライド
	virtual void Update() override {}        //更新処理をオーバーライド
	virtual void Draw() override;            //描画処理をオーバーライド

	void set_p1(eFighter p1) { p1_fighter = p1; }
	void set_p2(eFighter p2) { p2_fighter = p2; }
};