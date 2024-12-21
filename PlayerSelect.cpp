#include "PlayerSelect.h"
#include "DxLib.h"

PlayerSelect::PlayerSelect(GameCgr* changer,GameVar* gVar) : 
	GameScene(changer,gVar),
	select(0){
	button[GO_ITEM_SELECT] = (Button*) new Button(100, 0, 710, 540, 910, 640, LoadGraph("image\\backGround.png"));
	button[GO_ROULETTE_PLAY] = (Button*) new Button(1, 0, 710, 690, 910, 790, LoadGraph("image\\backGround.png"));
}

void PlayerSelect::Initialize() {

}
void PlayerSelect::Finalize() {

}
void PlayerSelect::Update() {

	

	if (button[GO_ITEM_SELECT]->CheckLeft() == PRESSED) {
		gameCgr->SceneChange(ITEM_SELECT);
	}

	if (button[GO_ROULETTE_PLAY]->CheckLeft() == PRESSED) {

	}

	button[GO_ITEM_SELECT]->Update();
	button[GO_ROULETTE_PLAY]->Update();

	//gameCgr->SceneChange(ITEM_SELECT);
}

void PlayerSelect::Draw() {
	//DrawString(100, 100, "PlayerSelect", RGB(255, 255, 255));

	
	if (button[GO_ITEM_SELECT]->DrawCheckLeft() == INVALID) {
		DrawString(100, 100, "INVALID", RGB(255, 255, 255));
	}
	if (button[GO_ITEM_SELECT]->DrawCheckLeft() == PRESSED) {
		DrawString(100, 100, "PRESSED", RGB(255, 255, 255));
	}
	if (button[GO_ITEM_SELECT]->DrawCheckLeft() == NONE) {
		DrawString(100, 100, "NONE", RGB(255, 255, 255));
	}
	if (button[GO_ITEM_SELECT]->DrawCheckLeft() == CHARGING) {
		DrawString(100, 100, "CHARGING", RGB(255, 255, 255));
	}

	if (button[GO_ROULETTE_PLAY]->DrawCheckLeft() == PRESSED) {

	}

	button[GO_ITEM_SELECT]->Draw();
	button[GO_ROULETTE_PLAY]->Draw();
}

