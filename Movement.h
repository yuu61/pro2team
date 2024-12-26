#pragma once
#include "MovementI.h"
#include "MoveType.h"
#include "Graphics.h"

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

