#include "MoveTypeNormal.hpp"

MoveTypeNormal:: MoveTypeNormal(float x, float y, int flame) :
	MoveType(x / static_cast<float>(flame), y / static_cast<float>(flame), flame){
}

std::tuple<float, float> MoveTypeNormal::Calc() {
	flame--;
	return { x, y };
}
