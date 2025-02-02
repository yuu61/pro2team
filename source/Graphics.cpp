
#include "..\header\Graphics.hpp"
#include "..\header\MovementMove.hpp"
#include "..\header\MovementExpand.hpp"
#include "..\header\MovementRotate.hpp"
#include "..\header\MovementRepetate.hpp"

Graphics::Graphics() :
    Graphics(0, 0, 0, 0, -2) {
}

Graphics::Graphics(int g) :
    Graphics(0, 0, 0, 0, g) {
}

Graphics::Graphics(float x1, float y1, float cx, float cy, int g) :
    location{ x1,y1 },
    graph(g), 
    cExtRate{ cx, cy },
    movement{nullptr} {

    int fx{ 0 }, fy{ 0 };
    
    GetGraphSize(graph, &fx, &fy);
    size = { fx * cExtRate.x, fy * cExtRate.y };
    SetCnt();
}

void Graphics::Finalize() 
{
    for (int i = 0; i < MOVEMENT_TYPE_MAX; i++) {
        delete movement[i];
    }
}

void Graphics::SetVisible(bool in)
{
    visible = in;
}

void Graphics::SetGraph(int in) {
    graph = in;

    int fx{ 0 }, fy{ 0 };

    GetGraphSize(graph, &fx, &fy);
    size = { fx * cExtRate.x, fy * cExtRate.y };
    cnt = { fx * 0.5f, fy * 0.5f };
}

// 画像を表示する
void Graphics::Draw() {

    if (visible) {
        DrawRotaGraph3(location.x + cnt.x * cExtRate.x , location.y + cnt.y * cExtRate.y,
            cnt.x, cnt.y, 
            extRate.x * cExtRate.x , extRate.y * cExtRate.y,
            angle, graph, TRUE,
            turnX, turnY);
        DrawFormatStringToHandle(location.x + size.x/2 + strCnt , location.y + size.y / 3, // 座標がかなり適当
            strColor, strHandle, _T("%s"), str.c_str());
    }
}
void Graphics::Draw(int inx, int iny) {

    if (visible) {
        DrawRotaGraph3(location.x + cnt.x * cExtRate.x + inx, location.y + cnt.y * cExtRate.y + iny,
            cnt.x, cnt.y,
            extRate.x * cExtRate.x, extRate.y * cExtRate.y,
            angle, graph, TRUE,
            turnX, turnY);
        DrawFormatStringToHandle(location.x + size.x / 2 + strCnt + inx, location.y + size.y / 3 + iny, // 座標がかなり適当
            strColor, strHandle, _T("%s"), str.c_str());
    }
}

//　グラフィックを囲うように枠を表示する。
void Graphics::LightUp() {
    
    DrawBoxAA(
        location.x - 30 - gLoc.x  ,
        location.y - 30 - gLoc.y ,
        location.x + size.x + 30 - gLoc.x,
        location.y + size.y + 30 - gLoc.y, GetColor(0, 255, 255), TRUE);
        
    
}

void Graphics::SetMove( eMoveType moveType, float x, float y, int flame) {
        delete movement[MOVEMENT_MOVE];
        movement[MOVEMENT_MOVE] = (Movement*) new MovementMove(this, moveType, x, y, flame);
}

void Graphics::SetMoveTo(eMoveType moveType, float x, float y, int flame) {
    delete movement[MOVEMENT_MOVE];
    movement[MOVEMENT_MOVE] = (Movement*) new MovementMove(this, moveType, x - location.x , y - location.y, flame);
}

void Graphics::SetExpand(eMoveType moveType, float time, int flame) {
    delete movement[MOVEMENT_EXPAND];
    movement[MOVEMENT_EXPAND] = (Movement*) new MovementExpand(this, moveType, (time - 1) * extRate.x, (time - 1) * extRate.y,
        (size.x / extRate.x),
        (size.y / extRate.y),
        flame);
}

void Graphics::SetExpandTo(eMoveType moveType, float time, int flame) {
    delete movement[MOVEMENT_EXPAND];
    movement[MOVEMENT_EXPAND] = (Movement*) new MovementExpand(this, moveType, (time - extRate.x), (time - extRate.y),
        (size.x / extRate.x) ,
        (size.y / extRate.y) ,
        flame);

    /*
    movement[MOVEMENT_EXPAND] = (Movement*) new MovementExpand(this, moveType, (time * cExtRateX - extRateX), (time * cExtRateY - extRateY),
        (size.x / extRateX) * (time * cExtRateX - extRateX) / cExtRateX,
        (size.y / extRateY) * (time * cExtRateY - extRateY) / cExtRateY,
        flame);
        */
}



/*
void Graphics::SetMovement(eMovementType movementType, eMoveType moveType, float x, float y,int flame) {
    switch (movementType) {
    case MOVEMENT_MOVE_TO:
        delete movement[MOVEMENT_MOVE];
        movement[MOVEMENT_MOVE] = (Movement*) new MovementMove(this, moveType, x - location.x, y - location.y, flame);
        break;
    }
    
}
*/
/*
void Graphics::SetMovement(eMovementType movementType, eMoveType moveType, float time, int flame) {
    switch (movementType) { 
    case MOVEMENT_EXPAND:
        delete movement[MOVEMENT_EXPAND];
        // movement[MOVEMENT_EXPAND] = (Movement*) new MovementExpand(this, moveType, (location.sizeX - location.x) / 2 * (time - 1.f), (location.sizeY - location.y) / 2 * (time - 1.f), flame);
        movement[MOVEMENT_EXPAND] = (Movement*) new MovementExpand(this, moveType,  ((location.sizeX - location.x) / scale) * (time - scale) / 2,
                                                                                    ((location.sizeY - location.y) / scale) * (time - scale) / 2, flame);
        scale = time;
        break;
    }
}
*/


void Graphics::SetRotate(eMoveType moveType, float rota, int flame) {
    delete movement[MOVEMENT_ROTATE];
    movement[MOVEMENT_ROTATE] = (Movement*) new MovementRotate(this, moveType, rota, flame);
}

void Graphics::SetRotateTo(eMoveType moveType, float rota, int flame) {
    delete movement[MOVEMENT_ROTATE];
    movement[MOVEMENT_ROTATE] = (Movement*) new MovementRotate(this, moveType, rota - angle / degree, flame);
}

void Graphics::SetRepetate(eMoveType moveType, float x, float y, int time, int flame) {
    delete movement[MOVEMENT_REPETATE];
    movement[MOVEMENT_REPETATE] = (Movement*) new MovementRepetate(this, moveType, x ,y , time, flame);
}

void Graphics::Move(float x, float y) {
    location.x += x;
    location.y += y;
}

void Graphics::MoveGL(float x, float y) {
    gLoc.x += x;
    gLoc.y += y;
}

void Graphics::Expand(float x, float y, float ux, float uy) {
    extRate.x += x;
    extRate.y += y;
    size.x += ux;
    size.y += uy;

    //Move(-ux / 2 , -uy / 2);
    MoveGL(ux / 2,uy / 2);
}

void Graphics::Rotate(float rota) {
    angle += rota * degree;
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