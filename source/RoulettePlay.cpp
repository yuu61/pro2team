#include "..\header\RoulettePlay.h"
#include "..\dxlib_for_visual_studio\DxLib.h"
#include "..\header\Container.h"
#include "..\header\CatchInput.h"

RoulettePlay::RoulettePlay(GameCgr* changer, GameVar* gv) : GameScene(changer ,gv)
{
	
}

void RoulettePlay::Initialize() {
	status = 0;

	gameVar->roulette->SetExpandTo(MOVE_SINE, 1.f, 45);
	gameVar->roulette->SetMoveTo(MOVE_SINE, 0.f, 0.f, 45);
	gameVar->roulette->Graphics::SetMoveTo(MOVE_SINE, (1920 - 1000) / 2, 0, 45);

	gameVar->backGround->SetMoveTo(MOVE_SINE, 700.f, -350.f, 45);
	gameVar->backGround->SetExpandTo(MOVE_SINE, 2.f, 45);


	gameVar->strawberry[1]->SetMoveTo(MOVE_SINE, 1920 - 300, 100, 45);
	gameVar->strawberry[0]->SetMoveTo(MOVE_SINE, 100, 100, 45);

	gameVar->playerStore[0]->SetMoveTo(MOVE_SINE, 0, 600, 45);
	gameVar->playerStore[1]->SetMoveTo(MOVE_SINE, 1920 - 400, 600, 45); 
	gameVar->playerStore[0]->SetRepetate(MOVE_SINE, 0, -100,45, 45);
	gameVar->playerStore[1]->SetRepetate(MOVE_SINE, 0, -100,45, 45);

}

void RoulettePlay::Finalize() {

}

void RoulettePlay::Update() {
	static int flame{ 0 };
	switch (status) {
	case 0:
		if (gameVar->player->GetInputKey(KEY_CANSEL) == 1) {
			gameCgr->SceneChange(PLAYER_SELECT);	
		}

		if (gameVar->player->GetInputKey(KEY_RIGHT)) {
			gameVar->roulette->SetRotate(MOVE_NORMAL, 2.f, 1);
		}
		else if (gameVar->player->GetInputKey(KEY_LEFT)) {
			gameVar->roulette->SetRotate(MOVE_NORMAL, -2.f, 1);
		}

		else if (gameVar->player->GetInputKey(KEY_ENTER) == 1) {
			status++;
			gameVar->roulette->SetRotate(MOVE_GRAD_UP, 360 * 4, 60 * 6);
		}
		break;
	case 1:
		
		flame++;
		if (flame >= 60 * 6) {
			status++;
			flame = 0;
		}

		// WQ
		if (gameVar->opponent->GetInputKey(KEY_RIGHT) == 1) {
			gameVar->roulette->SetRepetate(MOVE_GRAD_DOWN, 60.f, 60.f, 4, 16);
		}
		else if (gameVar->opponent->GetInputKey(KEY_LEFT) == 1) {
			gameVar->roulette->SetRepetate(MOVE_GRAD_DOWN, -60.f, 60.f, 4, 16);
		}

		break;
	case 2:
		gameVar->roulette->SetRotate(MOVE_NORMAL, 8.f, 1);
		// WQ
		if (gameVar->opponent->GetInputKey(KEY_RIGHT) == 1) {
			gameVar->roulette->SetRepetate(MOVE_GRAD_DOWN, 60.f, 60.f, 4, 16);
		}
		else if (gameVar->opponent->GetInputKey(KEY_LEFT) == 1) {
			gameVar->roulette->SetRepetate(MOVE_GRAD_DOWN, -60.f, 60.f, 4, 16);
		}
		
		// ń]~ßé
		if (gameVar->player->GetInputKey(KEY_ENTER) == 1) {
			status++;
			gameVar->roulette->SetRotate(MOVE_GRAD_DOWN, 360 * 4, 60 * 6);
		}
		break;
	case 3:
		flame++;
		if (flame >= 360) {
			status++;
			flame = 0;
			int num{ 7 - (int)(gameVar->roulette->at(0)->GetDegree() + 90) / 45 % 8 };
			int x{ gameVar->roulette->GetX() }, y{ gameVar->roulette->GetY() };
			gameVar->player->addPoints(gameVar->roulette->at(num)->GetStrawberry());
			cakeTemp = gameVar->roulette->at(num);
			cakeTemp->SetMoveTo(MOVE_NORMAL, x, y, 1);
			cakeTemp->SetMove(MOVE_GRAD_UP, 0, 1080, 60);
			
			gameVar->roulette->erase(num);
			gameVar->roulette->insert(num, new Cake());
			gameVar->roulette->at(num)->SetAngle(cakeTemp->GetAngle());
			gameVar->roulette->at(num)->SetMove(MOVE_NORMAL, 0, 1080 , 1);
			gameVar->roulette->at(num)->SetMoveTo(MOVE_GRAD_DOWN, 0, 0, 120);
			gameVar->SetStrawberryPoints();
		}
		break;
	case 4:
		flame++;
		if (flame >= 120) {
			delete cakeTemp;
			cakeTemp = nullptr;
			gameCgr->SceneChange(PLAYER_SELECT);
			flame = 0;

			if (gameVar->turn >= gameVar->endTurn) {
				//Q[Iš
				gameCgr->SceneChange(ENDING);
			}

			gameVar->SwapPlayer();
			gameVar->turn++;
			gameVar->SetStringTurnNow();
			gameVar->SetKey();
			
		}
	}

	arrow->Update();
	gameVar->roulette->Update();

	for (int i = 0; i < 2; i++) {
		gameVar->strawberry[i]->Update();
		gameVar->playerStore[i]->Update();
	}

	if (cakeTemp != nullptr) {
		cakeTemp->Update();
	}
}


void RoulettePlay::Draw() {

	gameVar->roulette->Draw();
	arrow->Draw();

	if (cakeTemp != nullptr) {
		cakeTemp->Draw();
	}

	for (int i = 0; i < 2; i++) {
		gameVar->strawberry[i]->Draw();
		gameVar->playerStore[i]->Draw();
	}

	switch (status) {
	case 0:
		DrawFormatStringToHandle(gameVar->player->GetX() , 500, RGB(255, 255, 255), gameVar->fontHandle, " CANSEL to \"%c\"\n START to \"%c\"",
			gameVar->keyCharPlayer[KEY_CANSEL],
			gameVar->keyCharPlayer[KEY_ENTER]);
		break;
	case 1:
		DrawFormatStringToHandle(gameVar->opponent->GetX(), 500, RGB(255, 255, 255), gameVar->fontHandle, "SHAKE to\n       \"%c\" \"%c\"",
			gameVar->keyCharOpponent[KEY_RIGHT],
			gameVar->keyCharOpponent[KEY_LEFT]);
		break;
	case 2:
		
		DrawFormatStringToHandle(gameVar->player->GetX(), 500, RGB(255, 255, 255), gameVar->fontHandle, "   STOP to \"%c\"",
			gameVar->keyCharPlayer[KEY_ENTER]);

		DrawFormatStringToHandle(gameVar->opponent->GetX(), 500, RGB(255, 255, 255), gameVar->fontHandle, "SHAKE to\n       \"%c\" \"%c\"",
			gameVar->keyCharOpponent[KEY_RIGHT],
			gameVar->keyCharOpponent[KEY_LEFT]);
		
		break;
	}

	
	//bZ[W\Ś
	

	DrawString(100, 50, "RoulettePlay", RGB(255, 255, 255));

}