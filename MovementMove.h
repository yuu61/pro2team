#pragma once
#include "Movement.h"

class EventMove : Movement
{
public:
	EventMove(MovementI* eventI, eMoveType moveType, float x, float y,int flame);
	void Action() override;
};

