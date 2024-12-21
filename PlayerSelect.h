#pragma once
#include "GameScene.h"
#include "Button.h"

typedef enum _eButton {
    GO_ITEM_SELECT,
    GO_ROULETTE_PLAY,
    E_BUTTON
}eButton;

class PlayerSelect : public GameScene
{

    int select;
    Button* button[E_BUTTON];
    // Button button();
public:

	PlayerSelect(GameCgr* changer, GameVar* gVar);

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override ;        //終了処理は実装してもしなくてもいい
    void Update() override ;    //更新処理は必ず継承先で実装する
    void Draw() override ;    //描画処理は必ず継承先で実装する
};
