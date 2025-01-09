#pragma once
#include "GameScene.h"
#include "ButtonCharge.h"

// アイテムを選択するシーンのクラス。
class ItemSelect : public GameScene
{
    // 選択されてるボタンのインデックスを保管する。
    int select{ 0 };
    Button* button[5]{  new Button(100, 0, 710.f, 540.f, 910.f, 640.f, LoadGraph("image\\backGround.png")),
                        nullptr };

public:

    ItemSelect(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
};


