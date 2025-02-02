#include "..\header\ItemClock.hpp"

ItemClock::ItemClock(GameVarMgr* gameVar) :
	Item(gameVar, LoadGraph(_T("image\\clock.png"))) {

}

void ItemClock::Use() {
	
}