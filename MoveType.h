#pragma once
#include <tuple>

class MoveType
{
protected:
	float x;
	float y;
	int flame;
public:
	MoveType(float x, float y, int flame);
	virtual std::tuple<int ,int> Calc() = 0;
};

