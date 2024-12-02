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

class Peace_Of_Cake :public Graphic {
	int point;					// �P�[�L�̃C�`�S�̐�
	int item;					// �P�[�L�̒��Ɋ܂܂�Ă�A�C�e���B�i�O�Ȃ牽�������Ă��Ȃ��j
	int radian;					// �p�x
};

// ���[���b�g
class Rulette :public Graphic {
	Peace_Of_Cake POC[8];
	int radian;					// �p�x
};

class Item : public Graphic 
{
protected :
	bool exist;					// �A�C�e�������݂��邩�ǂ���
	int itemID;

public:
	bool Return_Exist();
	int Return_ItemID();
	void Use();
};

class Item_Menu : public Graphic
{
protected:
	Item item[8];
public:
	Item Return_Item(int idx);
};