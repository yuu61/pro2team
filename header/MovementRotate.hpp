#pragma once
#include "Movement.hpp"

class MovementRotate : public Movement
{
public:
	MovementRotate(MovementI* eventI, eMoveType moveType, float rota, int flame);
	~MovementRotate();
	void Action() override;
};
