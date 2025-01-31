#include "..\header\BaseMgr.hpp"
#include "..\header\GameMgr.hpp"
#include "..\header\Title.hpp"

BaseMgr::BaseMgr():
	nextScene(SCENE_NON) {
	baseSceneStore[0] = (BaseScene*) new Title((BaseCgr*)this);
	baseSceneStore[1] = (BaseScene*) new GameMgr((BaseCgr*)this);
	baseScene = baseSceneStore[0];
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
			baseScene = baseSceneStore[1];
			break;
		case SCENE_MENU:
			baseScene = baseSceneStore[0];
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