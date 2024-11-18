#include "DxLib.h"

// ケーキのデータ格納
int remain[8];

// プレイヤーのアイテムを格納
int playerItem[2][8] = { {0} };

// プレイヤーのHPを格納
int playerHP[2] = { 0 };

// ルーレットが回っているか
bool roulette = FALSE;

// プレイヤーの選択している要素を格納
int select = 0;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 

	// アイテムを引く

	// 描写する関数

	while () {

		// 現在のプレイヤーの表示。

		// 選択の操作を受け付ける。

		// アイテムを使う。
		
		// ルーレットを開始する。

		// ルーレットを止める(戻り値をルーレットの結果を反映する)。

		// ルーレットの結果を反映する。

		// 勝利条件を確認する。

		// ターンを回す。

		if (roulette) {
			//ルーレットを描画する関数の変数を変更する処理
		}


		// ルーレット以外を描画する関数

		// ルーレットを描画する関数

	}


}
