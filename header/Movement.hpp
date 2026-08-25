#pragma once
#include "MovementI.hpp"
#include "MoveType.hpp"

typedef enum _eMovementType {
	MOVEMENT_MOVE,
	MOVEMENT_EXPAND,
	MOVEMENT_ROTATE,
	MOVEMENT_REPETATE,
	MOVEMENT_TYPE_MAX,
}eMovementType;




class Movement
{
protected:
	
	MovementI* movementI{ nullptr };
	MoveType* moveType{ nullptr };

public:
	Movement();
	Movement(MovementI* eventI, eMoveType moveType, float x, float y, int flame);
	virtual ~Movement();

	int GetFlame();
	virtual void Action();

};

