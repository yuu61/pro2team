#pragma once
#include "MoveType.hpp"

typedef struct _Unit {
	float x;
	float y;
}Unit;

class MoveTypeGrad : public MoveType
{
private:
	int varIndecatingUpOrDown;
	int i{ 0 };
	double unit;
	double sum{ 0 };
public:
	MoveTypeGrad(float x, float y, int flame , int upOrDown);

	std::tuple<float, float> Calc() override;
};