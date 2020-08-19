#include "stdafx.h"
#include "Npc.h"

Npc::Npc() {
	isSus = false;
	switch (rand()%3) {
	case 0:
		npc = new Sprite("Resources/Image/Npc.png");
		break;
	case 1:
		npc = new Sprite("Resources/Image/Npc_Pink.png");
		break;
	case 2:
		npc = new Sprite("Resources/Image/Npc_Ast.png");
		break;
	default:
		break;
	}
	AddChild(npc);

	rect = npc->getRect();
}

//Npc::Npc(bool isDead) {
//	this->isDead = isDead;
//	if (isDead) {
//		npc = new Sprite("Resources/Image/Npc_Dying.png");
//		npc = new Sprite("Resources/Image/Npc_Dead.png");
//	}
//	else {
//		npc = new Sprite("Resources/Image/Npc.png");
//
//	}
//	AddChild(npc);
//
//	rect = npc->getRect();
//}

Npc::Npc(bool isSus) {
	this->isSus = isSus;
	if (isSus) {
		//npc = new Sprite("Resources/Image/Npc_Dying.png");
		//npc = new Sprite("Resources/Image/Npc_Dead.png");
		npc = new Sprite("Resources/Image/Npc_Sus.png");
		AddChild(npc);
		rect = npc->getRect();
	}/*
	else {
		npcD = new Sprite("Resources/Image/Npc_Dead.png");
		AddChild(npcD);
		rect = npcD->getRect();
	}*/
}

Npc::~Npc() {

}

void Npc::Update(float dTime) {
	Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime * 1.2, getPosY());
}

void Npc::Render() {
	if (isSus) {
		Object::Render();
		npc->Render();
	}
	else {
		Object::Render();
		npc->Render();

	}
}

bool Npc::IsSus() {
	return isSus;
}