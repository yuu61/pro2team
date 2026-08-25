#include "..\header\GameVar.hpp"

#include "..\header\Graphics.hpp"
#include "..\header\Roulette.hpp"
#include "..\dxlib_for_visual_studio\DxLib.h"

GameVar::GameVar() :
	background(std::make_unique<Graphics>(0.f, 0.f, 1.f, 1.f,
		LoadGraph(_T("image\\backGround.jpg")))),
	roulette(std::make_unique<Roulette>()),
	players(this),
	fontHandle(CreateFontToHandle(nullptr, 50, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8))
{
	roulette->SetRotate(MOVE_NORMAL, 360 * 5, 1);
}

GameVar::~GameVar()
{
	if (fontHandle != -1) {
		DeleteFontToHandle(fontHandle);
	}
}

Graphics& GameVar::Background()
{
	return *background;
}

Roulette& GameVar::RouletteWheel()
{
	return *roulette;
}

PlayerSession& GameVar::Players()
{
	return players;
}

void GameVar::UseBasket()
{
	const int cakeIndex{ 7 - (static_cast<int>(roulette->at(0)->GetDegree()) + 90) / 45 % 8 };
	roulette->at(cakeIndex)->AddStrawberry(5);
}
