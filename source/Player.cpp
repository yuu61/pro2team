#include "..\header\Player.h"
#include "..\header\CatchInput.h"
#include "..\header\ItemEye.h"
Player::Player() {}

Player::Player(int enter, int cansel, int left, int right) :
	point(0),
	crown(0),
	item{ nullptr } ,
	key{ enter,cansel,left,right } {

	SetItem((Item*)new ItemEye());
	SetItem((Item*)new ItemEye());
	SetItem((Item*)new ItemEye());
	SetItem((Item*)new ItemEye());
}

int Player::GetInputKey(eKey checkKey) {
	return inputKey[key[checkKey]];
}

void Player::SetItem(Item* newItem) {
	for (int i = 0; i < ITEM_NUM; i++) {
		if (item[i] == nullptr) {
			item[i] = newItem;
			break;
		}
	}
}