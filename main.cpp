#include "DxLib.h"
#include "FpsControll.h"
#include "constants.h"

// ケーキのデータ格納
int remain[8];

// プレイヤーのアイテムを格納
int playerItem[2][8] = { {0} };

// プレイヤーのHPを格納
int playerHP[2] = { 0 };

// プレイヤーの選択している要素を格納
int playerSelect = 0;

// 状態遷移
int status = 0;

// 使ったアイテムのIDを格納する
int itemUse = 0;


// グラフィックスデータを格納する構造体
typedef struct _Graphic {
	bool visible;				// 画像を表示するかどうか
	int Graph;					// 表示する画像のハンドルを格納
	int x;						// 左上の座標を格納
	int y;
	int xx;						//右下の座標を格納
	int yy;
	int event;					// 適応されるイベントの格納
	int flame;					// イベントのフレーム数の格納
}Graphic;


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	SetWaitVSyncFlag(FALSE);			// 垂直同期をオフにする（こうしない45fpsぐらいになる）

	if (DxLib_Init() == -1)			// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// グラフィックスの格納 
	Graphic graphic[G_NUM];

	// エフェクトの格納
	Graphic effect[E_NUM];


	FpsControll_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {



		// 操作部：変数の値をプレイヤーからの操作によって変える。
		switch (status) {
		case 1:					// 選択の操作を受け付ける。

			break;
		case 2:					// ルーレットの操作を受け付ける。

			break;
		default:				// 操作を受け付けない。

			break;
		}

		// 処理部：操作部で変えた変数を読み取り、適切に処理する。グラフィックス構造体を調整または生成する。
		if (itemUse) {
			;			switch (itemUse) {

			case 1:
				break;
			}


			itemUse = 0;
		}

		// 描画部：操作部、処理部で変えた変数を読み取り、適切に描画する

		// 背景など常に描画するもの

		for (int i = 0; i < G_NUM; i++) {
			if (graphic[i].visible) {

			}
		}

		// エフェクトなど、動的に配置されるもの。

		for (int i = 0; i < G_NUM; i++) {
			if (effect[i].visible) {

			}
		}


		// エスケープキーでゲームを終了する。
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			DxLib_End();
			return 0;			//正常な終了を通知
		}

		// FPSをコントロールする奴ら
		FpsControll_Wait();
		FpsControll_Update();
		FpsControll_Draw();
	}



	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return -1;					// 異常終了の通知
}
