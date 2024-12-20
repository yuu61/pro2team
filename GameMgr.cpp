#include "GameMgr.h"
#include "DxLib.h"
#include "PlayerSelect.h"
#include "ItemSelect.h"
#include "RoulettePlay.h"

GameMgr::GameMgr(BaseCgr* changer) : BaseScene(changer),
	nextScene(GAME_NON) {
	gameVar = new GameVar();

	gSStore[PLAYER_SELECT] = (GameScene*) new PlayerSelect((GameCgr*)this, gameVar);
	gSStore[ITEM_SELECT] = (GameScene*) new ItemSelect((GameCgr*)this, gameVar);
	gSStore[ROULETTE_PLAY] = (GameScene*) new RoulettePlay((GameCgr*)this, gameVar);

	gameScene = gSStore[PLAYER_SELECT];
	
}

void GameMgr::SceneChange(eGame Changer) {
	nextScene = Changer;
}

void GameMgr::Initialize() {
	gameScene->Initialize();
}
void GameMgr::Finalize() 
{

}

void GameMgr::Update() {
	
	if (nextScene != GAME_NON) {
		switch (nextScene)
		{
		case PLAYER_SELECT:
			gameScene = gSStore[PLAYER_SELECT];
			break;
		case ITEM_SELECT:
			gameScene = gSStore[ITEM_SELECT];
			break;
		case ROULETTE_PLAY:
			gameScene = gSStore[ROULETTE_PLAY];
			break;
		case BACK:
			
			break;
		}

		nextScene = GAME_NON;
		gameScene->Initialize();
	}

	gameScene->Update();
	
}

void GameMgr::Draw() {
	gameVar->GetBackGround()->Draw();
	gameScene->Draw();
}