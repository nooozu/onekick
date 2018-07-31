#pragma once

typedef enum {
	eScene_Title,    //�^�C�g�����
	eScene_Menu,    //���j���[���
	eScene_CharSelect,
	eScene_Game,    //�Q�[�����
	eScene_Config,  //�ݒ���

	eScene_None,    //����
} eScene;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;

	//�w��V�[���ɕύX����
	virtual void ChangeScene(eScene NextScene) = 0;
};
