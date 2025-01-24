#pragma once
#include "MoveType.hpp"

class MoveTypeNormal : public MoveType
{
private:
	
public:
	MoveTypeNormal(float x, float y, int flame);

	std::tuple<float, float> Calc() override;
};

