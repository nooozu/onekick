#include "SceneManager.h"
#include "Title.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "CharSelect.h"

//���̃V�[���Ǘ��ϐ�
SceneManager::SceneManager() : mNextScene(eScene_None)
{
	mScene = (BaseScene*) new Title(this);
}

//������
void SceneManager::Initialize()
{
	mScene->Initialize();
}

//�I������
void SceneManager::Finalize()
{
	mScene->Finalize();
}

//�X�V
void SceneManager::Update() {
	//���̃V�[�����Z�b�g����Ă�����
	if (mNextScene != eScene_None) {

		//���݂̃V�[���̏I�����������s
		mScene->Finalize();
		delete mScene;

		//�V�[���ɂ���ď����𕪊�
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

		//���̃V�[�������N���A
		mNextScene = eScene_None;

		//�V�[����������
		mScene->Initialize();
	}

	//�V�[���̍X�V
	mScene->Update();
}

void SceneManager::Draw()
{
	mScene->Draw();
}

// ���� nextScene �ɃV�[����ύX����
void SceneManager::ChangeScene(eScene NextScene)
{
	mNextScene = NextScene;    //���̃V�[�����Z�b�g����
}