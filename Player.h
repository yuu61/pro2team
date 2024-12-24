#pragma once
#include "Graphics.h"
#include "Item.h"

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

	Item* item[8];
	int point;
	int crown;
	int key[E_KEY];

public:

	Player();
	Player(int enter, int cansel, int left, int right);

	int GetInputKey(eKey checkKey);
	void Initialize() override {};
	void Finalize() override {};
	void Update() {};
	// void Draw();
	
};

