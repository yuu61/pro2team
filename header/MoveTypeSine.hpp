#pragma once
#include "MoveType.hpp"
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