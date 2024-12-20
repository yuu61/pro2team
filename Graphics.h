#pragma once
#include "Task.h"

class Graphics : public Task
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
	Graphics();
	Graphics(int x, int xx, int y, int yy, int graph);

	void Initialize() override;

	void SetVisible(bool in);
	void SetGraph(const char* in);
	void SetLocation(int inx, int iny, int inxx, int inyy);
	void Draw();
	void Draw(int inx, int iny);
	void ChangeScale(int scale);
	void LightUp();
	void Update() override;
	int GetX() { return x; }
	int GetXx() { return xx; }
	int GetY() { return y; }
	int GetYy() { return yy; }
};


