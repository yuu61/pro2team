#pragma once
#include "Task.h"
#include "MovementI.h"
#include "Movement.h"

typedef struct _Location {
	float x1, y1, x2, y2;
}Location;

// グラフィックスを表現するクラス。
class Graphics : public Task, public MovementI
{
protected:

	bool visible;				// 画像を表示するかどうか
	int graph;					// 表示する画像のハンドルを格納
	// 座標を保存する変数。
	Location location;
	// 大きさを倍率で格納する。
	float scale{ 1 };
	// 移動などのイベントを格納する。
	Movement* movement[MOVEMENT_TYPE_MAX];

public:
	Graphics();
	Graphics(const char graph[]);
	Graphics(float x1, float y1, float x2, float y2, int graph);

	void Initialize() override;

	void SetVisible(bool in);
	void SetGraph(const char* in);
	void SetGraph(int in);
	int GetGraph() { return graph; }
	void SetLocation(float inx, float iny, float inxx, float inyy);
	// 画像を描画する。
	void Draw();
	void Draw(int inx, int iny);
	void SetScale(float scale);
	// 見た目を強調してわかりやすくする。
	void LightUp();

	void Update() override;

	// イベントをセットする。
	void SetMovement(eMovementType eventType, eMoveType moveType, float x, float y, int flame);
	void SetMovement(eMovementType eventType, eMoveType moveType, float time, int flame);

	// イベントを実行する。
	void Move(float x, float y) override;
	void Expand(float x, float y) override;

	int GetX1() { return location.x1; }
	int GetX2() { return location.x2; }
	int GetY1() { return location.y1; }
	int GetY2() { return location.y2; }
};
