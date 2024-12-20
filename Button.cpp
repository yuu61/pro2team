#include "Button.h"
#include "CatchInput.h"


Button::Button() :
	status(0),
	checkKey(0),
	checkTime(1),
	Graphics() {
}

Button::Button(int checkKey,int checkTime, int x, int y, int xx, int yy, int graph) :
	status(0),
	checkKey(checkKey),
	checkTime(checkTime),
	Graphics(x,y,xx,yy,graph){
}

void Button::Initialize() {}

void Button::Finalize(){}

void Button::Update() {
	this->Graphics::Update();
}

void Button::Draw() {
	this->Graphics::Draw();

}

bool Button::DrawCheck() {
	if (status == PRESSED) {
		return 1;
	}
	return 0;
}

bool Button::Check() {
	
	if (InputKey[checkKey] == 1) {
		status = CHARGING;
	}
	else if (InputKey[checkKey] == 0) {
		status = NONE;
	}

	if (status == CHARGING && InputKey[checkKey] >= checkTime) {
		status = PRESSED;
		return 1;
	}

	return 0;
}