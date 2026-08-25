#include "Ending.hpp"

Ending::Ending(GameCgr* changer, GameVar* gv) :
	GameScene(changer, gv){
}

void Ending::Initialize() {
	gameVar->RouletteWheel().SetExpandTo(MOVE_SINE, 1.f, 60);
	gameVar->RouletteWheel().SetRotate(MOVE_NORMAL, -360 * 10, 60 * 60);
	gameVar->Players().At(0).SetString("");
	gameVar->Players().At(1).SetString("");
}

void Ending::Finalize() {

}

void Ending::Update() {
	gameVar->RouletteWheel().Update();
	gameVar->Players().UpdateAll();

}

void Ending::Draw() 
{

	
	gameVar->Players().DrawAll();
	gameVar->RouletteWheel().Draw();

	DrawFormatStringToHandle(600, 600, GetColor(255, 255, 255), gameVar->FontHandle(), _T("%s"), str.c_str());
}
