#include "stdafx.h"
#include "Player.h"

Player::Player() {
	isJump = false;
	doubleJump = false;
	gravity = 9.8;

	playerAnimation = new Animation(10);
	playerAnimation->AddFrame("Resources/Image/player-run.png");
	playerAnimation->AddFrame("Resources/Image/player-stop.png");
}

Player::~Player()
{

}

void Player::Render() {
	Object::Render();
	playerAnimation();

}

void Player::Update() {

	gravity += 9.8f;

	numArray[0].setNum(score / 1000);
	numArray[1].setNum(score / 100 % 10);
	numArray[2].setNum(score / 10 % 10);
	numArray[3].setNum(score % 10);

	player->setPos(player->getPosX(), player->getPosY() + gravity * dTime);
	if (isJump) {
		player->setPos(player->getPosX(), player->getPosY() - 500 * dTime);
		if (doubleJump) {
			player->setPos(player->getPosX(), player->getPosY() - 300 * dTime);
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

}

