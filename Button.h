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

	void Initialize() override;        //�����������͎������Ă����Ȃ��Ă�����
	void Finalize() override;        //�I�������͎������Ă����Ȃ��Ă�����
	void Update();    //�X�V�����͕K���p����Ŏ�������
	// void Draw() ;    //�`�揈���͕K���p����Ŏ�������
};

