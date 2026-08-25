#pragma once
#include "Item.hpp"


class ItemBasket : public Item
{
public:
	ItemBasket(GameVarMgr* gameVar);
	ItemBasket(const ItemBasket&) = delete;
	ItemBasket& operator=(const ItemBasket&) = delete;
	ItemBasket& operator=(ItemBasket&&) = delete;

	void Use() override;
};

