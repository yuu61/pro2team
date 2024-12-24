#pragma once
#include "GameScene.h"
#include "ButtonCharge.h"

typedef enum _eButton {
    GO_ITEM_SELECT,
    GO_ROULETTE_PLAY,
    E_BUTTON
}eButton;

class PlayerSelect : public GameScene
{

    int select;
    Button* button[E_BUTTON]{new Button(100, 0, 710, 540, 910, 640, LoadGraph("image\\backGround.png")) , new Button(1, 0, 710, 690, 910, 790, LoadGraph("image\\backGround.png")) };
    // ButtonCharge button();
public:

	PlayerSelect(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override ;        //終了処理は実装してもしなくてもいい
    void Update() override ;    //更新処理は必ず継承先で実装する
    void Draw() override ;    //描画処理は必ず継承先で実装する
};
