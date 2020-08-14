#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	gravity = 0;
	score = 0;
	isJump = false;
	doubleJump = false;

	backgroundList.push_back(new Sprite("Resources/Image/Background.png"));
	Sprite* tmpBackground = new Sprite("Resources/Image/Background.png");
	tmpBackground->setPos(SCREEN_WIDTH, 0);
	backgroundList.push_back(tmpBackground);


	Sprite* tmpBridge = new Sprite("Resources/Image/LoopMap.png");
	tmpBridge->setPos(0, 500);
	bridgeList.push_back(tmpBridge);

	Sprite* temp1Bridge = new Sprite("Resources/Image/LoopMap.png");
	temp1Bridge->setPos(SCREEN_WIDTH, 500);
	bridgeList.push_back(temp1Bridge);

	Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
	tmpCoin->setPos(SCREEN_WIDTH + 70, 400);
	coinList.push_back(tmpCoin);

	Sprite* tmpObstacle = new Sprite("Resources/Image/Drop.png");
	tmpObstacle->setPos(SCREEN_WIDTH, 400);
	obstacleList.push_back(tmpObstacle);

	for (int i = 0; i < 4; i++) {
		numArray[i].setPos(0 + 60 * i, 10);
	}
}
GameScene::~GameScene() {

}

void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}

	for (auto& bridge : bridgeList) {
		bridge->Render();
	}

	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}

	for (auto& coin : coinList) {
		coin->Render();
	}
	for (int i = 0; i < 4; i++) {
		numArray[i].Render();
	}

	player->Render();
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);

	int randNum = rand() % 20 + 1;

	if (randNum == 1) {
		Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
		tmpCoin->setPos(SCREEN_WIDTH + 100, 400);
		coinList.push_back(tmpCoin);
	}

	if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN || inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (player->getPosY() == 350) {
			isJump = true;
			gravity = 0;
		}
	}
	player->Update(dTime);

	int backgroundDiff = 500 * dTime;
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++)
	{
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		//(*iter)->setPos((*iter)->getPosX() - 1000 * dTime, (*iter)->getPosY());
		//if ((*iter)->getPosX() < -SCREEN_WIDTH+150) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			Sprite* tmpBackground = new Sprite("Resources/Image/Background.png");
			tmpBackground->setPos(SCREEN_WIDTH - 20, 0);
			backgroundList.push_back(tmpBackground);

			if (iter == backgroundList.end()) {
				break;
			}
		}
	}
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++)
	{
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);
			Sprite* tmpBridge = new Sprite("Resources/Image/LoopMap.png");
			tmpBridge->setPos(SCREEN_WIDTH - 40, 500);
			bridgeList.push_back(tmpBridge);

			if (iter == bridgeList.end()) {
				break;
			}
		}
	}
	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++)
	{
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());

		if (player->IsCollisionRect((*iter))) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);
			Sprite* tmpObstacle = new Sprite("Resources/Image/Drop.png");
			tmpObstacle->setPos(SCREEN_WIDTH, 400);
			obstacleList.push_back(tmpObstacle);

			if (iter == obstacleList.end()) {
				break;
			}
		}
	}
	for (auto iter = coinList.begin(); iter != coinList.end(); iter++)
	{
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
			//Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
			//tmpCoin->setPos(SCREEN_WIDTH + 70, 400);
			//coinList.push_back(tmpCoin);

			if (iter == coinList.end()) {
				break;
			}
		}

	}

	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			score += 1;
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
			if (iter == coinList.end()) {
				break;
			}
		}
	}

}