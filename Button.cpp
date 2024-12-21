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
	Graphics(x,y,xx,yy,graph){
}

void Button::Initialize() {}

void Button::Finalize(){}

void Button::Update() {
	this->Graphics::Update();
}

/*
void Button::Draw() {
	this->Graphics::Draw();

}
*/

eButtonStatus Button::DrawCheckLeft() {
	return statusLeft;
}

eButtonStatus Button::DrawCheckRight() {
	return statusRight;
}

void Button::CheckClick(int time, int charge, eButtonStatus* status) {
	if (time == 0) {
		*status = NONE;
	}
	else if (time == 1 && (inputMouse.x >= x && inputMouse.y >= y && inputMouse.x <= xx && inputMouse.y <= yy)) {
		*status = CHARGING;
		if (time == charge) {
			*status = PRESSED;
		}
		else if (charge == 0) {
			*status = INVALID;
		}
	}
	else if ((inputMouse.x >= x && inputMouse.y >= y && inputMouse.x <= xx && inputMouse.y <= yy) == false) {
		*status = INVALID;
	}
	else if (time == charge && *status == CHARGING) {
		*status = PRESSED;
	}
	else if (time > charge) {
		*status = INVALID;
	}

}

eButtonStatus Button::CheckLeft() {
	CheckClick(inputMouse.left, checkLeftCharge, &statusLeft);
	return statusLeft;
}

eButtonStatus Button::CheckRight() {
	CheckClick(inputMouse.right, checkRightCharge, &statusRight);
	return statusRight;
}

