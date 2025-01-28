#include "..\header\MoveTypeNormal.hpp"

MoveTypeNormal:: MoveTypeNormal(float x, float y, int flame) :
	MoveType(x/flame,y/flame,flame){
}

std::tuple<float, float> MoveTypeNormal::Calc() {
	flame--;
	return { x, y };
}