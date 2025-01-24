#pragma once
#include "BaseCgr.hpp"
#include "BaseScene.hpp"

// BaseSceneを管理するためのクラス
class BaseMgr :public BaseCgr ,Task
{
    BaseScene* baseScene;
    eScene nextScene;
    
public:

    BaseMgr();

    // nextSceneを変更する関数
    void SceneChange(eScene changer) override;
    
    void Initialize() override;        //初期化処理は実装してもしなくてもいい
    void Finalize() override;        //終了処理は実装してもしなくてもいい
    void Update() override;    //更新処理は必ず継承先で実装する
    void Draw() override;    //描画処理は必ず継承先で実装する
    
    ~BaseMgr() {};
};

