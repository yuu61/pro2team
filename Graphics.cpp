#include "DxLib.h"
#include "Graphics.h"
#include "MovementMove.h"

Graphics::Graphics() :
    visible(1),
    graph(0),
    location{0,0,0,0},
    graphLocation{0,0,0,0},
    scale(1),
    movement{ nullptr,nullptr } {
}

Graphics::Graphics(float x1, float y1, float x2, float y2, int graph) :
    visible(1),
    location{x1,y1,x2,y2},
    graphLocation{x1,y1,x2,y2},
    scale(1),
    graph(graph),
    movement{nullptr,nullptr} {
    
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

void Graphics::SetLocation(float inx1, float iny1, float inx2, float iny2) {
    location = { inx1,iny1,inx2,iny2 };
    graphLocation = { inx1,iny1,inx2,iny2 };
}

// 画像を表示する
void Graphics::Draw() {

    if (visible) {
        DrawExtendGraph(graphLocation.x1, graphLocation.y1, graphLocation.x2, graphLocation.y2, graph, TRUE);
    }
}
void Graphics::Draw(int inx, int iny) {

    if (visible) {
        DrawExtendGraph(graphLocation.x1 + inx, graphLocation.y1 + iny, graphLocation.x2 + inx, graphLocation.y2 + iny, graph, TRUE);
    }
}

void Graphics::SetScale(float in) {
    scale = in;
}

//　グラフィックを囲うように枠を表示する。
void Graphics::LightUp() {

}

void Graphics::SetMovement(eMovementType eventType, eMoveType moveType, float x, float y,int flame) {
    switch (eventType) {
    case MOVEMENT_MOVE:
        movement[eventType] = (Movement*) new MovementMove(this, moveType, x, y, flame);
    }
    
}

void Graphics::Move(float x, float y) {
    location.x1 += x;
    location.y1 += y;
    location.x2 += x;
    location.y2 += y;
}

void Graphics::Expand(float x, float y) {
    location.x1 -= x;
    location.y1 -= y;
    location.x2 += x;
    location.y2 += y;
}

// 全ての描画イベントの参照先の情報更新処理。グラフィクス用の変数はここでのみ変更
void Graphics::Update() {
    for (int i = 0; i < MOVEMENT_TYPE_MAX; i++) {
        if (movement[i] != nullptr) {
            movement[i]->Action();
        }
    }
}