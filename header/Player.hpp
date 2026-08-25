#pragma once
#include "Graphics.hpp"
#include "CatchInput.hpp"
#include "Item.hpp"

#include <array>
#include <memory>

static const int ITEM_NUM{ 4 };

typedef enum _eKey {
	KEY_ENTER,
	KEY_CANCEL,
	KEY_LEFT,
	KEY_RIGHT,
	E_KEY
}eKey;

class Player : public Graphics
{
private:

	std::array<std::unique_ptr<Item>, ITEM_NUM> item{};
	int points{ 0 };
	int crown{ 0 };
	int key[E_KEY]{};
	

public:

	Player();
	Player(int enter, int cansel, int left, int right, float x, float y, float cx, float cy, int graph);

	int GetInputKey(eKey checkKey){ return inputKey[key[checkKey]]; }
	int GetKey(eKey checkKey) const {return key[checkKey];}

	void Initialize() override {};
	void Finalize() override {};
	Item* GetItem(int index) { return item[index].get(); }
	void SetItem(std::unique_ptr<Item> newItem);
	int GetPoints() const { return points; }
	void addPoints(int p) { points += p; }
	// void Draw();
	
};

