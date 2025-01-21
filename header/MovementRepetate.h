#pragma once

#include "Movement.h"

class MovementRepetate : public Movement
{
private:
	int v{ 1 };
	int oneFlame;
public:
	MovementRepetate(MovementI* eventI, eMoveType moveType, float x,float y, int time, int flame);
	~MovementRepetate();
	void Action() override;
};

