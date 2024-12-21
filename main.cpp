#include "DxLib.h"
#include "BaseMgr.h"
#include "CatchInput.h"
#include "FpsControll.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    SetWaitVSyncFlag(FALSE),ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定

    

    SetGraphMode(1920, 1080, 32);

    BaseMgr baseMgr;
    baseMgr.Initialize();

    FpsControll_Initialize();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && UpdateKey() == 0 && UpdateMouse() == 0) {//画面更新 & メッセージ処理 & 画面消去 & キー入力 & マウス入力

        baseMgr.Update();  //更新
        baseMgr.Draw();    //描画
        

        //フレームレート表示
        FpsControll_Draw();
        // フレームレート制御
        FpsControll_Update();
        // フレームレート分待機
        FpsControll_Wait();
    }

    baseMgr.Finalize();

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}