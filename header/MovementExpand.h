#pragma once
#include "Movement.h"

class MovementExpand : public Movement
{
	float unitX, unitY;
	float unitCX, unitCY;

public:
	//x vgĺĘ ux vÚŽĘ 
	MovementExpand(MovementI* eventI, eMoveType moveType, float x, float y, float ux, float uy, int flame);
	~MovementExpand();
	void Action() override;
};

