#pragma once

#include "GameVarMgr.hpp"
#include "PlayerSession.hpp"
#include "Roulette.hpp"

#include <memory>

// ゲーム全体で共有するオブジェクトの構成だけを担当する。
class GameVar : public GameVarMgr
{
public:
	GameVar();
	~GameVar() override;

	GameVar(const GameVar&) = delete;
	GameVar& operator=(const GameVar&) = delete;

	Graphics& Background();
	Roulette& RouletteWheel();
	PlayerSession& Players();
	int FontHandle() const { return fontHandle; }

	void UseBasket() override;

private:
	std::unique_ptr<Graphics> background;
	std::unique_ptr<Roulette> roulette;
	PlayerSession players;
	int fontHandle{ -1 };
};
