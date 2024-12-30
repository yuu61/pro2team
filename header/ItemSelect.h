#pragma once
#include "GameScene.h"
#include "ButtonCharge.h"

class ItemSelect : public GameScene
{
    int select;
    ButtonCharge button;

public:

    ItemSelect(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
};


