#pragma once
#include "Graphics.h"

typedef enum _eButtonStatus {
	NONE,
	CHARGING,
	PRESSED
}eButtonStatus;

class Button : Graphics
{
private:
	int status;
	int checkKey;
	int checkTime;

public:
	Button();
	Button(int checkKey,int checkTime, int x, int xx, int y, int yy, int graph);
	~Button() {};

	void SetKey(int k) { checkKey = k; }
	bool Check();
	bool DrawCheck();

	void Initialize() override;        //�����������͎������Ă����Ȃ��Ă�����
	void Finalize() override;        //�I�������͎������Ă����Ȃ��Ă�����
	void Update();    //�X�V�����͕K���p����Ŏ�������
	void Draw() ;    //�`�揈���͕K���p����Ŏ�������
};

