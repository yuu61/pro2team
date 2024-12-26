#pragma once
#include "MoveType.h"

class MoveTypeNormal : MoveType
{
private:
	
public:
	MoveTypeNormal(float x, float y, int flame);

	std::tuple<int, int> Calc() override;
};

