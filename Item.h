#pragma once
#include "Graphics.h"

// �A�C�e���̃N���X
class Item :public Graphics
{
public:
	Item(const char graph[]);
	virtual void Use() = 0;
};

