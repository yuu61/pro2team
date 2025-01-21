#pragma once
#include "Movement.h"

class MovementExpand : public Movement
{
	float unitX, unitY;
	float unitCX, unitCY;

public:
	//x ���v�g��� ux ���v�ړ��� 
	MovementExpand(MovementI* eventI, eMoveType moveType, float x, float y, float ux, float uy, int flame);
	~MovementExpand();
	void Action() override;
};

