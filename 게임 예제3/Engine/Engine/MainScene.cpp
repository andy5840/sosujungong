#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene() {
	background = new Sprite("Resources/Image/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/Image/mainname.png");
	AddObject(title);
	title->setPos(275, 0);

	startButton = new Sprite("Resources/Image/in.png");
	AddObject(startButton);
	startButton->setPos(SCREEN_WIDTH / 2, 350);

	exitButton = new Sprite("Resources/Image/out.png");
	AddObject(exitButton);
	exitButton->setPos(SCREEN_WIDTH / 2, 500);

}

MainScene::MainScene(bool b, int score) {
	this->b = b;
	this->score = score;
	background = new Sprite("Resources/Image/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/Image/mainname.png");
	AddObject(title);
	title->setPos(275, 0);

	dead = new Sprite("Resources/Image/Caught.png");
	AddObject(dead);
	dead->setPos(150, 30);

	startButton = new Sprite("Resources/Image/in.png");
	AddObject(startButton);
	startButton->setPos(SCREEN_WIDTH / 2, 350);

	exitButton = new Sprite("Resources/Image/out.png");
	AddObject(exitButton);
	exitButton->setPos(SCREEN_WIDTH / 2, 500);
	
	if (score == 0) {
		scoreSprite = new Sprite("Resources/Image/Over_none.png");	//you such a idle boy
	}
	if (score > 0) {
		scoreSprite = new Sprite("Resources/Image/Over_0.png");	//you've killed too many people
	}
	if (score > 10){
		scoreSprite = new Sprite("Resources/Image/Over_10.png");	//you murderer
	}
	AddObject(scoreSprite);
	scoreSprite->setPos(0, 100);

}

MainScene::~MainScene() {

}

void MainScene::Render() {
	background->Render();
	title->Render();
	startButton->Render();
	exitButton->Render();
	if (b) {
		dead->Render();
		scoreSprite->Render();
	}
}

void MainScene::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

		if (startButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}

		if (exitButton->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}

	}
}