#pragma once
#include "Graphics.h"
#include "Player.h"
#include "DxLib.h"

// ゲームのシーンで使えるグローバル変数代わりのクラス。グローバル変数ヘッダーに変えたい。
class GameVar
{
private:
	// 背景画像
	Graphics* backGround{ new Graphics(0,0,1920,1080,LoadGraph("image\\backGround.png")) };

public:
	GameVar();
	~GameVar() {};
	Graphics* GetBackGround() { return backGround; }
	// プレイヤーを保存する。
	Player* playerStore[2]{ new Player(KEY_INPUT_S,KEY_INPUT_W,KEY_INPUT_A,KEY_INPUT_D),new Player(KEY_INPUT_K ,KEY_INPUT_I,KEY_INPUT_J,KEY_INPUT_L) };
	// 現在のメインプレイヤー
	Player* player{ playerStore[0] };

	
};

