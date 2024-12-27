#include "PlayerSelect.h"
#include "CatchInput.h"
#include "DxLib.h"
#include "GameVar.h"


PlayerSelect::PlayerSelect(GameCgr* changer,GameVar* gVar) : 
	GameScene(changer,gVar),
	select(0){
}

void PlayerSelect::Initialize() {

}
void PlayerSelect::Finalize() {

}
void PlayerSelect::Update() {

	
	if (button[GO_ITEM_SELECT]->CheckLeft(gameVar->player->GetInputKey(KEY_CANSEL)) == PRESSED) {
		gameCgr->SceneChange(ITEM_SELECT);
	}
	

	

	if (button[GO_ROULETTE_PLAY]->CheckLeft(gameVar->player->GetInputKey(KEY_ENTER)) == PRESSED) {
		button[GO_ROULETTE_PLAY]->SetMovement(MOVEMENT_EXPAND, MOVE_SINE, 2, 120);
	}

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

