#pragma once
#include "Task.h"
#include "GameCgr.h"
#include "GameVar.h"

class GameScene : public Task
{
protected:
    GameCgr* gameCgr;
    GameVar* gameVar;

public:
    GameScene(GameCgr* changer,GameVar* gVar);
    virtual ~GameScene() {};
    virtual void Initialize() override {}        //�����������͎������Ă����Ȃ��Ă�����
    virtual void Finalize() override {};        //�I�������͎������Ă����Ȃ��Ă�����
    virtual void Update() override {};    //�X�V�����͕K���p����Ŏ�������
    virtual void Draw() override {};    //�`�揈���͕K���p����Ŏ�������
};

