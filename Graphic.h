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
	void Set_Graph(const char* in);
	void Set_Location(int inx, int iny, int inxx, int inyy);
	void Display();
	void Display(int inx, int iny);
	void Change_Scale(int scale);
	void Light_Up();
	void Update();
	int Get_X() { return x; }
	int Get_Xx() { return xx; }
	int Get_Y() { return y; }
	int Get_Yy() { return yy; }
};

class Piece_Of_Cake :public Graphic {
	int point;					// ケーキのイチゴの数
	int item;					// ケーキの中に含まれてるアイテム。（０なら何も入っていない）
};

// ルーレット
class Rulette :public Graphic {

	Piece_Of_Cake POC[8];
	int radian;					// 角度
	int speed;
	int gSpeed;

public:
	void Start();
	void Stop();
	void Rotate();
	void Display();
	bool Get_Stoping();
	int Get_Poc() 
	{ 
		return Rulette.POC[Rulette.radian / 45].point;
	}
};

class Item : public Graphic 
{
protected :
	bool exist;					// アイテムが存在するかどうか
	int itemID;

public:
	bool Return_Exist() { return exist; }
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