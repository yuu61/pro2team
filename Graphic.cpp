#include "Graphic.h"
#include "DxLib.h"
void Graphic::Set_Visible(bool in)
{
    visible = x;
}

void Graphic::Set_Graph(char* in)
{
    graph = LoadGraph(in);
}

void Graphic::Set_Location(int inx, int iny, int inxx, int inyy) {
    x = inx;
    y = iny;
    xx = inxx;
    yy = inyy;
    gX = x;						// ����̍��W���i�[
    gY = y;
    gXx = y;						//�E���̍��W���i�[
    gYy = y;
}

// �摜��\������
void Graphic::Display() {
    if (visible) {
        DrawExtendGraph(x, y, xx, yy, graph, TRUE);
    }
}
void Graphic::Display(int inx,int iny) {
    if (visible) {
        DrawExtendGraph(x + inx, y + iny, xx + inx, yy +iny, graph, TRUE);
    }
}

void Graphic::Be_Big() {
    
}

//�@�O���t�B�b�N���͂��悤�ɘg��\������B
void Graphic::Light_Up() {
    DrawExtendGraph(x, y, xx, yy, graph, TRUE);
}

// �S�Ă̕`��C�x���g�̎Q�Ɛ�̏��X�V�����B�O���t�B�N�X�p�̕ϐ��͂����ł̂ݕύX
void Graphic::Update() {
    if (x != gX) {
        {
            if (x > gX) {
                gX += 1;
            }
            else {
                gX -= 1;
            }
        }
    }
    if (xx != gXx) {
        {
            if (xx > gXx) {
                gXx += 1;
            }
            else {
                gXx -= 1;
            }
        }
    }
    if (y != gY) {
        {
            if (x > gY) {
                gY += 1;
            }
            else {
                gY -= 1;
            }
        }
    }
    if (x != gYy){
        {
            if (x > gYy) {
                gYy += 1;
            }
            else {
                gYy -= 1;
            }
        }
    }
}


void Container<Item>::Display() {
    
};
