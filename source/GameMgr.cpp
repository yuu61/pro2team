#include "GameMgr.hpp"
#include <DxLib.h>
#include "PlayerSelect.hpp"
#include "ItemSelect.hpp"
#include "RoulettePlay.hpp"
#include "Ending.hpp"

GameMgr::GameMgr(BaseCgr* changer) : BaseScene(changer),
	nextScene(GAME_NON) {

	gSStore[PLAYER_SELECT] = (GameScene*) new PlayerSelect((GameCgr*)this, gameVar);
	gSStore[ITEM_SELECT] = (GameScene*) new ItemSelect((GameCgr*)this, gameVar);
	gSStore[ROULETTE_PLAY] = (GameScene*) new RoulettePlay((GameCgr*)this,gameVar);
	gSStore[ENDING] = (GameScene*) new Ending((GameCgr*)this, gameVar);

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
		case ENDING:
			gameScene = gSStore[ENDING];
			break;
		case BACK:
			baseCgr->SceneChange(SCENE_MENU);
			break;
		case E_GAME:
		case GAME_NON:
			break;
		}

		nextScene = GAME_NON;
		gameScene->Initialize();
	}

	gameVar->Background().Update();
	gameScene->Update();
	
}

void GameMgr::Draw() {
	
	gameVar->Background().Draw();
	gameScene->Draw();
	DrawFormatStringToHandle(1920 - 300, 30, GetColor(255, 255, 255), gameVar->FontHandle(),
		_T("TURN %zu/%zu"), gameVar->Players().Turn(), gameVar->Players().EndTurn());
	
}
