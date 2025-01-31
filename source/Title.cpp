#include "..\header\Title.hpp"
#include "..\dxlib_for_visual_studio\DxLib.h"
#include "..\header\CatchInput.hpp"


Title::Title(BaseCgr* changer) :
	BaseScene(changer){
	button[0]->Click = [changer]() {changer->SceneChange(SCENE_GAME); };
	button[1]->Click = []() {DxLib_End(); return 0; };
}

void Title::Initialize() {
	titleZimaku->SetRepetate(MOVE_NORMAL, 0, 30, 60, 60 * 300);
	button[select]->Selected(true);
}

void Title::Update() {

	if (inputKey[KEY_INPUT_A] == 1) {
		ButtonControl(&select, -1, BUTTON_NUM, button);
	}
	else if (inputKey[KEY_INPUT_D] == 1) {
		ButtonControl(&select, 1, BUTTON_NUM, button);
	}
	
	button[select]->CheckLeft(inputKey[KEY_INPUT_S]);
	
	backGround->Update();
	titleZimaku->Update();

	for (int i = 0; i < 2; i++) {
		button[i]->Update();
	}
}

void Title::Draw() {
	backGround->Draw();
	titleZimaku->Draw();

	for (int i = 0; i < 2; i++) {
		button[i]->Draw();
	}

}