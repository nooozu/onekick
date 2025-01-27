#pragma once

typedef enum {
	eScene_Title,    //タイトル画面
	eScene_Menu,    //メニュー画面
	eScene_CharSelect,
	eScene_Game,    //ゲーム画面
	eScene_Config,  //設定画面

	eScene_None,    //無し
} eScene;

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;

	//指定シーンに変更する
	virtual void ChangeScene(eScene NextScene) = 0;
};
