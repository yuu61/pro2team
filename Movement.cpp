#include "Movement.h"
#include "MoveTypeNormal.h"
#include "MoveTypeSine.h"


Movement::Movement(MovementI* eventI, eMoveType eMoveType, float x, float y,float time,int flame) :
	movementI(eventI)
	{
	switch (eMoveType) {
	case MOVE_NORMAL:
		moveType = (MoveType*) new MoveTypeNormal(x, y, flame);
		break;
	case MOVE_SINE:
		moveType = (MoveType*) new MoveTypeSine(x, y,time,flame);
		break;
	}

}

Movement::~Movement() {
	
}