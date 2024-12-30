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
    Button* button[E_BUTTON]{   new Button(100, 0, 710.f, 540.f, 910.f, 640.f, LoadGraph("image\\backGround.png")) ,
                                new Button(1, 0, 710.f, 690.f, 910.f, 790.f, LoadGraph("image\\backGround.png")) };
    
public:

	PlayerSelect(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override ;        //終了処理は実装してもしなくてもいい
    void Update() override ;    //更新処理は必ず継承先で実装する
    void Draw() override ;    //描画処理は必ず継承先で実装する
};
