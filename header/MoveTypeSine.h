#pragma once
#include "MoveType.h"
class MoveTypeSine : public MoveType
{
private:
	// 
	double unit;
	double sum{ 0 };
public:
	MoveTypeSine(float x, float y, int flame);

	std::tuple<float, float> Calc() override;
};