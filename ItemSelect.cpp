#include "ItemSelect.h"
#include "DxLib.h"

ItemSelect::ItemSelect(GameCgr* changer, GameVar* gVar) : GameScene(changer, gVar)
{

}

void ItemSelect::Initialize() {

}
void ItemSelect::Finalize() {

}
void ItemSelect::Update() {



}
void ItemSelect::Draw() {
	DrawString(100, 100, "ItemSelect", RGB(255, 255, 255));
}