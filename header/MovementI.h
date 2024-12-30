#pragma once
class MovementI
{
public:
	virtual void Move(float x, float y) = 0;
	virtual void Expand(float x, float y) = 0;
};

