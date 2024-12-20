#pragma once
#include "GameScene.h"
#include "Button.h"

typedef enum _eButton {
    ITEM,
    ROULETTE,
    MAX
}eButton;

class PlayerSelect : public GameScene
{
    int select;
    Button button[MAX];
    // Button button();
public:

	PlayerSelect(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //�����������͎������Ă����Ȃ��Ă�����
    void Finalize() override ;        //�I�������͎������Ă����Ȃ��Ă�����
    void Update() override ;    //�X�V�����͕K���p����Ŏ�������
    void Draw() override ;    //�`�揈���͕K���p����Ŏ�������
};
