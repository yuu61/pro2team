#include "..\header\PlayerSelect.h"
#include "..\dxlib_for_visual_studio\DxLib.h"

PlayerSelect::PlayerSelect(GameCgr* changer,GameVar* gVar) : 
	GameScene(changer,gVar),
	select(0){
	button[ITEM] = Button(KEY_INPUT_S, 1, 710, 540, 910, 640, LoadGraph("image\\backGround.png"));
	button[ROULETTE] = Button(KEY_INPUT_S, 1, 710, 690, 910, 790, LoadGraph("image\\backGround.png"));
}

void PlayerSelect::Initialize() {

}
void PlayerSelect::Finalize() {

}
void PlayerSelect::Update() {

	

	if (button[ITEM].Check()) {
		
	}

	if (button[ROULETTE].Check()) {

	}

	button[ITEM].Update();
	button[ROULETTE].Update();

	//gameCgr->SceneChange(ITEM_SELECT);
}

void PlayerSelect::Draw() {
	//DrawString(100, 100, "PlayerSelect", RGB(255, 255, 255));

	
	if (button[ITEM].DrawCheck()) {
		DrawString(100, 100, "PlayerSelect", RGB(255, 255, 255));
	}

	if (button[ROULETTE].DrawCheck()) {

	}

	button[ITEM].Draw();
	button[ROULETTE].Draw();
}