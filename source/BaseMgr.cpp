#include "..\header\BaseMgr.h"
#include "..\header\GameMgr.h"

BaseMgr::BaseMgr():
	nextScene(SCENE_NON) {
	baseScene = (BaseScene*) new GameMgr((BaseCgr*)this);
}

void BaseMgr::SceneChange(eScene Changer) {
	nextScene = Changer;
}

void BaseMgr::Initialize() {
	baseScene->Initialize();
}

void BaseMgr::Finalize() {
	baseScene->Finalize();
}

void BaseMgr::Update() {

	if (nextScene != SCENE_NON) {
		switch (nextScene)
		{
		case SCENE_GAME:
			baseScene = (BaseScene*) new GameMgr((BaseCgr*)this);
			break;
		case SCENE_MENU:
			baseScene = (BaseScene*) new GameMgr((BaseCgr*)this);
			break;
		}

		nextScene = SCENE_NON;
		baseScene->Initialize();
	}

	baseScene->Update();
}

void BaseMgr::Draw() {
	baseScene->Draw();
}