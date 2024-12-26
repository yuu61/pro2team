#pragma once
#include <tuple>

typedef enum _eMoveType {
	MOVE_NONE,
	MOVE_NORMAL,
	MOVE_SIGN
}eMoveType;

class MoveType
{
protected:
	float x;
	float y;
	int flame;
public:
	MoveType(float x, float y, int flame);
	virtual std::tuple<float ,float> Calc() = 0;
};

