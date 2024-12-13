#include "DxLib.h"
#include "My_Check_Hit_Key.h"

int preKey = 0;

int MyCheckHitKey(int keycode) {

	if (preKey == keycode) {
		return -1;
	}

	preKey = keycode;

	return CheckHitKey(keycode);

}