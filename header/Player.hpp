#pragma once
#include "Graphics.hpp"
#include "CatchInput.hpp"
#include "Item.hpp"

static const int ITEM_NUM{ 4 };

typedef enum _eKey {
	KEY_ENTER,
	KEY_CANSEL,
	KEY_LEFT,
	KEY_RIGHT,
	E_KEY
}eKey;

class Player : public Graphics
{
private:

	Item* item[ITEM_NUM];
	int points;
	int crown;
	int key[E_KEY];
	

public:

	Player();
	Player(int enter, int cansel, int left, int right, float x, float y, float cx, float cy, int graph);

	int GetInputKey(eKey checkKey){ return inputKey[key[checkKey]]; }
	int GetKey(eKey checkKey) {return key[checkKey];}

	void Initialize() override {};
	void Finalize() override {};
	Item* GetItem(int index) { return item[index]; }
	void SetItem(Item* newItem);
	int GetPoints() { return points; }
	void addPoints(int p) { points += p; }
	// void Draw();
	
};

