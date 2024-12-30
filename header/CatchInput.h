#pragma once

//

typedef struct _InputMouse {
	int x;
	int y;
	int left; //押されている時間
	int right; //押されている時間
}InputMouse;



extern int inputKey[256]; // キーが押されているフレーム数を格納する

extern InputMouse inputMouse; //　マウスの情報を格納する

// キーの入力状態を更新する
extern int UpdateKey();// 現在のキーの入力状態を格納する

extern int UpdateMouse();// 現在のキーの入力状態を格納する
