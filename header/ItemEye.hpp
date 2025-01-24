#pragma once
#include "Item.hpp"

// アイテムの目のクラス
class ItemEye : public Item
{
public:
	ItemEye(GameVarMgr* gameVar);

	void Use() override;
};

