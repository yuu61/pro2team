#pragma once
#include "Item.h"

// アイテムの目のクラス
class ItemEye : public Item
{
public:
	ItemEye(GameVarMgr* gameVar);

	void Use() override;
};

