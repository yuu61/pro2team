#include "CatchInput.h"
#include "DxLib.h"

// �L�[�̓��͏�Ԃ��X�V����

int InputKey[256]{ 0 };

int gpUpdateKey() {
    char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            InputKey[i]++;     // ���Z
        }
        else {              // ������Ă��Ȃ����
            InputKey[i] = 0;   // 0�ɂ���
        }
    }
    return 0;
}