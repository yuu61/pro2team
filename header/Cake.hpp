#pragma once
#include "Graphics.hpp"
#include "Item.hpp"

#define CAKE_NUM 8

class Cake : public Graphics 
{
private:
	int strawberry{ 0 };
	Item* item{ nullptr };

public:
	Cake();
	Cake(int strawberry);
	Cake(Item* item);
	Cake(int strawberry, Item* item);

	void AddStrawberry(int i);

	void SetCakeGraph();
	int GetStrawberry() { return strawberry; }
};