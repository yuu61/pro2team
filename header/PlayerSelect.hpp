#pragma once
#include "GameScene.hpp"
#include "ButtonCharge.hpp"

typedef enum _eButton {
    GO_ROULETTE_PLAY,
    GO_ITEM_SELECT,
    GO_TITLE,
    E_BUTTON
}eButton;



class PlayerSelect : public GameScene
{
    int BUTTON_NUM{ 3 };
    int select;
    Button* button[E_BUTTON]{   new Button(1, 0, 800.f, 600.f, 0.2, 0.2, LoadGraph("image\\buttonRoulette.png")) ,
                                new Button(1, 0, 1300.f, 600.f, 0.2, 0.2, LoadGraph("image\\buttonItem.png")),
                                new Button(1, 0, 1600.f, 200.f, 0.15, 0.15, LoadGraph("image\\buttonTitle.png")) };
    
public:

	PlayerSelect(GameCgr* changer,GameVar* gv);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override ;        //終了処理は実装してもしなくてもいい
    void Update() override ;    //更新処理は必ず継承先で実装する
    void Draw() override ;    //描画処理は必ず継承先で実装する
};
