#include "../header/ItemEye.hpp"
#include "..\dxlib_for_visual_studio\DxLib.h"

ItemEye::ItemEye(GameVarMgr* gameVar):
	Item(gameVar, LoadGraph(_T("image\\eye.png"))) {

}

void ItemEye::Use() {

}