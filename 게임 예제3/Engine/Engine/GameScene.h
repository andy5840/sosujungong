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
#include "Npc.h"
#include "Obstacle.h"
#include "Cctv.h"
#include "Npc.h"
#include <Windows.h>

class GameScene : public Scene
{
private :
	int score, npcCounter;
	bool backgroundInstatiate, bridgeInstantiate, npcInstantiate, npcDInstantiate, obstacleInstantiate, cctvInstantiate, kill;
	float countTimer, npcInstDelayTimer,obstacleInstDelayTimer, npcSpawnInstDelayTimer;

	std::list<Background *> backgroundList;
	std::list<Bridge *> bridgeList;
	std::list<Npc*> npcList;
	std::list<Npc*> npcDList;
	std::list<Obstacle*> obstacleList;
	std::list<Cctv*> cctvList;

	Number *numArray[2];
	Player* player;
public :
	GameScene();
	~GameScene();

	void Render();
	void Render(bool b);
	void Update(float dTime);

	void CollisionCheck();
	void OptimizationObject();
	void InstantiateObject();
	
	void TimerSetting(float dTime);
	void UISetting();
};