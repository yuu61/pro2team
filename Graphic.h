#pragma once
#include "DxLib.h"
// グラフィックスデータを格納する構造体
class Graphic
{
private:
	bool visible;				// 画像を表示するかどうか
	int graph;					// 表示する画像のハンドルを格納
	int x;						// 左上の座標を格納
	int y;
	int xx;						//右下の座標を格納
	int yy;
	int iniX;					// デフォルトの左上の座標を格納
	int iniY;
	int iniXx;					// デフォルトの右下の座標を格納
	int iniYy;
	int flame;					// イベントのフレーム数の格納

	int event[10];				// 適応されるイベントの格納

public:
	void Set_Visible(bool in);
	void Set_Graph(char* in);
	void Set_Location(int inx, int iny, int inxx, int inyy);
	void Display();
	void Be_Big();
	void Light_Up();
	void Update();
};

class Rulette :Graphic {

};

class Item_Menu :Graphic {
	Item item[8] ;
};

class Item :Graphic {
	
};