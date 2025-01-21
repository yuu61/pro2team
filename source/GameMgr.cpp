#include "..\header\GameMgr.h"
#include "..\dxlib_for_visual_studio\DxLib.h"
#include "..\header\PlayerSelect.h"
#include "..\header\ItemSelect.h"
#include "..\header\RoulettePlay.h"
#include "..\header\Ending.h"

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
			
			break;
		}

		nextScene = GAME_NON;
		gameScene->Initialize();
	}

	gameVar->backGround->Update();
	gameScene->Update();
	
}

void GameMgr::Draw() {
	
	gameVar->backGround->Draw();
	gameScene->Draw();
	DrawFormatStringToHandle(1920 - 300, 30, GetColor(255, 255, 255),gameVar->fontHandle, "TURN %d/%d", gameVar->turn, gameVar->endTurn);
	
}