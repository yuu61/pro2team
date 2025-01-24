#pragma once
#include "Item.hpp"


class ItemBasket : public Item
{
public:
	ItemBasket(GameVarMgr* gameVar);

	void Use() override;
};

