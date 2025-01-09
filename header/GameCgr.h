#pragma once

typedef enum _eGame{
	PLAYER_SELECT,
	ITEM_SELECT,
	ROULETTE_PLAY,
	E_GAME,
	GAME_NON,
	BACK
}eGame;

// GameMgrにGameSceneからのシーン変更の指示を出すためのクラス。
class GameCgr
{
public:
	// シーン変更を依頼する関数
	virtual void SceneChange(eGame changer) = 0;
	virtual ~GameCgr() = 0;
};

