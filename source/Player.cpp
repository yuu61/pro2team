#include "..\header\Player.hpp"
#include "..\header\ItemEye.hpp"
#include "..\header\ItemClock.hpp"
#include "..\header\ItemBasket.hpp"

#include <utility>

Player::Player() {}

Player::Player(int enter, int cansel, int left, int right, float x, float y, float cx, float cy, int graph) :
	Graphics(x, y, cx, cy, graph),
	key{ enter,cansel,left,right } {
	
}

void Player::SetItem(std::unique_ptr<Item> newItem) {
	for (auto& itemSlot : item) {
		if (itemSlot == nullptr) {
			itemSlot = std::move(newItem);
			return;
		}
	}
}
