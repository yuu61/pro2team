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
    gX = x;						// 左上の座標を格納
    gY = y;
    gXx = y;						//右下の座標を格納
    gYy = y;
}

// 画像を表示する
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

//　グラフィックを囲うように枠を表示する。
void Graphic::Light_Up() {
    DrawExtendGraph(x, y, xx, yy, graph, TRUE);
}

// 全ての描画イベントの参照先の情報更新処理。グラフィクス用の変数はここでのみ変更
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
    
        // イチゴを増やすアイテムの処理
    case 1:

    }
}

// ルーレットを回す処理
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

// ルーレットのケーキを表示する処理
void Rulette::Display() {
    for (int i = 0; i < CAKE_NUM; i++) {
        this->POC[i].Display();
    }
}

// ルーレットが停止したかを確認する処理
bool Rulette::Get_Stoping() {
    static int sFlame = 0;
    // ルーレット停止後、すこし次の処理の以降に遅延を持たせる。
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