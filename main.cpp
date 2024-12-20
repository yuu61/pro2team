#include "DxLib.h"
#include "BaseMgr.h"
#include "CatchInput.h"
#include "FpsControll.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    SetWaitVSyncFlag(FALSE),ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    

    SetGraphMode(1920, 1080, 32);

    BaseMgr baseMgr;
    baseMgr.Initialize();

    FpsControll_Initialize();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

        baseMgr.Update();  //�X�V
        baseMgr.Draw();    //�`��
        

        //�t���[�����[�g�\��
        FpsControll_Draw();
        // �t���[�����[�g����
        FpsControll_Update();
        // �t���[�����[�g���ҋ@
        FpsControll_Wait();
    }

    baseMgr.Finalize();

    DxLib_End(); // DX���C�u�����I������
    return 0;
}