#pragma once
#include "..\header\GameScene.h"
#include "..\header\Button.h"

class RoulettePlay : public GameScene
{
    int select;
    Button button;

public:

    RoulettePlay(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
};
