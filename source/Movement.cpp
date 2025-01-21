#include "..\header\Movement.h"
#include "..\header\MoveTypeNormal.h"
#include "..\header\MoveTypeSine.h"
#include "..\header\MoveTypeGrad.h"

Movement::Movement(MovementI* eventI, eMoveType eMoveType, float x, float y,int flame) :
	movementI(eventI)
	{
	switch (eMoveType) {
	case MOVE_NORMAL:
		moveType = (MoveType*) new MoveTypeNormal(x, y, flame);
		break;
	case MOVE_SINE:
		moveType = (MoveType*) new MoveTypeSine(x , y ,flame);
		break;
	case MOVE_GRAD_UP:
		moveType = (MoveType*) new MoveTypeGrad(x, y, flame,1);
		break;
	case MOVE_GRAD_DOWN:
		moveType = (MoveType*) new MoveTypeGrad(x, y, flame,-1);
		break;
	}

}

Movement::~Movement() {
	
}