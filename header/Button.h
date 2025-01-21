#pragma once
#include "Graphics.h"
#include <functional>

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
	// クリックの状態の保存
	eButtonStatus statusRight;
	eButtonStatus statusLeft;
	// クリック完了に必要なフレーム数
	int checkRightCharge;
	int checkLeftCharge;

	// クリックの状態を更新する。左右両用。
	virtual eButtonStatus CheckClick(int time, int charge, eButtonStatus stutas,bool cheat);

public:
	Button();
	Button(int checkLeftCharge, int checkRightCharge, float x, float y, double xx, double yy, int graph);
	~Button() {};

	// �N���b�N�C�x���g��ۑ�����B
	std::function<void(void)> Click{ []() {} };

	// マウスのクリックを確認する
	// virtual eButtonStatus CheckLeft();
	// virtual eButtonStatus CheckRight();

	// キーボードからの入力を確認する。
	virtual eButtonStatus CheckLeft(int inputKeyCharge);
	virtual eButtonStatus CheckRight(int inputKeyCharge);
	bool CheckLocation();


	eButtonStatus GetStatusLeft() { return statusLeft; }
	eButtonStatus GetStatusRight() { return statusRight; }

	void Initialize() override;        //初期化処理は実装してもしなくてもいい
	void Finalize() override;        //終了処理は実装してもしなくてもいい
	void Update();    //更新処理は必ず継承先で実装する
	// void Draw() ;    //描画処理は必ず継承先で実装する
};

