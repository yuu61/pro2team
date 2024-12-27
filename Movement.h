#pragma once
#include "MovementI.h"
#include "MoveType.h"

typedef enum _eMovementType {
	MOVEMENT_MOVE,
	MOVEMENT_EXPAND,
	MOVEMENT_TYPE_MAX,
	MOVEMENT_MOVE_TO
}eMovementType;




class Movement
{
protected:
	
	MovementI* movementI;
	MoveType* moveType;

public:
	Movement() {};
	//Movement(MovementI* eventI, eMoveType moveType, float x, float y, int flame);
	Movement(MovementI* eventI, eMoveType moveType, float x, float y,float time, int flame);
	virtual ~Movement();

	int GetFlame(){ return moveType->GetFlame(); }
	virtual void Action() {};

};

