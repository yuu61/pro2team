#pragma once
#include ".\Task.h"

class Graphics : public Task
{
protected:

	bool visible;				// 画像を表示するかどうか
	int graph;					// 表示する画像のハンドルを格納
	int x;						// 左上の座標を格納
	int y;
	int xx;						//右下の座標を格納
	int yy;
	int gX;						//グラフィックス用の変数
	int gY;
	int gXx;
	int gYy;

public:
	Graphics();
	Graphics(int x, int xx, int y, int yy, int graph);

	void Initialize() override;

	void SetVisible(bool in);
	void SetGraph(const char* in);
	void SetLocation(int inx, int iny, int inxx, int inyy);
	void Draw();
	void Draw(int inx, int iny);
	void ChangeScale(int scale);
	void LightUp();
	void Update() override;
	int GetX() { return x; }
	int GetXx() { return xx; }
	int GetY() { return y; }
	int GetYy() { return yy; }
};


