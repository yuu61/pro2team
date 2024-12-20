#include "..\header\GameVar.h"
#include "..\dxlib_for_visual_studio\DxLib.h"

GameVar::GameVar() {
	//backGround = Graphics();
	backGround.SetGraph("image\\backGround.png");
	backGround.SetLocation(0, 0, 1920, 1080);
}

