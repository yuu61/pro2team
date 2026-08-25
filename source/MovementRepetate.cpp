#include "MovementRepetate.hpp"

MovementRepetate::MovementRepetate(MovementI* eventI, eMoveType moveType, float x, float y, int time, int flame) :
	Movement(eventI, moveType,
		x * static_cast<float>(flame) / static_cast<float>(time) * 2.0f,
		y * static_cast<float>(flame) / static_cast<float>(time) * 2.0f,
		flame),
	oneFlame(time / 2) {

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
	
	movementI->Move(x * static_cast<float>(v), y * static_cast<float>(v));
}
