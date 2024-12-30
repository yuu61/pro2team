#pragma once

typedef enum _eGame{
	PLAYER_SELECT,
	ITEM_SELECT,
	ROULETTE_PLAY,
	E_GAME,
	GAME_NON,
	BACK
}eGame;

class GameCgr
{
public:
	virtual void SceneChange(eGame changer) = 0;
	virtual ~GameCgr() = 0;
};

