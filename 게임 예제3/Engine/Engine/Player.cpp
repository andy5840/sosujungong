#include "stdafx.h"
#include "Player.h"
#include "GameScene.h"

Player::Player() {
	isJump = false;
	doubleJump = false;
	gravity = 9.8;

	playerAnimation = new Animation(6);
	playerAnimation->AddFrame("Resources/Image/Cyan.png");
	playerAnimation->AddFrame("Resources/Image/Npc_Cyan.png");
	AddChild(playerAnimation);

	rect = playerAnimation->getRect();
}

Player::~Player() {

}

void Player::Render() {
	Object::Render();
	playerAnimation->Render();
}

void Player::Update(float dTime) {
	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);

	if (isJump) {
		setPos(getPosX(), getPosY() - 450 * dTime);
		if (doubleJump) {
			setPos(getPosX(), getPosY() - 200 * dTime);
		}
		if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
			doubleJump = true;
		}
	}
	if (getPosY() > 450) {
		setPos(getPosX(), 450);
		doubleJump = false;
		isJump = false;
	}

	if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (getPosY() == 450) {
			isJump = true;
			gravity = 0;
		}
	}

	if (inputManager->GetKeyState(VK_RIGHT) == KEY_ON) {	//좌우로 움직임
		setPos(getPosX() + 5, getPosY());
	}

	if (inputManager->GetKeyState(VK_LEFT) == KEY_ON) {
		setPos(getPosX() - 10, getPosY());
	}


	playerAnimation->Update(dTime);
}