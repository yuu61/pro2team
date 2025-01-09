#include "..\header\MovementExpand.h"

MovementExpand::MovementExpand(MovementI* movementI, eMoveType moveType, float x, float y, int flame) :
	Movement(movementI, moveType, x, y, flame) {
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