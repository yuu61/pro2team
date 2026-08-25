#pragma once
#include "Container.hpp"
#include "Cake.hpp"

class Roulette : public Container<Cake*>
{
private:

public:
	Roulette();
	Roulette(const Roulette&) = delete;
	Roulette(Roulette&&) = delete;
	Roulette& operator=(const Roulette&) = delete;
	Roulette& operator=(Roulette&&) = delete;



};

