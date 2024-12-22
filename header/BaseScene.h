#pragma once
#include ".\Task.h"
#include ".\BaseCgr.h"

class BaseScene : public Task
{
protected:
    BaseCgr* baseCgr;

public:
    BaseScene(BaseCgr* changer) ;
    virtual ~BaseScene() {};
	virtual void Initialize() override {}        //初期化処理は実装してもしなくてもいい
    virtual void Finalize() override {};        //終了処理は実装してもしなくてもいい
    virtual void Update() override {};    //更新処理は必ず継承先で実装する
    virtual void Draw() override {};    //描画処理は必ず継承先で実装する
};

