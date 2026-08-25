#pragma once
#include <tuple>

typedef enum _eMoveType {
	MOVE_NORMAL,
	MOVE_SINE,
	MOVE_GRAD_UP,
	MOVE_GRAD_DOWN
}eMoveType;

class MoveType
{
protected:
	float x;
	float y;
	int flame;
public:
	MoveType(float x, float y, int flame);
	virtual ~MoveType() = default;
	int GetFlame();
	virtual std::tuple<float ,float> Calc() = 0;
};

