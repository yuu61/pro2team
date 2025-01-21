#include "..\header\ItemSelect.h"
#include "..\dxlib_for_visual_studio\DxLib.h"

ItemSelect::ItemSelect(GameCgr* changer, GameVar* gv) : GameScene(changer,gv)
{
	button[0]->Click = [this]() {gameCgr->SceneChange(PLAYER_SELECT); };
}

void ItemSelect::Initialize() {
	select = 0;

	for(int i = 0; i < ITEM_NUM; i++) {
		if (gameVar->player->GetItem(i) != nullptr) {
			button[i + 1] = (Button*) new Button(1, 0, 17 + (i + 1)* 384, 600, 0.35, 0.35, gameVar->player->GetItem(i)->GetGraph());
			                                 
			button[i + 1]->Click = [this, i]() {button[i + 1]->SetRepetate(MOVE_NORMAL, 50.f, 0.f, 6, 60);
												gameVar->player->GetItem(i)->Use(); };
		}
		else {
			button[i + 1] = nullptr; 
		}
	}

	button[0]->SetExpandTo(MOVE_SINE, 1.1f, 12);

	gameVar->backGround->SetExpandTo(MOVE_SINE, 2.3f, 45);
	gameVar->backGround->SetMoveTo(MOVE_SINE, -700.f,-200.f, 45);

	gameVar->player->SetMoveTo(MOVE_SINE, 400, 100, 45);
}
void ItemSelect::Finalize() {

}
void ItemSelect::Update() {

	if (gameVar->player->GetInputKey(KEY_LEFT) == 1) {
		button[select]->SetExpandTo(MOVE_SINE, 1.0f, 12);
		select--;
		if (select < 0) {
			for (int i = ITEM_NUM; i >= 0; i--) {
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
		if (select >= ITEM_NUM + 1 || button[select] == nullptr) {
			select = 0;
		}
		button[select]->SetExpandTo(MOVE_SINE, 1.1f, 12);
	}

	button[select]->CheckLeft(gameVar->player->GetInputKey(KEY_ENTER)) ;

	if (gameVar->player->GetInputKey(KEY_CANSEL) == 1) {
		gameCgr->SceneChange(PLAYER_SELECT);
	}


	button[0]->Update();

	for (int i = 1; i < 5; i++) {
		if (button[i] != nullptr) {
			button[i]->Update();
		}
	}

	gameVar->roulette->Update();
	arrow->Update();

	gameVar->player->Update();
}

void ItemSelect::Draw() {
	gameVar->player->Draw();
	gameVar->roulette->Draw();
	arrow->Draw();

	button[select]->LightUp();
	DrawFormatString(100, 150, GetColor(255, 255, 255), "%d %d %d %d %lf %lf", 
		button[select]->GetX(), button[select]->GetY(), button[select]->GetSizeX(), button[select]->GetSizeY(),
		button[select]->GetExtRateX(), button[select]->GetExtRateY());
	
	button[0]->Draw();

	for (int i = 1; i < 5; i++) {
		if (button[i] != nullptr) {
			button[i]->Draw();
		}
		else {

		}
	}

	DrawFormatStringToHandle(600, 1000, RGB(255, 255, 255), gameVar->fontHandle, "RETURN to \"%c\"  ENTER to \"%c\"  SELECT to \"%c\" \"%c\"",
		gameVar->keyCharPlayer[KEY_CANSEL],
		gameVar->keyCharPlayer[KEY_ENTER],
		gameVar->keyCharPlayer[KEY_RIGHT],
		gameVar->keyCharPlayer[KEY_LEFT]);

	DrawString(100, 50, "ItemSelect", RGB(255, 255, 255));
	
}