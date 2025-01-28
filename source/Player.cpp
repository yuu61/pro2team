#include "../header/Player.hpp"
#include "../header/ItemEye.hpp"
#include "../header/ItemClock.hpp"
#include "../header/ItemBasket.hpp"

Player::Player() {}

Player::Player(int enter, int cansel, int left, int right, float x, float y, float cx, float cy, int graph) :
	points(0),
	crown(0),
	item{ nullptr },
	key{ enter,cansel,left,right },
	Graphics(x, y, cx, cy, graph) {
	
}

void Player::SetItem(Item* newItem) {
	for (int i = 0; i < ITEM_NUM; i++) {
		if (item[i] == nullptr) {
			item[i] = newItem;
			break;
		}
	}
}