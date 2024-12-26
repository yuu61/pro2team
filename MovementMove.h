#pragma once
#include "Movement.h"

class MovementMove : public Movement
{
public:
	MovementMove(MovementI* eventI, eMoveType moveType, float x, float y,int flame);
	void Action() override {};
};

