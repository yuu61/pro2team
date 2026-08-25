#include "PlayerSession.hpp"

#include "GameVarMgr.hpp"
#include "ItemBasket.hpp"
#include "ItemClock.hpp"
#include "ItemEye.hpp"
#include <DxLib.h>

#include <string>

PlayerSession::PlayerSession() :
	players{
		std::make_unique<Player>(KEY_INPUT_S, KEY_INPUT_W, KEY_INPUT_A, KEY_INPUT_D,
			0.f, 300.f, 1.f, 1.f, LoadGraph(_T("image\\dansei_01_a.png"))),
		std::make_unique<Player>(KEY_INPUT_K, KEY_INPUT_I, KEY_INPUT_J, KEY_INPUT_L,
			400.f, 300.f, 1.f, 1.f, LoadGraph(_T("image\\josei_01_a.png"))) },
	scores{
		std::make_unique<Graphics>(100.f, 0.f, 0.3f, 0.3f, LoadGraph(_T("image\\strawberry.png"))),
		std::make_unique<Graphics>(500.f, 0.f, 0.3f, 0.3f, LoadGraph(_T("image\\strawberry.png"))) }
{
	for (std::size_t i = 0; i < PLAYER_COUNT; ++i) {
		scores[i]->SetStringHandle(CreateFontToHandle(nullptr, 200, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8));
	}

	RefreshTurnText();
	RefreshScores();
}

void PlayerSession::InitializeItems(GameVarMgr* itemAction)
{
	for (std::size_t i = 0; i < PLAYER_COUNT; ++i) {
		players[i]->SetItem(std::make_unique<ItemBasket>(itemAction));
		players[i]->SetItem(std::make_unique<ItemBasket>(itemAction));
		players[i]->SetItem(std::make_unique<ItemEye>(itemAction));
		players[i]->SetItem(std::make_unique<ItemClock>(itemAction));
	}
}

PlayerSession::~PlayerSession() = default;

Player& PlayerSession::Current()
{
	return *players[currentPlayerIndex];
}

Player& PlayerSession::Opponent()
{
	return *players[1 - currentPlayerIndex];
}

Player& PlayerSession::At(std::size_t index)
{
	return *players.at(index);
}

Graphics& PlayerSession::CurrentScore()
{
	return *scores[currentPlayerIndex];
}

Graphics& PlayerSession::OpponentScore()
{
	return *scores[1 - currentPlayerIndex];
}

Graphics& PlayerSession::ScoreAt(std::size_t index)
{
	return *scores.at(index);
}

char PlayerSession::CurrentKeyLabel(eKey key) const
{
	return KeyLabel(*players[currentPlayerIndex], key);
}

char PlayerSession::OpponentKeyLabel(eKey key) const
{
	return KeyLabel(*players[1 - currentPlayerIndex], key);
}

void PlayerSession::CompleteTurn()
{
	currentPlayerIndex = 1 - currentPlayerIndex;
	++turn;
	RefreshTurnText();
}

void PlayerSession::RefreshScores()
{
	for (std::size_t i = 0; i < PLAYER_COUNT; ++i) {
		scores[i]->SetString(std::to_string(players[i]->GetPoints()));
	}
}

void PlayerSession::UpdateAll()
{
	for (std::size_t i = 0; i < PLAYER_COUNT; ++i) {
		scores[i]->Update();
		players[i]->Update();
	}
}

void PlayerSession::DrawAll()
{
	for (std::size_t i = 0; i < PLAYER_COUNT; ++i) {
		scores[i]->Draw();
		players[i]->Draw();
	}
}

char PlayerSession::KeyLabel(const Player& player, eKey key)
{
	switch (player.GetKey(key)) {
	case KEY_INPUT_S:
		return 'S';
	case KEY_INPUT_W:
		return 'W';
	case KEY_INPUT_A:
		return 'A';
	case KEY_INPUT_D:
		return 'D';
	case KEY_INPUT_K:
		return 'K';
	case KEY_INPUT_I:
		return 'I';
	case KEY_INPUT_J:
		return 'J';
	case KEY_INPUT_L:
		return 'L';
	default:
		return '?';
	}
}

void PlayerSession::RefreshTurnText()
{
	Current().SetString("YOUR TURN");
	Opponent().SetString("");
}
