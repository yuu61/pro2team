#pragma once
#include "Task.h"
#include "GameCgr.h"
#include "GameVar.h"

class GameScene : public Task
{
protected:
    GameCgr* gameCgr;
    GameVar* gameVar;

public:
    GameScene(GameCgr* changer,GameVar* gVar);
    virtual ~GameScene() {};
    virtual void Initialize() override {}        //初期化処理は実装してもしなくてもいい
    virtual void Finalize() override {};        //終了処理は実装してもしなくてもいい
    virtual void Update() override {};    //更新処理は必ず継承先で実装する
    virtual void Draw() override {};    //描画処理は必ず継承先で実装する
};

