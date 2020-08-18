#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	score = 0;
	npcCounter = 0;

	backgroundInstatiate = false;
	bridgeInstantiate = true;
	cctvInstantiate = false;
	obstacleInstantiate = true;
	npcInstantiate = false;

	obstacleInstDelayTimer = 0;
	npcInstDelayTimer = 0;

	Background* background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	Npc* npc = new Npc();
	npc->setPos(0, 0);
	//npc->setPos(player->getPosX() + 200, player->getPosY());
	npcList.push_back(npc);
	AddObject(npc);

	//Bridge* bridge = new Bridge();
	//bridge->setPos(0, 500);
	//bridgeList.push_back(bridge);
	//AddObject(bridge);	

	Cctv* cctv = new Cctv();
	cctv->setPos(0, 1800);
	cctvList.push_back(cctv);
	AddObject(cctv);

	for (int i = 0; i < 4; i++) {
		numArray[i] = new Number();
		numArray[i]->setPos(0 + 60 * i, 10);
		AddUI(numArray[i]);
	}

	player = new Player();
	AddObject(player);
}

GameScene::~GameScene() {

}

void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}
	for (auto& npc : npcList) {
		npc->Render();
	}
	for (auto& bridge : bridgeList) {
		bridge->Render();
	}
	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}
	
	for (auto& cctv : cctvList) {
		cctv->Render();
	}
	player->Render();
	for (int i = 0; i < 4; i++) {
		numArray[i]->Render();
	}
	for (auto& npc : npcList) {
		npc->Render();
	}
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);

	UISetting();
	TimerSetting(dTime);
	OptimizationObject();
	InstantiateObject();
	CollisionCheck();
}

void GameScene::TimerSetting(float dTime) {
	npcInstDelayTimer += dTime;
	obstacleInstDelayTimer += dTime;
}

void GameScene::UISetting() {
	numArray[0]->setNum(score / 1000);
	numArray[1]->setNum(score / 100 % 10);
	numArray[2]->setNum(score / 10 % 10);
	numArray[3]->setNum(score % 10);
}

void GameScene::OptimizationObject() {
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			backgroundInstatiate = false;
			obstacleInstantiate = false;
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}

	for (auto iter = npcList.begin(); iter != npcList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = npcList.erase(iter);
			npcInstantiate = false;
			if (iter == npcList.end()) {
				break;
			}
		}
	}

	for (auto iter = cctvList.begin(); iter != cctvList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = cctvList.erase(iter);
			cctvInstantiate = false;
			if (iter == cctvList.end()) {
				break;
			}
		}
	}

	for (auto iter = npcList.begin(); iter != npcList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = npcList.erase(iter);
			if (iter == npcList.end()) {
				break;
			}
		}
	}

	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);

			if (iter == obstacleList.end()) {
				break;

			}
		}
	}
}

void GameScene::CollisionCheck() {
	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}
	}
}

void GameScene::InstantiateObject() {

	if (!backgroundInstatiate) {
		Background* background = new Background();
		background->setPos(SCREEN_WIDTH - 20, 0);
		backgroundList.push_back(background);
		AddObject(background);
		backgroundInstatiate = true;
	}

	if (!cctvInstantiate) {
		Cctv* cctv = new Cctv();
		cctv->setPos(SCREEN_WIDTH-20, 55);
		cctvList.push_back(cctv);
		AddObject(cctv);
		cctvInstantiate = true;
	}

	if (!npcInstantiate) {
		Npc* npc = new Npc();
		npc->setPos(SCREEN_WIDTH - 50, 500);
		npcList.push_back(npc);
		AddObject(npc);
		npcInstantiate = true;
	}

	//if (!bridgeInstantiate) {
	//	Bridge* bridge = new Bridge();
	//	bridge->setPos(SCREEN_WIDTH - 20, 500);
	//	bridgeList.push_back(bridge);
	//	AddObject(bridge);
	//	bridgeInstantiate = true;
	//}



	//if (!obstacleInstantiate) {
	//	if (obstacleInstDelayTimer > 1.f) {
	//		obstacleInstDelayTimer = 0;
	//		npcCounter = 4;
	//		Obstacle* obstacle = new Obstacle(rand() % 2);
	//		obstacle->setPos(SCREEN_WIDTH + 50, 400);
	//		AddObject(obstacle);
	//		obstacleList.push_back(obstacle);
	//		obstacleInstantiate = true;
	//	}
	//}

	if (npcCounter > 0) {
		if (npcInstDelayTimer > 0.1f) {
			npcCounter--;
			npcInstDelayTimer = 0;
			Npc* npc = new Npc();
			npc->setPos(SCREEN_WIDTH, 300);
			AddObject(npc);
			npcList.push_back(npc);
		}
	}
	else {
		if (npcInstDelayTimer > 0.1f) {
			npcInstDelayTimer = 0;
			Npc* npc = new Npc();
			npc->setPos(SCREEN_WIDTH, 400);
			AddObject(npc);
			npcList.push_back(npc);
		}
	}
}