#pragma once
#include "Graphics.hpp"
#include "GameVarMgr.hpp"

// アイテムのクラス
class Item :public Graphics
{
protected:
	GameVarMgr* gameVarMgr;
public:
	Item(GameVarMgr* gameVar,int graph);
	virtual void Use() = 0;
};

