#pragma once

typedef enum _eScene {
	SCENE_NON,
	SCENE_GAME,
	SCENE_MENU
} eScene;

// baseSceneからBaseMgrにシーンの変更の指示を出すためのクラス
class BaseCgr
{
public:
	// シーンを変えるための関数
	virtual void SceneChange(eScene changer) = 0;
	virtual ~BaseCgr() = 0;
};

