#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "GameScene.h"

class MainScene : public Scene
{
private:
	bool b = false;
	int high = 0, score;
public :
	MainScene();
	MainScene(bool b, int score);
	~MainScene();

	Sprite* dead;
	Sprite* background;
	Sprite* startButton;
	Sprite* exitButton;
	Sprite* title;
	Sprite* scoreSprite;

	void Render();
	void Update(float dTime);
};