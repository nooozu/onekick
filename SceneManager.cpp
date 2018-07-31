#include "SceneManager.h"
#include "Title.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "CharSelect.h"

//次のシーン管理変数
SceneManager::SceneManager() : mNextScene(eScene_None)
{
	mScene = (BaseScene*) new Title(this);
}

//初期化
void SceneManager::Initialize()
{
	mScene->Initialize();
}

//終了処理
void SceneManager::Finalize()
{
	mScene->Finalize();
}

//更新
void SceneManager::Update() {
	//次のシーンがセットされていたら
	if (mNextScene != eScene_None) {

		//現在のシーンの終了処理を実行
		mScene->Finalize();
		delete mScene;

		//シーンによって処理を分岐
		switch (mNextScene) {
		case eScene_Title:
			mScene = (BaseScene*) new Title(this);
			break;
		case eScene_Menu:
			mScene = (BaseScene*) new Menu(this);
			break;
		case eScene_CharSelect:
			mScene = (BaseScene*) new CharSelect(this);
			break;
		case eScene_Game:
			mScene = (BaseScene*) new Game(this);
			break;
		case eScene_Config:
			mScene = (BaseScene*) new Config(this);
			break;
		}

		//次のシーン情報をクリア
		mNextScene = eScene_None;

		//シーンを初期化
		mScene->Initialize();
	}

	//シーンの更新
	mScene->Update();
}

void SceneManager::Draw()
{
	mScene->Draw();
}

// 引数 nextScene にシーンを変更する
void SceneManager::ChangeScene(eScene NextScene)
{
	mNextScene = NextScene;    //次のシーンをセットする
}