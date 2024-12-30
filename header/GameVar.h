#pragma once
#include "Graphics.h"
#include "Player.h"
#include "DxLib.h"

class GameVar
{
private:
	Graphics backGround;

public:
	GameVar();
	~GameVar() {};
	Graphics* GetBackGround() { return &backGround; }
	Player* playerStore[2]{new Player(KEY_INPUT_S,KEY_INPUT_W,KEY_INPUT_A,KEY_INPUT_D)};
	Player* player{ playerStore[0] };

	//get();
	//set();
};

