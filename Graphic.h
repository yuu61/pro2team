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

class Peace_Of_Cake :public Graphic {
	int point;					// ケーキのイチゴの数
	int item;					// ケーキの中に含まれてるアイテム。（０なら何も入っていない）
	int radian;					// 角度
};

// ルーレット
class Rulette :public Graphic {
	Peace_Of_Cake POC[8];
	int radian;					// 角度
};

class Item : public Graphic 
{
protected :
	bool exist;					// アイテムが存在するかどうか
	int itemID;

public:
	bool Return_Exist();
	int Return_ItemID();
	void Use();
};

class Item_Menu : public Graphic
{
protected:
	Item item[8];
public:
	Item Return_Item(int idx);
};