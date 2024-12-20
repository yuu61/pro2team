#include "CatchInput.h"
#include "DxLib.h"

// キーの入力状態を更新する

int InputKey[256]{ 0 };

int gpUpdateKey() {
    char tmpKey[256]; // 現在のキーの入力状態を格納する
    GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
            InputKey[i]++;     // 加算
        }
        else {              // 押されていなければ
            InputKey[i] = 0;   // 0にする
        }
    }
    return 0;
}