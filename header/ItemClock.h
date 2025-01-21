#pragma once
#include "Item.h"


class ItemClock : public Item
{
public:
	ItemClock(GameVarMgr* gameVar);

	void Use() override;
};

