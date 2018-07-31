#include "BaseScene.h"

eFighter BaseScene::p1_fighter = eMonkey;
eFighter BaseScene::p2_fighter = eMonkey;

BaseScene::BaseScene(ISceneChanger* changer)
{
	mSceneChanger = changer;
}

void BaseScene::Finalize()
{	
}

void BaseScene::Draw()
{
}