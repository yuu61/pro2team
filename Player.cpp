#include "Player.h"
#include "CatchInput.h"

Player::Player() {}

Player::Player(int enter, int cansel, int left, int right) :
	point(0),
	crown(0),
	item{ nullptr } ,
	key{ enter,cansel,left,right } {
}

int Player::GetInputKey(eKey checkKey) {
	return inputKey[key[checkKey]];
}


/*
if (inputKey[key[checkKey]] == 1) {
	return true;
}
else if (InputKey[checkKey] == 1) {
	status = CHARGING;
}


if (status == CHARGING && InputKey[checkKey] >= checkTime) {
	status = PRESSED;
	return 1;
}

return 0;

*/