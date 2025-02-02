#include "..\header\ItemBasket.hpp"

ItemBasket::ItemBasket(GameVarMgr* gameVar) :
	Item(gameVar, LoadGraph(_T("image\\basket.png"))) {

}

void ItemBasket::Use() {
	gameVarMgr->UseBasket();
}