#pragma once
#include "Item.hpp"


class ItemClock : public Item
{
public:
	ItemClock(GameVarMgr* gameVar);

	void Use() override;
};

