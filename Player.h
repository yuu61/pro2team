#pragma once
#include "Graphics.h"
#include "Item.h"

typedef enum _eKey {
	KEY_LEFT,
	KEY_RIGHT,
	KEY_ENTER,
	KEY_CANSEL,
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
	

	//eKey 
	void Initialize() override;
	void Finalize() override;
	void Update() ;
	// void Draw();
	
};

