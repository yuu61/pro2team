#include "../header/MovementRotate.hpp"
#include <tuple>

MovementRotate::MovementRotate(MovementI* eventI, eMoveType moveType, float rota, int flame):
	Movement(eventI, moveType, rota, 0, flame) {

}
MovementRotate::~MovementRotate() {
	for (; moveType->GetFlame() > 0;) {
		Action();
	}
}

void MovementRotate::Action() {
	auto [x, y] = moveType->Calc();
	movementI->Rotate(x);
}