#pragma once
#include "Item.h"

// アイテムの目のクラス
class ItemEye : public Item
{
public:
	ItemEye();

	void Use() override;
};

