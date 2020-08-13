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

	startButton->setCenter(300, 120, startButton);				//in ������
	startButton->setPos(SCREEN_WIDTH / 2, 350);	

	exitButton = new Sprite("Resources/image/out.png");	//out ������
	AddObject(exitButton);

	//exitButton->setCenter(500, 120, exitButton);				//???
	exitButton->setPos(SCREEN_WIDTH / 2, 500);

}

MainScene::~MainScene()
{
	//AddObject�� �����Ͽ���
	//SceneObject���� �����Ҵ��� �����ǹǷ� ���� ���� ���ص� ��
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
