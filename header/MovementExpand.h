#pragma once
#include "Movement.h"

class MovementExpand : public Movement
{
public:
	MovementExpand(MovementI* eventI, eMoveType moveType, float x, float y,int flame);
	~MovementExpand();
	void Action() override;
};

