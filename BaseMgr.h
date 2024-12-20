#pragma once
#include "Task.h"
#include "BaseCgr.h"
#include "BaseScene.h"


class BaseMgr :public BaseCgr ,Task
{
    BaseScene* baseScene;
    eScene nextScene;
    
public:

    BaseMgr();

    void SceneChange(eScene changer) override;

    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
    
    ~BaseMgr() {};
};

