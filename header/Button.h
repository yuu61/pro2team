#pragma once
#include "Graphics.h"

typedef enum _eButtonStatus {
	NONE,
	CHARGING,
	CHARGED,
	PRESSED,
	INVALID
}eButtonStatus;

class Button : public Graphics
{
protected:
	eButtonStatus statusRight;
	eButtonStatus statusLeft;
	int checkRightCharge;
	int checkLeftCharge;

	virtual eButtonStatus CheckClick(int time, int charge, eButtonStatus stutas,bool cheat);

public:
	Button();
	Button(int checkLeftCharge, int checkRightCharge, float x, float xx, float y, float yy, int graph);
	~Button() {};

	// virtual eButtonStatus CheckLeft();
	virtual eButtonStatus CheckLeft(int inputKeyCharge);
	// virtual eButtonStatus CheckRight();
	virtual eButtonStatus CheckRight(int inputKeyCharge);
	bool CheckLocation();

	eButtonStatus GetStatusLeft();
	eButtonStatus GetStatusRight();

	void Initialize() override;        //初期化処理は実装してもしなくてもいい
	void Finalize() override;        //終了処理は実装してもしなくてもいい
	void Update();    //更新処理は必ず継承先で実装する
	// void Draw() ;    //描画処理は必ず継承先で実装する
};

