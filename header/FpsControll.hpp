#pragma once
#include "..\dxlib_for_visual_studio\DxLib.h"

// FPSの初期化、一番最初に行う
void FpsControll_Initialize();

//FPS制御
bool FpsControll_Update();

//FPS表示
void FpsControll_Draw();

//待機することでフレームレートを60にする関数。
void FpsControll_Wait();



