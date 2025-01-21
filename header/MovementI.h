#pragma once
class MovementI
{
public:
	virtual void Move(float x, float y) = 0;
	virtual void MoveGL(float x, float y) = 0;
	virtual void Expand(float x, float y, float ux, float uy) = 0;
	virtual void Rotate(float rota) = 0;

};

