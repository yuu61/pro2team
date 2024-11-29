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
    iniX = x;						// ����̍��W���i�[
    iniY = y;
    iniXx = y;						//�E���̍��W���i�[
    iniYy = y;
}

// �摜��\������
void Graphic::Display() {
    if (visible) {
        DrawExtendGraph(x, y, xx, yy, graph, TRUE);
    }
}

void Graphic::Be_Big() {
    
}

//�@�O���t�B�b�N���͂��悤�ɘg��\������B
void Graphic::Light_Up() {
    DrawExtendGraph(x, y, xx, yy, graph, TRUE);
}

// �S�Ă̕`��C�x���g�̎Q�Ɛ�̏��X�V����
void Graphic::Update() {
    if (event[0] == 1) {
        static int flame = 0;
        x -= 1;
        y -= 1;
        xx += 1;
        yy -= 1;
        flame++;
        if (flame >= 60) {
            //�C�x���g�I������
            event[0];
        }
    }
}
