#include "..\header\MovementRepetate.h"
#include <cmath>

static const double pi = 3.141592653589793;

MovementRepetate::MovementRepetate(MovementI* eventI, eMoveType moveType, float x, float y, int time, int flame) :
	oneFlame(time / 2),
	Movement(eventI, moveType, x * flame / time * 2, y * flame / time * 2, flame) {

}
MovementRepetate::~MovementRepetate() {
	for (; moveType->GetFlame() > 0;) {
		Action();
	}
}

void MovementRepetate::Action() {
	if (moveType->GetFlame() % oneFlame == 0 && moveType->GetFlame() % (oneFlame * 2) != 0) {
		v = -v;
	}
	auto [x, y] = moveType->Calc();
	
	movementI->Move(x * v, y * v);
}