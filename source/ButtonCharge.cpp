#include "../header/ButtonCharge.hpp"
#include "../header/CatchInput.hpp"


ButtonCharge::ButtonCharge() :
	Button() {
}

ButtonCharge::ButtonCharge(int checkLeftCharge, int checkRightCharge, float x, float y, double xx, double yy, int graph) :
	Button(checkLeftCharge, checkRightCharge, x, y, xx, yy, graph) {

}

void ButtonCharge::Initialize() {}

void ButtonCharge::Finalize(){}

void ButtonCharge::Update() {
	this->Graphics::Update();
}

/*
void ButtonCharge::Draw() {
	this->Graphics::Draw();

}
*/

/*
eButtonStatus ButtonCharge::GetStatusLeft() {
	return statusLeft;
}

eButtonStatus ButtonCharge::GetStatusRight() {
	return statusRight;
}
*/

eButtonStatus ButtonCharge::CheckClick(int time, int charge, eButtonStatus status, bool cheat) {

	

	if (time == 0) {
		return NONE;
	}
	else if (status == INVALID) {
		return INVALID;
	}
	else if (time == 1 && (CheckLocation() || cheat)) {
		
		if (charge == 1) {
			return PRESSED;
		}
		else if (charge == 0) {
			return INVALID;
		}
		return CHARGING;

	}
	else if (!(CheckLocation() || cheat)) {
		return INVALID;
	}
	else if (time == charge && status == CHARGING) {
		Click();
		return PRESSED;
	}
	else if (time > charge) {
		return INVALID;
	}
	return status;

}
/*
eButtonStatus ButtonCharge::CheckLeft() {
	CheckClick(inputMouse.left, checkLeftCharge, &statusLeft,false);
	return statusLeft;
}

eButtonStatus ButtonCharge::CheckRight() {
	CheckClick(inputMouse.right, checkRightCharge, &statusRight,false);
	return statusRight;
}

*/