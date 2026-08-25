#include "MoveTypeSine.hpp"
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
	const double scale{ std::sin(unit * static_cast<double>(flame)) *
		std::sin(unit * static_cast<double>(flame)) / sum };
	return {
		static_cast<float>(scale * static_cast<double>(x)),
		static_cast<float>(scale * static_cast<double>(y))
	};
	//return { (sin(unit * flame) / sum) * x , (sin(unit * flame) / sum) * y };
}
