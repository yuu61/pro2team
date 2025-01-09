#pragma once
#include "Graphics.h"

// アイテムのクラス
class Item :public Graphics
{
public:
	Item(const char graph[]);
	virtual void Use() = 0;
};

