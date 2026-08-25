#include "..\header\RoulettePlay.hpp"
#include "..\dxlib_for_visual_studio\DxLib.h"
#include "..\header\Container.hpp"
#include "..\header\CatchInput.hpp"

RoulettePlay::RoulettePlay(GameCgr* changer, GameVar* gv) : GameScene(changer ,gv)
{
	
}

void RoulettePlay::Initialize() {
	status = 0;
	auto& roulette = gameVar->RouletteWheel();
	auto& players = gameVar->Players();

	roulette.SetExpandTo(MOVE_SINE, 1.f, 45);
	roulette.SetMoveTo(MOVE_SINE, 0.f, 0.f, 45);
	roulette.Graphics::SetMoveTo(MOVE_SINE, (1920 - 1000) / 2, 0, 45);

	gameVar->Background().SetMoveTo(MOVE_SINE, 700.f, -350.f, 45);
	gameVar->Background().SetExpandTo(MOVE_SINE, 2.f, 45);


	players.ScoreAt(1).SetMoveTo(MOVE_SINE, 1920 - 300, 100, 45);
	players.ScoreAt(0).SetMoveTo(MOVE_SINE, 100, 100, 45);

	players.At(0).SetMoveTo(MOVE_SINE, 0, 600, 45);
	players.At(1).SetMoveTo(MOVE_SINE, 1920 - 400, 600, 45);
	players.At(0).SetRepetate(MOVE_SINE, 0, -100,45, 45);
	players.At(1).SetRepetate(MOVE_SINE, 0, -100,45, 45);

}

void RoulettePlay::Finalize() {

}

void RoulettePlay::Update() {
	static int flame{ 0 };
	auto& roulette = gameVar->RouletteWheel();
	auto& players = gameVar->Players();
	auto& player = players.Current();
	auto& opponent = players.Opponent();

	switch (status) {
	case 0:
		if (player.GetInputKey(KEY_CANCEL) == 1) {
			gameCgr->SceneChange(PLAYER_SELECT);	
		}

		if (player.GetInputKey(KEY_RIGHT)) {
			roulette.SetRotate(MOVE_NORMAL, 2.f, 1);
		}
		else if (player.GetInputKey(KEY_LEFT)) {
			roulette.SetRotate(MOVE_NORMAL, -2.f, 1);
		}

		else if (player.GetInputKey(KEY_ENTER) == 1) {
			status++;
			roulette.SetRotate(MOVE_GRAD_UP, 360 * 4, 60 * 6);
		}
		break;
	case 1:
		
		flame++;
		if (flame >= 60 * 6) {
			status++;
			flame = 0;
		}

		// WQ
		if (opponent.GetInputKey(KEY_RIGHT) == 1) {
			roulette.SetRepetate(MOVE_GRAD_DOWN, 60.f, 60.f, 4, 16);
		}
		else if (opponent.GetInputKey(KEY_LEFT) == 1) {
			roulette.SetRepetate(MOVE_GRAD_DOWN, -60.f, 60.f, 4, 16);
		}

		break;
	case 2:
		roulette.SetRotate(MOVE_NORMAL, 8.f, 1);
		// WQ
		if (opponent.GetInputKey(KEY_RIGHT) == 1) {
			roulette.SetRepetate(MOVE_GRAD_DOWN, 60.f, 60.f, 4, 16);
		}
		else if (opponent.GetInputKey(KEY_LEFT) == 1) {
			roulette.SetRepetate(MOVE_GRAD_DOWN, -60.f, 60.f, 4, 16);
		}
		
		// ń]~ßé
		if (player.GetInputKey(KEY_ENTER) == 1) {
			status++;
			roulette.SetRotate(MOVE_GRAD_DOWN, 360 * 4, 60 * 6);
		}
		break;
	case 3:
		flame++;
		if (flame >= 360) {
			status++;
			flame = 0;
			int num{ 7 - (int)(roulette.at(0)->GetDegree() + 90) / 45 % 8 };
			int x{ roulette.GetX() }, y{ roulette.GetY() };
			player.addPoints(roulette.at(num)->GetStrawberry());
			cakeTemp = roulette.at(num);
			cakeTemp->SetMoveTo(MOVE_NORMAL, x, y, 1);
			cakeTemp->SetMove(MOVE_GRAD_UP, 0, 1080, 60);
			
			roulette.erase(num);
			roulette.insert(num, new Cake());
			roulette.at(num)->SetAngle(cakeTemp->GetAngle());
			roulette.at(num)->SetMove(MOVE_NORMAL, 0, 1080 , 1);
			roulette.at(num)->SetMoveTo(MOVE_GRAD_DOWN, 0, 0, 120);
			players.RefreshScores();
		}
		break;
	case 4:
		flame++;
		if (flame >= 120) {
			delete cakeTemp;
			cakeTemp = nullptr;
			gameCgr->SceneChange(PLAYER_SELECT);
			flame = 0;

			if (players.IsFinalTurn()) {
				//Q[Iš
				gameCgr->SceneChange(ENDING);
			}

			players.CompleteTurn();
			
		}
	}

	arrow->Update();
	roulette.Update();
	players.UpdateAll();

	if (cakeTemp != nullptr) {
		cakeTemp->Update();
	}
}


void RoulettePlay::Draw() {
	auto& players = gameVar->Players();

	gameVar->RouletteWheel().Draw();
	arrow->Draw();

	if (cakeTemp != nullptr) {
		cakeTemp->Draw();
	}

	players.DrawAll();

	switch (status) {
	case 0:
		DrawFormatStringToHandle(players.Current().GetX(), 500, RGB(255, 255, 255), gameVar->FontHandle(), _T(" CANCEL to \"%c\"\n START to \"%c\""),
			players.CurrentKeyLabel(KEY_CANCEL),
			players.CurrentKeyLabel(KEY_ENTER));
		break;
	case 1:
		DrawFormatStringToHandle(players.Opponent().GetX(), 500, RGB(255, 255, 255), gameVar->FontHandle(), _T("SHAKE to\n       \"%c\" \"%c\""),
			players.OpponentKeyLabel(KEY_RIGHT),
			players.OpponentKeyLabel(KEY_LEFT));
		break;
	case 2:
		
		DrawFormatStringToHandle(players.Current().GetX(), 500, RGB(255, 255, 255), gameVar->FontHandle(), _T("   STOP to \"%c\""),
			players.CurrentKeyLabel(KEY_ENTER));

		DrawFormatStringToHandle(players.Opponent().GetX(), 500, RGB(255, 255, 255), gameVar->FontHandle(), _T("SHAKE to\n       \"%c\" \"%c\""),
			players.OpponentKeyLabel(KEY_RIGHT),
			players.OpponentKeyLabel(KEY_LEFT));
		
		break;
	}

	
	//bZ[W\Ś
	

	DrawString(100, 50, _T("RoulettePlay"), RGB(255, 255, 255));

}
