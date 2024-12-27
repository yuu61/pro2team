#pragma once
#include "Movement.h"

class MovementExpand : public Movement
{
public:
	MovementExpand(MovementI* eventI, eMoveType moveType, float x, float y, float time,int flame);
	~MovementExpand();
	void Action() override;
};

