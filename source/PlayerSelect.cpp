#include "..\header\PlayerSelect.h"
#include "..\header\CatchInput.h"
#include "..\dxlib_for_visual_studio\DxLib.h"
#include "..\header\GameVar.h"


PlayerSelect::PlayerSelect(GameCgr* changer,GameVar* gVar) : 
	GameScene(changer,gVar),
	select(0){
	button[GO_ITEM_SELECT]->Click = [changer]() {changer->SceneChange(ITEM_SELECT); };
	//button[GO_ROULETTE_PLAY]->Click = [changer]() {changer->SceneChange(ROULETTE_PLAY); };
}

void PlayerSelect::Initialize() {

	button[GO_ROULETTE_PLAY]->Click = [this]() {button[GO_ROULETTE_PLAY]->SetMovement(MOVEMENT_EXPAND, MOVE_SINE, 2, 60); };
}
void PlayerSelect::Finalize() {

}
void PlayerSelect::Update() {

	button[GO_ITEM_SELECT]->CheckLeft(gameVar->player->GetInputKey(KEY_CANSEL));
	
	button[GO_ROULETTE_PLAY]->CheckLeft(gameVar->player->GetInputKey(KEY_ENTER));


	button[GO_ITEM_SELECT]->Update();
	button[GO_ROULETTE_PLAY]->Update();
}

void PlayerSelect::Draw() {
	//DrawString(100, 100, "PlayerSelect", RGB(255, 255, 255));

	
	if (button[GO_ITEM_SELECT]->GetStatusLeft() == INVALID) {
		DrawString(100, 100, "INVALID", RGB(255, 255, 255));
	}
	if (button[GO_ITEM_SELECT]->GetStatusLeft() == PRESSED) {
		DrawString(100, 100, "PRESSED", RGB(255, 255, 255));
	}
	if (button[GO_ITEM_SELECT]->GetStatusLeft() == NONE) {
		DrawString(100, 100, "NONE", RGB(255, 255, 255));
	}
	if (button[GO_ITEM_SELECT]->GetStatusLeft() == CHARGING) {
		DrawString(100, 100, "CHARGING", RGB(255, 255, 255));
	}
	if (button[GO_ITEM_SELECT]->GetStatusLeft() == CHARGED) {
		DrawString(100, 100, "CHARGED", RGB(255, 255, 255));
	}

	button[GO_ITEM_SELECT]->Draw();
	button[GO_ROULETTE_PLAY]->Draw();
}

