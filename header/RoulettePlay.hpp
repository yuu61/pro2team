#pragma once
#include "GameScene.hpp"
#include "ButtonCharge.hpp"

class RoulettePlay : public GameScene
{
    Cake* cakeTemp{ nullptr };
    int status{ 0 };
    Graphics* arrow{ new Graphics(1920 / 2 - 50,1080 - 110,0.2f,0.2f , LoadGraph("image\\arrow.png")) };
    
public:

    RoulettePlay(GameCgr* changer, GameVar* gv);
    
    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
};
