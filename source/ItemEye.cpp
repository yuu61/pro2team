#include "../header/ItemEye.h"
#include "..\dxlib_for_visual_studio\DxLib.h"

ItemEye::ItemEye(GameVarMgr* gameVar):
	Item(gameVar, LoadGraph("image\\eye.png")) {

}

void ItemEye::Use() {

}