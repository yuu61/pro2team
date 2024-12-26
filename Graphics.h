#pragma once
#include "Task.h"
#include "MovementI.h"
#include "Movement.h"

typedef struct _Location {
	float x1, y1, x2, y2;
}Location;


typedef enum _eMovementType {
	MOVEMENT_MOVE,
	MOVEMENT_EXPAND,
	MOVEMENT_TYPE_MAX
}eMovementType;


typedef enum _eMoveType {
	MOVE_NONE,
	MOVE_NORMAL,
	MOVE_SIGN
}eMoveType;


class Graphics : public Task, MovementI
{
protected:

	Movement* movement[MOVEMENT_TYPE_MAX];
	bool visible;				// 画像を表示するかどうか
	int graph;					// 表示する画像のハンドルを格納
	Location location;
	Location graphLocation;
	float scale;
	

public:
	Graphics();
	Graphics(float x, float y, float xx, float yy, int graph);

	void Initialize() override;

	void SetVisible(bool in);
	void SetGraph(const char* in);
	void SetLocation(float inx, float iny, float inxx, float inyy);
	void Draw();
	void Draw(int inx, int iny);
	void SetScale(float scale);
	void LightUp();
	void Update() override;

	void SetMovement(eMovementType eventType, eMoveType moveType, float x, float y, int flame);
	void Move(float x, float y) override;
	void Expand(float x, float y) override;

	int GetX() { return location.x1; }
	int GetXx() { return location.x2; }
	int GetY() { return location.y1; }
	int GetYy() { return location.y2; }
};


