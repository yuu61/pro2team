#pragma once
#include "Graphics.h"
#include "GameVarMgr.h"

// アイテムのクラス
class Item :public Graphics
{
protected:
	GameVarMgr* gameVarMgr;
public:
	Item(GameVarMgr* gameVar,int graph);
	virtual void Use() = 0;
};

