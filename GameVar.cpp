#include "GameVar.h"
#include "Dxlib.h"

GameVar::GameVar() {
	//backGround = Graphics();
	backGround.SetGraph("image\\backGround.png");
	backGround.SetLocation(0, 0, 1920, 1080);
}

