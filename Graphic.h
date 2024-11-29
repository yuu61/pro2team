#pragma once
#include "DxLib.h"
// �O���t�B�b�N�X�f�[�^���i�[����\����
class Graphic
{
private:
	bool visible;				// �摜��\�����邩�ǂ���
	int graph;					// �\������摜�̃n���h�����i�[
	int x;						// ����̍��W���i�[
	int y;
	int xx;						//�E���̍��W���i�[
	int yy;
	int iniX;					// �f�t�H���g�̍���̍��W���i�[
	int iniY;
	int iniXx;					// �f�t�H���g�̉E���̍��W���i�[
	int iniYy;
	int flame;					// �C�x���g�̃t���[�����̊i�[

	int event[10];				// �K�������C�x���g�̊i�[

public:
	void Set_Visible(bool in);
	void Set_Graph(char* in);
	void Set_Location(int inx, int iny, int inxx, int inyy);
	void Display();
	void Be_Big();
	void Light_Up();
	void Update();
};

class Rulette :Graphic {

};

class Item_Menu :Graphic {
	Item item[8] ;
};

class Item :Graphic {
	
};