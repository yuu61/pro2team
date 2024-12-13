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
	void Set_Graph(const char* in);
	void Set_Location(int inx, int iny, int inxx, int inyy);
	void Display();
	void Display(int inx, int iny);
	void Change_Scale(int scale);
	void Light_Up();
	void Update();
	int Get_X() { return x; }
	int Get_Xx() { return xx; }
	int Get_Y() { return y; }
	int Get_Yy() { return yy; }
};

class Piece_Of_Cake :public Graphic {
	int point;					// �P�[�L�̃C�`�S�̐�
	int item;					// �P�[�L�̒��Ɋ܂܂�Ă�A�C�e���B�i�O�Ȃ牽�������Ă��Ȃ��j
};

// ���[���b�g
class Rulette :public Graphic {

	Piece_Of_Cake POC[8];
	int radian;					// �p�x
	int speed;
	int gSpeed;

public:
	void Start();
	void Stop();
	void Rotate();
	void Display();
	bool Get_Stoping();
	int Get_Poc() 
	{ 
		return Rulette.POC[Rulette.radian / 45].point;
	}
};

class Item : public Graphic 
{
protected :
	bool exist;					// �A�C�e�������݂��邩�ǂ���
	int itemID;

public:
	bool Return_Exist() { return exist; }
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