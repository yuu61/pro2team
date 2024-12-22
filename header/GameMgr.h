#pragma once
#include ".\BaseScene.h"
#include ".\GameCgr.h"
#include ".\GameScene.h"


class GameMgr : public BaseScene , GameCgr 
{
protected :
	GameScene* gSStore[10]; // 適当に数を入れてる
	GameScene* gameScene;
	eGame nextScene;
	GameVar* gameVar;

public :
	GameMgr(BaseCgr* changer);
	~GameMgr() {};
	
	void SceneChange(eGame changer) override;

	void Initialize()override;        //初期化処理は実装してもしなくてもいい
	void Finalize() override;        //終了処理は実装してもしなくてもいい
	void Update() override;    //更新処理は必ず継承先で実装する
	void Draw() override;    //描画処理は必ず継承先で実装する
};


