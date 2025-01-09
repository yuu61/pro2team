#include "..\dxlib_for_visual_studio\DxLib.h"
#include "..\header\Graphics.h"
#include "..\header\MovementMove.h"
#include "..\header\MovementExpand.h"

Graphics::Graphics() :
    visible(1),
    graph(0),
    location{0,0,200,200},
    scale(1),
    movement{ nullptr} {
}

Graphics::Graphics(const char graph[]) :
    visible(1),
    graph(LoadGraph(graph)),
    location{ 0,0,200,200 },
    scale(1),
    movement{ nullptr } {
}

Graphics::Graphics(float x1, float y1, float x2, float y2, int graph) :
    visible(1),
    location{x1,y1,x2,y2},
    scale(1),
    graph(graph),
    movement{nullptr} {
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

void Graphics::SetGraph(int in) {
    graph = in;
}


void Graphics::SetLocation(float inx1, float iny1, float inx2, float iny2) {
    location = { inx1,iny1,inx2,iny2 };
}

// 画像を表示する
void Graphics::Draw() {

    if (visible) {
        DrawExtendGraph(location.x1, location.y1, location.x2, location.y2, graph, TRUE);
    }
}
void Graphics::Draw(int inx, int iny) {

    if (visible) {
        DrawExtendGraph(location.x1 + inx, location.y1 + iny, location.x2 + inx, location.y2 + iny, graph, TRUE);
    }
}

void Graphics::SetScale(float in) {
    scale = in;
}

//　グラフィックを囲うように枠を表示する。
void Graphics::LightUp() {
    DrawBoxAA(location.x1 - 30, location.y1 - 30, location.x2 + 30, location.y2 + 30, GetColor(0, 255, 255), TRUE);
}

void Graphics::SetMovement(eMovementType movementType, eMoveType moveType, float x, float y,int flame) {
    switch (movementType) {
    case MOVEMENT_MOVE:
        delete movement[movementType];
        movement[movementType] = (Movement*) new MovementMove(this, moveType, x, y, flame);
        break;
    case MOVEMENT_MOVE_TO:
        delete movement[MOVEMENT_MOVE];
        movement[MOVEMENT_MOVE] = (Movement*) new MovementMove(this, moveType, x - location.x1, y - location.y1, flame);
        break;
    }
    
}

void Graphics::SetMovement(eMovementType movementType, eMoveType moveType, float time, int flame) {
    switch (movementType) { 
    case MOVEMENT_EXPAND:
        delete movement[MOVEMENT_EXPAND];
        // movement[MOVEMENT_EXPAND] = (Movement*) new MovementExpand(this, moveType, (location.x2 - location.x1) / 2 * (time - 1.f), (location.y2 - location.y1) / 2 * (time - 1.f), flame);
        movement[MOVEMENT_EXPAND] = (Movement*) new MovementExpand(this, moveType,  ((location.x2 - location.x1) / scale) * (time - scale) / 2,
                                                                                    ((location.y2 - location.y1) / scale) * (time - scale) / 2, flame);
        scale = time;
        break;
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
            if (movement[i]->GetFlame() == 0) {
                movement[i] = nullptr;
            }
        }
    }
}