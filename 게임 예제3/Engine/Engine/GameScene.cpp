#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	score = 0;
	kill = false;
	npcCounter = 0;

	backgroundInstatiate = false;
	bridgeInstantiate = true;
	cctvInstantiate = false;
	obstacleInstantiate = true;
	npcInstantiate = false;

	obstacleInstDelayTimer = 0;
	npcSpawnInstDelayTimer = 0;
	npcInstDelayTimer = 0;
	countTimer = 0;

	Background* background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	//kill = new Sprite("Resources/Image/mainname.png");
	//AddObject(title);
	//title->setPos(275, 0);

	Npc* npc = new Npc();
	//npc->setPos(SCREEN_WIDTH, 500);
	//npc->setPos(player->getPosX() + 200, player->getPosY());
	//npcList.push_back(npc);
	AddObject(npc);

	//Bridge* bridge = new Bridge();
	//bridge->setPos(0, 500);
	//bridgeList.push_back(bridge);
	//AddObject(bridge);	

	Cctv* cctv = new Cctv();
	cctv->setPos(0, 1800);
	cctvList.push_back(cctv);
	AddObject(cctv);

	for (int i = 0; i < 2; i++) {
		numArray[i] = new Number();
		numArray[i]->setPos(100 + 30 * i, 10);
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
	for (auto& bridge : bridgeList) {
		bridge->Render();
	}
	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}	
	for (auto& cctv : cctvList) {
		cctv->Render();
	}
	for (int i = 0; i < 2; i++) {
		numArray[i]->Render();
	}
	for (auto& npc : npcList) {
		npc->Render();
	}
	player->Render();
}

void GameScene::Render(bool b) {
	for (auto& background : backgroundList) {
		background->Render();
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
	for (int i = 0; i < 2; i++) {
		numArray[i]->Render();
	}
	player->Render();
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
	npcSpawnInstDelayTimer += dTime;
	obstacleInstDelayTimer += dTime;
	countTimer += dTime;
}

void GameScene::UISetting() {
	numArray[0]->setNum(score / 10 % 10);
	numArray[1]->setNum(score % 10);
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
	if (inputManager->GetKeyState(VK_SPACE) == KEY_ON && countTimer>0.5f) {//space를 누르면 npc가 죽을 수 있도록
		for (auto c = cctvList.begin(); c != cctvList.end(); c++) {
			if (player->IsCollisionRect((*c))) {
				std::cout << "under cctv" << std::endl;
				sceneManager->ChangeScene(new MainScene(true, score));
				countTimer = 0;
				return;
			}
			else {
				for (auto cc = npcList.begin(); cc != npcList.end(); cc++) {
					if (player->IsCollisionRect((*cc))) {
						if ((*cc)->IsSus()) {
							std::cout << "under Sus" << std::endl;
							sceneManager->ChangeScene(new MainScene(true, score));
							return;
						}
						Npc* npcD = new Npc(false);
						npcD->setPos((*cc)->getPosX(), (*cc)->getPosY());
						score++;
						countTimer = 0;
						npcCounter = rand() % 3;
						RemoveObject((*cc));
						SAFE_DELETE(*cc);
						cc = npcList.erase(cc);
						if (cc == npcList.end()) {
							break;
						}
						return;
					}
				}
			}
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
		cctv->setPos(SCREEN_WIDTH-100, 56);
		cctvList.push_back(cctv);
		AddObject(cctv);
		cctvInstantiate = true;
	}

	if (npcCounter > 0) {
		if (npcInstDelayTimer > 1.0f) {
			npcCounter--;
			npcInstDelayTimer = 0;
			Npc* npc = new Npc(true);
			npc->setPos(SCREEN_WIDTH-50, 450);
			AddObject(npc);
			npcList.push_back(npc);
		}
	}
	else {
		if (npcInstDelayTimer > 2.1f) {
			npcInstDelayTimer = 0;
			Npc* npc = new Npc();
			npc->setPos(SCREEN_WIDTH-50, 500);
			AddObject(npc);
			npcList.push_back(npc);
			npcSpawnInstDelayTimer = 0;
		}
	}
}