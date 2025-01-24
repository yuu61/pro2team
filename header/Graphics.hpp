#pragma once
#include "..\dxlib_for_visual_studio\DxLib.h"
#include "Task.hpp"
#include "MovementI.hpp"
#include "Movement.hpp"
#include <string.h>
#include <iostream>


//using namespace std;

typedef struct _Location {
	float x, y;
}Location;

#define PI 3.141592653589793

const double degree{ PI / 180 };

// グラフィックスを表現するクラス。
class Graphics : public Task, public MovementI
{
protected:

	bool visible{ true };				// 画像を表示するかどうか
	int graph{ -1 };					// 表示する画像のハンドルを格納
	int backGraph{ -1 };
	

	double angle{ 0 };
	bool turnX{ false }, turnY{ false };
	// 座標を保存する変数。
	Location location;
	// 画像を拡大したときのずれを補正するための変数。
	Location gLoc{ 0,0 };
	// 画像の大きさ（座標を確認する用）
	Location size{ 0,0 };
	// 回転の中央の座標
	Location cnt{ 0,0 };
	// 画像の大きさの倍率
	Location extRate{ 1,1 };
	// 画像の大きさの倍率（固定）
	const Location cExtRate{ 1,1 };
	// 移動などのイベントを格納する。
	Movement* movement[MOVEMENT_TYPE_MAX]{ nullptr };

	std::string str{""};
	int strHandle{ CreateFontToHandle(NULL , 50 , 9 ,DX_FONTTYPE_ANTIALIASING_EDGE_8X8) };
	unsigned strColor{ GetColor(255,255,255) };
	float strCnt{ 0 };

public:
	Graphics();
	Graphics(int graph);
	Graphics(float x1, float y1, float cx, float cy, int graph);

	void Initialize() override {};
	void Finalize() override;

	void SetVisible(bool in);
	void SetGraph(int in);
	void SetBackGraph(int in) { backGraph = in; }
	int GetGraph() { return graph; }
	// 画像を描画する。
	void virtual Draw();
	// コンテナに使うやつ
	void virtual Draw(int inx, int iny);

	void SetString(std::string s) { str = s; SetStringCnt(); }
	void SetStringHandle(int h) { strHandle = h; SetStringCnt(); }
	void SetString(unsigned c) { strColor = c; }
	void SetStringCnt() {strCnt = -GetDrawFormatStringWidthToHandle(strHandle, "%s", str.c_str()) / 2.f;}

	// 見た目を強調してわかりやすくする。
	void LightUp();

	void Update() override;

	// イベントをセットする。
	virtual void SetMove(eMoveType moveType, float x, float y, int flame);
	virtual void SetMoveTo(eMoveType moveType, float x, float y, int flame);

	virtual void SetExpand(eMoveType moveType, float time, int flame);
	virtual void SetExpandTo(eMoveType moveType, float time, int flame);
	
	virtual void SetRotate(eMoveType moveType, float rota, int flame);
	virtual void SetRotateTo(eMoveType moveType, float rota, int flame);

	// time は一回の反復の一方にかかるフレームとする
	virtual void SetRepetate(eMoveType moveType, float x,float y, int time , int flame);

	// イベントを実行する。
	void Move(float x, float y) override;
	void MoveGL(float x, float y) override;
	void Expand(float x, float y, float ux, float uy) override;
	void Rotate(float rota) override;

	void SetCnt(){ cnt = { size.x / 2 / extRate.x / cExtRate.x,size.y / 2 / extRate.y / cExtRate.y }; }
	void SetCnt(float x, float y){ cnt = { x,y }; }

	void SetAngle(double a) { angle = a; }
	void SetDegree(double a) {angle = a * degree;}

	double GetAngle() { return angle; }
	double GetDegree() { return angle / degree; }

	int GetX() { return location.x; }
	int GetY() { return location.y; }
	int GetSizeX() { return size.x; }
	int GetSizeY() { return size.y; }
	double GetExtRateX() { return extRate.x; }
	double GetExtRateY() { return extRate.y; }
};
