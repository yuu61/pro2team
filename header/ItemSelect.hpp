#pragma once
#include "GameScene.hpp"
#include "ButtonCharge.hpp"

// アイテムを選択するシーンのクラス。
class ItemSelect : public GameScene
{
    // 選択されてるボタンのインデックスを保管する。
    int select{ 0 };
    
    Button* button[5]{ new Button(1, 0, 17, 600, 0.2f, 0.2f, LoadGraph(_T("image\\buttonReturn.png"))),
                        nullptr };
    Graphics* arrow{ new Graphics(1920 - 900 + 212,500,0.15f,0.15f , LoadGraph(_T("image\\arrow.png"))) };

public:

    ItemSelect(GameCgr* changer, GameVar* gv);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
};