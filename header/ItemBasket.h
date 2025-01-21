#pragma once
#include "Item.h"


class ItemBasket : public Item
{
public:
	ItemBasket(GameVarMgr* gameVar);

	void Use() override;
};

