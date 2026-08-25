#pragma once
#include "GameVarMgr.hpp"
#include "Graphics.hpp"

// アイテムのクラス
class Item :public Graphics
{
protected:
	GameVarMgr* gameVarMgr;
public:
	Item(GameVarMgr* gameVar,int graph);
	Item(const Item&) = delete;
	Item& operator=(const Item&) = delete;
	Item& operator=(Item&&) = delete;
	virtual void Use() = 0;
};

