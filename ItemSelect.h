#pragma once
#include "GameScene.h"
#include "Button.h"

class ItemSelect : public GameScene
{
    int select;
    Button button;

public:

    ItemSelect(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //�����������͎������Ă����Ȃ��Ă�����
    void Finalize() override;        //�I�������͎������Ă����Ȃ��Ă�����
    void Update() override;    //�X�V�����͕K���p����Ŏ�������
    void Draw() override;    //�`�揈���͕K���p����Ŏ�������
};


