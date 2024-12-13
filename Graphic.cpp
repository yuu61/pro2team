#include "Graphic.h"
#include "DxLib.h"
#include "constants.h"

void Graphic::Set_Visible(bool in)
{
    visible = x;
}

void Graphic::Set_Graph(const char* in)
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

void Graphic::Change_Scale(int scale) {
    this->x -= scale;
    this->xx += scale;
    this->y -= scale;
    this->yy += scale;
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

bool Item::Return_Exist() {
    if (exist) {
        return TRUE;
    }
    return FALSE;
}

int Item::Return_ItemID() {
    return itemID;
}

void Item::Use() {
    
    switch (itemID) {
    
        // �C�`�S�𑝂₷�A�C�e���̏���
    case 1:

    }
}

// ���[���b�g���񂷏���
void Rulette::Start() {
    this->speed += 10;
}

void Rulette::Stop() {
    this->speed = 0;
}

void Rulette::Rotate() {
    if (speed <= gSpeed) {
        gSpeed -= 1;
    }
    else if (speed >= gSpeed) {
        gSpeed += 1;
    }

    if (gSpeed + radian >= 360) {
        gSpeed = gSpeed + radian - 360;
    }
    else {
        this->radian += gSpeed;
    }
}

// ���[���b�g�̃P�[�L��\�����鏈��
void Rulette::Display() {
    for (int i = 0; i < CAKE_NUM; i++) {
        this->POC[i].Display();
    }
}

// ���[���b�g����~���������m�F���鏈��
bool Rulette::Get_Stoping() {
    static int sFlame = 0;
    // ���[���b�g��~��A���������̏����̈ȍ~�ɒx������������B
    if (gSpeed == 0) {
        sFlame += 1;
    }
    if (sFlame >= 60) {
        sFlame = 0;
        return TRUE;
    }
    return FALSE;
}

Item Item_Menu::Return_Item(int idx){
    if (item[idx].Return_Exist() == TRUE) {

    }
    return item[idx];
}