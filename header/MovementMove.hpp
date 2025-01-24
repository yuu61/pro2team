#pragma once
#include "Movement.hpp"

class MovementMove : public Movement
{
public:
	MovementMove(MovementI* eventI, eMoveType moveType, float x, float y,int flame);
	~MovementMove() ;
	void Action() override;
};

