#include "MoveTypeNormal.h"

MoveTypeNormal:: MoveTypeNormal(float x, float y, int flame) :
	MoveType(x,y,flame){

}

std::tuple<float, float> MoveTypeNormal::Calc() {
	return { 1, 2 };
}