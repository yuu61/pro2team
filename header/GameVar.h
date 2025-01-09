#pragma once
#include "Graphics.h"
#include "Player.h"
#include "DxLib.h"

// �Q�[���̃V�[���Ŏg����O���[�o���ϐ�����̃N���X�B�O���[�o���ϐ��w�b�_�[�ɕς������B
class GameVar
{
private:
	// �w�i�摜
	Graphics* backGround{ new Graphics(0,0,1920,1080,LoadGraph("image\\backGround.png")) };

public:
	GameVar();
	~GameVar() {};
	Graphics* GetBackGround() { return backGround; }
	// �v���C���[��ۑ�����B
	Player* playerStore[2]{ new Player(KEY_INPUT_S,KEY_INPUT_W,KEY_INPUT_A,KEY_INPUT_D),new Player(KEY_INPUT_K ,KEY_INPUT_I,KEY_INPUT_J,KEY_INPUT_L) };
	// ���݂̃��C���v���C���[
	Player* player{ playerStore[0] };

	
};

