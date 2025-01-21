#include "..\header\MoveTypeGrad.h"
#include <cmath>

static const double pi = 3.141592653589793;

MoveTypeGrad::MoveTypeGrad(float x, float y, int flame , int uod) :
	varIndecatingUpOrDown(uod),
	MoveType(x, y, flame) {
	for (int i = 1; i <= flame; i++) {
		sum += i;
	}
	unit = 1 / sum;

	if (uod == 1) {
		i = 0;
	}
	else {
		i = flame + 1;
	}
}

std::tuple<float, float> MoveTypeGrad::Calc() {
	flame--;
	i += varIndecatingUpOrDown;
	return { i * unit * x, i * unit * y };
}