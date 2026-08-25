#pragma once
#include "Item.hpp"


class ItemClock : public Item
{
public:
	ItemClock(GameVarMgr* gameVar);
	ItemClock(const ItemClock&) = delete;
	ItemClock& operator=(const ItemClock&) = delete;
	ItemClock& operator=(ItemClock&&) = delete;

	void Use() override;
};

