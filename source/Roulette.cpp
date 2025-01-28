#include "../header/Roulette.hpp"

Roulette::Roulette() :
	Container(){
	for (int i = 0; i < CAKE_NUM; i++) {
		vec.push_back(new Cake());
		vec.at(i)->SetDegree(i * 45);
	}
}

