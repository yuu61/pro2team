#include "GameVar.hpp"

#include "Graphics.hpp"
#include "Roulette.hpp"
#include <DxLib.h>

GameVar::GameVar() :
	background(std::make_unique<Graphics>(0.f, 0.f, 1.f, 1.f,
		LoadGraph(_T("image\\backGround.jpg")))),
	roulette(std::make_unique<Roulette>()),
	fontHandle(CreateFontToHandle(nullptr, 50, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8))
{
	players.InitializeItems(this);
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
	const auto cakeIndex{ static_cast<std::size_t>(
		7 - (static_cast<int>(roulette->at(0)->GetDegree()) + 90) / 45 % 8) };
	roulette->at(cakeIndex)->AddStrawberry(5);
}
