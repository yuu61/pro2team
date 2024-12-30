#pragma once
#include "Graphics.h"
#include "Button.h"


class ButtonCharge : public Button
{
private:
	/*
	eButtonStatus statusRight;
	eButtonStatus statusLeft;
	int checkRightCharge;
	int checkLeftCharge;
	*/

	eButtonStatus CheckClick(int time, int charge, eButtonStatus stutas, bool cheat) override;

public:
	ButtonCharge();
	ButtonCharge(int checkLeftCharge, int checkRightCharge, int x, int xx, int y, int yy, int graph);
	~ButtonCharge() {};

	//eButtonStatus CheckLeft() override ;
	//eButtonStatus CheckRight() override;
	/*
	eButtonStatus GetStatusLeft();
	eButtonStatus GetStatusRight();
	*/
	void Initialize() override;        //初期化処理は実装してもしなくてもいい
	void Finalize() override;        //終了処理は実装してもしなくてもいい
	void Update();    //更新処理は必ず継承先で実装する
	// void Draw() ;    //描画処理は必ず継承先で実装する
};

