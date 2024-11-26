#include <stdio.h>
#include "DxLib.h"
#include "FpsControll.h"
#include "constants.h"

// ケーキのデータ格納
Cake remain[8];

// プレイヤーのアイテムを格納
int playerItem[2][ITEM_NUM] = { {0} };

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

bool toBeBigCake = FALSE;

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

typedef struct _cake {
	int point;					// ケーキのイチゴの数
	int item;					// ケーキの中に含まれてるアイテム。（０なら何も入っていない）
	int locationX;				// 座標
	int locationY;
	int radian;					// 角度
}Cake;

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

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
	{
		// 操作部：変数の値をプレイヤーからの操作によって変える。

		switch (status) 
		{
			case 1:	
				// アイテム選択の操作を受け付ける。
				// アイテムを選択する操作
				if (CheckHitKey(KEY_INPUT_A)) {
					playerSelect -= 1;
				}
				if (CheckHitKey(KEY_INPUT_D)) {
					playerSelect += 1;
				}

				// アイテムの選択が一周するように（のちにルーレットを選択する手段を確保する）
				switch (playerSelect)
				{
				case 8:playerSelect = 0; break;//playerSelect > ITEM_NUM - 1 ７を越えたつまり8　呼び出した関数で触る場合はswitchを削除してifのコメントアウトを解除
				default:playerSelect = ITEM_NUM - 1;break;
				}
				/*
				if (playerSelect < 0) {
					playerSelect = ITEM_NUM - 1;
				}
				else if (playerSelect > ITEM_NUM - 1) {
					playerSelect = 0;
				}
				*/

				// アイテムを決定する操作
				if (CheckHitKey(KEY_INPUT_S)) {
					itemUse = playerItem[turnPlayer][playerSelect];
				}
				else if (CheckHitKey(KEY_INPUT_W)) {			// ルーレット画面へ移動する操作（条件は仮置き）
					status = 2;
					toBeBigCake = TRUE;
				}
				break;

			case 2:					// ルーレットの操作を受け付ける。
				if (CheckHitKey(KEY_INPUT_S))
				{
					rulette = TRUE;		// ルーレットを開始する操作。
					status = 0;			// 暫く操作を受け付けない。（要改修）
				}

				break;

			//default:break;冗長なためコメントアウト	// 操作を受け付けない。
		}

		// 処理部：操作部で変えた変数を読み取り、適切に処理する。グラフィックス構造体を調整または生成する。
		if (itemUse) {

			switch (itemUse) 
			{
			case 1:			// ポイントを増やす効果
				playerPoints[turnPlayer] += 1;
				graphic[1]; // これがポイントのグラフィックスと仮定する
				graphic[1].event = 1;
				break;
			}

			itemUse = 0;
		}

		

		// ケーキの回転中の描画のための、変数の調整（考え中）
		if (rulette) {
			//ケーキの描画を考えてフレームを管理する
			static int cakeFlame = 0;
			cakeFlame++;
			for (int i = 0; i < CAKE_NUM; i++) {
				remain[i].locationX;		//	適切に値を変更したい
				remain[i].locationY;
				remain[i].radian;
			}
			if (cakeFlame >= 360) {
				cakeFlame = 0;
			}			
		}



		// 描画部：操作部、処理部で変えた変数を読み取り、適切に描画する

		// 背景など常に描画するもの

		for (int i = 0; i < G_NUM; i++)
		{
			if (graphic[i].visible) 
			{
				switch (graphic[i].event) 
				{
				case 1:
					// 一定時間表示を大きくする
					if (graphic[i].flame == 0)
					{
						graphic[i].flame = 60;
						graphic[i].x = graphic[i].x - 60;
						graphic[i].y = graphic[i].y - 60;
						graphic[i].xx = graphic[i].xx + 60;
						graphic[i].yy = graphic[i].yy + 60;
					}

					graphic[i].flame--;

					if (graphic[i].flame == 0)
					{
						
						graphic[i].x = graphic[i].x + 60;			// 一定時間経過後の処理
						graphic[i].y = graphic[i].y + 60;
						graphic[i].xx = graphic[i].xx - 60;
						graphic[i].yy = graphic[i].yy - 60;
						
						graphic[i].event = 0;
					}
					break;
				}
				// 画像を表示する
				DrawExtendGraph(graphic[i].x, graphic[i].y, graphic[i].xx, graphic[i].yy, graphic[i].graph, TRUE);
			}
		}

		//ケーキを大きくする描画
		if (toBeBigCake) {
			static int cakeScale = 0;
		}


		for (int i = 0; i < CAKE_NUM; i++) {

		}

		// エフェクトなど、動的に配置されるもの。

		for (int i = 0; i < G_NUM; i++) {
			if (effect[i].visible) {

			}
		}

		// turnEndを踏んだら、プレイヤーが切り替わる。
		if (turnEnd) {

			switch (turnPlayer)
			{
			case 0:turnPlayer = 1; break;
			case 1:turnPlayer = 0; break;
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


		DxLib_End();				// ＤＸライブラリ使用の終了処理
		return -1;					// 異常終了の通知
	}
}