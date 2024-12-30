#include "MovementMove.h"
#include <tuple>

MovementMove::MovementMove(MovementI* movementI, eMoveType moveType, float x, float y,int flame) :
	Movement(movementI, moveType, x, y , flame) {
}

MovementMove::~MovementMove() {
	for (; moveType->GetFlame() > 0;) {
		Action();
	}
}
void MovementMove::Action() {
	auto [x, y] = moveType->Calc();
	movementI->Move(x, y);
}