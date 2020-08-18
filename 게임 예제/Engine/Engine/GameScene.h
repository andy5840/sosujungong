#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include <list>
//Object Headers
#include "Number.h"
#include "Player.h"
#include "Background.h"
#include "Bridge.h"
#include "Coin.h"
#include "Obstacle.h"
#include "Cctv.h"
#include "Npc.h"

class GameScene : public Scene
{
private :
	int score, npcCounter;
	bool backgroundInstatiate, bridgeInstantiate, npcInstantiate, obstacleInstantiate, cctvInstantiate;
	float npcInstDelayTimer,obstacleInstDelayTimer;

	std::list<Background *> backgroundList;
	std::list<Bridge *> bridgeList;
	std::list<Npc*> npcList;
	std::list<Coin*> coinList;
	std::list<Obstacle*> obstacleList;
	std::list<Cctv*> cctvList;

	Number *numArray[4];
	Player* player;
public :
	GameScene();
	~GameScene();

	void Render();
	void Update(float dTime);

	void CollisionCheck();
	void OptimizationObject();
	void InstantiateObject();
	
	void TimerSetting(float dTime);
	void UISetting();
};