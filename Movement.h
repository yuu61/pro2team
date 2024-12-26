#pragma once
#include "MovementI.h"
#include "MoveType.h"

typedef enum _eMovementType {
	MOVEMENT_MOVE,
	MOVEMENT_EXPAND,
	MOVEMENT_TYPE_MAX
}eMovementType;




class Movement
{
protected:
	
	MovementI* movementI;
	MoveType* moveType;

public:
	Movement() {};
	Movement(MovementI* eventI, eMoveType moveType, float x, float y, int flame);
	virtual void Action() = 0;

};

