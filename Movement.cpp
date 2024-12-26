#include "Movement.h"
#include "MoveTypeNormal.h"


Movement::Movement(MovementI* eventI, eMoveType eMoveType, float x, float y,int flame) :
	movementI(eventI)
	{
	switch (eMoveType) {
	case MOVE_NORMAL:
		moveType = (MoveType*) new MoveTypeNormal(x, y, flame);
	}

}