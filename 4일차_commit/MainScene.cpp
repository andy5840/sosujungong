#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene()
{
	background = new Sprite("Resources/image/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/image/mainname.png");
	AddObject(title);
	title->setPos(257, 0);

	startButton = new Sprite("Resources/image/in.png");
	AddObject(startButton);

	startButton->setCenter(300, 120, startButton);				//in 사이즈
	startButton->setPos(SCREEN_WIDTH / 2, 350);	

	exitButton = new Sprite("Resources/image/out.png");	//out 사이즈
	AddObject(exitButton);

	//exitButton->setCenter(500, 120, exitButton);				//???
	exitButton->setPos(SCREEN_WIDTH / 2, 500);

}

MainScene::~MainScene()
{
	//AddObject로 생성하여서
	//SceneObject에서 동적할당이 해제되므로 굳이 해제 안해도 됨
	//SAFE_DELTE(background);
}

void MainScene::Render()
{
	background->Render();
	title->Render();
	startButton->Render();
	exitButton->Render();

}

void MainScene::Update(float dTime)
{
	Scene::Update(dTime);
	//std::cout<<
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
