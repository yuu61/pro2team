#include "DxLib.h"
#include "FpsControll.h"
#include "constants.h"

// ケーキのデータ格納
int remain[8];

// プレイヤーのアイテムを格納
int playerItem[2][8] = { {0} };

// プレイヤーのHPを格納
int playerPoints[2] = { 0 };

// プレイヤーの選択している要素を格納
int playerSelect = 0;

// 状態遷移
int status = 0;

// 使ったアイテムのIDを格納する
int itemUse = 0;

int turnPlayer = 0;

bool turnEnd = false;

int rulette;

// グラフィックスデータを格納する構造体
typedef struct _Graphic {
	bool visible;				// 画像を表示するかどうか
	int graph;					// 表示する画像のハンドルを格納
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

	// fpsの初期化
	FpsControll_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {



		// 操作部：変数の値をプレイヤーからの操作によって変える。

		switch (status) {
		case 1:					// アイテム選択の操作を受け付ける。

			// アイテムを選択する操作
			if (CheckHitKey(KEY_INPUT_A)) {
				playerSelect -= 1;
			}
			if (CheckHitKey(KEY_INPUT_D)) {
				playerSelect += 1;
			}

			// アイテムを決定する操作
			if (CheckHitKey(KEY_INPUT_S)) {
				itemUse = playerItem[turnPlayer][playerSelect];
			}

			break;
		case 2:					// ルーレットの操作を受け付ける。
			if (CheckHitKey(KEY_INPUT_S)) {

			}
			break;
		default:				// 操作を受け付けない。

			break;
		}

		// 処理部：操作部で変えた変数を読み取り、適切に処理する。グラフィックス構造体を調整または生成する。
		if (itemUse) {
			;			switch (itemUse) {

			case 1:
				playerPoints[turnPlayer] += 1;
				graphic[1]; // これがポイントのグラフィックスと仮定する
				graphic[1].event = 1;
				break;
			}


			itemUse = 0;
		}

		// 描画部：操作部、処理部で変えた変数を読み取り、適切に描画する

		// 背景など常に描画するもの

		for (int i = 0; i < G_NUM; i++) {
			if (graphic[i].visible) {

				switch (graphic[i].event) {
				case 1:
					// 一定時間表示を大きくする
					if (graphic[i].flame == 0) {
						graphic[i].flame = 60;
						graphic[i].x = graphic[i].x + 60;
					}
					else {

					}
					graphic[i].flame--;
					if (graphic[i].flame == 0) {
						graphic[i].event = 0;
					}
					break;
				default:
					break;
				}
				// 画像を表示する
				DrawExtendGraph(graphic[i].x, graphic[i].y, graphic[i].xx, graphic[i].yy, graphic[i].graph, TRUE);
			}
		}

		// エフェクトなど、動的に配置されるもの。

		for (int i = 0; i < G_NUM; i++) {
			if (effect[i].visible) {

			}
		}

		// turnEndを踏んだら、プレイヤーが切り替わる。
		if (turnEnd) {

			switch (turnPlayer) {
			case 0:
				turnPlayer = 1;
				break;

			case 1:
				turnPlayer = 0;
				break;
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
