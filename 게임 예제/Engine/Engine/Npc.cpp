#include "stdafx.h"
#include "Npc.h"

Npc::Npc() {
	npc = new Sprite("Resources/Image/Npc.png");
	AddChild(npc);
}

Npc::~Npc() {

}

void Npc::Render() {
	Object::Render();
	npc->Render();
}

void Npc::Update(float dTime) {
	Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime, getPosY());
}