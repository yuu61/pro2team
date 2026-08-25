#include "ItemEye.hpp"
#include <DxLib.h>

ItemEye::ItemEye(GameVarMgr* gameVar):
	Item(gameVar, LoadGraph(_T("image\\eye.png"))) {

}

void ItemEye::Use() {

}
