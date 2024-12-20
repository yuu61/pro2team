#pragma once
#include "Task.h"
#include "BaseCgr.h"

class BaseScene : public Task
{
protected:
    BaseCgr* baseCgr;

public:
    BaseScene(BaseCgr* changer) ;
    virtual ~BaseScene() {};
	virtual void Initialize() override {}        //�����������͎������Ă����Ȃ��Ă�����
    virtual void Finalize() override {};        //�I�������͎������Ă����Ȃ��Ă�����
    virtual void Update() override {};    //�X�V�����͕K���p����Ŏ�������
    virtual void Draw() override {};    //�`�揈���͕K���p����Ŏ�������
};

