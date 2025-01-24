#include "..\header\Ending.hpp"

Ending::Ending(GameCgr* changer, GameVar* gv) :
	GameScene(changer, gv){
}

void Ending::Initialize() {
	gameVar->roulette->SetExpandTo(MOVE_SINE, 1.f, 60);
	gameVar->roulette->SetRotate(MOVE_NORMAL, -360 * 10, 60 * 60);
	gameVar->playerStore[0]->SetString("");
	gameVar->playerStore[1]->SetString("");
}

void Ending::Finalize() {

}

void Ending::Update() {
	gameVar->roulette->Update();
	for (int i = 0; i < 2; i++) {
		gameVar->playerStore[i]->Update();
		gameVar->strawberry[i]->Update();
	}

}

void Ending::Draw() 
{

	
	for (int i = 0; i < 2; i++) {
		gameVar->playerStore[i]->Draw();
		gameVar->strawberry[i]->Draw();
	}
	gameVar->roulette->Draw();

	DrawFormatStringToHandle(600, 600, GetColor(255, 255, 255), gameVar->fontHandle, "%s", str.c_str());
}