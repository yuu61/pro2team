#include <stdbool.h>
#include "DxLib.h"
#include "FpsControll.h"
#include "constants.h"
#include "Graphic.h"
#include "My_Check_Hit_Key.h"

// プレイヤーのアイテムを格納
int playerItem[2][ITEM_NUM] = { {0} };

// プレイヤーのHPを格納
int playerPoints[2] = { 0 };

// プレイヤーの選択している要素を格納
int playerSelect = 0;

// 状態遷移
// １：アイテムの選択画面
// ２：ルーレットの操作画面
// ３：ルーレット後の処理
int status = 0;

enum eStatus {MENU,ITEM,RULETTE, };

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
int ruletteStatus;

/*
typedef struct _cake {
	
}Cake;
*/

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	SetWaitVSyncFlag(FALSE);			// 垂直同期をオフにする（こうしない45fpsぐらいになる）

	//return 0;

	if (DxLib_Init() == -1)			// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// アイテムメニュー
	Item_Menu itemMenu[2];

	// ルーレット
	Rulette rulette;

	// グラフィックスの格納 
	Graphic graphic[G_NUM];

	graphic[0].Set_Graph("Image\\convert.png");
	graphic[0].Set_Location(0, 0, SCREEN_X, SCREEN_Y);

	// エフェクトの格納
	Graphic effect[E_NUM];


	// fpsの初期化
	FpsControll_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
	{
		// アイテムメニューの更新
		itemMenu[0].Update();
		itemMenu[1].Update();

		// アイテムメニューの表示
		itemMenu[turnPlayer].Display();

		// 背景などのグラフィックスの表示
		for (int i = 0; i < G_NUM; i++) {
			graphic[i].Update();
			graphic[i].Display();
		}

		/*
		for (int i = 0; i < E_NUM; i++) {
			effect[i].Update();
			effect[i].Display();
		}
		*/
		

		
		// 操作部：変数の値をプレイヤーからの操作によって変える。

		switch (status) 
		{
			//GetHitKeyStateAllを使う形に変えたい
			case MENU:
				
				

				// アイテムボックスを選択する操作
				if (CheckHitKey(KEY_INPUT_S)) {
					status = ITEM;

				}
				else if (CheckHitKey(KEY_INPUT_W)) {			// ルーレット画面へ移動する操作（条件は仮置き）
					rulette.Change_Scale(100);
					status = RULETTE;	
				}
				break;



			case ITEM:

				// アイテム選択の操作を受け付ける。
				// アイテムを選択する操作

				if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_A)) {
					if (CheckHitKey(KEY_INPUT_A)) {
						playerSelect -= 1;
					}
					else if (CheckHitKey(KEY_INPUT_D)) {
						playerSelect += 1;
					}
					//	アイテムボックスかルーレットを選択する
					switch (playerSelect)
					{
					case 8:playerSelect = 0; break;//0未満か7より大きい場合に一周させる
					case -1:playerSelect = ITEM_NUM - 1; break;

					}
				}

				// アイテムを使う操作
				if (CheckHitKey(KEY_INPUT_S)) {
					
					if (itemMenu[turnPlayer].Return_Item(playerSelect).Return_Exist()) {
						itemMenu[turnPlayer].Return_Item(playerSelect).Use();
					}
					
				}



			case RULETTE:					// ルーレットの操作を受け付ける。

				if (CheckHitKey(KEY_INPUT_S) && ruletteStatus == 1) {
					// 適当に待機する処理
				}
				else if (CheckHitKey(KEY_INPUT_S) && ruletteStatus == 2) {
					ruletteStatus = 3;		// ルーレットを開始する操作。
											// 暫く操作を受け付けない
					rulette.Start();
				}
				else if (ruletteStatus == 3) {
					// 適当に待機する
					static int waitFlame = 0;
					waitFlame += rand() % 100;
					// 適当な時間待ったらルーレットを止めれるようにする。
					if (waitFlame >= 10000000) {
						ruletteStatus = 4;
						waitFlame = 0;
					}
				}
								// ルーレットを止めるときの操作
				else if (CheckHitKey(KEY_INPUT_S) && ruletteStatus == 4) {
					rulette.Stop();
					if (rulette.Get_Stoping()) {
						ruletteStatus = 0;
						status = 3;
						rulette.Change_Scale(-100);

					}
					
				}

				rulette.Rotate();

				break;

			case 3:
				rulette.Get_Radian();
				

		}	



		/*
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