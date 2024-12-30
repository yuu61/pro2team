#pragma once
#include "MoveType.h"

class MoveTypeNormal : public MoveType
{
private:
	
public:
	MoveTypeNormal(float x, float y, int flame);

	std::tuple<float, float> Calc() override;
};

