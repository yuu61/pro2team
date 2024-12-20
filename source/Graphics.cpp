#include "..\header\Graphics.h"
#include "..\dxlib_for_visual_studio\DxLib.h"


Graphics::Graphics() :
    visible(1),
    graph(0),
    x(0),
    y(0),
    xx(100),
    yy(100),
    gX(x),						// 左上の座標を格納
    gY(y),
    gXx(xx),						//右下の座標を格納
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
    gX = x;						// 左上の座標を格納
    gY = y;
    gXx = y;						//右下の座標を格納
    gYy = y;
}

// 画像を表示する
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

//　グラフィックを囲うように枠を表示する。
void Graphics::LightUp() {
    DrawExtendGraph(x, y, xx, yy, graph, TRUE);
}

// 全ての描画イベントの参照先の情報更新処理。グラフィクス用の変数はここでのみ変更
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