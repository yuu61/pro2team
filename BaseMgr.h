#pragma once
#include "Task.h"
#include "BaseCgr.h"
#include "BaseScene.h"


class BaseMgr :public BaseCgr ,Task
{
    BaseScene* baseScene;
    eScene nextScene;
    
public:

    BaseMgr();

    void SceneChange(eScene changer) override;

    void Initialize() override;        //�����������͎������Ă����Ȃ��Ă�����
    void Finalize() override;        //�I�������͎������Ă����Ȃ��Ă�����
    void Update() override;    //�X�V�����͕K���p����Ŏ�������
    void Draw() override;    //�`�揈���͕K���p����Ŏ�������
    
    ~BaseMgr() {};
};

