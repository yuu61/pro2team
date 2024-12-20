#include "FpsControll.h"

static int mStartTime;      //����J�n����
static int mCount;          //�J�E���^
static float mFps;          //fps
static const int N = 60;  //���ς����T���v����
static const int FPS = 60;  //�ݒ肵��FPS

// FPS�̏������A��ԍŏ��ɍs��
void FpsControll_Initialize() {
	mStartTime = GetNowCount();
	mCount = 0;
	mFps = 0;
}

//FPS����
bool FpsControll_Update() {
	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

//FPS�\��
void FpsControll_Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
}

//�ҋ@���邱�ƂŃt���[�����[�g��60�ɂ���֐��B
void FpsControll_Wait() {
	int tookTime = GetNowCount() - mStartTime;  //������������
	int waitTime = mCount * 1000 / FPS - tookTime;  //�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);  //�ҋ@
	}
}

