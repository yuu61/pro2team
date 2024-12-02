#pragma once
#include "DxLib.h"
#include <vector>

using namespace std;

// グラフィックスデータを格納する構造体
class Graphic
{
protected:
	bool visible;				// 画像を表示するかどうか
	int graph;					// 表示する画像のハンドルを格納
	int x;						// 左上の座標を格納
	int y;
	int xx;						//右下の座標を格納
	int yy;
	int gX;						//グラフィックス用の変数
	int gY;
	int gXx;					
	int gYy;
	int flame;					// イベントのフレーム数の格納

	int event[10];				// 適応されるイベントの格納

public:
	void Set_Visible(bool in);
	void Set_Graph(char* in);
	void Set_Location(int inx, int iny, int inxx, int inyy);
	void Display();
	void Display(int inx, int iny);
	void Be_Big();
	void Light_Up();
	void Update();
};

class Rulette :Graphic {

};

class Item :Graphic {
	
};

class Item_Menu : Item {
	Item item[8];
};