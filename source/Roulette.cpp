#include "Roulette.hpp"

Roulette::Roulette() :
	Container(){
	for (std::size_t i = 0; i < static_cast<std::size_t>(CAKE_NUM); ++i) {
		vec.push_back(new Cake());
		vec.at(i)->SetDegree(static_cast<double>(i) * 45.0);
	}
}

