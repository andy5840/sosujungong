#include "stdafx.h"
#include "Cctv.h"

Cctv::Cctv() {
	cctv = new Sprite("Resources/Image/Cctv.png");
	AddChild(cctv);

	rect = cctv->getRect();
}
Cctv::~Cctv() {

}

void Cctv::Update(float dTime) {
	Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime, getPosY());
}

void Cctv::Render() {
	Object::Render();
	cctv->Render();
}