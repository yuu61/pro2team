#pragma once
#include "BaseScene.h"
#include "GameCgr.h"
#include "GameScene.h"


class GameMgr : public BaseScene , GameCgr 
{
protected :
	GameScene* gSStore[10]; // �K���ɐ������Ă�
	GameScene* gameScene;
	eGame nextScene;
	GameVar* gameVar;

public :
	GameMgr(BaseCgr* changer);
	~GameMgr() {};
	
	void SceneChange(eGame changer) override;

	void Initialize()override;        //�����������͎������Ă����Ȃ��Ă�����
	void Finalize() override;        //�I�������͎������Ă����Ȃ��Ă�����
	void Update() override;    //�X�V�����͕K���p����Ŏ�������
	void Draw() override;    //�`�揈���͕K���p����Ŏ�������
};


