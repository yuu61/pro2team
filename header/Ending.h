#pragma once
#include "GameScene.h"
#include <iostream>



class Ending : public GameScene
{
    // 選択されてるボタンのインデックスを保管する。
    int select{ 0 };
    std::string str{ "THANK YOU FOR PLAYING!!\n\n\n\n       END to \"Esc\"" };

public:

    Ending(GameCgr* changer, GameVar* gv);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
};


