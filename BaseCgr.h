#pragma once

typedef enum _eScene {
	SCENE_NON,
	SCENE_GAME,
	SCENE_MENU
} eScene;

// baseScene����BaseMgr�ɃV�[���̕ύX�̎w�����o�����߂̃N���X
class BaseCgr
{
public:
	// �V�[����ς��邽�߂̊֐�
	virtual void SceneChange(eScene changer) = 0;
	virtual ~BaseCgr() = 0;
};

