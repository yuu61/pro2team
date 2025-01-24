#include "..\header\ItemBasket.hpp"

ItemBasket::ItemBasket(GameVarMgr* gameVar) :
	Item(gameVar, LoadGraph("image\\basket.png")) {

}

void ItemBasket::Use() {
	gameVarMgr->UseBasket();
}