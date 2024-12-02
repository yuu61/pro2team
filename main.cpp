#include <stdbool.h>
#include "DxLib.h"
#include "FpsControll.h"
#include "constants.h"
#include "Graphic.h"

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

// ルーレットの稼働状態を格納する変数	０：ルーレットを使っていない	
//										１：ルーレット回転開始前の拡大表示	
//										２：ルーレット開始可能状態
//										３：ルーレット回転開始	(操作不可）
//										４：ルーレット停止可能状態
//										５：ルーレット停止
int rulette;

bool toBeBigCake = FALSE;

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

	Item_Menu itemMenu;

	// グラフィックスの格納 
	Graphic graphic[G_NUM];

	// エフェクトの格納
	Graphic effect[E_NUM];

	// fpsの初期化
	FpsControll_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
	{
		itemMenu.Update();
		

		/*
		// 操作部：変数の値をプレイヤーからの操作によって変える。

		switch (status) 
		{
			//GetHitKeyStateAllを使う形に変えたい
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
				case 8:playerSelect = 0; break;//0未満か7より大きい場合に一周させる
				case -1:playerSelect = ITEM_NUM - 1;break;
				}

				// アイテムを決定する操作
				if (CheckHitKey(KEY_INPUT_S)) {
					if (playerItem[turnPlayer][playerSelect] != NULL) {
						itemUse = playerItem[turnPlayer][playerSelect];
					}
				}
				else if (CheckHitKey(KEY_INPUT_W)) {			// ルーレット画面へ移動する操作（条件は仮置き）
					status = 2;	
					toBeBigCake = TRUE;
				}
				break;

			case 2:					// ルーレットの操作を受け付ける。
				if (CheckHitKey(KEY_INPUT_S) && rulette == 1)
				if (CheckHitKey(KEY_INPUT_S) && rulette == 2) {
					rulette = 3;		// ルーレットを開始する操作。
										// 暫く操作を受け付けない
				}
				else if (rulette == 3) {
					// 適当に待機する
					static int waitFlame = 0;
					waitFlame += rand() % 100;
					// 適当な時間待ったらルーレットを止めれるようにする。
					if (waitFlame >= 10000000) {
						rulette = 4;
						waitFlame = 0;
					}
				}
								// ルーレットを止めるときの操作
				else if (CheckHitKey(KEY_INPUT_S) && rulette == 4) {
					rulette = 5;
				}

				break;
							
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

		
		if (rulette == 1) {
			static int waitFlame = 0;
			waitFlame += rand() % 100;	// 適当な数を入れる
			if (waitFlame >= 1000) {	// 適当に待つ
				rulette = 2;
			}
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
			graphic[i].Display();
		}

		//ケーキを大きくする描画
		if (toBeBigCake) {
			static int cakeScale = 0;
			cakeScale++;
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

		*/
		DxLib_End();				// ＤＸライブラリ使用の終了処理
		return -1;					// 異常終了の通知
	}
}