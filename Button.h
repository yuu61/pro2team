#pragma once
#include "Graphics.h"

typedef enum _eButtonStatus {
	NONE,
	CHARGING,
	PRESSED
}eButtonStatus;

class Button : Graphics
{
private:
	int status;
	int checkKey;
	int checkTime;

public:
	Button();
	Button(int checkKey,int checkTime, int x, int xx, int y, int yy, int graph);
	~Button() {};

	void SetKey(int k) { checkKey = k; }
	bool Check();
	bool DrawCheck();

	void Initialize() override;        //初期化処理は実装してもしなくてもいい
	void Finalize() override;        //終了処理は実装してもしなくてもいい
	void Update();    //更新処理は必ず継承先で実装する
	void Draw() ;    //描画処理は必ず継承先で実装する
};

