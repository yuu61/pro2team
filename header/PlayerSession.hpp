#pragma once

#include "Graphics.hpp"
#include "Player.hpp"

#include <array>
#include <cstddef>
#include <memory>

class GameVarMgr;

// プレイヤーとターン進行に関する状態をまとめて管理する。
class PlayerSession
{
public:
	static constexpr std::size_t PLAYER_COUNT{ 2 };

	PlayerSession();
	~PlayerSession();

	PlayerSession(const PlayerSession&) = delete;
	PlayerSession& operator=(const PlayerSession&) = delete;

	void InitializeItems(GameVarMgr* itemAction);

	Player& Current();
	Player& Opponent();
	Player& At(std::size_t index);

	Graphics& CurrentScore();
	Graphics& OpponentScore();
	Graphics& ScoreAt(std::size_t index);

	char CurrentKeyLabel(eKey key) const;
	char OpponentKeyLabel(eKey key) const;

	std::size_t Turn() const { return turn; }
	std::size_t EndTurn() const { return END_TURN; }
	bool IsFinalTurn() const { return turn >= END_TURN; }

	void CompleteTurn();
	void RefreshScores();
	void UpdateAll();
	void DrawAll();

private:
	static constexpr std::size_t END_TURN{ 8 };

	static char KeyLabel(const Player& player, eKey key);
	void RefreshTurnText();

	std::array<std::unique_ptr<Player>, PLAYER_COUNT> players;
	std::array<std::unique_ptr<Graphics>, PLAYER_COUNT> scores;
	std::size_t currentPlayerIndex{ 0 };
	std::size_t turn{ 1 };
};
