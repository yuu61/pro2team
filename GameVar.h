#pragma once
#include "Graphics.h"

class GameVar
{
private:
	Graphics backGround;

public:
	GameVar();
	~GameVar() {};
	Graphics* GetBackGround() { return &backGround; }
	//get();
	//set();
};
