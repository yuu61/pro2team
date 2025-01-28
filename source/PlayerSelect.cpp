#include "../header/PlayerSelect.hpp"
#include "../header/CatchInput.hpp"
#include "../dxlib_for_visual_studio/DxLib.h"
#include "../header/GameVar.hpp"


const int BUTTON_NUM{ 2 };

PlayerSelect::PlayerSelect(GameCgr* changer,GameVar* gv) :
	GameScene(changer,gv),
	select(0){
	button[GO_ITEM_SELECT]->Click = [changer]() {changer->SceneChange(ITEM_SELECT); };
	button[GO_ROULETTE_PLAY]->Click = [changer]() {changer->SceneChange(ROULETTE_PLAY); };

	/*
	button[GO_ROULETTE_PLAY]->Click = [this]() {
		button[GO_ROULETTE_PLAY]->SetExpandTo(MOVE_SINE, 2.f, 60);
		int sum{ 0 };
		for (int i = 0; i < 10; i++) {
			sum += i;
		}
		button[GO_ROULETTE_PLAY]->SetRotateTo(MOVE_SINE, sum, 60);
	};
	*/

	// ‚Þ‚è‚â‚è�‰ŠúˆÊ’u‚ð�Ý’è
	gameVar->roulette->SetExpandTo(MOVE_SINE, 0.5f, 45);
	gameVar->roulette->Graphics::SetMoveTo(MOVE_SINE, 1920 - 900, 30, 45);
	gameVar->roulette->SetMoveTo(MOVE_SINE, -250.f, -250.f, 45);

	//gameVar->backGround->SetMoveTo(MOVE_SINE, 0.f, 0.f, 45);
	//gameVar->backGround->SetExpandTo(MOVE_SINE, 1.5f, 45);

}

void PlayerSelect::Initialize() {
	gameVar->roulette->SetExpandTo(MOVE_SINE, 0.5f, 45);
	gameVar->roulette->Graphics::SetMoveTo(MOVE_SINE, 1920 - 900, 30, 45);
	gameVar->roulette->SetMoveTo(MOVE_SINE, -250.f, -250.f, 45);
	
	gameVar->backGround->SetMoveTo(MOVE_SINE, 0.f, 0.f, 45);
	gameVar->backGround->SetExpandTo(MOVE_SINE, 1.5f, 45);


	select = 0;
	button[select]->SetExpandTo(MOVE_SINE, 1.1f, 12);

	gameVar->playerStrawberry->SetMoveTo(MOVE_SINE, 500, 0, 45);
	gameVar->opponentStrawberry->SetMoveTo(MOVE_SINE, 100, 0, 45);

	gameVar->player->SetMoveTo(MOVE_SINE, 400, 300, 45);
	gameVar->opponent->SetMoveTo(MOVE_SINE, 0, 400, 45);

}

void PlayerSelect::Finalize() {

}

void PlayerSelect::Update() {

	if (gameVar->player->GetInputKey(KEY_LEFT) == 1) {
		button[select]->SetExpandTo(MOVE_SINE, 1.0f, 12);
		select--;
		if (select < 0) {
			for (int i = BUTTON_NUM - 1 ; i >= 0; i--) {
				if (button[i] != nullptr) {
					select = i;
					break;
				}
			}
		}
		button[select]->SetExpandTo(MOVE_SINE, 1.1f, 12);
	}
	if (gameVar->player->GetInputKey(KEY_RIGHT) == 1) {
		button[select]->SetExpandTo(MOVE_SINE, 1.0f, 12);
		select++;
		if (select >= BUTTON_NUM || button[select] == nullptr) {
			select = 0;
		}
		button[select]->SetExpandTo(MOVE_SINE, 1.1f, 12);
	}

	button[select]->CheckLeft(gameVar->player->GetInputKey(KEY_ENTER));

	for (int i = 0; i < BUTTON_NUM; i++) {
		if (button[i] != nullptr) {
			button[i]->Update();
		}
	}

	gameVar->roulette->Update();

	for (int i = 0; i < 2; i++) {
		gameVar->strawberry[i]->Update();
		gameVar->playerStore[i]->Update();
	}

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


	button[select]->LightUp();

	gameVar->roulette->Draw();
	button[GO_ITEM_SELECT]->Draw();
	button[GO_ROULETTE_PLAY]->Draw();

	
	DrawString(100, 50, "PlayerSelect", RGB(255, 255, 255));
	

	DrawFormatString(100, 150, GetColor(255, 255, 255), "%d %d\n%d %d\n%lf %lf",
		button[GO_ROULETTE_PLAY]->GetX(), button[GO_ROULETTE_PLAY]->GetY(), button[GO_ROULETTE_PLAY]->GetSizeX(), button[GO_ROULETTE_PLAY]->GetSizeY(),
		button[GO_ROULETTE_PLAY]->GetExtRateX(), button[GO_ROULETTE_PLAY]->GetExtRateY());
	
	for (int i = 0; i < 2; i++) {
		gameVar->strawberry[i]->Draw();
		gameVar->playerStore[i]->Draw();
	}

	DrawFormatStringToHandle(1000, 1000, RGB(255, 255, 255), gameVar->fontHandle, "ENTER to \"%c\"  SELECT to \"%c\" \"%c\"",
		gameVar->keyCharPlayer[KEY_ENTER],
		gameVar->keyCharPlayer[KEY_RIGHT],
		gameVar->keyCharPlayer[KEY_LEFT]);
}

