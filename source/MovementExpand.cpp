#include "..\header\MovementExpand.hpp"

MovementExpand::MovementExpand(MovementI* movementI, eMoveType moveType, float x, float y, float ux, float uy, int flame) :
	Movement(movementI, moveType, x, y,flame) {

	unitX = ux;
	if (unitX < 0) {
		unitX = -unitX;
	}

	unitY = uy;
	if (unitY < 0) {
		unitY = -unitY;
	}
}

MovementExpand::~MovementExpand() {
	for (; moveType->GetFlame() > 0;) {
		Action();
	}
}

void MovementExpand::Action() {
	auto [x, y] = moveType->Calc();
	movementI->Expand(x, y, unitX * x, unitY * y);
}