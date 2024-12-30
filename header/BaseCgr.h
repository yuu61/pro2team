#pragma once

typedef enum _eScene {
	SCENE_NON,
	SCENE_GAME,
	SCENE_MENU
} eScene;


class BaseCgr
{
public:
	virtual void SceneChange(eScene changer) = 0;
	virtual ~BaseCgr() = 0;
};

