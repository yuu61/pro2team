#include "Graphics.h"
#include "DxLib.h"


Graphics::Graphics() :
    visible(1),
    graph(0),
    x(0),
    y(0),
    xx(100),
    yy(100),
    gX(x),						// ����̍��W���i�[
    gY(y),
    gXx(xx),						//�E���̍��W���i�[
    gYy(yy) {
}

Graphics::Graphics(int x, int y, int xx, int yy, int graph) :
    visible(1),
    x(x),
    y(y),
    xx(xx),
    yy(yy),
    gX(x),
    gY(y),
    gXx(xx),
    gYy(yy),
    graph(graph){
    
}


void Graphics::Initialize() {}

void Graphics::SetVisible(bool in)
{
    visible = in;
}

void Graphics::SetGraph(const char* in)
{
    graph = LoadGraph(in);
}

void Graphics::SetLocation(int inx, int iny, int inxx, int inyy) {
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
void Graphics::Draw() {

    if (visible) {
        DrawExtendGraph(x, y, xx, yy, graph, TRUE);
    }
}
void Graphics::Draw(int inx, int iny) {

    if (visible) {
        DrawExtendGraph(x + inx, y + iny, xx + inx, yy + iny, graph, TRUE);
    }
}

void Graphics::ChangeScale(int scale) {
    this->x -= scale;
    this->xx += scale;
    this->y -= scale;
    this->yy += scale;
}

//�@�O���t�B�b�N���͂��悤�ɘg��\������B
void Graphics::LightUp() {
    DrawExtendGraph(x, y, xx, yy, graph, TRUE);
}

// �S�Ă̕`��C�x���g�̎Q�Ɛ�̏��X�V�����B�O���t�B�N�X�p�̕ϐ��͂����ł̂ݕύX
void Graphics::Update() {
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
    if (x != gYy) {
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