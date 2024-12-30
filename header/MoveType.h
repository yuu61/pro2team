#pragma once
#include <tuple>

typedef enum _eMoveType {
	MOVE_NONE,
	MOVE_NORMAL,
	MOVE_SINE
}eMoveType;

class MoveType
{
protected:
	float x;
	float y;
	int flame;
public:
	MoveType(float x, float y, int flame);
	int GetFlame() { return flame; }
	virtual std::tuple<float ,float> Calc() = 0;
};

