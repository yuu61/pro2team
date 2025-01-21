#include "..\header\MoveTypeSine.h"
#include <cmath>

static const double pi = 3.141592653589793;

MoveTypeSine::MoveTypeSine(float x, float y, int flame) :
	MoveType(x, y, flame){
	unit = pi / flame;
	for (int i = 1; i <= flame; i++) {
		sum += sin(unit * i) * sin(unit * i);
		//sum += sin(unit * i);
	}

}

std::tuple<float, float> MoveTypeSine::Calc() {
	flame--;
	return { (sin(unit * flame) * sin(unit * flame) / sum) * x , (sin(unit * flame) * sin(unit * flame) / sum) * y };
	//return { (sin(unit * flame) / sum) * x , (sin(unit * flame) / sum) * y };
}