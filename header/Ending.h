#pragma once
#include "GameScene.h"
#include <iostream>



class Ending : public GameScene
{
    // �I������Ă�{�^���̃C���f�b�N�X��ۊǂ���B
    int select{ 0 };
    std::string str{ "THANK YOU FOR PLAYING!!\n\n\n\n       END to \"Esc\"" };

public:

    Ending(GameCgr* changer, GameVar* gv);

    void Initialize() override;        //�����������͎������Ă����Ȃ��Ă�����
    void Finalize() override;        //�I�������͎������Ă����Ȃ��Ă�����
    void Update() override;    //�X�V�����͕K���p����Ŏ�������
    void Draw() override;    //�`�揈���͕K���p����Ŏ�������
};


