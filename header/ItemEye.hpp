#pragma once
#include "Item.hpp"

// アイテムの目のクラス
class ItemEye : public Item
{
public:
	ItemEye(GameVarMgr* gameVar);
	ItemEye(const ItemEye&) = delete;
	ItemEye& operator=(const ItemEye&) = delete;
	ItemEye& operator=(ItemEye&&) = delete;

	void Use() override;
};

