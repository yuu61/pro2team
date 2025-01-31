#pragma once
#include "Graphics.hpp"
#include "Player.hpp"
#include "Roulette.hpp"
#include "Button.hpp"
#include "..\dxlib_for_visual_studio\DxLib.h"
#include <string>
#include "GameVarMgr.hpp"

#include "ItemEye.hpp"
#include "ItemBasket.hpp"
#include "ItemClock.hpp"

// ゲームのシーンで使えるグローバル変数代わりのクラス。グローバル変数ヘッダーに変えたい。
/*
Player* player;
Player* opponent;
Graphics* backGround;
*/

class GameVar : GameVarMgr{
public:
	GameVar() {
		SetKey();
		SetStringTurnNow();
		SetStrawberryPoints();
		for (int i = 0; i < 2; i++) {
			strawberry[i]->SetStringHandle(CreateFontToHandle(NULL, 200, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8));
			playerStore[i]->SetItem((Item*)new ItemBasket((GameVarMgr*)this));
			playerStore[i]->SetItem((Item*)new ItemBasket((GameVarMgr*)this));
			playerStore[i]->SetItem((Item*)new ItemEye((GameVarMgr*)this));
			playerStore[i]->SetItem((Item*)new ItemClock((GameVarMgr*)this));
			
			roulette->SetRotate(MOVE_NORMAL, 360 * 5, 1);
		}
	};

	~GameVar() {};

	int turn{ 1 };
	const int endTurn{ 8 };

	Player* player{ new Player(KEY_INPUT_S, KEY_INPUT_W, KEY_INPUT_A, KEY_INPUT_D, 0.f, 300.f, 1.f, 1.f, LoadGraph("image\\dansei_01_a.png")) };
	Player* opponent{ new Player(KEY_INPUT_K, KEY_INPUT_I, KEY_INPUT_J, KEY_INPUT_L, 400.f, 300.f, 1.f, 1.f, LoadGraph("image\\josei_01_a.png")) };
	Player* playerStore[2]{ player, opponent };
	Graphics* backGround{ new Graphics(0, 0, 1, 1, LoadGraph("image\\backGround.jpg")) };
	Roulette* roulette{ new Roulette() };

	Graphics* strawberry[2]{ new Graphics(100,0,0.3f,0.3f,LoadGraph("image\\strawberry.png")),new Graphics(500,0,0.3f,0.3f,LoadGraph("image\\strawberry.png")) };
	Graphics* playerStrawberry{ strawberry[0] };
	Graphics* opponentStrawberry{ strawberry[1] };
	int fontHandle{ CreateFontToHandle(NULL , 50 , 9 ,DX_FONTTYPE_ANTIALIASING_EDGE_8X8) };

	char keyCharPlayer[E_KEY]{ ',',',',',',',' };
	char keyCharOpponent[E_KEY]{ ',',',',',',',' };

	void SetKey() {
		if (player->GetKey(KEY_ENTER) == KEY_INPUT_S) {
			keyCharPlayer[KEY_ENTER] = 'S';
			keyCharPlayer[KEY_CANCEL] = 'W';
			keyCharPlayer[KEY_RIGHT] = 'D';
			keyCharPlayer[KEY_LEFT] = 'A';

			keyCharOpponent[KEY_ENTER] = 'K';
			keyCharOpponent[KEY_CANCEL] = 'I';
			keyCharOpponent[KEY_RIGHT] = 'L';
			keyCharOpponent[KEY_LEFT] = 'J';
		}
		else if(player->GetKey(KEY_ENTER) == KEY_INPUT_K){
			keyCharPlayer[KEY_ENTER] = 'K';
			keyCharPlayer[KEY_CANCEL] = 'I';
			keyCharPlayer[KEY_RIGHT] = 'L';
			keyCharPlayer[KEY_LEFT] = 'J';

			keyCharOpponent[KEY_ENTER] = 'S';
			keyCharOpponent[KEY_CANCEL] = 'W';
			keyCharOpponent[KEY_RIGHT] = 'D';
			keyCharOpponent[KEY_LEFT] = 'A';
		}
	}

	void SetStringTurnNow() {
		player->SetString("YOUR TURN");
		opponent->SetString("");
	}

	void SetStrawberryPoints() {
		for (int i = 0; i < 2; i++) {
			strawberry[i]->SetString(std::to_string(playerStore[i]->GetPoints()));
		}
	}

	void SwapPlayer() {
		Player* temp{ player };
		player = opponent;
		opponent = temp;
		
		Graphics* tempg{ playerStrawberry };
		playerStrawberry = opponentStrawberry;
		opponentStrawberry = tempg;

	}
	
	void UseBasket() {
		int num{ 7 - (int)(roulette->at(0)->GetDegree() + 90) / 45 % 8 };
		roulette->at(num)->AddStrawberry(5);
	}

};


/*
Player* player{ new Player(KEY_INPUT_S, KEY_INPUT_W, KEY_INPUT_A, KEY_INPUT_D) };
Player* opponent{ new Player(KEY_INPUT_K, KEY_INPUT_I, KEY_INPUT_J, KEY_INPUT_L) };
Graphics* backGround{ new Graphics(0, 0, 1.1, 1.05, LoadGraph("..\\image\\backGround.png")) };
*/
/*
class GameVar
{
private:
	// 背景画像
	Graphics* backGround{ new Graphics(0,0,1.1,1.05,LoadGraph("image\\backGround.png")) };

public:
	GameVar();
	~GameVar() {};
	Graphics* GetBackGround() { return backGround; }
	// プレイヤーを保存する。
	Player* playerStore[2]{ new Player(KEY_INPUT_S,KEY_INPUT_W,KEY_INPUT_A,KEY_INPUT_D),new Player(KEY_INPUT_K ,KEY_INPUT_I,KEY_INPUT_J,KEY_INPUT_L) };
	// 現在のメインプレイヤー
	Player* player{ playerStore[0] };

	
};

*/