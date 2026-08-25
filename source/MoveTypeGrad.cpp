#include "MoveTypeGrad.hpp"

MoveTypeGrad::MoveTypeGrad(float x, float y, int flame , int uod) :
	MoveType(x, y, flame),
	varIndecatingUpOrDown(uod) {
	for (int frameIndex = 1; frameIndex <= flame; ++frameIndex) {
		sum += static_cast<double>(frameIndex);
	}
	unit = 1.0 / sum;

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
	return {
		static_cast<float>(static_cast<double>(i) * unit * static_cast<double>(x)),
		static_cast<float>(static_cast<double>(i) * unit * static_cast<double>(y))
	};
}
