#pragma once

typedef enum _eGame{
	PLAYER_SELECT,
	ITEM_SELECT,
	ROULETTE_PLAY,
	E_GAME,
	GAME_NON,
	BACK
}eGame;

// GameMgr��GameScene����̃V�[���ύX�̎w�����o�����߂̃N���X�B
class GameCgr
{
public:
	// �V�[���ύX���˗�����֐�
	virtual void SceneChange(eGame changer) = 0;
	virtual ~GameCgr() = 0;
};

