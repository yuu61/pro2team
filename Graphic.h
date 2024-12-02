#pragma once
#include "DxLib.h"
#include <vector>

using namespace std;

// �O���t�B�b�N�X�f�[�^���i�[����\����
class Graphic
{
protected:
	bool visible;				// �摜��\�����邩�ǂ���
	int graph;					// �\������摜�̃n���h�����i�[
	int x;						// ����̍��W���i�[
	int y;
	int xx;						//�E���̍��W���i�[
	int yy;
	int gX;						//�O���t�B�b�N�X�p�̕ϐ�
	int gY;
	int gXx;					
	int gYy;
	int flame;					// �C�x���g�̃t���[�����̊i�[

	int event[10];				// �K�������C�x���g�̊i�[

public:
	void Set_Visible(bool in);
	void Set_Graph(char* in);
	void Set_Location(int inx, int iny, int inxx, int inyy);
	void Display();
	void Display(int inx, int iny);
	void Be_Big();
	void Light_Up();
	void Update();
};

class Rulette :Graphic {

};

class Item :Graphic {
	
};

class Item_Menu : Item {
	Item item[8];
};