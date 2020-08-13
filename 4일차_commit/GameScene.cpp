#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
	gravity = 0;
	isJump = false;
	doubleJump = false;

	backgroundList.push_back(new Sprite("Resources/image/Background.png"));

	Sprite* tmpBackground = new Sprite("Resources/image/Background.png");
	tmpBackground->setPos(SCREEN_WIDTH, 0);
	backgroundList.push_back(tmpBackground);
	//-------------------------------------------------------------------------------------------------------------------

	Sprite* tmpBridge = new Sprite("Resources/image/LoopMap.png");
	tmpBridge->setPos(0, 500);
	bridgeList.push_back(tmpBridge);

	Sprite* tempBridge = new Sprite("Resources/image/LoopMap.png");
	tempBridge->setPos(SCREEN_WIDTH, 500);
	bridgeList.push_back(tempBridge);

	//-------------------------------------------------------------------------------------------------------------------

	player = new Animation(30);
	player->AddFrame("Resources/image/player-stop.png");
	player->AddFrame("Resources/image/player-run.png");
	player->setPos(50, 100);
}

GameScene::~GameScene()
{

}

void GameScene::Render()
{
	for (auto& background : backgroundList) {
		background->Render();
	}

	for (auto& bridge : bridgeList) {
		bridge->Render();
	}

	player->Render();
}

void GameScene::Update(float dTime)
{
	Scene::Update(dTime);
	gravity += 9.8f;
	
	player->setPos(player->getPosX(), player->getPosY() + gravity * dTime);

	if (isJump) {
		player->setPos(player->getPosX(), player->getPosY() - 350 * dTime);
		if (doubleJump) {
			player->setPos(player->getPosX(), player->getPosY()-300*dTime);
		}
		if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN || inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
			doubleJump = true;
		}
	}

	if (player->getPosY() > 350) {
		player->setPos(player->getPosX(), 350);
		doubleJump = false;
		isJump = false;
	}

	if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN || inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (player->getPosY() == 350) {
			isJump = true;
			gravity = 0;
		}
	}

	player->Update(dTime);
	int backgroundDiff = 500 * dTime;		//dTime 을 그때그때 바꾸기 위해
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		//(*iter)->setPos((*iter)->getPosX() - 1000 * dTime, (*iter)->getPosY());

		//if ((*iter)->getPosX() < -SCREEN_WIDTH+150) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE((*iter));
			iter = backgroundList.erase(iter);
			Sprite* tmpBackground = new Sprite("Resources/image/Background.png");
			tmpBackground->setPos(SCREEN_WIDTH, 0);
			backgroundList.push_back(tmpBackground);
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		//(*iter)->setPos((*iter)->getPosX() - 1000 * dTime, (*iter)->getPosY());

		//if ((*iter)->getPosX() < -SCREEN_WIDTH+150) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE((*iter));
			iter = bridgeList.erase(iter);
			Sprite* tmpBridge = new Sprite("Resources/image/LoopMap.png");
			tmpBridge->setPos(SCREEN_WIDTH, 500);
			bridgeList.push_back(tmpBridge);
			if (iter == bridgeList.end()) {
				break;
			}
		}
	}
}
