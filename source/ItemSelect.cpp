#include "..\header\ItemSelect.h"
#include "..\dxlib_for_visual_studio\DxLib.h"

ItemSelect::ItemSelect(GameCgr* changer, GameVar* gVar) : GameScene(changer, gVar)
{

}

void ItemSelect::Initialize() {
	select = 0;

	button[0] = new Button(1, 0, 17, 600, 367, 950, gameVar->player->GetItem(0)->GetGraph());
	button[0]->Click = [this]() {gameCgr->SceneChange(PLAYER_SELECT); };

	for(int i = 0; i < ITEM_NUM; i++) {
		if (gameVar->player->GetItem(i) != nullptr) {
			button[i + 1] = (Button*) new ButtonCharge(45, 0, 17 + (i + 1)* 384, 600, 367 + (i + 1) * 384, 950, gameVar->player->GetItem(i)->GetGraph());
			button[i + 1]->Click = [this]() {gameCgr->SceneChange(PLAYER_SELECT); };
		}
		else {
			button[i + 1] = nullptr;
		}
	}

	button[0]->SetMovement(MOVEMENT_EXPAND, MOVE_SINE, 1.1f, 6);
}
void ItemSelect::Finalize() {

}
void ItemSelect::Update() {

	if (gameVar->player->GetInputKey(KEY_LEFT) == 1) {
		button[select]->SetMovement(MOVEMENT_EXPAND, MOVE_SINE, 1.0f, 6);
		select--;
		if (select < 0) {
			for (int i = ITEM_NUM; i >= 0; i--) {
				if (button[i] != nullptr) {
					select = i;
					break;
				}
			}
		}
		button[select]->SetMovement(MOVEMENT_EXPAND, MOVE_SINE, 10.1f, 6);
	}
	if (gameVar->player->GetInputKey(KEY_RIGHT) == 1) {
		button[select]->SetMovement(MOVEMENT_EXPAND, MOVE_SINE, 1.0f, 6);
		select++;
		if (select > ITEM_NUM || button[select] == nullptr) {
			select = 0;
		}
		button[select]->SetMovement(MOVEMENT_EXPAND, MOVE_SINE, 1.1f, 6);
	}


	button[select]->CheckLeft(gameVar->player->GetInputKey(KEY_ENTER)) ;

	button[0]->Update();

	for (int i = 1; i < 5; i++) {
		if (button[i] != nullptr) {
			button[i]->Update();
		}
	}
}

void ItemSelect::Draw() {

	DrawString(100, 100, "ItemSelect", RGB(255, 255, 255));

	button[select]->LightUp();
	
	button[0]->Draw();

	for (int i = 1; i < 5; i++) {
		if (button[i] != nullptr) {
			button[i]->Draw();
		}
		else {

		}
	}
	
}