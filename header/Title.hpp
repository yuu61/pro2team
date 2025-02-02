#pragma once
#include "Button.hpp"
#include "BaseMgr.hpp"



class Title : BaseScene{
private:

   int BUTTON_NUM{ 2 };

	int select{ 0 };
    Button* button[2]{ new Button(1,0,960 - 100 - 650,700,1,1,LoadGraph(_T("image\\buttonStart.png"))),
                       new Button(1,0,960 + 100,700,1,1,LoadGraph(_T("image\\buttonEnd.png"))) };
    Graphics* backGround{ new Graphics(0,0,1,1,LoadGraph(_T("image\\backGround.jpg"))) };
    Graphics* titleZimaku{ new Graphics(0,0,1,1,LoadGraph(_T("image\\titlezimaku.png"))) };

public:
    Title(BaseCgr* changer);

    void Initialize() override ;        //初期化処理は実装してもしなくてもいい
    void Finalize() override {};        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
};