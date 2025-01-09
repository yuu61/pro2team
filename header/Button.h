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
	// �N���b�N�̏�Ԃ̕ۑ�
	eButtonStatus statusRight;
	eButtonStatus statusLeft;
	// �N���b�N�����ɕK�v�ȃt���[����
	int checkRightCharge;
	int checkLeftCharge;

	// �N���b�N�̏�Ԃ��X�V����B���E���p�B
	virtual eButtonStatus CheckClick(int time, int charge, eButtonStatus stutas,bool cheat);

public:
	Button();
	Button(int checkLeftCharge, int checkRightCharge, float x, float xx, float y, float yy, int graph);
	~Button() {};

	// �N���b�N�C�x���g��ۑ�����B
	std::function<void(void)> Click{ []() {} };

	// �}�E�X�̃N���b�N���m�F����
	// virtual eButtonStatus CheckLeft();
	// virtual eButtonStatus CheckRight();

	// �L�[�{�[�h����̓��͂��m�F����B
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

