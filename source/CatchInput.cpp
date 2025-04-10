#include "..\header\CatchInput.hpp"
#include "..\dxlib_for_visual_studio\DxLib.h"

// キーの入力状態を更新する

int inputKey[256]{ 0 };

InputMouse inputMouse{ 0,0,0,0 };

int UpdateKey() {
    char tmpKey[256]; // 現在のキーの入力状態を格納する
    GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
            inputKey[i]++;     // 加算
        }
        else {              // 押されていなければ
            inputKey[i] = 0;   // 0にする
        }
    }
    return 0;
}

int UpdateMouse() {
    
    GetMousePoint(&inputMouse.x, &inputMouse.y);
    
    if ((GetMouseInput() & MOUSE_INPUT_LEFT)) {
        inputMouse.left++;
    }
    else {
        inputMouse.left = 0;
    }

    if ((GetMouseInput() & MOUSE_INPUT_RIGHT)) {
        inputMouse.right++;
    }
    else {
        inputMouse.right = 0;
    }

    return 0;
}