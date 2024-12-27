#include "MovementExpand.h"

MovementExpand::MovementExpand(MovementI* movementI, eMoveType moveType, float x, float y, float time, int flame) :
	Movement(movementI, moveType, x, y, time, flame) {
}

MovementExpand::~MovementExpand() {
	for (; moveType->GetFlame() > 0;) {
		Action();
	}
}
void MovementExpand::Action() {
	auto [x, y] = moveType->Calc();
	movementI->Expand(x, y); 
}