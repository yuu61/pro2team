#include "Button.h"
#include "CatchInput.h"


Button::Button() :
	statusRight(NONE),
	statusLeft(NONE),
	checkRightCharge(1),
	checkLeftCharge(1),
	Graphics() {
}

Button::Button(int checkLeftCharge, int checkRightCharge, int x, int y, int xx, int yy, int graph) :
	statusRight(NONE),
	statusLeft(NONE),
	checkRightCharge(checkRightCharge),
	checkLeftCharge(checkLeftCharge),
	Graphics(x, y, xx, yy, graph) {
}

void Button::Initialize() {}

void Button::Finalize() {}

void Button::Update() {
	this->Graphics::Update();
}

/*
void ButtonCharge::Draw() {
	this->Graphics::Draw();

}
*/

eButtonStatus Button::GetStatusLeft() {
	return statusLeft;
}

eButtonStatus Button::GetStatusRight() {
	return statusRight;
}

eButtonStatus Button::CheckClick(int time, int charge, eButtonStatus status ,bool cheat) {

	if (status == CHARGED && time == 0) {
		return PRESSED;
	}
	else if (time == 0) {
		return NONE;
	}
	else if (status == INVALID) {
		return INVALID;
	}
	else if (time == 1 && (CheckLocation() || cheat)) {
		if (time == charge) {
			return CHARGED;
		}
		else if (charge == 0) {
			return INVALID;
		}
		return CHARGING;
	}
	else if (!(CheckLocation() || cheat)) {
		return INVALID;
	}
	else if (time >= charge && status == CHARGING) {
		return CHARGED;
	}
	return status;
}

/*
eButtonStatus Button::CheckLeft() {
	CheckClick(inputMouse.left, checkLeftCharge, statusLeft, false);
	return statusLeft;
}
*/

eButtonStatus Button::CheckLeft(int inputKeyCharge) {
	statusLeft = CheckClick(inputKeyCharge, checkLeftCharge, statusLeft,true);
	return statusLeft;
}

/*
eButtonStatus Button::CheckRight() {
	CheckClick(inputMouse.right, checkRightCharge, statusRight,false);
	return statusRight;
}
*/

eButtonStatus Button::CheckRight(int inputKeyCharge) {
	statusRight = CheckClick(inputKeyCharge, checkRightCharge, statusRight, true);
	return statusRight;
}

bool Button::CheckLocation() {
	return (inputMouse.x >= x && inputMouse.y >= y && inputMouse.x <= xx && inputMouse.y <= yy);
}