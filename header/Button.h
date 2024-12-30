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

	void Initialize() override;        //�����������͎������Ă����Ȃ��Ă�����
	void Finalize() override;        //�I�������͎������Ă����Ȃ��Ă�����
	void Update();    //�X�V�����͕K���p����Ŏ�������
	// void Draw() ;    //�`�揈���͕K���p����Ŏ�������
};

