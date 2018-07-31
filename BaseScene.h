#pragma once

#include <Siv3D.hpp>
#include "Task.h"
#include "ISceneChanger.h"
#include "Fighter.h"

//�V�[���̊��N���X
class BaseScene : public Task {
protected:
	ISceneChanger* mSceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X

	static eFighter p1_fighter;
	static eFighter p2_fighter;

public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}    //�������������I�[�o�[���C�h
	virtual void Finalize() override;        //�I���������I�[�o�[���C�h
	virtual void Update() override {}        //�X�V�������I�[�o�[���C�h
	virtual void Draw() override;            //�`�揈�����I�[�o�[���C�h

	void set_p1(eFighter p1) { p1_fighter = p1; }
	void set_p2(eFighter p2) { p2_fighter = p2; }
};