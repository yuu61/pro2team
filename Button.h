#pragma once
#include "Graphics.h"

typedef enum _eButtonStatus {
	NONE,
	CHARGING,
	PRESSED,
	INVALID
}eButtonStatus;

class Button : public Graphics
{
private:
	eButtonStatus statusRight;
	eButtonStatus statusLeft;
	int checkRightCharge;
	int checkLeftCharge;

	void CheckClick(int time, int charge, eButtonStatus* stutas);

public:
	Button();
	Button(int checkLeftCharge, int checkRightCharge, int x, int xx, int y, int yy, int graph);
	~Button() {};

	eButtonStatus CheckLeft();
	eButtonStatus CheckRight();
	eButtonStatus DrawCheckLeft();
	eButtonStatus DrawCheckRight();

	void Initialize() override;        //初期化処理は実装してもしなくてもいい
	void Finalize() override;        //終了処理は実装してもしなくてもいい
	void Update();    //更新処理は必ず継承先で実装する
	// void Draw() ;    //描画処理は必ず継承先で実装する
};

