#pragma once
#include "BaseScene.h"
#include "GameCgr.h"
#include "GameScene.h"

// ゲームのシーンを管理するためのクラス
class GameMgr : public BaseScene , GameCgr 
{
private :
	GameScene* gSStore[E_GAME]; // ゲームのシーンを保存する。
	GameScene* gameScene;
	eGame nextScene;
	GameVar* gameVar; // グローバル変数代わり　将来的にはグローバル変数ヘッダーに変えたい

public :
	GameMgr(BaseCgr* changer);
	~GameMgr() {};
	
	// シーンの変更を依頼する関数
	void SceneChange(eGame changer) override;

	void Initialize()override;        //初期化処理は実装してもしなくてもいい
	void Finalize() override;        //終了処理は実装してもしなくてもいい
	void Update() override;    //更新処理は必ず継承先で実装する
	void Draw() override;    //描画処理は必ず継承先で実装する
};

